#include<iostream>
#include"manager.h"
using namespace std;

manager::manager(int id, string name, int did)//���캯��
{
	this->m_id = id;//�����ŵ��ڴ������ı��
	this->m_name = name;
	this->m_deptid = did;
}
void manager::showinfo()//��ȡ������Ϣ
{
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\t��λ��" << this->getdeptname()
		<< "\t��λְ������ϰ彻�������񣬲��·���Ա����" << endl;
}
string manager::getdeptname()//��ȡ��λ����
{
	return string("����");
}