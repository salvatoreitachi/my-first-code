#pragma once
#include<iostream>
#include"worker.h"
using namespace std;
//�ϰ��ļ�
class boss :public worker
{
public:
	boss(int id, string name, int did);//���캯��
	void showinfo();
	//��ȡ��λ����
	string getdeptname();
};