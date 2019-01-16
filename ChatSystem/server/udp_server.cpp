#include "udp_server.h"
#include "Data.h"


UdpServer::UdpServer(uint16_t _port)
    :port(_port)
  {}
  void UdpServer::InitServer()
  {
    //创建套接字
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock < 0){
      std::cerr << "socket error!" << std::endl;
      return;
    }
    //绑定端口号
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0){
      std::cerr << "bind error!" << std::endl;
      return;
      //UDP不需要发送缓冲区,不需要超时重传
      //TCP需要发送缓冲区，需要超时重传(用户不管，所以要存在发送缓冲区)
      //OS从网络上哪数据放到缓冲区
      //TCP存在接收、发送缓冲区.什么时候发由TCP控制(流量控制、超时重传、拥塞控制)
      //UDP存在接收缓冲区、但不存在发送缓冲区
    }
  }
  //面试官问:UDP丢包怎么办？
  //将TCP中的一些合适的可靠机制放在用户层去实现
  
  //服务器收数据
  void UdpServer::RecvData(std::string &out_string)
  {
    char buf[SIZE];
    //维护在线用户列表
    struct sockaddr_in peer;
    socklen_t len = sizeof(peer);
    ssize_t rs = recvfrom(sock, buf, SIZE, 0, (struct sockaddr*)&peer, &len);
    if(rs > 0){
      buf[rs] = 0;
      out_string = buf;
      pool.PutMess(out_string);
      Data d;
      d.Unserialize(out_string);
      if(d.type == "quit"){
        std::map<uint32_t, struct sockaddr_in>::iterator it = online.find(peer.sin_addr.s_addr);
        if(it != online.end()){
          online.erase(it->first);//key值
        }
      }else{
        online.insert(std::pair<uint32_t, struct sockaddr_in>(peer.sin_addr.s_addr, peer));
      }
    }
    std::cout << "接收成功" << std::endl;
  }
  //服务器向目的地址单向发送消息
  void UdpServer::SendData(const std::string &in_string, const struct sockaddr_in &peer)
  {
    sendto(sock, in_string.c_str(), in_string.size(), 0, (struct sockaddr*)&peer,sizeof(peer));
    std::cout << "发送成功" << std::endl;
  }

  //服务器向除发送发以外的所有人发送消息
void UdpServer::BroadCast()
{
  std::string mess;
  pool.GetMess(mess);

  std::map<uint32_t, struct sockaddr_in>::iterator it = online.begin();
  for( ; it != online.end() ; it++ )
  {
    SendData(mess, it->second);
  }
}

UdpServer::~UdpServer()
  {
    close(sock);
    port = -1;
  }
