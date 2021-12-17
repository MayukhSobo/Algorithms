#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int currentSum = 0;
    int maxSum = INT_MIN;
    for(auto &each: nums) {
        // Either previous sum + current element is 
        // bigger or the current element itself is
        // bigger
        int s = currentSum+each;
        if (s > each) {
            currentSum = s;
        }else{
            currentSum = each;
        }

        // Track the max sum out of all the current sums
        if (currentSum > maxSum) maxSum = currentSum;
    }
    return maxSum;
}