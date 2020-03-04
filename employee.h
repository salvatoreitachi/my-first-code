#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//普通员工文件
class employee:public worker
{
public:
	employee(int id,string name,int did);//构造函数
	void showinfo();
	//获取岗位名称
	string getdeptname();
};