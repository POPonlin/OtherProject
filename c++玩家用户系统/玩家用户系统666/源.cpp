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
	virtual void Add() = 0;//����
	virtual void Output() = 0;//����
	virtual void Change() = 0;//�޸�
	virtual void Delete() = 0;//ɾ��
	virtual void Find() = 0;//����
	virtual void selffind() = 0;//��Ҳ鿴������Ϣ
	virtual void selfchange() = 0;//����޸�������Ϣ
	virtual void save() = 0;//������Ϣ
	virtual void read() = 0;//��ȡ��Ϣ
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
	virtual void Add();//����
	virtual void Output();//����
	virtual void Change();//�޸�
	virtual void Delete();//ɾ��
	virtual void Find();//����
	virtual void selffind();
	virtual void selfchange();
	virtual void save();//������Ϣ
	virtual void read();//��ȡ��Ϣ
};
void player::Add()
{
	play* p;
	cout << "���������ӵ���Ҹ���" << endl;
	cin >> count;
	if (count < 0)
	{
		cout << "��������ȷ�ĸ�����count>0)" << endl;
		return;
	}
	head = new play;
	head->ID = 0;
	head->level = 0;
	head->next = NULL;
	tail = head;//������Ϊ��ʱ��ͷ����β
	for (int i = 0; i < count; i++)
	{
		p = new play;
		cout << "��������ҵ�ID��LEVEL" << endl;
		cin >> p->ID;
		cin >> p->level;
		p->next = NULL;
		tail->next = p;//����pΪtail����һ������p��tail������
		tail = p;//����p��Ϊ�µı�β
	}
	cout << "���������Ϣ�ɹ���һ��������" << count << "�����" << endl;
	system("pause");
	system("cls");
}
void player::Output()
{

	if (head == NULL)
	{
		cout << "����������Ϊ��" << endl;
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
		cout << "����������Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	play* p, * pre;
	int m;
	cout << "����������Ҫɾ�������ID" << endl;
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
			cout << "IDΪ" << m << "����ҵ���Ϣ�Գɹ�ɾ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		pre = p;//ʹ�����ǰ�ƶ�һ��
		p = p->next;
	}
	cout << "���Ҹ�ID���ʧ�ܣ������ID�Ƿ���ڣ�����������" << endl;
	system("pause");
	system("cls");
}
void player::Change()
{
	if (head == NULL)
	{
		cout << "����������Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	play* p;
	p = head->next;
	int m;
	cout << "��������Ҫ��ѯ�����ID" << endl;
	cin >> m;
	while (p != NULL)
	{
		if (p->ID == m)
		{
			cout << "���ҵ�����ҵ���Ϣ��" << endl;
			cout << "ID:" << p->ID << "\tLEVEL:" << p->level << ";" << endl;
			cout << "�Ƿ������޸�,1ͬ�⣬0ȡ��" << endl;
			int n;
			cin >> n;
			if (n == 1)
			{
				cout << "�������޸ĵ�ID��LEVEL��" << endl;
				cin >> p->ID;
				cin >> p->level;
				cout << "�޸ĳɹ�" << endl;
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
		cout << "����������Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	play* p;
	p = head->next;
	int m;
	cout << "��������Ҫ��ѯ�����ID" << endl;
	cin >> m;
	while (p != NULL)
	{
		if (p->ID == m)
		{
			cout << "���ҵ�����ҵ���Ϣ��" << endl;
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
		cout << "����������Ϊ��" << endl;
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
			cout << "��ĵ���Ϣ��" << endl;
			cout << "ID:" << p->ID << "\tLEVEL:" << p->level << ";" << endl;
			system("pause");
			system("cls");
		}
		p = p->next;
	}
}
void player::selfchange()
{
	cout << "ע�⣺�޸�ID����Ҫ���µ�¼" << endl;
	play* p;
	p = head->next;
	while (p != NULL)
	{
		if (p->ID == player_ID)
		{
			cout << "��ǰ��ĵ���ϢΪ��" << endl;
			cout << "ID:" << p->ID << "\tLEVEL:" << p->level << ";" << endl;
			cout << "�Ƿ������޸�,1ͬ�⣬0ȡ��" << endl;
			int n;
			cin >> n;
			if (n == 1)
			{
				cout << "�������޸ĵ�ID��LEVEL��" << endl;
				cin >> p->ID;
				cin >> p->level;
				cout << "�޸ĳɹ�" << endl;
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
		cout << "������Ϊ��" << endl;
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
		cout << "��Ϣ����ɹ�" << endl;
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
	cout << "��ȡ��Ϣ�ɹ�" << endl;
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
	cout << "��������Ĺ���ԱID" << endl;
	cin >> id_adm;
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	cout << "����ɹ�" << endl;
	system("pause");
}
void adm::Output()
{
	cout << "����Ա��IDΪ��";
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
	cout << "�������Լ���ID��" << endl;
	int m;
	cin >> m;

}
void power()
{
	cout << "��ѡ����ҵ�Ȩ��" << "\n" << "1Ϊ����Ȩ�ޣ�2Ϊ�ر�Ȩ��" << endl;
	cin >> flag;
	if ((flag != 1) && (flag != 2))
	{
		cout << "�����ѡ�����" << endl;
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
		cout << "\t\t\t\t\t" << "1.�鿴�Լ��������Ϣ" << endl;
		cout << "\t\t\t\t\t" << "2.�鿴������ҵ���Ϣ" << endl;
		cout << "\t\t\t\t\t" << "3.�޸��Լ��������Ϣ" << endl;
		cout << "\t\t\t\t\t" << "4.�鿴�Լ�����Ʒ" << endl;
		cout << "\t\t\t\t\t" << "5.��¼��Ϸ" << endl;
		cout << "\t\t\t\t\t" << "6.�������˵�" << endl;

		if (flag == 2)
		{
			cout << "����Ա�Ѿ�������ʹ�ô�ϵͳ��Ȩ��" << endl;
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
			case 4:cout << "��ǰ�������Ϊ����Ħ֮��" << endl;
				cout << "��ǰ��ľ���֮Դ����Ϊ��648" << endl;
				cout << "��ǰ��Ľ�ɫΪ������" << endl;
				cout << "���磺��������ˣ���������װ���أ�" << endl;
				cout << "���磺�Ҳ�������" << endl;
				cout << "���磺�ų�������ҵ��ţ��㻹��װ����~555" << endl;
				break;
			case 5:cout << "��¼��Ϸ�ɹ���" << endl;
				cout << "��ӭ��������������Ϸ��" << endl;
				break;
			case 6:system("cls"); return;
			default:cout << "�������" << endl;
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
		cout << "\t\t\t\t\t" << "1.�鿴ȫ�������Ϣ" << endl;
		cout << "\t\t\t\t\t" << "2.�������" << endl;
		cout << "\t\t\t\t\t" << "3.�޸������Ϣ" << endl;
		cout << "\t\t\t\t\t" << "4.ɾ�������Ϣ" << endl;
		cout << "\t\t\t\t\t" << "5.���������Ϣ" << endl;
		cout << "\t\t\t\t\t" << "6.�������Ȩ��" << endl;
		cout << "\t\t\t\t\t" << "7.��¼��Ϸ" << endl;
		cout << "\t\t\t\t\t" << "8.�������ѡ��" << endl;
		cout << "\t\t\t\t\t" << "9.���ù���Ա��Ϣ" << endl;
		cout << "\t\t\t\t\t" << "0.�鿴����Ա������Ϣ" << endl;
		cout << "\t\t\t\t\t" << "10.��ȡ�������Ϣ" << endl;
		cout << "\t\t\t\t\t" << "11.������Ϣ" << endl;
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
		case 7:system("cls"); cout << "��¼��Ϸ�ɹ���" << endl; break;
		case 8:system("cls");
			cout << "�Ƿ񱣴�������ݣ�" << endl;
			cout << "ѡ��1.����\t2.������" << endl;
			int t;
			cout << "*****�����룺";
			cin >> t;
			switch (t)
			{
			case 1:pp->save();
				break;
			case 2:system("cls");
				break;
			default:
				rewind(stdin);//������̻��� 
				printf("ѡ����Ч��������ѡ��\n");
				system("pause");
				system("cls");
			}
			menu(); break;
		case 9:system("cls"); act(new adm); break;
		case 0:system("cls"); act2(new adm); break;
		case 10:system("cls"); pp->read(); break;
		case 11:system("cls"); pp->save();break;
		default:cout << "�������" << endl;
			system("pause");
			system("cls");
		}
	}

}

void adm_zhuce()
{
	ofstream ofs;
	ofs.open("adm_ID", ios::out);
	cout << "��������Ҫע����˺ţ�";
	char ID1[20];
	cin >> ID1;
	ofs << ID1 << endl;
	cout << "�˺ű���ɹ�" << endl;
	ofs.close();
	ofstream ofs2;
	ofs2.open("adm_password", ios::out);
	cout << "��������Ҫע������룺";
	char password1[20];
	cin >> password1;
	ofs2 << password1 << endl;
	cout << "���뱣��ɹ�" << endl;
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
		cout << "û���˺���Ϣ������ע���˺�" << endl;
		system("pause");
		system("cls");
		menu();
	}

	while (1)
	{
		char id[30];
		char id2[30];
		cout << "����ID:";
		cin >> id;
		ifs >> id2;
		if (strcmp(id, id2) != 0)
		{
			cout << "�����˺Ŵ���" << endl;
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
				cout << "����password:";
				char a[20];
				char c;
				int i = 0;
				while ((c = _getch()) != '\r')         /*���������Լ���ɾ*/
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
					cout << endl << "��½�ɹ�" << endl;
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
					cout << endl << "�����������" << endl;
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
		cout << "������ID:" << endl;
		cin >> id;
		if ((strcmp(id, "456")) != 0)
		{
			cout << "�˺��������" << endl;
		}
		else
		{
			break;
		}
	}*/
	cout << "���������ID" << endl;
	cin >> player_ID;
	cout << "������password(�û���ʼ�����Ϊ114514):" << endl;
	while (1)
	{
		char a[20];
		char c;
		int i = 0;
		while ((c = _getch()) != '\r')         /*���������Լ���ɾ*/
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
			cout << "�����������" << endl;
		}
	}
	system("cls");
	menu3();
}

void menu()
{
	cout << "\n\n\n\n" << endl;
	cout << "\t\t\t\t\t" << "ѡ��������:" << endl;
	cout << "\t\t\t\t\t" << "(����½�޷�������Ϸ)" << endl;
	cout << "\t\t\t\t\t" << "1.����Ա��¼" << endl;
	cout << "\t\t\t\t\t" << "2.��ҵ�¼" << endl;
	cout << "\t\t\t\t\t" << "3.�˳���Ϸ" << endl;
	cout << "\t\t\t\t\t" << "4.����Աע��" << endl;
	cout << "\t\t\t\t\t" << "5.���ע��" << endl;
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
		default:cout << "��Чѡ������������" << endl;
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