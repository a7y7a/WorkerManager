#include"Boss.h"

Boss::Boss(int id, string name, int deptid)
{
	mid = id;
	mname = name;
	mdeptid = deptid;
}
void Boss::showinfo()
{
	cout << "���" << mid
		<< "\t����" << mname
		<< "\t��λ" << showdept()
		<< "\t�������´�����" << endl;
}
string Boss::showdept()
{
	return string("�ϰ�");
}