#include"Employee.h"

Employee::Employee(int id, string name, int deptid)
{
	mid = id;
	mname = name;
	mdeptid = deptid;
}
void Employee::showinfo()
{
	cout << "���" << mid
		<< "\t����" << mname
		<< "\t��λ" << showdept()
		<< "\t��ɾ��������" << endl;
}
string Employee::showdept()
{
	return string("Ա��");
}