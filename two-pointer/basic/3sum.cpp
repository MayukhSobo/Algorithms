#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size()-1;
    vector<vector<int>> results;
    // We need to find all triplets x, y, z such x+y+z = 0
    for(int i=0; i<=n; i++) {
        int x = nums[i];
        int j = i+1, k = n;
        while (j < k) {
            if (nums[j] + nums[k] + x > 0) {
                k--;
            }else if (nums[j] + nums[k] + x < 0) {
                j++;
            }else{
                // We have found one tripet
                results.push_back(vector<int>{x, nums[j], nums[k]}); 
                while (j < k && nums[j] == nums[j+1]) j++;
                // j++;
                while (j < k && nums[k] == nums[k-1]) k--;
                
                j++;
                k--;
            }
            
        }
        while(i<n && nums[i] == nums[i+1]) i++;
    }
    return results;
}