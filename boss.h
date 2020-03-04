#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//老板文件
class boss :public worker
{
public:
	boss(int id, string name, int did);//构造函数
	void showinfo();
	//获取岗位名称
	string getdeptname();
};