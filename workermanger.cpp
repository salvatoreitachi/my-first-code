#include"workermanger.h"
#include<iostream>

using namespace std;

workermanger::workermanger()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(filename, ios::in);//���ļ�
	if(!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		//������ʼ�����ԣ���ʼ������ָ��
		this->m_empnum = 0;
		this->m_emparray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_fileisempty = true;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_empnum = 0;
		this->m_emparray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_fileisempty = true;
		ifs.close();
		return;
	}
	
	//�ļ����� ��¼����
	int num = this->get_empnum();
	//cout << "ְ��������Ϊ��" << num << endl;
	this->m_empnum = num;

	this->m_emparray = new worker * [this->m_empnum];//���ٿռ�
	this->init_emp();//���ļ��е����� �浽������
	
}

void workermanger::showmenu()
{
	cout << "*********************************" << endl;
	cout << "******��ӭʹ��ְ������ϵͳ!******" << endl;
	cout << "**********0�˳��������**********" << endl;
	cout << "**********1����ְ����Ϣ**********" << endl;
	cout << "**********2��ʾְ����Ϣ**********" << endl;
	cout << "**********3ɾ����ְְ��**********" << endl;
	cout << "**********4�޸�ְ����Ϣ**********" << endl;
	cout << "**********5����ְ����Ϣ**********" << endl;
	cout << "**********6���ձ������**********" << endl;
	cout << "**********7��������ĵ�**********" << endl;
	cout << "*********************************" << endl;
}

void workermanger::exitsys()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}

void workermanger::add_emp()//����
{
	cout << "���������ְ����������" << endl;
	int add_num = 0;
	cin >> add_num;
	if (add_num > 0)
	{ //�¿ռ��С=ԭ����¼����+��������
		int newsize = this->m_empnum + add_num;
		//����������
		worker** newspace = new worker * [newsize];
		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_emparray != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				newspace[i] = this->m_emparray[i];
			}
		}
		//�����������
		for (int i = 0; i < add_num; i++)
		{
			int id;
			string name;
			int deptid;//����ѡ��
			cout << "�������" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ" << endl;
			cout << "1��ְͨ��" << endl;
			cout << "2����" << endl;
			cout << "3�ϰ�" << endl;
			cout << "��Ҫ�����������֣����������" << endl;
			cin >> deptid;
			worker* worker = NULL;
			switch (deptid)
			{
			case 1:
				worker = new employee(id, name, deptid);
				break;
			case 2:
				worker = new manager(id, name, deptid);
				break;
			case 3:
				worker = new boss(id, name, deptid);
				break;
			default:
				break;
			}
			//������ְ��ָ�뱣�浽������
			newspace[this->m_empnum + i] = worker;
		}
		delete[]this->m_emparray;//�ͷ�ԭ�пռ�
		this->m_emparray = newspace;//�����µĿռ�ָ��
		this->m_empnum = newsize;//�����µ�ְ������
		this->m_fileisempty = false;//����ְ����Ϊ�ձ�־
		cout << "�ɹ����" << add_num << "����ְ��!" << endl;
		this->save();//�������ݵ��ļ���
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void workermanger::save()
{
	ofstream ofs;
	ofs.open(filename, ios::out);//��д�ļ���ʽ���ļ�
	for (int j = 0; j < this->m_empnum; j++)//
	{
		ofs << this->m_emparray[j]->m_id << " "
			<< this->m_emparray[j]->m_name << " "
			<< this->m_emparray[j]->m_deptid << endl;
	}
	ofs.close();
}

int workermanger::get_empnum()
{
	ifstream ifs;
	ifs.open(filename, ios::in);//���ļ�

	int id;
	string name;
	int deptid;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>deptid)
	{
		num++;
	}
	return num;
}

void workermanger::init_emp()//��ʼ��ְ��
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	int id;
	string name;
	int deptid;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> deptid)
	{
		worker* worker = NULL;
		if (deptid == 1)
		{
			worker = new employee(id, name, deptid);
		}
		else if (deptid == 2)
		{
			worker = new manager(id, name, deptid);
		}
		else
		{
			worker = new boss(id, name, deptid);
		}
		this->m_emparray[index] = worker;
		index++;
	}
	ifs.close();
}

void workermanger::show()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < m_empnum;i++)
		{
			this->m_emparray[i]->showinfo();
		}
	}
	system("pause");
	system("cls");
}

int workermanger::isexist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_empnum; i++)
	{
		if (this->m_emparray[i]->m_id == id)
		{
			index = i;//�ҵ�ְ��
			break;
		}
	}
	return index;
}

