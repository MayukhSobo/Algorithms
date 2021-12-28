#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

vector<vector<int>> results;
vector<int> current;
unordered_map<int, int> um;

void _permuteUnique(vector<int> &nums, int index) {
    int n = nums.size();
    if (index == nums.size()) {
        results.push_back(current);
        return;
    }
    for(int i=0; i<n; i++) {
        if (um[nums[i]] != 0) {
            current.push_back(nums[i]);
            um[nums[i]]--;
            _permuteUnique(nums, index+1);
            um[nums[i]]++;
            current.pop_back();
        }
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    for(auto &each: nums) {
        um[each]++;
    }
    _permuteUnique(nums, 0);
}