#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;


int minSubArrayLen(int target, vector<int>& nums) {
    int minLength = INT_MAX;
    int n = nums.size();
    int i=0, j = 0;
    int sum = 0;
    while (j < n) {
        sum += nums[j];
        while ((i <= j) && (sum >= target)) {
            minLength = min(minLength, j-i+1);
            sum -= nums[i];
            i++;
        }
        j++;    
    }
    return minLength == INT_MAX ? 0: minLength;
}