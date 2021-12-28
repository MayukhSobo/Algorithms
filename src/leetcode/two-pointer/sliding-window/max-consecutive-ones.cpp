#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int maxOnes = INT_MIN;
    int n = nums.size();
    int i = 0, j = 0;
    int zeroCount = 0;
    while (j < n) {
        if (nums[j] == 0) {
            zeroCount++;
        }
        
        while ((i <= j) && (zeroCount > k)) {
            if (nums[i] == 0) {
                zeroCount--;
            }
            i++;
        }
        maxOnes = max(maxOnes, j-i+1);
        j++;
    }
    return maxOnes;
}