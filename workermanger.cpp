#include"workermanger.h"
#include<iostream>

using namespace std;

workermanger::workermanger()
{
	//文件不存在
	ifstream ifs;
	ifs.open(filename, ios::in);//读文件
	if(!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		//继续初始化属性，初始化数组指针
		this->m_empnum = 0;
		this->m_emparray = NULL;
		//初始化文件是否为空
		this->m_fileisempty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空！" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		//初始化文件是否为空
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	
	//文件存在 记录数据
	int num = this->get_empnum();
	//cout << "职工的人数为：" << num << endl;
	this->m_empnum = num;

	this->m_emparray = new worker * [this->m_empnum];//开辟空间
	this->init_emp();//将文件中的数据 存到数组中
	
}

void workermanger::showmenu()
{
	cout << "*********************************" << endl;
	cout << "******欢迎使用职工管理系统!******" << endl;
	cout << "**********0退出管理程序**********" << endl;
	cout << "**********1增加职工信息**********" << endl;
	cout << "**********2显示职工信息**********" << endl;
	cout << "**********3删除离职职工**********" << endl;
	cout << "**********4修改职工信息**********" << endl;
	cout << "**********5查找职工信息**********" << endl;
	cout << "**********6按照编号排序**********" << endl;
	cout << "**********7清空所有文档**********" << endl;
	cout << "*********************************" << endl;
}

void workermanger::exitsys()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}

void workermanger::add_emp()//加人
{
	cout << "请输入添加职工的数量：" << endl;
	int add_num = 0;
	cin >> add_num;
	if (add_num > 0)
	{ //新空间大小=原来记录人数+新增人数
		int newsize = this->m_empnum + add_num;
		//开辟新区域
		worker** newspace = new worker * [newsize];
		//将原来空间下数据，拷贝到新空间下
		if (this->m_emparray != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				newspace[i] = this->m_emparray[i];
			}
		}
		//批量添加数据
		for (int i = 0; i < add_num; i++)
		{
			int id;
			string name;
			int deptid;//部门选择
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请选择该职工岗位" << endl;
			cout << "1普通职工" << endl;
			cout << "2经理" << endl;
			cout << "3老板" << endl;
			cout << "不要输入其他数字，否则程序会崩" << endl;
			cin >> deptid;
			worker* worker = NULL;
			switch (deptid)
			{
			case 1:
				worker = new employee(id, name, deptid);
				break;
			case 2:
				worker = new manager(id, name, deptid);
				break;
			case 3:
				worker = new boss(id, name, deptid);
				break;
			default:
				break;
			}
			//将创建职工指针保存到数组中
			newspace[this->m_empnum + i] = worker;
		}
		delete[]this->m_emparray;//释放原有空间
		this->m_emparray = newspace;//更新新的空间指向
		this->m_empnum = newsize;//更新新的职工人数
		this->m_fileisempty = false;//更新职工不为空标志
		cout << "成功添加" << add_num << "名新职工!" << endl;
		this->save();//保存数据到文件中
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

void workermanger::save()
{
	ofstream ofs;
	ofs.open(filename, ios::out);//用写文件方式打开文件
	for (int j = 0; j < this->m_empnum; j++)//
	{
		ofs << this->m_emparray[j]->m_id << " "
			<< this->m_emparray[j]->m_name << " "
			<< this->m_emparray[j]->m_deptid << endl;
	}
	ofs.close();
}

int workermanger::get_empnum()
{
	ifstream ifs;
	ifs.open(filename, ios::in);//打开文件

	int id;
	string name;
	int deptid;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>deptid)
	{
		num++;
	}
	return num;
}

void workermanger::init_emp()//初始化职工
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	int id;
	string name;
	int deptid;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		worker* worker = NULL;
		if (deptid == 1)
		{
			worker = new employee(id, name, deptid);
		}
		else if (deptid == 2)
		{
			worker = new manager(id, name, deptid);
		}
		else
		{
			worker = new boss(id, name, deptid);
		}
		this->m_emparray[index] = worker;
		index++;
	}
	ifs.close();
}

void workermanger::show()
{
	//判断文件是否为空
	if (this->m_fileisempty)
	{
		cout << "文件不存在或者记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < m_empnum;i++)
		{
			this->m_emparray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}

int workermanger::isexist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_empnum; i++)
	{
		if (this->m_emparray[i]->m_id == id)
		{
			index = i;//找到职工
			break;
		}
	}
	return index;
}

