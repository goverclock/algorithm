#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
long long ans = -1e18, sum;
pair<int, int> p[50010];

int main(){
	int w, s;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &w, &s);
		p[i] = {w + s, s};
	}
	if(n == 1){
		printf("%d", -p[1].second);
		return 0;
	}
	sort(p + 1, p + 1 + n);

	for(int i = 0; i < n; i++){
		sum += p[i].first - p[i].second;
		ans = max(ans, sum - p[i + 1].second);
	}

	printf("%lld\n", ans);

	return 0;
}
