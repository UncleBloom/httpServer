//
// Created by 王一舟 on 2021/10/8.
//

#include "HttpProcessor.h"
#include <sstream>

map<int, string> HttpProcessor::codeToPhrase = {{200, "OK"},
                                                {400, "Bad Request"},
                                                {401, "Unauthorized"},
                                                {403, "Forbidden"},
                                                {404, "Not Found"},
                                                {500, "Internal Server Error"},
                                                {503, "Server Unavailable"}};

/*
 * 处理HTTP报文
 */
void HttpProcessor::process() {
  //接收并存储请求报文
  long recvLen = recv(c_sock, recvMassage, sizeof(recvMassage), 0);
  if (recvLen == 1)
    cout << "!! receive error\n";
  else if (recvLen == 0) {
    cout << "!! disconnect\n";
    return;
  } else
    //获取请求行
    getRequestLine();
  //生成并发送响应报文
  if (sendResponse()) {
    // cout << "send respond massage successful" << endl;
  } else {
    cout << "!! failed to send respond massage: " + to_string(statesCode) +
                " | URL: " + url + "\n";
  }
  close(c_sock);
}

/*
 * description: 获取请求行
 * return: 1成功解析；0解析异常
 */
int HttpProcessor::getRequestLine() {
  // 匹配请求行的正则表达式
  smatch sMatch;
  regex regulation("([A-Za-z]+) +(.*) +(HTTP/[0-9][.][0-9])");
  string s(recvMassage);
  // 若请求违法
  if (!regex_search(s, sMatch, regulation)) {
    statesCode = 400;
    cout << "!! request massage format exception\n";
    return 0;
  }
  // 解析URL
  char clientIP[20];
  inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, 20);
  cout << "-- " + sMatch[0].str() + " | from IP:" + string(clientIP) +
              " ; port:" + to_string(clientAddr.sin_port) + "\n";
  this->method = sMatch[1];
  if (sMatch[2].str().size() <= 2)
    this->url = "/index.html";
  else {
    string str = sMatch[2].str();
    this->url = str.substr(0, str.find('?'));
  }
  return 1;
}

/*
 * description: 生成并发送响应报文
 * return: 1正确响应请求；0异常
 */
int HttpProcessor::sendResponse() {
  ifstream f(file_path + url, ios::in);
  // 如果没找到文件
  if (!f.is_open()) {
    statesCode = 404;
    f.open(NOT_FOUND_FILE, ios::in);
    if (!f.is_open()) {
      cout << "!! not open 404 file\n";
    }
  }
  // 读取文件内容并计算长度
  filebuf *tmp = f.rdbuf();
  int contentSize = tmp->pubseekoff(0, f.end, f.in);
  tmp->pubseekpos(0, f.in);
  stringstream content;
  content << f.rdbuf();

  // 生成响应报文
  stringstream respondMassage;
  respondMassage << version + " " + to_string(statesCode) + " " +
                        codeToPhrase[statesCode] + "\r\n";
  respondMassage << "Connection: close\r\n";
  respondMassage << "Server: Legolas Wang\r\n";
  respondMassage << "Content size: " << contentSize << "\r\n";
  respondMassage << "\r\n";
  respondMassage << content.str() << "\r\n";
  string massageStr = respondMassage.str();
  cout << "√ " + url + " : " + to_string(statesCode) + " " +
              codeToPhrase[statesCode]
       << endl;

  // 发送相应报文
  send(c_sock, massageStr.c_str(), massageStr.size(), 0);
  return statesCode == 200;
}