void workermanger::delemp()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入想要删除的职工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->isexist(id);
		if (index != -1)//说明职工存在 并且删除
		{
			//数据迁移
			for (int i = index; i < this->m_empnum - 1; i++)
			{
				this->m_emparray[i] = this->m_emparray[i + 1];
			}
			this->m_empnum--;//更新数组中记录人员格式
			this->save();//数组同步更新到文件中
			cout << "删除成功。" << endl;

		}
		else
		{
			cout << "未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workermanger::change()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请输入修改职工编号" << endl;
		int id;
		cin >> id;
		int ret = this->isexist(id);
		if (ret != -1)
		{
			delete this->m_emparray[ret];
			int newid = 0;
			string newname = "";
			int newdeptid = 0;
			cout << "查到编号为" << id << "的职工，请输入新的职工号" << endl;
			cin >> newid;
			cout << "请输入新的姓名" << endl;
			cin >> newname;
			cout << "请输入新的岗位编号" << endl;
			cout << "1普通职工" << endl;
			cout << "2经理" << endl;
			cout << "3老板" << endl;
			cin >> newdeptid;
			worker* worker = NULL;
			switch (newdeptid)
			{
			case 1:
				worker = new employee(newid, newname, 1);
				break;
			case 2:
				worker = new manager(newid, newname, 2);
				break;
			case 3:
				worker = new boss(newid, newname, 3);
				break;
			default:
				break;
			}
			//更新数据更新到数组中
			this->m_emparray[ret] = worker;
			cout << "修改成功！" << endl;
			//数据保存到文件中
			this->save();
		}
		else
		{
			cout << "查无此人，修改失败！" << endl;
		}
		system("pause");
		system("cls");
	}
}

void workermanger::findemp()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择查找方式" << endl;
		cout << "1按编号查找" << endl;
		cout << "2按姓名查找" << endl;
		int j = 0;
		cin >> j;
		if (j == 1)
		{
			int id = 0;
			cout << "请输入职工id号" << endl;
			cin >> id;
			int ret = this->isexist(id);
			if (ret != -1)
			{
				cout << "查找成功，该职工信息如下:" << endl;
				this->m_emparray[ret]->showinfo();
			}
			else
			{
				cout << "查无此人" << endl;
			}
		}
		else if (j == 2)
		{
			string name = "";
			cout << "请输入职工姓名" << endl;
			cin >> name;
			bool flag = false;//默认未找到此人
			for (int i = 0; i < this->m_empnum; i++)
			{
				if (this->m_emparray[i]->m_name == name)
				{
					cout << "找到此人,该职工信息如下" << endl;
					flag = true;
					this->m_emparray[i]->showinfo();
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;
			}	
		}
		else
		{
			cout << "输入有误" << endl;
		}
		system("pause");
		system("cls");
	}
}

void workermanger::sort()
{
	if (this->m_fileisempty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1按照工号进行升序" << endl;
		cout << "2按照工号进行降序" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_empnum; i++)
		{
			int a = i;
			for (int j = i + 1; j < this->m_empnum; j++)
			{
				if (select == 1)
				{
					if (this->m_emparray[a]->m_id > this->m_emparray[j]->m_id)
					{
						a = j;
					}
				}
				else if (select == 2)
				{
					if (this->m_emparray[a]->m_id < this->m_emparray[j]->m_id)
					{
						a = j;
					}
				}
			}
			//判断一开始认定的最小值或最大值是不是计算的最小值或最大值
			if (i != a)
			{
				worker* temp = this->m_emparray[i];
				this->m_emparray[i] = this->m_emparray[a];
				this->m_emparray[a] = temp;
			}
		}
		cout << "排序成功，排序结果为" << endl;
		this->save();
		this->show();
	}

}

void workermanger::clean()
{
	cout << "确认清空文件？" << endl;
	cout << "1确认" << endl;
	cout << "2返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(filename, ios::trunc);//trunc就是删除已有文件并新建该文件
		ofs.close();

		if (this->m_emparray != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				if (this->m_emparray[i] != NULL)
				{
					delete this->m_emparray[i];
				}
			}
			this->m_empnum = 0;
			delete[] this->m_emparray;
			this->m_emparray = NULL;
			this->m_fileisempty = true;
		}
		cout << "清空成功！" << endl;
	}
	else if (select == 2)
	{
		cout << "即将返回主菜单" << endl;
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

workermanger::~workermanger()
{
	if (this->m_emparray != NULL)
	{
		delete[]this->m_emparray;
		this->m_emparray = NULL;
	}
}


