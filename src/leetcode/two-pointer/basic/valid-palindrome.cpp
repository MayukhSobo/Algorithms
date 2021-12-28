#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {    
    int left = 0, right = s.length()-1;
    while(left<right)
    {
        if(!isalnum(s[left])) left++;
        else if(!isalnum(s[right])) right--;
        else if(tolower(s[left])!=tolower(s[right])) return false;
        else {left++; right--;}
    }
    return true;
}