#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

bool validPalindrome(string s) {
    int n = s.size();
    int i = 0, j = n-1;
    while (i < j) {
        if (s[i] != s[j]) {
            int tempI = i;
            int tempJ = j;
            i++;
            while (i < j) {
                if (s[i] != s[j]) break;
                i++;
                j--;
            }
            if (i >= j) break;
            i = tempI;
            j = tempJ;

            j--;
            while (i < j) {
                if (s[i] != s[j]) return false;
                i++;
                j--;
            } 
        }
        i++;
        j--;
    }
    return true;
}