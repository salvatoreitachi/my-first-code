#include<iostream>
#include"boss.h"
using namespace std;

boss::boss(int id, string name, int did)//构造函数
{
	this->m_id = id;//自身编号等于传进来的编号
	this->m_name = name;
	this->m_deptid = did;
}
void boss::showinfo()//获取个人信息
{
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t岗位：" << this->getdeptname()
		<< "\t岗位职责：管理公司整体运营，数钱" << endl;
}
string boss::getdeptname()//获取岗位名称
{
	return string("老板");
}