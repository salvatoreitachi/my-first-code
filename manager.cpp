#include<iostream>
#include"manager.h"
using namespace std;

manager::manager(int id, string name, int did)//构造函数
{
	this->m_id = id;//自身编号等于传进来的编号
	this->m_name = name;
	this->m_deptid = did;
}
void manager::showinfo()//获取个人信息
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getdeptname()
		<< "\t岗位职责：完成老板交给的任务，并下发给员工。" << endl;
}
string manager::getdeptname()//获取岗位名称
{
	return string("经理");
}