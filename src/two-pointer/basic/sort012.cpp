#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

void sortColors(vector<int>& nums) {
    // Our pivot element is 1
    // We need to segregate all the 0s in one side
    // First, we push all the 0s before the pivot element
    int n = nums.size();
    int pivot = 0;
    while(pivot < n && nums[pivot] == 0) {
        pivot++;
    }
    if (pivot == n) return;
    int i = pivot+1;
    while (i < n) {
        if (nums[i] == 0) {
            swap(nums[pivot++], nums[i]);
        }
        i++;
    }
    int pivot2 = n-1;
    while (pivot2 >= pivot && nums[pivot2] == 2) {
        pivot2--;
    }
    if (pivot2 < pivot) return;
    i = pivot2-1;
    while (i >= pivot) {
        if (nums[i] == 2) {
            swap(nums[pivot2--], nums[i]);
        }
        i--;
    }
}