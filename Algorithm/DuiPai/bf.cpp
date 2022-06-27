// freopen("data.in", "r", stdin);
// freopen("data.ans", "w", stdout);

#include<iostream>
#include<cstring>
using namespace std;
int aa[12345];int bb[12345];int vis[123456];
int main()
{
    freopen("data.in", "r", stdin);
freopen("data.ans", "w", stdout);
	int n,m;
	while(cin>>n>>m)
	{
		int flag=0;
		memset(aa,0,sizeof(aa));
		memset(bb,0,sizeof(bb));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++) 
		{
			cin>>aa[i];
			vis[aa[i]]=1;
		}
		for(int j=0;j<m;j++) cin>>bb[j];
		for(int i=0;i<m;i++)
		{
			if(vis[flag+bb[i]]) 
			{
				flag++;
				i=0;
			}
		}
		cout<<flag<<endl;
	}
	return 0;
}
