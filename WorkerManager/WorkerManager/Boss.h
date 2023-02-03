#pragma once
#include"Worker.h"

class Boss :public Worker
{
public:
	Boss(int id, string name, int deptid);
	virtual void showinfo();
	virtual string showdept();
};