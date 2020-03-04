#pragma once
#include<iostream> //包含输入输出流头文件
using namespace std; //标准命名空间
#include<string>

class worker
{
public:
	//显示个人信息
	virtual void showinfo() = 0;
	//获取岗位名称
	virtual string getdeptname() = 0;
	int m_id;
	string m_name;
	int m_deptid;
};
