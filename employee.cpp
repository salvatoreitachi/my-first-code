#include<iostream>
#include"employee.h"
using namespace std;

employee::employee(int id, string name, int did)//���캯��
{
	this->m_id = id;
	this->m_name = name;
	this->m_deptid = did;
}
void employee::showinfo()//��ȡ������Ϣ
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getdeptname()
		<< "\t��λְ����ɾ�����������" << endl;
}
string employee::getdeptname()//��ȡ��λ����
{
	return string ("Ա��");
}