#pragma once //防止头文件重复包含
#include<iostream> //包含输入输出流头文件
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define filename "empfile.txt"
using namespace std; //标准命名空间

class workermanger
{
public:
	workermanger();//构造函数
	void showmenu();//显示菜单
	void exitsys();//退出系统
	int m_empnum;//记录职工人数
	worker** m_emparray;//worker指向员工数组
	void add_emp();//加人
	void save();
	bool m_fileisempty;//判断文件空不空
	int get_empnum();//统计文件人数
	void init_emp();//初始化职工
	void show();
	int isexist(int id);
	void delemp();
	void change();//更改职工信息
	void findemp();//查找职工
	void sort();//排序算法
	void clean();
	~workermanger();//析构函数
};


