#include <graphics.h>
#include <ege/sys_edit.h>
#include<windows.h>
#include<iostream>
#include<ctime>
#include<cstdio>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
void Background();
void draw();
void Read(int);
void Coount(long,long,sys_edit);
struct node{
	string name;
	int rate;
}a[10009];
bool cd[10009];
//#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
int main()
{
	//setinitmode(0);
	initgraph(920, 517,0);
	setcaption("�����Ż�");
	//setbkcolor(WHITE);
	//setcolor(BLACK);
	//getch();
	PIMAGE pimg = newimage();
//	Background();
	getimage(pimg, "data//backg.jpg");
	int x = 0, y = 0;

	putimage(x, y, pimg);
	//����˳�ѭ����ֱ��getch()���޷������ģ���Ϊ�����ʱ��Ҳ�ڲ���������Ϣ
	//��Ҫ����հ�����Ϣ
	flushkey();
	
	draw();
	getch();
//	putimage_withalpha(NULL, pimg, x, y);
	delimage(pimg);
	closegraph();
	return 0;
}
void Background()
{
}
void draw()
{
	//system("pause");
	int fontHeight = 20;
	setfont(fontHeight, 0, "����");
	setbkmode(TRANSPARENT);
	sys_edit editBox;
	editBox.create(0);						//������false��ʾ����
	editBox.move(100, 200);						//����λ��
	int editTextHeight = 16;
	editBox.size(editTextHeight *8, 2 * editTextHeight );	//���óߴ磬�߶�һ��Ҫ���ֵĸ߶�һ�㣬��Ϊ�����ı߿�Ҳռһ����С��
	editBox.setbgcolor(WHITE);					//���ñ�����ɫ
	editBox.setcolor(BLACK);					//����������ɫ
	editBox.setfont(editTextHeight, 0, "����");	//�������� 

	int maxLen = 60;

	editBox.setmaxlen(maxLen);					//����������󳤶�
	//editBox.setreadonly(false);				//Ĭ����������
	editBox.visable(true);						//ʹ�ɼ�
	//��ȡ���� 
	editBox.setfocus();
	//�������뻺���� 
	bool flag_press = false;		//��������Ƿ��� 

	for (; is_run(); delay_fps(60)) {
	//	cleardevice();
	//	xyprintf(100, 0, "��������С��%d", buffSize);
	//	xyprintf(100, 150, "����Ҫ�������˶���");
		outtextxy(100, 150, "����Ҫ�������˶���");
		editBox.visable(true);
		bool isClick = false;
		int xc=0,yc=0;
		//��ȡ�����Ϣ
		while (mousemsg()) {
			mouse_msg msg = getmouse();

			//����Ϣ����ѭ�����жϵ��
			if (msg.is_left() && msg.is_down()) {
				isClick = true;
				xc = msg.x;
				yc = msg.y;
			}
		}

		//������ͨ����־λ���ж�
		if (isClick) {
		//	system("pause");
			Coount(xc,yc,editBox);
			
		}
	/*	//��������������ݾ����
		if (strBuff[0] != '\0') {
			xyprintf(100, 40, "�����ı����ȣ�%d", buffLen);
			//�����������Ϊ���ݽ϶�,xyprintf�����Զ����У��������������
			outtextxy(100, 60, "��������:");
			rectprintf(100, 80, 380, 200, "%s", strBuff);
		}*/
	}
}
void Coount(long x,long y,sys_edit editBox)
{
	//151,336
	//263,415
	if(151<=x&&x<=262&&336<=y&&y<=415)//���� 
	{
		const int buffSize = 100;
		char strBuff[100] = "";
		int buffLen = 0;
		//��ȡ����������ַ���
		editBox.gettext(buffSize, strBuff);
		//�����ַ������� 
		buffLen = strlen(strBuff);
		int a;
		sscanf(strBuff, "%d", &a);
		//��������ȡ���������� 
		//xyprintf(100, 0, "%d", a);
		Read(a);
		editBox.settext("");
	}
}
void Read(int s)
{
	freopen("File.txt","r",stdin);
	freopen("�н�.txt","w",stdout);
	int n=0;
	int sum=0;
	while(1)
	{
		int i=n+1;
		cin>>a[i].name>>a[i].rate;
		sum+=a[i].rate;
		if(a[i].name=="0"&&a[i].rate==-1)break;
		n++;
	}
	srand(time(0));
	int p=rand()%sum+1;
	memset(cd,0,sizeof(cd));
	while(s--)
	{
		bool ok=1; 
		for(int i=1;i<=n;i++)
		{
			p-=a[i].rate;
			if(p<=0)
			{
				if(!cd[i])
				{
					cout<<a[i].name<<endl;
					cd[i]=1;
					ok=0;
					break;
				}
			}
		}
		p=rand()%sum+1;
		s+=ok;
	} 
	fclose(stdout);
	system("start �н�.txt");
}
