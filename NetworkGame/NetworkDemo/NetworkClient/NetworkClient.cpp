// NetworkClient.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <WS2tcpip.h>
#include <iostream>
#include <vector>
#include <time.h>
#include "../../Network/Network/NetworkIO.h"
UsingNamespaceNetwork
using namespace std;
class AutoWSA
{
public:
	AutoWSA()
	{
		WSADATA wsa_data;
		WSAStartup(MAKEWORD(2, 2), &wsa_data);
	}
	~AutoWSA()
	{
		WSACleanup();
	}
};


#define IP_SERVER_S "127,0,0,1"
#define IP_SERVER 127,0,0,1
#define PROT_SERVER 9796


int main()
{
	AutoWSA wsa;

	SocketAddress server_addr(IP_SERVER, PROT_SERVER);

	TcpSocketPtr socket = SocketUtil::CreateTcpSocket();

	if (socket->Connect(server_addr) < 0)
	{
		cout << "connect to server failed." << endl;
	}
	else
	{
		cout << "connect to server success." << endl;
	}
	srand((unsigned)time(NULL));
	int client_no = rand();

	std::string data = "hello this is client: " + to_string(client_no);

	socket->Send(data.c_str(), data.length()-3);

    return 0;
}

