#include "udp_client.h"

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    std::cout << "Usage:" << argv[1] << " [server_ip][serverport]" << std::endl; 
    return 1;
  }

  UdpClient client(argv[1], atoi(argv[2]));
  client.InitClient();

  std::string message;
  while(1)
  {
    std::cout << "Please Enter$ ";
    std::cin >> message;
    client.SendData(message);
  }
  return 0;
}
