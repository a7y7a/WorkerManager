#pragma once
#include"Worker.h"

class Employee :public Worker
{
public:
	Employee(int id, string name, int deptid);
	virtual void showinfo();
	virtual string showdept();
};
