#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    if (k == 0) {
        return;
    }
    int p=0, q=n-k, r=n-1;
    while (q < r) {
        swap(nums[q++], nums[r--]);
    }
    q = n-k-1;
    while (p < q) {
        swap(nums[p++], nums[q--]);
    }
    
    p = 0, q = n-1;
    while (p < q) {
        swap(nums[p++], nums[q--]);
    }
}