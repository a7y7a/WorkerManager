#include"Manager.h"

Manager::Manager(int id, string name, int deptid)
{
	mid = id;
	mname = name;
	mdeptid = deptid;
}
void Manager::showinfo()
{
	cout << "���" << mid
		<< "\t����" << mname
		<< "\t��λ" << showdept()
		<< "\t����ϰ�����񣬸�Ա���´�����" << endl;
}
string Manager::showdept()
{
	return string("����");
}