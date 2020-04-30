#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x7fffffff
void Read();
struct node{
	string name;
	int rate;
}a[10009];
bool cd[10009];
signed main()
{
	Read(); 
	return 0;
}
void Read()
{
	cout<<"你想要几个幸运儿：";
	int s;
	cin>>s;
	cout<<"读入存档......"<<endl;
	freopen("File.txt","r",stdin);
	freopen("中奖.txt","w",stdout);
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
