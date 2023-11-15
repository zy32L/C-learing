//通讯录管理系统

#include<iostream>
#include<string>
#define MAX 1000   //不能加;
using namespace std;

struct Person
{
	string m_Name;
	int m_Sex; //1 男 2 女
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
		cout << "通讯录已满！" << endl;
			return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		
		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;

		while (1)
		{
			cin >> sex;  //如果输入1或2，可以退出循环；如果不是则重复重新输入
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入性别不符合,请重新输入！" << endl;
			}
		}
		
		//年龄
		cout << "请输入年龄:" << endl;
		int age = 0;
		while (1)
		{
			cin >> age;
			if (age <= 0 || age >= 130)
			{
				cout << "请重新输入年龄" << endl;
			}
			else
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
		}
		
		//号码
		cout << "请输入电话号码:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		
		//地址
		cout << "请输入地址:" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause");
		system("cls");
	}
}

void showPerson(struct Addressbooks * abs)
{
	if (abs->m_Size == 0)
		cout << "当前记录为空" << endl;
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex ==1 ?"男":"女" )<< "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");
}

void deletePerson(Addressbooks *abs,string name)
{
	//首先检测查找的联系人是否存在，若存在则返回具体位置，不存在则返回-1
	int num = 0;
	for (int i = 0; i < abs->m_Size; i++)
	{
		
		if (abs->personArray[i].m_Name == name)
		{
			cout << "找到TA了" << endl;
			for (int j = i;j < abs->m_Size-1 ; j++)
			{
				abs->personArray[j] = abs->personArray[j + 1];
			}
			abs->m_Size--;
			num++;
		}
	}
	if (num == 0)
		cout<<"查无此人" << endl;
	
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
			cout << "姓名： " << abs->personArray[i].m_Name << "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
			num++;
		}
	}
	if (num == 0)
		cout << "查无此人" << endl;

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
			cout << "请输入姓名： " << endl;
			cin >> name1;
			abs->personArray[i].m_Name = name1;

			int sex = 0;
			cout << "请输入性别：1--男 2--女 " << endl;
			while (1)
			{
				cin >> sex;
				if (sex == 1 || sex == 2)
				{
					abs->personArray[i].m_Sex = sex;
					break;
				}
				else
					cout<<"请重新输入!" << endl;
			}

			int age = 0;
			cout << "请输入年龄： " << endl;
			while(1)
			{ 
				if (age > 0 && age <= 130)
				{
					abs->personArray[i].m_Age = age;
					break;
				}
				else
					cout<< "请重新输入!" << endl;
			}
			
			string phone;
			cout << "请输入电话：" << endl;
			cin >> phone;
			abs->personArray[i].m_Phone= phone;

			string address;
			cout << "请输入住址：" << endl;
			cin >> address;
			abs->personArray[i].m_Addr = address;

			num++;
		}
	}
	if (num == 0)
		cout << "查无此人" << endl;

	system("pause");
	system("cls");
}

void clearPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已请空！" << endl;
	system("pause");
	system("cls");
}

//1.显示菜单界面
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
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
		case 1:  //显示联系人
			addPerson(&abs);
			break;

		case 2:  //显示联系人
			showPerson(&abs);
			break;

		case 3:  //删除联系人
		{
			string deleteName;
			cout << "请输入要删除信息的人名:" << endl;
			cin >> deleteName;
			deletePerson(&abs, deleteName);
		}
			break;

		case 4:  //查找联系人
		{
			string searchName;
			cout << "请输入要查找的人名：" << endl;
			cin >> searchName;
			searchPerson(&abs, searchName);
		}
			break;

		case 5:  //修改联系人
		{
			string modifyName;
			cout << "请输入要修改的人名：" << endl;
			cin >> modifyName;
			modifyPerson(&abs, modifyName);
		}
			break;

		case 6:  //清空联系人
			clearPerson(&abs);
			break;

		case 0:
			cout << "欢迎下次使用!" << endl;
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