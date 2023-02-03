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
		cout << "�ļ�������" << endl;
		mnum = 0;
		marry = NULL;
		mfile = true;
		ifs.close();
		return;
	}
	if (ifs.get() == EOF)
	{
		cout << "�ļ�Ϊ��" << endl;
		mnum = 0;
		marry = NULL;
		mfile = true;
		ifs.close();
		return;
	}
	int num = getnum();
	cout << "ְ������Ϊ" << num << endl;
	mnum = num;
	marry = new Worker * [mnum];
	minit();
}

void WorkManager::menu()
{
	cout << "********************************************" << endl;
	cout << "********* ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "************* 0.�˳�������� *************" << endl;
	cout << "************* 1.����ְ����Ϣ *************" << endl;
	cout << "************* 2.��ʾְ����Ϣ *************" << endl;
	cout << "************* 3.ɾ����ְְ�� *************" << endl;
	cout << "************* 4.�޸�ְ����Ϣ *************" << endl;
	cout << "************* 5.����ְ����Ϣ *************" << endl;
	cout << "************* 6.���ձ������ *************" << endl;
	cout << "************* 7.��������ĵ� *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkManager::mexit()
{
	cout << "����" << endl;
	//system("pause");
	//exit(0);
}

void WorkManager::madd()
{
	cout << "�����������" << endl;
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
				cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
				cin >> id;
				int ret = 0;
				for (int j = 0; j < mnum + i; j++)
				{
					if (newarry[j]->mid == id)
					{
						cout << "����ظ�" << endl;
						ret = 1;
						break;
					}
				}
				if (!ret)
				{
					break;
				}
			}
			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
					cout << "�����" << endl;
					break;
				}
			} while (deptid);
			newarry[mnum + i] = worker;
		}
		delete[] marry;
		mnum = newsize;
		marry = newarry;
		cout << "��ӳɹ�" << addnum << "��Ա��" << endl;
		msave();
		mfile = false;
	}
	else
	{
		cout << "����" << endl;
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
			cout << id << "��λ��Ŵ���" << endl;
			break;
		}
		marry[i++] = worker;
	}
}

void WorkManager::mshow()
{
	if (mfile)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
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
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
		system("pause");
		system("cls");
		return;
	}
	int id;
	cout << "��������" << endl;
	cin >> id;
	int ret = isexit(id);
	if (ret == -1)
	{
		cout << "δ�ҵ���ְ��" << endl;
		return;
	}
	for (int i = ret; i < mnum; i++)
	{
		marry[i] = marry[i + 1];
	}
	mnum--;
	msave();
	cout << "ɾ���ɹ�" << endl;
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
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
		system("pause");
		system("cls");
		return;
	}
	int id;
	cout << "�������޸�Ա�����" << endl;
	cin >> id;
	int ret = isexit(id);
	if (ret == -1)
	{
		cout << "δ�ҵ���ְ��" << endl;
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
			cout << "�������ţ�" << endl;
			cin >> nid;
			if (marry[j]->mid == nid)
			{
				cout << "����ظ�" << endl;
				nret = 1;
				break;
			}
		}
		if (!nret)
		{
			break;
		}
	}
	cout << "������������" << endl;
	cin >> nname;
	cout << "��ѡ���ְ���ĸ�λ��" << endl;
	cout << "1����ְͨ��" << endl;
	cout << "2������" << endl;
	cout << "3���ϰ�" << endl;
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
			cout << "�����" << endl;
			break;
		}
	} while (ndeptid);
	marry[ret] = worker;
	cout << "�޸ĳɹ�" << endl;
	msave();
	system("pause");
	system("cls");
}

void WorkManager::mfind()
{
	if (mfile)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��������ҷ�ʽ" << endl;
	cout << "1.����Ų���" << endl;
	cout << "2.����������" << endl;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
	{
		int id;
		cout << "�������޸�Ա�����" << endl;
		cin >> id;
		int ret = isexit(id);
		if (ret == -1)
		{
			cout << "δ�ҵ���ְ��" << endl;
			return;
		}
		marry[ret]->showinfo();
		break;
	}
	case 2:
	{
		string name;
		cout << "�������޸�Ա������" << endl;
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
			cout << "δ�ҵ���ְ��" << endl;
			return;
		}
		marry[ret]->showinfo();
		break;
	}
	default:
		cout << "�����" << endl;
		break;
	}
	system("pause");
	system("cls");
}

void WorkManager::msort()
{
	if (mfile)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
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
	cout << "�������" << endl;
	msave();
}

void WorkManager::mclean()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
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
		cout << "����ɹ�" << endl;
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



