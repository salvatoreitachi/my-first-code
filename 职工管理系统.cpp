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
	int choice = 0;//用于储存用户选项
	while (true)
	{
		wm.showmenu();
		cout << "请输入您的选择" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0://退出系统
			wm.exitsys();
			break;
		case 1://增加职工
			wm.add_emp();
			break;
		case 2://显示职工
			wm.show();
			break;
		case 3://删除职工
			wm.delemp();
			break;
		case 4://修改职工
			wm.change();
			break;
		case 5://查找职工
			wm.findemp();
			break;
		case 6://排序职工
			wm.sort();
			break;
		case 7://清空文档
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