#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, l, r;
long long ans = -1e9, q[300010], s[300010];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		int tmp;
		scanf("%d", &tmp);
		s[i] = s[i - 1] + tmp;
	}

	l = 1, r = 1;
	q[1] = 0;
	for(int i = 1; i <= n; i++){
		while(l <= r && q[l] < i - m) l++;
		ans = max(ans, s[i] - s[q[l]]);
		while(l <= r && s[q[r]] >= s[i]) r--;
		q[++r] = i;
	}

	printf("%lld\n", ans);

	return 0;
}
