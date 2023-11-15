//ͨѶ¼����ϵͳ

#include<iostream>
#include<string>
#define MAX 1000   //���ܼ�;
using namespace std;

struct Person
{
	string m_Name;
	int m_Sex; //1 �� 2 Ů
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;

};

void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼������" << endl;
			return;
	}
	else
	{
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;

		while (1)
		{
			cin >> sex;  //�������1��2�������˳�ѭ��������������ظ���������
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�����Ա𲻷���,���������룡" << endl;
			}
		}
		
		//����
		cout << "����������:" << endl;
		int age = 0;
		while (1)
		{
			cin >> age;
			if (age <= 0 || age >= 130)
			{
				cout << "��������������" << endl;
			}
			else
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
		}
		
		//����
		cout << "������绰����:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		
		//��ַ
		cout << "�������ַ:" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;

		system("pause");
		system("cls");
	}
}

void showPerson(struct Addressbooks * abs)
{
	if (abs->m_Size == 0)
		cout << "��ǰ��¼Ϊ��" << endl;
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա� " << (abs->personArray[i].m_Sex ==1 ?"��":"Ů" )<< "\t";
			cout << "���䣺 " << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}

void deletePerson(Addressbooks *abs,string name)
{
	//���ȼ����ҵ���ϵ���Ƿ���ڣ��������򷵻ؾ���λ�ã��������򷵻�-1
	int num = 0;
	for (int i = 0; i < abs->m_Size; i++)
	{
		
		if (abs->personArray[i].m_Name == name)
		{
			cout << "�ҵ�TA��" << endl;
			for (int j = i;j < abs->m_Size-1 ; j++)
			{
				abs->personArray[j] = abs->personArray[j + 1];
			}
			abs->m_Size--;
			num++;
		}
	}
	if (num == 0)
		cout<<"���޴���" << endl;
	
	system("pause");
	system("cls");
}

void searchPerson(Addressbooks *abs, string name)
{
	int num = 0;
	for (int i = 0; i < abs->m_Size; i++)
	{

		if (abs->personArray[i].m_Name == name)
		{
			cout << "������ " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա� " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺 " << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
			num++;
		}
	}
	if (num == 0)
		cout << "���޴���" << endl;

	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs, string name)
{
	int num = 0;
	for (int i = 0; i < abs->m_Size; i++)
	{
		
		if (abs->personArray[i].m_Name == name)
		{
			string name1;
			cout << "������������ " << endl;
			cin >> name1;
			abs->personArray[i].m_Name = name1;

			int sex = 0;
			cout << "�������Ա�1--�� 2--Ů " << endl;
			while (1)
			{
				cin >> sex;
				if (sex == 1 || sex == 2)
				{
					abs->personArray[i].m_Sex = sex;
					break;
				}
				else
					cout<<"����������!" << endl;
			}

			int age = 0;
			cout << "���������䣺 " << endl;
			while(1)
			{ 
				if (age > 0 && age <= 130)
				{
					abs->personArray[i].m_Age = age;
					break;
				}
				else
					cout<< "����������!" << endl;
			}
			
			string phone;
			cout << "������绰��" << endl;
			cin >> phone;
			abs->personArray[i].m_Phone= phone;

			string address;
			cout << "������סַ��" << endl;
			cin >> address;
			abs->personArray[i].m_Addr = address;

			num++;
		}
	}
	if (num == 0)
		cout << "���޴���" << endl;

	system("pause");
	system("cls");
}

void clearPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");
}

//1.��ʾ�˵�����
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
	cout << "**********************" << endl;
}

int main()
{
	Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;

	while (1) 
	{
		showMenu();
		cin >> select;

		switch (select)
		{
		case 1:  //��ʾ��ϵ��
			addPerson(&abs);
			break;

		case 2:  //��ʾ��ϵ��
			showPerson(&abs);
			break;

		case 3:  //ɾ����ϵ��
		{
			string deleteName;
			cout << "������Ҫɾ����Ϣ������:" << endl;
			cin >> deleteName;
			deletePerson(&abs, deleteName);
		}
			break;

		case 4:  //������ϵ��
		{
			string searchName;
			cout << "������Ҫ���ҵ�������" << endl;
			cin >> searchName;
			searchPerson(&abs, searchName);
		}
			break;

		case 5:  //�޸���ϵ��
		{
			string modifyName;
			cout << "������Ҫ�޸ĵ�������" << endl;
			cin >> modifyName;
			modifyPerson(&abs, modifyName);
		}
			break;

		case 6:  //�����ϵ��
			clearPerson(&abs);
			break;

		case 0:
			cout << "��ӭ�´�ʹ��!" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	
	system("pause");
	return 0;
}