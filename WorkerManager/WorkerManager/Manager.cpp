#include"Manager.h"

Manager::Manager(int id, string name, int deptid)
{
	mid = id;
	mname = name;
	mdeptid = deptid;
}
void Manager::showinfo()
{
	cout << "编号" << mid
		<< "\t姓名" << mname
		<< "\t岗位" << showdept()
		<< "\t完成老板的任务，给员工下达任务" << endl;
}
string Manager::showdept()
{
	return string("经理");
}