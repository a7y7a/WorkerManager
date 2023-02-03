#include"WorkManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"


WorkManager::WorkManager()
{
	mnum = 0;
	marry = NULL;
	ifstream ifs(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		mnum = 0;
		marry = NULL;
		mfile = true;
		ifs.close();
		return;
	}
	if (ifs.get() == EOF)
	{
		cout << "文件为空" << endl;
		mnum = 0;
		marry = NULL;
		mfile = true;
		ifs.close();
		return;
	}
	int num = getnum();
	cout << "职工人数为" << num << endl;
	mnum = num;
	marry = new Worker * [mnum];
	minit();
}

void WorkManager::menu()
{
	cout << "********************************************" << endl;
	cout << "********* 欢迎使用职工管理系统！ **********" << endl;
	cout << "************* 0.退出管理程序 *************" << endl;
	cout << "************* 1.增加职工信息 *************" << endl;
	cout << "************* 2.显示职工信息 *************" << endl;
	cout << "************* 3.删除离职职工 *************" << endl;
	cout << "************* 4.修改职工信息 *************" << endl;
	cout << "************* 5.查找职工信息 *************" << endl;
	cout << "************* 6.按照编号排序 *************" << endl;
	cout << "************* 7.清空所有文档 *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkManager::mexit()
{
	cout << "结束" << endl;
	//system("pause");
	//exit(0);
}

void WorkManager::madd()
{
	cout << "输入添加人数" << endl;
	int addnum;
	cin >> addnum;
	if (addnum > 0)
	{
		int newsize = mnum + addnum;
		Worker** newarry = new Worker * [newsize];
		if (marry != NULL)
		{
			for (int i = 0; i < mnum; i++)
			{
				newarry[i] = marry[i];
			}
		}
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int deptid;
			while (true)
			{
				cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
				cin >> id;
				int ret = 0;
				for (int j = 0; j < mnum + i; j++)
				{
					if (newarry[j]->mid == id)
					{
						cout << "编号重复" << endl;
						ret = 1;
						break;
					}
				}
				if (!ret)
				{
					break;
				}
			}
			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			Worker* worker = NULL;
			do
			{
				cin >> deptid;
				switch (deptid)
				{
				case 1:
					worker = new Employee(id, name, deptid);
					deptid = 0;
					break;
				case 2:
					worker = new Employee(id, name, deptid);
					deptid = 0;
					break;
				case 3:
					worker = new Employee(id, name, deptid);
					deptid = 0;
					break;
				default:
					deptid = 4;
					cout << "输错了" << endl;
					break;
				}
			} while (deptid);
			newarry[mnum + i] = worker;
		}
		delete[] marry;
		mnum = newsize;
		marry = newarry;
		cout << "添加成功" << addnum << "名员工" << endl;
		msave();
		mfile = false;
	}
	else
	{
		cout << "错了" << endl;
	}
	system("pause");
	system("cls");
}

void WorkManager::msave()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < mnum; i++)
	{
		ofs << marry[i]->mid << " "
			<< marry[i]->mname << " "
			<< marry[i]->mdeptid << " "
			<< endl;
	}
	ofs.close();
}

int WorkManager::getnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id = 0;
	string name;
	int deptid = 0;
	int num = 0;
	while (ifs >> id && ifs >> name && id >> deptid)
	{
		num++;
	}
	return num;
}

void WorkManager::minit()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id = 0;
	string name;
	int deptid = 0;
	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		Worker* worker = NULL;
		switch (deptid)
		{
		case 1:
			worker = new Employee(id, name, deptid);
			break;
		case 2:
			worker = new Employee(id, name, deptid);
			break;
		case 3:
			worker = new Employee(id, name, deptid);
			break;
		default:
			cout << id << "岗位编号错误" << endl;
			break;
		}
		marry[i++] = worker;
	}
}

void WorkManager::mshow()
{
	if (mfile)
	{
		cout << "文件为空或不存在" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < mnum; i++)
	{
		marry[i]->showinfo();
	}
}

int WorkManager::isexit(int id)
{
	int ret = -1;
	for (int i = 0; i < mnum; i++)
	{
		if (marry[i]->mid == id)
		{
			ret = i;
			break;
		}
	}
	return ret;
}

