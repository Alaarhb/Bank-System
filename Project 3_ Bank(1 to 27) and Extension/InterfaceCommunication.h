#pragma once
#include <iostream>
#include <string>
using namespace std;

class InterfaceCommunication
{

public :

	virtual void SendEmail(string Title, string Body) = 0;
	virtual void SendFax(string Title, string Body) = 0;
	virtual void SendSms(string Title, string Body) = 0;

};

