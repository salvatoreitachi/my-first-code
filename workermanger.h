#pragma once //��ֹͷ�ļ��ظ�����
#include<iostream> //�������������ͷ�ļ�
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define filename "empfile.txt"
using namespace std; //��׼�����ռ�

class workermanger
{
public:
	workermanger();//���캯��
	void showmenu();//��ʾ�˵�
	void exitsys();//�˳�ϵͳ
	int m_empnum;//��¼ְ������
	worker** m_emparray;//workerָ��Ա������
	void add_emp();//����
	void save();
	bool m_fileisempty;//�ж��ļ��ղ���
	int get_empnum();//ͳ���ļ�����
	void init_emp();//��ʼ��ְ��
	void show();
	int isexist(int id);
	void delemp();
	void change();//����ְ����Ϣ
	void findemp();//����ְ��
	void sort();//�����㷨
	void clean();
	~workermanger();//��������
};


