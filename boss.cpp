#include<iostream>
#include"boss.h"
using namespace std;

boss::boss(int id, string name, int did)//���캯��
{
	this->m_id = id;//�����ŵ��ڴ������ı��
	this->m_name = name;
	this->m_deptid = did;
}
void boss::showinfo()//��ȡ������Ϣ
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getdeptname()
		<< "\t��λְ�𣺹���˾������Ӫ����Ǯ" << endl;
}
string boss::getdeptname()//��ȡ��λ����
{
	return string("�ϰ�");
}