void workermanger::delemp()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;
		int index = this->isexist(id);
		if (index != -1)//˵��ְ������ ����ɾ��
		{
			//����Ǩ��
			for (int i = index; i < this->m_empnum - 1; i++)
			{
				this->m_emparray[i] = this->m_emparray[i + 1];
			}
			this->m_empnum--;//���������м�¼��Ա��ʽ
			this->save();//����ͬ�����µ��ļ���
			cout << "ɾ���ɹ���" << endl;

		}
		else
		{
			cout << "δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

void workermanger::change()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "�������޸�ְ�����" << endl;
		int id;
		cin >> id;
		int ret = this->isexist(id);
		if (ret != -1)
		{
			delete this->m_emparray[ret];
			int newid = 0;
			string newname = "";
			int newdeptid = 0;
			cout << "�鵽���Ϊ" << id << "��ְ�����������µ�ְ����" << endl;
			cin >> newid;
			cout << "�������µ�����" << endl;
			cin >> newname;
			cout << "�������µĸ�λ���" << endl;
			cout << "1��ְͨ��" << endl;
			cout << "2����" << endl;
			cout << "3�ϰ�" << endl;
			cin >> newdeptid;
			worker* worker = NULL;
			switch (newdeptid)
			{
			case 1:
				worker = new employee(newid, newname, 1);
				break;
			case 2:
				worker = new manager(newid, newname, 2);
				break;
			case 3:
				worker = new boss(newid, newname, 3);
				break;
			default:
				break;
			}
			//�������ݸ��µ�������
			this->m_emparray[ret] = worker;
			cout << "�޸ĳɹ���" << endl;
			//���ݱ��浽�ļ���
			this->save();
		}
		else
		{
			cout << "���޴��ˣ��޸�ʧ�ܣ�" << endl;
		}
		system("pause");
		system("cls");
	}
}

void workermanger::findemp()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ����ҷ�ʽ" << endl;
		cout << "1����Ų���" << endl;
		cout << "2����������" << endl;
		int j = 0;
		cin >> j;
		if (j == 1)
		{
			int id = 0;
			cout << "������ְ��id��" << endl;
			cin >> id;
			int ret = this->isexist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ����:" << endl;
				this->m_emparray[ret]->showinfo();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (j == 2)
		{
			string name = "";
			cout << "������ְ������" << endl;
			cin >> name;
			bool flag = false;//Ĭ��δ�ҵ�����
			for (int i = 0; i < this->m_empnum; i++)
			{
				if (this->m_emparray[i]->m_name == name)
				{
					cout << "�ҵ�����,��ְ����Ϣ����" << endl;
					flag = true;
					this->m_emparray[i]->showinfo();
				}
			}
			if (flag == false)
			{
				cout << "���޴���" << endl;
			}	
		}
		else
		{
			cout << "��������" << endl;
		}
		system("pause");
		system("cls");
	}
}

void workermanger::sort()
{
	if (this->m_fileisempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1���չ��Ž�������" << endl;
		cout << "2���չ��Ž��н���" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_empnum; i++)
		{
			int a = i;
			for (int j = i + 1; j < this->m_empnum; j++)
			{
				if (select == 1)
				{
					if (this->m_emparray[a]->m_id > this->m_emparray[j]->m_id)
					{
						a = j;
					}
				}
				else if (select == 2)
				{
					if (this->m_emparray[a]->m_id < this->m_emparray[j]->m_id)
					{
						a = j;
					}
				}
			}
			//�ж�һ��ʼ�϶�����Сֵ�����ֵ�ǲ��Ǽ������Сֵ�����ֵ
			if (i != a)
			{
				worker* temp = this->m_emparray[i];
				this->m_emparray[i] = this->m_emparray[a];
				this->m_emparray[a] = temp;
			}
		}
		cout << "����ɹ���������Ϊ" << endl;
		this->save();
		this->show();
	}

}

void workermanger::clean()
{
	cout << "ȷ������ļ���" << endl;
	cout << "1ȷ��" << endl;
	cout << "2����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(filename, ios::trunc);//trunc����ɾ�������ļ����½����ļ�
		ofs.close();

		if (this->m_emparray != NULL)
		{
			for (int i = 0; i < this->m_empnum; i++)
			{
				if (this->m_emparray[i] != NULL)
				{
					delete this->m_emparray[i];
				}
			}
			this->m_empnum = 0;
			delete[] this->m_emparray;
			this->m_emparray = NULL;
			this->m_fileisempty = true;
		}
		cout << "��ճɹ���" << endl;
	}
	else if (select == 2)
	{
		cout << "�����������˵�" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

workermanger::~workermanger()
{
	if (this->m_emparray != NULL)
	{
		delete[]this->m_emparray;
		this->m_emparray = NULL;
	}
}


