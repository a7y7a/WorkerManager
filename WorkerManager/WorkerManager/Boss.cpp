#include"Boss.h"

Boss::Boss(int id, string name, int deptid)
{
	mid = id;
	mname = name;
	mdeptid = deptid;
}
void Boss::showinfo()
{
	cout << "编号" << mid
		<< "\t姓名" << mname
		<< "\t岗位" << showdept()
		<< "\t给经理下达任务" << endl;
}
string Boss::showdept()
{
	return string("老板");
}