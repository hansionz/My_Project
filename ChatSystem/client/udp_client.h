#pragma once 

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netinet/in.h>

#define SIZE 1024 //发送信息的最大长度

//https和http的区别是在传输层和网络层之间加了ssl(加密层)
//然后在对方的同层进行解密
class UdpClient
{
public:
  UdpClient(std::string server_ip, uint16_t server_port);
  void InitClient();
  
  //客户端收数据
  void RecvData(std::string &out_string);

  //客户端发送数据
  void SendData(const std::string &in_string);

  ~UdpClient();

private:
  int sock;
  struct sockaddr_in server_addr;
};
