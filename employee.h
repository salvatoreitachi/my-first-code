#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//��ͨԱ���ļ�
class employee:public worker
{
public:
	employee(int id,string name,int did);//���캯��
	void showinfo();
	//��ȡ��λ����
	string getdeptname();
};