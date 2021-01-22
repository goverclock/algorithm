#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > que;
int n;
long long ans;

int main()
{
	cin >> n;
	int tmp;
	for(int i = 0; i < n; i++)
	{
		cin >> tmp;
		que.push(tmp);
	}
	while(que.size() >= 2)
	{
		int a1, a2;
		a1 = que.top();
		que.pop();
		a2 = que.top();
		que.pop();
		ans += a1 + a2;
		que.push(a1 + a2);
	}
	que.pop();

	printf("%lld\n", ans);

	return 0;
}
