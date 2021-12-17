#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> res(2);
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if (um.count(target-nums[i]) == 0) {
                // The element is not present
                um[nums[i]] = i;
            }else{
                res[0] = um[target-nums[i]];
                res[1] = i;
                // res.push_back(i);
                
            }
        }
        return res;
}
