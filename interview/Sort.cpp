#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void quickSort(vector<int>& nums, int l, int r) {	// including r
    if (l >= r) return;
    int pos = l + rand() % (r - l);
    int piv = nums[pos];
    swap(nums[pos], nums[r]);
    int ind = l;
    for (int i = l; i <= r; i++) {
        if (nums[i] <= piv) {
            swap(nums[i], nums[ind]);
            ind++;
        }
    }
    ind--;
    quickSort(nums, l, ind - 1);
    quickSort(nums, ind + 1, r);
}

// merge [l,mid] and [mid+1,r]
void merge(vector<int>& nums, vector<int> &tmp, int l, int mid, int r) {
	int i = l, j = mid + 1;
	int ind = 0;
	while (i <= mid && j <= r) {
		if (nums[i] <= nums[j])
			tmp[ind++] = nums[i++];
		else
			tmp[ind++] = nums[j++];
	}

	while (i <= mid) tmp[ind++] = nums[i++];
	while (j <= r) tmp[ind++] = nums[j++];

	for (int i = 0; i < r - l + 1; ++i) nums[l + i] = tmp[i];
}

void mergeSort(vector<int>& nums, vector<int> &tmp, int l, int r) {	// including r
	if (l >= r) return;
	int mid = l + r >> 1;
	mergeSort(nums, tmp, l, mid);
	mergeSort(nums, tmp, mid + 1, r);
	merge(nums, tmp, l, mid, r);
}

int main() {
	static const vector<int> ans{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	static const vector<vector<int>> oorder{
		{1, 3, 5, 7, 9, 2, 4, 6, 8, 0},
		{9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
		{0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
		{5, 6, 7, 8, 9, 0, 1, 2, 3, 4}
	};

	for (const auto &o : oorder) {
		vector<int> cur(o);
		quickSort(cur, 0, cur.size() - 1);
		assert(cur == ans);
	}

	vector<int> tmp(ans.size());
	for (const auto &o : oorder) {
		vector<int> cur(o);
		mergeSort(cur, tmp, 0, cur.size() - 1);
		assert(cur == ans);
	}
	
	return 0;
}

