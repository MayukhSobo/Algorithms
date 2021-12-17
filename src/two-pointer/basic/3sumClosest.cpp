#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size()-1;
    int sumThisFar = INT_MIN;
    for(int i=0; i<=n; i++) {
        int x = nums[i];
        int j = i+1, k = n;
        while (j < k) {
            int sum = nums[j] + nums[k] + x;
            if (sumThisFar == INT_MIN || (abs(target-sum) < abs(target-sumThisFar))) {
                sumThisFar = sum;    
            }
            if (nums[j]+nums[k]+x < target) {
                j++;
            }else if (nums[j]+nums[k]+x > target) {
                k--;
            }else{
                return target;
            }
        }
    }
    return sumThisFar;
}