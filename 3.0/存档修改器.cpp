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
		cout<<"�������ͣ�\n����1�鿴��ǰ����\n����2�������\nɾ���Ļ��Լ�ȥFile.txt����ɾ����"<<endl;
		cout<<"����0����������һ��Ҫ����0������0�Żᱣ��"<<endl;;
		cin>>opt;
		if(opt==1)
		{
			for(int i=1;i<=n;i++)
			{
				cout<<a[i].name<<" "<<a[i].rate<<endl;
			}
			cout<<"������:"<<n<<endl;
			cout<<"���н����ʣ�"<<sum<<endl;
		}else if(opt==2)
		{
			cout<<"�������� �ո��س��ָ� ����������0"<<endl;
			string name;
			int s=0;
			while(1)
			{
				cin>>name;
				if(name=="0")break;
				s++;
				a[n+s].name=name;
			}
			cout<<"���������ǵ��н�����"<<endl;
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

