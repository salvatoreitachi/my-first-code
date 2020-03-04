#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//经理文件
class manager:public worker
{
public:
	manager(int id, string name, int did);//构造函数
	void showinfo();
	//获取岗位名称
	string getdeptname();
};