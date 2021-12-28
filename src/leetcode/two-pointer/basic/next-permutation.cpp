#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n=nums.size();
    if (n <= 2) {
        reverse(nums.begin(), nums.end());
        return;
    }
    int i, prevNumer = INT_MIN;
    for(i=n-1; i>=0; i--) {
        if (nums[i] >= prevNumer) {
            prevNumer = nums[i];
        }else{
            break;
        }
    }
    
    // If i becomes -1, 
    // then the breaking the point doesn't exists
    // so only reverse the array

    if (i < 0) {
        reverse(nums.begin(), nums.end());
    }else{
        // Find the element which is just greater than
        // the element at the breaking point
        sort(nums.begin()+i+1, nums.end());
        int swapNumber = nums[i];
        int j;        
        for(j=i+1; j<n; j++) {
            if (nums[j]>swapNumber) {
                break;
            }
        }
        swap(nums[i], nums[j]);
    }
}