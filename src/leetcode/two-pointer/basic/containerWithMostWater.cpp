#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int i=0, j = height.size()-1;
    int maxVolume = INT_MIN;
    while (i < j) {
        int h = min(height[i], height[j]);
        int w = j-i;
        maxVolume = max(maxVolume, h * w);
        if (height[i] < height[j]) {
            i++;
        }else if (height[i] > height[j]){
            j--;
        }else{
            i++;
            j--;
        }
    }
    return maxVolume;
}