#include<iostream>
#include"employee.h"
using namespace std;

employee::employee(int id, string name, int did)//构造函数
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void employee::showinfo()//获取个人信息
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getdeptname()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}
string employee::getdeptname()//获取岗位名称
{
	return string ("员工");
}