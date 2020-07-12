#include <graphics.h>
#include <ege/sys_edit.h>
#include<windows.h>
#include<iostream>
#include<ctime>
#include<cstdio>
#include<bits/stdc++.h>
#include<cstring>
#define ll long long
using namespace std;
void Background(PIMAGE pimg);
void draw(PIMAGE pimg);
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
	PIMAGE pimg = newimage();
	setcaption("物理抽号机");
	//setbkcolor(WHITE);
	//setcolor(BLACK);
	//getch();
	Background(pimg);
	//如果退出循环，直接getch()是无法阻塞的，因为输入的时候也在产生按键消息
	//需要先清空按键消息
	flushkey();
	
	draw(pimg);
	getch();
//	putimage_withalpha(NULL, pimg, x, y);
	delimage(pimg);
	closegraph();
	return 0;
}
void Background(PIMAGE pimg)
{	
//	
	getimage(pimg, "data//backg.jpg");
	int x = 0, y = 0;

	putimage(x, y, pimg);
}
void draw(PIMAGE pimg)
{
	int fontHeight = 20;
	setfont(fontHeight, 0, "楷体");
	setbkmode(TRANSPARENT);
	sys_edit editBox;
	editBox.create(0);						//创建，false表示单行
	editBox.move(100, 200);						//设置位置
	int editTextHeight = 16;
	editBox.size(editTextHeight *8, 2 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
	editBox.setbgcolor(WHITE);					//设置背景颜色
	editBox.setcolor(BLACK);					//设置文字颜色
	editBox.setfont(editTextHeight, 0, "楷体");	//设置字体 

	int maxLen = 60;

	editBox.setmaxlen(maxLen);					//设置输入最大长度
	//editBox.setreadonly(false);				//默认允许输入
	editBox.visable(true);						//使可见
	//获取焦点 
	editBox.setfocus();
	//创建输入缓存区 
	bool flag_press = false;		//用来标记是否按下 
	for (; is_run(); delay_fps(60)) {
		cleardevice();
	//system("pause");
		Background(pimg);
	//	xyprintf(100, 0, "缓存区大小：%d", buffSize);
	//	xyprintf(100, 150, "你想要几个幸运儿？");
		outtextxy(100, 150, "你想要几个幸运儿？");
	//	editBox.visable(true);
		bool isClick = false;
		int x=0,y=0;
		//获取鼠标消息
		while (mousemsg()) {
			mouse_msg msg = getmouse();

			//在消息处理循环中判断点击
			if (msg.is_left() && msg.is_down()) {
				isClick = true;
				x = msg.x;
				y = msg.y;
			}
		}

		//在这里通过标志位来判断
		if (isClick&&(151<=x&&x<=262&&336<=y&&y<=415)) {
			const int buffSize = 100;
			char strBuff[100] = "";
			int buffLen = 0;
			//获取输入框内容字符串
			editBox.gettext(buffSize, strBuff);
			//计算字符串长度 
			buffLen = strlen(strBuff);
			int a;
			sscanf(strBuff, "%d", &a);
			//如果你想获取后清空输入框 
			//xyprintf(100, 0, "%d", a);
			Read(a);
			editBox.settext("");
		//	system("pause");
		//	Coount(xc,yc,editBox);
		//	editBox.setreadonly(true);				//默认允许输入
		//	editBox.visable(true);
		//	editBox.setfocus();
		/*	int fontHeight = 20;
			setfont(fontHeight, 0, "楷体");
			setbkmode(TRANSPARENT);
		//	editBox.create(0);						//创建，false表示单行
			editBox.move(100, 200);						//设置位置
			int editTextHeight = 16;
			editBox.size(editTextHeight *8, 2 * editTextHeight );	//设置尺寸，高度一般要比字的高多一点，因为输入框的边框也占一定大小。
			editBox.setbgcolor(WHITE);					//设置背景颜色
			editBox.setcolor(BLACK);					//设置文字颜色
			editBox.setfont(editTextHeight, 0, "楷体");	//设置字体 
		
			int maxLen = 60;
		
			editBox.setmaxlen(maxLen);					//设置输入最大长度
			//editBox.setreadonly(false);				//默认允许输入
			editBox.visable(true);						//使可见
			//获取焦点 
			editBox.setfocus();*/
			//创建输入缓存区 
			bool flag_press = false;		//用来标记是否按下 
		}
	/*	//如果缓存区有内容就输出
		if (strBuff[0] != '\0') {
			xyprintf(100, 40, "输入文本长度：%d", buffLen);
			//区域输出，因为内容较多,xyprintf不会自动换行，所以用下面这个
			outtextxy(100, 60, "输入内容:");
			rectprintf(100, 80, 380, 200, "%s", strBuff);
		}*/
	}
}
void Coount(long x,long y,sys_edit editBox)
{
	//151,336
	//263,415
	if(151<=x&&x<=262&&336<=y&&y<=415)//生成 
	{
		const int buffSize = 100;
		char strBuff[100] = "";
		int buffLen = 0;
		//获取输入框内容字符串
		editBox.gettext(buffSize, strBuff);
		//计算字符串长度 
		buffLen = strlen(strBuff);
		int a;
		sscanf(strBuff, "%d", &a);
		//如果你想获取后清空输入框 
		//xyprintf(100, 0, "%d", a);
		Read(a);
		editBox.settext("");
	}
}
void Read(int s)
{
	freopen("File.txt","r",stdin);
	freopen("中奖.txt","w",stdout);
	int n=0;
	ll sum=0;
	while(1)
	{
		int i=n+1;
		double x;
		cin>>a[i].name>>x;
		x*=100;
		sum+=(int)x;
		a[i].rate=(int)x;
		if(a[i].name=="0"&&a[i].rate<0)break;
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
	system("start 中奖.txt");
}
