#include "udp_server.h"

void* RecvMess(void *arg)
{
  UdpServer *us = (UdpServer*)arg;
  std::string message;
  while(1)
  {
    us->RecvData(message);
    std::cout << "test:" << message << std::endl;
  }
}
void* SendMess(void *arg)
{
  UdpServer *us = (UdpServer*)arg;
  while(1)
  {
    us->BroadCast();
  }
}
int main(int argc, char* argv[])
{
  if(argc != 2)
  {
    std::cout << "Usage:" << argv[0] << " port" << std::endl;
    return 1;
  }

  UdpServer server(atoi(argv[1]));
  server.InitServer();
  pthread_t r, s;
  //收数据线程
  pthread_create(&r, NULL, RecvMess, (void*)&server);
  //从环形队列获取数据，并转发给其他人的线程
  pthread_create(&s, NULL, SendMess, (void*)&server);

  pthread_join(r, NULL);
  pthread_join(s, NULL);

  return 0;
}
