#include"WorkManager.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"

int main()
{
	WorkManager w;
	int choice;
	do
	{
		w.menu();
		cout << "ÇëÊäÈëÑ¡Ôñ" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			w.mexit();
			break;
		case 1:
			w.madd();
			break;
		case 2:
			w.mshow();
			break;
		case 3:
			w.mdel();
			break;
		case 4:
			w.mmod();
			break;
		case 5:
			w.mfind();
			break;
		case 6:
			w.msort();
			break;
		case 7:
			w.mclean();
			break;
		default:
			system("cls");
			break;
		}
	} while (choice);
	
	system("pause");
	return 0;
}