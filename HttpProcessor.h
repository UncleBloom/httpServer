//
// Created by 王一舟 on 2021/10/8.
//

#ifndef WEBSERVER_HTTPPROCESSOR_H
#define WEBSERVER_HTTPPROCESSOR_H

#include <arpa/inet.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <netinet/in.h>
#include <regex>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <utility>

#define NOT_FOUND_FILE "../404.html" // 404报错时返回的html文件的相对路径

using namespace std;

class HttpProcessor {
public:
  /*
   * 处理HTTP报文
   */
  void process();

  //构造函数
  HttpProcessor(string version, string filePath, int cSock,
                const sockaddr_in &clientAddr)
      : version(std::move(version)), file_path(std::move(filePath)),
        c_sock(cSock), clientAddr(clientAddr) {}

private:
  //版本号
  string version;

  //服务器资源文件夹路径
  string file_path;

  //请求报文的方法
  string method;

  //请求资源的URL
  string url;

  //套接字
  int c_sock;

  //客户端地址
  sockaddr_in clientAddr;

  //状态码
  int statesCode = 200;

  //请求报文
  char recvMassage[2048]{};

  //状态码与描述的对应表
  static map<int, string> codeToPhrase;

  /*
   * description: 获取请求行
   * return: 1成功解析；0解析异常
   */
  int getRequestLine();

  /*
   * description: 生成并发送响应报文
   * return: 1正确响应请求；0异常
   */
  int sendResponse();
};

#endif // WEBSERVER_HTTPPROCESSOR_H
