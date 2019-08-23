// IpMonitor_Cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <thread>
#include "sessionsManager.h"

int main()
{

	using namespace std::chrono_literals;

	Aws::SDKOptions options;
	Aws::InitAPI(options);
	{
		Session *sess = new Session();
		while(true) 
		{
			sess->addIp();
			std::this_thread::sleep_for(3600s);
		}
	}
	Aws::ShutdownAPI(options);
}

