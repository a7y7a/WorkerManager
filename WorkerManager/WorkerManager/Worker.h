#pragma once
#include<iostream>
using namespace std;
#include<string>

class Worker
{
public:
	virtual void showinfo() = 0;
	virtual string showdept() = 0;

	//Worker();
	int mid;
	string mname;
	int mdeptid;
	//~Worker();
};