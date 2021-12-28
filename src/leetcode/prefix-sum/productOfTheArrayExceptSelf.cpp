#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(nums);
    partial_sum(ans.begin(), ans.end(), ans.begin(), multiplies<int>());
    int suffixPartialProd = 1;
    for(int i=n-1; i>0; i--) {
        ans[i] = ans[i-1] * suffixPartialProd;
        suffixPartialProd *= nums[i];
    }
    ans[0] = suffixPartialProd;
    return ans;
}