#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//�����ļ�
class manager:public worker
{
public:
	manager(int id, string name, int did);//���캯��
	void showinfo();
	//��ȡ��λ����
	string getdeptname();
};