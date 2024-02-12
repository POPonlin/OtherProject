#include<iostream>
#include<string>
#include<conio.h>
#include <windows.h>
#include<fstream>
using namespace std;
static int flag = 1;
static int player_ID;
static int id_adm;
void menu();
void menu2();
void menu3();
class base_things
{
public:
	virtual void Add() = 0;//增加
	virtual void Output() = 0;//遍历
	virtual void Change() = 0;//修改
	virtual void Delete() = 0;//删除
	virtual void Find() = 0;//查找
	virtual void selffind() = 0;//玩家查看自身信息
	virtual void selfchange() = 0;//玩家修改自身信息
	virtual void save() = 0;//保存信息
	virtual void read() = 0;//读取信息
};
typedef struct user
{
	int ID;
	int level;
	struct user* next;
}play;

class player :public base_things
{
public:
	play* head = NULL;

	play* tail = NULL;

	int count = 0;
public:
	virtual void Add();//增加
	virtual void Output();//遍历
	virtual void Change();//修改
	virtual void Delete();//删除
	virtual void Find();//查找
	virtual void selffind();
	virtual void selfchange();
	virtual void save();//保存信息
	virtual void read();//读取信息
};
void player::Add()
{
	play* p;
	cout << "请输入增加的玩家个数" << endl;
	cin >> count;
	if (count < 0)
	{
		cout << "请输入正确的个数（count>0)" << endl;
		return;
	}
	head = new play;
	head->ID = 0;
	head->level = 0;
	head->next = NULL;
	tail = head;//当链表为空时，头就是尾
	for (int i = 0; i < count; i++)
	{
		p = new play;
		cout << "请输入玩家的ID与LEVEL" << endl;
		cin >> p->ID;
		cin >> p->level;
		p->next = NULL;
		tail->next = p;//先让p为tail的下一个，将p与tail连起来
		tail = p;//在让p成为新的表尾
	}
	cout << "增加玩家信息成功，一共增加了" << count << "个玩家" << endl;
	system("pause");
	system("cls");
}
void player::Output()
{

	if (head == NULL)
	{
		cout << "链表内内容为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	play* p;
	p = head->next;
	while (p != NULL)
	{
		cout << "ID:" << p->ID << "\tLEVEL:" << p->level << ";" << endl;
		p = p->next;
	}
	system("pause");
	system("cls");
}
void player::Delete()
{
	if (head == NULL)
	{
		cout << "链表内内容为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	play* p, * pre;
	int m;
	cout << "请输入你想要删除的玩家ID" << endl;
	cin >> m;
	pre = head;
	p = head->next;
	while (p != NULL)
	{
		if (p->ID == m)
		{
			pre->next = p->next;
			free(p);
			p = NULL;
			cout << "ID为" << m << "的玩家的信息以成功删除" << endl;
			system("pause");
			system("cls");
			return;
		}
		pre = p;//使结点向前移动一次
		p = p->next;
	}
	cout << "查找该ID玩家失败，请检查该ID是否存在，或其他问题" << endl;
	system("pause");
	system("cls");
}
void player::Change()
{
	if (head == NULL)
	{
		cout << "链表内内容为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	play* p;
	p = head->next;
	int m;
	cout << "请输入你要查询的玩家ID" << endl;
	cin >> m;
	while (p != NULL)
	{
		if (p->ID == m)
		{
			cout << "已找到该玩家的信息：" << endl;
			cout << "ID:" << p->ID << "\tLEVEL:" << p->level << ";" << endl;
			cout << "是否做出修改,1同意，0取消" << endl;
			int n;
			cin >> n;
			if (n == 1)
			{
				cout << "请输入修改的ID与LEVEL：" << endl;
				cin >> p->ID;
				cin >> p->level;
				cout << "修改成功" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				system("pause");
				system("cls");
				return;
			}
		}
		p = p->next;
	}
}
void player::Find()
{
	if (head == NULL)
	{
		cout << "链表内内容为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	play* p;
	p = head->next;
	int m;
	cout << "请输入你要查询的玩家ID" << endl;
	cin >> m;
	while (p != NULL)
	{
		if (p->ID == m)
		{
			cout << "已找到该玩家的信息：" << endl;
			cout << "ID:" << p->ID << "\tLEVEL:" << p->level << ";" << endl;
			system("pause");
			system("cls");
		}
		p = p->next;
	}
}
void player::selffind()
{
	if (head == NULL)
	{
		cout << "链表内内容为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	play* p;
	p = head->next;
	while (p != NULL)
	{
		if (p->ID == player_ID)
		{
			cout << "你的的信息：" << endl;
			cout << "ID:" << p->ID << "\tLEVEL:" << p->level << ";" << endl;
			system("pause");
			system("cls");
		}
		p = p->next;
	}
}
void player::selfchange()
{
	cout << "注意：修改ID后需要重新登录" << endl;
	play* p;
	p = head->next;
	while (p != NULL)
	{
		if (p->ID == player_ID)
		{
			cout << "当前你的的信息为：" << endl;
			cout << "ID:" << p->ID << "\tLEVEL:" << p->level << ";" << endl;
			cout << "是否做出修改,1同意，0取消" << endl;
			int n;
			cin >> n;
			if (n == 1)
			{
				cout << "请输入修改的ID与LEVEL：" << endl;
				cin >> p->ID;
				cin >> p->level;
				cout << "修改成功" << endl;
				system("pause");
				system("cls");
			}
			else
			{
				system("pause");
				system("cls");
				return;
			}
		}
		p = p->next;
	}
}
void player::save()
{
	ofstream ofs;
	ofs.open("players_date", ios::out | ios::app);

	if (head == NULL)
	{
		cout << "链表内为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (head != NULL)
	{
		play* p;
		p = head->next;
		while (p != NULL)
		{
			ofs << p->ID << "\t" << p->level << endl;
			p = p->next;
		}
		cout << "信息保存成功" << endl;
	}

	ofs.close();
	system("pause");
	system("cls");
}
void player::read()
{
	ifstream ifs;
	ifs.open("players_date", ios::in | ios::app);
	int ID2;
	int LEVEL2;
	head = new play;
	play* p;
	head->next = NULL;
	tail = head;
	while (ifs >> ID2 >> LEVEL2)
	{
		p = new play;
		p->ID = ID2;
		p->level = LEVEL2;
		p->next = NULL;
		tail->next = p;
		tail = p;
		if (ifs.eof())
		{
			break;
		}
	}
	ifs.close();
	cout << "读取信息成功" << endl;
	system("pause");
	system("cls");
}
class adm :public base_things
{
public:
	virtual void Add();
	virtual void Output();
	virtual void Delete() {}
	virtual void Change() {}
	virtual void Find() {}
	virtual void selffind() {}
	virtual void selfchange() {}
	virtual void save() {};
	virtual void read() {};
};
void adm::Add()
{
	cout << "请输入你的管理员ID" << endl;
	cin >> id_adm;
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	cout << "保存成功" << endl;
	system("pause");
}
void adm::Output()
{
	cout << "管理员的ID为：";
	cout << id_adm;
}
void act(base_things* kkk)
{
	kkk->Add();
	delete kkk;
}
void act2(base_things* bbb)
{
	bbb->Output();
	delete bbb;
}
void find_self()
{
	cout << "请输入自己的ID：" << endl;
	int m;
	cin >> m;

}
void power()
{
	cout << "请选择玩家的权限" << "\n" << "1为开启权限，2为关闭权限" << endl;
	cin >> flag;
	if ((flag != 1) && (flag != 2))
	{
		cout << "输入的选择错误" << endl;
		return;
	}
}
//player pp;
base_things* pp = new player;
void menu3()
{
	while (1)
	{
		cout << "\n\n\n\n" << endl;
		cout << "\t\t\t\t\t" << "1.查看自己的玩家信息" << endl;
		cout << "\t\t\t\t\t" << "2.查看其他玩家的信息" << endl;
		cout << "\t\t\t\t\t" << "3.修改自己的玩家信息" << endl;
		cout << "\t\t\t\t\t" << "4.查看自己的物品" << endl;
		cout << "\t\t\t\t\t" << "5.登录游戏" << endl;
		cout << "\t\t\t\t\t" << "6.返回主菜单" << endl;

		if (flag == 2)
		{
			cout << "管理员已经禁用你使用此系统的权力" << endl;
			system("pause");
			system("cls");
			return;
		}
		else if (flag == 1)
		{
			int n;
			cin >> n;
			switch (n)
			{
			case 1:pp->selffind(); break;
			case 2:pp->Find(); break;
			case 3:pp->selfchange(); break;
			case 4:cout << "当前你的武器为：护摩之杖" << endl;
				cout << "当前你的纠缠之源数量为：648" << endl;
				cout << "当前你的角色为：胡桃" << endl;
				cout << "虎哥：别搁哪跑了，我问你我装备呢？" << endl;
				cout << "刀哥：我不到啊！" << endl;
				cout << "虎哥：团长，你给我等着！你还我装备！~555" << endl;
				break;
			case 5:cout << "登录游戏成功！" << endl;
				cout << "欢迎来到东百往事游戏版" << endl;
				break;
			case 6:system("cls"); return;
			default:cout << "输入错误" << endl;
				system("pause");
				system("cls");
			}
		}

	}
}

void menu2()
{

	while (1)
	{
		cout << "\n\n\n\n" << endl;
		cout << "\t\t\t\t\t" << "1.查看全部玩家信息" << endl;
		cout << "\t\t\t\t\t" << "2.增加玩家" << endl;
		cout << "\t\t\t\t\t" << "3.修改玩家信息" << endl;
		cout << "\t\t\t\t\t" << "4.删除玩家信息" << endl;
		cout << "\t\t\t\t\t" << "5.查找玩家信息" << endl;
		cout << "\t\t\t\t\t" << "6.设置玩家权限" << endl;
		cout << "\t\t\t\t\t" << "7.登录游戏" << endl;
		cout << "\t\t\t\t\t" << "8.返回身份选项" << endl;
		cout << "\t\t\t\t\t" << "9.设置管理员信息" << endl;
		cout << "\t\t\t\t\t" << "0.查看管理员基本信息" << endl;
		cout << "\t\t\t\t\t" << "10.读取保存的信息" << endl;
		cout << "\t\t\t\t\t" << "11.保存信息" << endl;
		int n;
		cin >> n;

		switch (n)
		{
		case 1:system("cls"); pp->Output(); break;
		case 2:system("cls"); pp->Add(); break;
		case 3:system("cls"); pp->Change(); break;
		case 4:system("cls"); pp->Delete(); break;
		case 5:system("cls"); pp->Find(); break;
		case 6:system("cls"); power(); break;
		case 7:system("cls"); cout << "登录游戏成功！" << endl; break;
		case 8:system("cls");
			cout << "是否保存操作内容？" << endl;
			cout << "选择：1.保存\t2.不保存" << endl;
			int t;
			cout << "*****请输入：";
			cin >> t;
			switch (t)
			{
			case 1:pp->save();
				break;
			case 2:system("cls");
				break;
			default:
				rewind(stdin);//清除键盘缓存 
				printf("选择无效，请重新选择！\n");
				system("pause");
				system("cls");
			}
			menu(); break;
		case 9:system("cls"); act(new adm); break;
		case 0:system("cls"); act2(new adm); break;
		case 10:system("cls"); pp->read(); break;
		case 11:system("cls"); pp->save();break;
		default:cout << "输入错误" << endl;
			system("pause");
			system("cls");
		}
	}

}

void adm_zhuce()
{
	ofstream ofs;
	ofs.open("adm_ID", ios::out);
	cout << "请输入你要注册的账号：";
	char ID1[20];
	cin >> ID1;
	ofs << ID1 << endl;
	cout << "账号保存成功" << endl;
	ofs.close();
	ofstream ofs2;
	ofs2.open("adm_password", ios::out);
	cout << "请输入你要注册的密码：";
	char password1[20];
	cin >> password1;
	ofs2 << password1 << endl;
	cout << "密码保存成功" << endl;
	ofs2.close();
	system("pause");
	system("cls");
	menu();
}
void adm_denglu()
{
	ifstream ifs;
	ifs.open("adm_ID", ios::in);
	if (!ifs)
	{
		cout << "没有账号信息，请先注册账号" << endl;
		system("pause");
		system("cls");
		menu();
	}

	while (1)
	{
		char id[30];
		char id2[30];
		cout << "输入ID:";
		cin >> id;
		ifs >> id2;
		if (strcmp(id, id2) != 0)
		{
			cout << "输入账号错误" << endl;
			adm_denglu();
		}
		else
		{
			ifstream ifs2;
			ifs2.open("adm_password", ios::in);
			char pas[30];
			ifs2 >> pas;

			while (1)
			{
				cout << "输入password:";
				char a[20];
				char c;
				int i = 0;
				while ((c = _getch()) != '\r')         /*输入密码以及回删*/
				{
					if (c != '\b')
					{
						cout << "*";
						a[i] = c;
						i++;
					}
					else if (i != 0)
					{
						cout << "\b \b";
						i--;
					}
				}
				a[i] = '\0';
				if (strcmp(a, pas) == 0)
				{
					cout << endl << "登陆成功" << endl;
					Sleep(500);
					cout << ".";
					Sleep(500);
					cout << ".";
					Sleep(500);
					cout << ".";
					system("cls");
					menu2();
				}
				else
				{
					cout << endl << "输入密码错误" << endl;
				}
			}
			system("cls");

		}
	}

}
void player_zhuce()
{

}
void player_denglu()
{
	/*while (1)
	{
		char id[20];
		cout << "请输入ID:" << endl;
		cin >> id;
		if ((strcmp(id, "456")) != 0)
		{
			cout << "账号输入错误" << endl;
		}
		else
		{
			break;
		}
	}*/
	cout << "请输入你的ID" << endl;
	cin >> player_ID;
	cout << "请输入password(用户初始密码均为114514):" << endl;
	while (1)
	{
		char a[20];
		char c;
		int i = 0;
		while ((c = _getch()) != '\r')         /*输入密码以及回删*/
		{
			if (c != '\b')
			{
				cout << "*";
				a[i] = c;
				i++;
			}
			else if (i != 0)
			{
				cout << "\b \b";
				i--;
			}
		}
		a[i] = '\0';
		if (strcmp(a, "114514") == 0)
		{
			break;
		}
		else
		{
			cout << "输入密码错误" << endl;
		}
	}
	system("cls");
	menu3();
}

void menu()
{
	cout << "\n\n\n\n" << endl;
	cout << "\t\t\t\t\t" << "选择你的身份:" << endl;
	cout << "\t\t\t\t\t" << "(不登陆无法进行游戏)" << endl;
	cout << "\t\t\t\t\t" << "1.管理员登录" << endl;
	cout << "\t\t\t\t\t" << "2.玩家登录" << endl;
	cout << "\t\t\t\t\t" << "3.退出游戏" << endl;
	cout << "\t\t\t\t\t" << "4.管理员注册" << endl;
	cout << "\t\t\t\t\t" << "5.玩家注册" << endl;
	while (1)
	{
		int n;
		cin >> n;
		switch (n)
		{
		case 1:system("cls"); adm_denglu(); break;
		case 2:system("cls"); player_denglu(); break;
		case 3:exit(0);
		case 4:system("cls"); adm_zhuce(); break;
		case 5:system("cls");
			break;
		default:cout << "无效选择，请重新输入" << endl;
			cin.ignore((std::numeric_limits< streamsize >::max)(), '\n');
			system("cls");
			system("pause");
		}
	}
}
int main()
{
	menu();
	return 0;
}