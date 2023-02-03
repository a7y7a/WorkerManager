#include"Employee.h"

Employee::Employee(int id, string name, int deptid)
{
	mid = id;
	mname = name;
	mdeptid = deptid;
}
void Employee::showinfo()
{
	cout << "编号" << mid
		<< "\t姓名" << mname
		<< "\t岗位" << showdept()
		<< "\t完成经理的任务" << endl;
}
string Employee::showdept()
{
	return string("员工");
}