using namespace std;
#include"workermanger.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<iostream>


int main()
{
	workermanger wm;
	int choice = 0;//���ڴ����û�ѡ��
	while (true)
	{
		wm.showmenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitsys();
			break;
		case 1://����ְ��
			wm.add_emp();
			break;
		case 2://��ʾְ��
			wm.show();
			break;
		case 3://ɾ��ְ��
			wm.delemp();
			break;
		case 4://�޸�ְ��
			wm.change();
			break;
		case 5://����ְ��
			wm.findemp();
			break;
		case 6://����ְ��
			wm.sort();
			break;
		case 7://����ĵ�
			wm.clean();
			break;
		case 8:
			break;
		case 9:
			break;
		default:
			system("cls");
			break;
		}
	}
	
	
	system("pause");
	return 0;
}