#pragma once
#include<iostream> //�������������ͷ�ļ�
using namespace std; //��׼�����ռ�
#include<string>

class worker
{
public:
	//��ʾ������Ϣ
	virtual void showinfo() = 0;
	//��ȡ��λ����
	virtual string getdeptname() = 0;
	int m_id;
	string m_name;
	int m_deptid;
};
