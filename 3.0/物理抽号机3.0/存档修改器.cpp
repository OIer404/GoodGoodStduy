#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x7fffffff
struct node{
	string name;
	int rate;
}a[10009];
signed main()
{
	freopen("File.txt","r",stdin);
	int n=0;
	int sum=0;
	while(1)
	{
		int i=n+1;
		cin>>a[n+1].name>>a[n+1].rate;
		sum+=a[i].rate;
		if(a[i].name=="0"&&a[i].rate==-1)break;
		n++;
	}
	freopen("CON","r",stdin);
	int opt=1;
	while(opt)
	{
		cout<<"操作类型：\n输入1查看当前名单\n输入2批量添加\n删除的话自己去File.txt里面删就行"<<endl;
		cout<<"输入0结束操作（一定要输入0！输入0才会保存"<<endl;;
		cin>>opt;
		if(opt==1)
		{
			for(int i=1;i<=n;i++)
			{
				cout<<a[i].name<<" "<<a[i].rate<<endl;
			}
			cout<<"总人数:"<<n<<endl;
			cout<<"总中奖概率："<<sum<<endl;
		}else if(opt==2)
		{
			cout<<"输入名字 空格或回车分隔 结束请输入0"<<endl;
			string name;
			int s=0;
			while(1)
			{
				cin>>name;
				if(name=="0")break;
				s++;
				a[n+s].name=name;
			}
			cout<<"请输入他们的中奖概率"<<endl;
			int x;
			cin>>x;
			for(int i=n+1;i<=n+s;i++)a[i].rate=x;
			n+=s;
		}
	}
	cout<<"Saving..."<<endl;
	freopen("File.txt","w",stdout);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i].name<<" "<<a[i].rate<<endl;
	}
	cout<<0<<" "<<-1<<endl;
	return 0;
}

