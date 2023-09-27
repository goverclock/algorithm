#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] & 1 != i & 1) {
			cout << -1 << endl;
			return 0;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {
			swap(a[i], a[a[i]]);
			ans++;
		}
	}
	cout << ans << endl;
    
    return 0;
}

