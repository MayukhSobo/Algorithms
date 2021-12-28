#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {    
    vector<vector<int>> results;
    if (nums.size() < 4) {
        return results;
    }
    int n = nums.size()-1;
    sort(nums.begin(), nums.end());       
    for(int i=0; i<=n; i++) {
        for(int j=i+1; j<=n; j++) {
            // We need to find all the a,b,c,d so that a+b+c+d = target
            long long a = nums[i];
            long long b = nums[j];
            int p = j+1, q = n;
            while (p < q) {
                if (a+b+nums[p]+nums[q] < target) {
                    p++;
                }else if (a+b+nums[p]+nums[q] > target) {
                    q--;
                }else{
                    // We have found a quadruplet
                    results.push_back(vector<int>{(int)a, (int)b, nums[p], nums[q]});
                    while (p < q && nums[p+1] == nums[p]) p++;
                    p++;
                    while (p < q && nums[q-1] == nums[q]) q--; 
                    q--;
                }
            }
            while (j < n && nums[j+1] == nums[j]) j++;
        }
        while(i < n && nums[i+1] == nums[i]) i++;
    }
    return results;
}