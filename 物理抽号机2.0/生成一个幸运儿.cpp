#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x7fffffff
void Read();
struct node{
	string name;
	int rate;
}a[10009];
signed main()
{
	cout<<"¶ÁÈë´æµµ......"<<endl;
	Read(); 
	return 0;
}
void Read()
{
	freopen("File.txt","r",stdin);
	freopen("ÖÐ½±.txt","w",stdout);
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
	for(int i=1;i<=n;i++)
	{
		p-=a[i].rate;
		if(p<=0)
		{
			cout<<a[i].name<<endl;
			fclose(stdout);
			system("start ÖÐ½±.txt");
			return;
		}
	}
}
