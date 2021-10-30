#include "HttpProcessor.h"
#include <thread>

#define MAXLINK 1024

string filePath; //服务器资源路径
string version;  //版本号
string IP;       // IP地址
int port;        //端口号

void catchOpt();
void config();
bool createConfigFile();

/*
 * 处理控制操作
 */
void catchOpt() {
  while (int ch = getchar()) {
    //退出程序
    if (ch == 'q') {
      exit(0);
    }
    //重新配置
    if (ch == 'c') {
      config();
    }
  }
}

/*
 * 从文件中读取配置，如果文件损坏或格式不对则重新创建配置文件
 */
void config() {
  ifstream config("config", ios::in);
  if (!config.is_open()) {
    cout << "config file is missing" << endl;
    if (createConfigFile())
      return;
  }
  char tmp[128] = {};
  string info;
  config.getline(tmp, sizeof(tmp));
  info = string(tmp);
  //读版本信息
  if (info.substr(0, info.find(':')) != "version") {
    cout << "config file is broken" << endl;
    if (createConfigFile())
      return;
  } else {
    version = info.substr(info.find(':') + 1);
  }
  //读资源路径
  config.getline(tmp, sizeof(tmp));
  info = string(tmp);
  if (info.substr(0, info.find(':')) != "filePath") {
    cout << "config file is broken" << endl;
    if (createConfigFile())
      return;
  } else {
    filePath = info.substr(info.find(':') + 1);
  }
  //读IP地址
  config.getline(tmp, sizeof(tmp));
  info = string(tmp);
  if (info.substr(0, info.find(':')) != "IP") {
    cout << "config file is broken" << endl;
    if (createConfigFile())
      return;
  } else {
    IP = info.substr(info.find(':') + 1);
  }
  //读端口号
  config.getline(tmp, sizeof(tmp));
  info = string(tmp);
  if (info.substr(0, info.find(':')) != "port") {
    cout << "config file is broken" << endl;
    if (createConfigFile())
      return;
  } else {
    string p = (info.substr(info.find(':') + 1));
    port = stoi(p);
  }
  cout << "----configurations renewed successfully----" << endl;
  cout << "- version: " << version << endl;
  cout << "- filePath: " << filePath << endl;
  cout << "- IP: " << IP << endl;
  cout << "- port: " << port << endl;
  cout << "----new configuration will apply to later connections----" << endl;
}

/*
 * 重新创建配置文件
 */
bool createConfigFile() {
  cout << "now you need to offer following information to recreate "
          "configuration file:"
       << endl;
  cout << "- version: ";
  cin >> version;
  cout << "- filePath: ";
  cin >> filePath;
  cout << "- IP: ";
  cin >> IP;
  cout << "- port: ";
  cin >> port;
  cout << "----configurations renewed successfully----" << endl;
  cout << "----new configuration will apply to later connections----" << endl;
  ofstream config("config", ios::out);
  if (!config.is_open()) {
    cout << "fail to create config file" << endl;
    return false;
  }
  config << "version:" << version << endl
         << "filePath:" << filePath << endl
         << "IP:" << IP << endl
         << "port:" << port << endl;
  config.close();
  cout << "create config file successfully" << endl;
  return true;
}

int main() {

  //配置服务器参数
  config();
  //创建监听套接字
  int _sock = socket(AF_INET, SOCK_STREAM, 0);
  if (_sock == -1) {
    perror("! socket error\n");
    return 1;
  }

  //绑定接受连接请求的端口
  sockaddr_in _sin = {};
  bzero(&_sin, sizeof(_sin));
  _sin.sin_family = AF_INET;   //协议族IPV4
  _sin.sin_port = htons(port); //端口号 host_to_net
  if (IP.empty() || IP == "-" || IP == "all") {
    _sin.sin_addr.s_addr = htonl(INADDR_ANY); //不限定访问该服务器的ip
  } else {
    inet_pton(AF_INET, IP.data(), &_sin.sin_addr);
  }
  if (-1 == ::bind(_sock, (sockaddr *)&_sin, sizeof(_sin))) {
    cout << "!! bind error" << endl;
    return 0;
  }

  //监听端口
  if (listen(_sock, MAXLINK) == -1) {
    perror("!! listen error\n");
  } else {
    cout << ">>> listening" << endl;
  }

  thread catchOp(catchOpt);
  catchOp.detach();

  while (true) {
    //等待连接请求
    sockaddr_in clientAddr = {};
    socklen_t nAddrLen = sizeof(sockaddr_in);
    int _cSock =
        accept(_sock, (sockaddr *)&clientAddr,
               &nAddrLen); //套接字，收到客户端socket地址，返回socket地址的大小
    if (_cSock < 0) {
      perror("!! client socket error!\n");
    }

    HttpProcessor *httpProcessor =
        new HttpProcessor(version, filePath, _cSock, clientAddr);
    //处理请求
    // httpProcessor->process();//单线程实现

    //多线程实现
    thread process(&HttpProcessor::process, httpProcessor);
    process.detach();
  }
}
