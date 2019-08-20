// IpMonitor_Cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "sessionsManager.h"

int main()
{

	Aws::SDKOptions options;
	Aws::InitAPI(options);
	{
		Session *sess = new Session();
		sess->addIp();
	}
	Aws::ShutdownAPI(options);
}

