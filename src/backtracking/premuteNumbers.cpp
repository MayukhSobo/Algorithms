#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;
// [1,2,3], [2,1,3], [3,2,1], [1,3,2]
vector<vector<int>> result;
vector<int> current;
unordered_map<int, bool> um;
void _premute(vector<int> &nums, int index) {
    int n = nums.size();
    if (index == n) {
        result.push_back(current);
        return;
    }

    for(int i=0; i<n; i++) {
        if (um[nums[i]] == false) {
            current.push_back(nums[i]);
            um[nums[i]] = true; 
            _premute(nums, index+1);
            current.pop_back();
            um[nums[i]] = false;
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    _premute(nums, 0);
    return result;
}
// 123 (i=0 begin=0)
// 123
// 123 (i=0 begin=1)