void WorkManager::mdel()
{
	if (mfile)
	{
		cout << "文件为空或不存在" << endl;
		system("pause");
		system("cls");
		return;
	}
	int id;
	cout << "请输入编号" << endl;
	cin >> id;
	int ret = isexit(id);
	if (ret == -1)
	{
		cout << "未找到该职工" << endl;
		return;
	}
	for (int i = ret; i < mnum; i++)
	{
		marry[i] = marry[i + 1];
	}
	mnum--;
	msave();
	cout << "删除成功" << endl;
	if (!mnum)
	{
		mfile = true;
	}
	system("pause");
	system("cls");
}

void WorkManager::mmod()
{
	if (mfile)
	{
		cout << "文件为空或不存在" << endl;
		system("pause");
		system("cls");
		return;
	}
	int id;
	cout << "请输入修改员工编号" << endl;
	cin >> id;
	int ret = isexit(id);
	if (ret == -1)
	{
		cout << "未找到该职工" << endl;
		return;
	}
	delete marry[ret];
	int nid = 0;;
	string nname = "";
	int ndeptid = 0;
	while (true)
	{
		int nret = 0;
		for (int j = 0; j < mnum; j++)
		{
			cout << "请输入编号：" << endl;
			cin >> nid;
			if (marry[j]->mid == nid)
			{
				cout << "编号重复" << endl;
				nret = 1;
				break;
			}
		}
		if (!nret)
		{
			break;
		}
	}
	cout << "请输入姓名：" << endl;
	cin >> nname;
	cout << "请选择该职工的岗位：" << endl;
	cout << "1、普通职工" << endl;
	cout << "2、经理" << endl;
	cout << "3、老板" << endl;
	Worker* worker = NULL;
	do
	{
		cin >> ndeptid;
		switch (ndeptid)
		{
		case 1:
			worker = new Employee(nid, nname, ndeptid);
			ndeptid = 0;
			break;
		case 2:
			worker = new Employee(nid, nname, ndeptid);
			ndeptid = 0;
			break;
		case 3:
			worker = new Employee(nid, nname, ndeptid);
			ndeptid = 0;
			break;
		default:
			ndeptid = 4;
			cout << "输错了" << endl;
			break;
		}
	} while (ndeptid);
	marry[ret] = worker;
	cout << "修改成功" << endl;
	msave();
	system("pause");
	system("cls");
}

void WorkManager::mfind()
{
	if (mfile)
	{
		cout << "文件为空或不存在" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入查找方式" << endl;
	cout << "1.按编号查找" << endl;
	cout << "2.按姓名查找" << endl;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
	{
		int id;
		cout << "请输入修改员工编号" << endl;
		cin >> id;
		int ret = isexit(id);
		if (ret == -1)
		{
			cout << "未找到该职工" << endl;
			return;
		}
		marry[ret]->showinfo();
		break;
	}
	case 2:
	{
		string name;
		cout << "请输入修改员工姓名" << endl;
		cin >> name;
		int ret = -1;
		for (int i = 0; i < mnum; i++)
		{
			if (marry[i]->mname == name)
			{
				ret = i;
				break;
			}
		}
		if (ret == -1)
		{
			cout << "未找到该职工" << endl;
			return;
		}
		marry[ret]->showinfo();
		break;
	}
	default:
		cout << "输错了" << endl;
		break;
	}
	system("pause");
	system("cls");
}

void WorkManager::msort()
{
	if (mfile)
	{
		cout << "文件为空或不存在" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < mnum - 1; i++)
	{
		for (int j = 0; j < mnum - i - 1; j++)
		{
			Worker* temp = NULL;
			if (marry[i]->mid > marry[i + 1]->mid)
			{
				temp = marry[i];
				marry[i] = marry[i + 1];
				marry[i + 1] = temp;
			}
		}
	}
	cout << "排序完毕" << endl;
	msave();
}

void WorkManager::mclean()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (marry != NULL)
		{
			for (int i = 0; i < mnum; i++)
			{
				if (marry[i] != NULL)
				{
					delete marry[i];
					//marry[i] = NULL;
				}
			}
			mnum = 0;
			delete[] marry;
			marry = NULL;
			mfile = true;
		}
		cout << "清除成功" << endl;
	}
	system("pause");
	system("cls");
}


WorkManager::~WorkManager()
{
	if (marry != NULL)
	{
		delete[] marry;
		marry = NULL;
	}
}



