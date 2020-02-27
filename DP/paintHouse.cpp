#include "bits/stdc++.h"
using namespace std;

// Brute force recursive approach
namespace Brute {
    int minCostToPaint(int cost[][3], int lastColor, int curHouse, int n) {
        /*
        R G B
        R B G

        G R B
        G B R

        B R G
        B G R

        // Red - 0
        // Blue - 1
        // Green - 2
        // Other - -1
        */

        if (n == 0) {
            return 0;
        }

        int c1 = INT_MAX;
        int c2 = INT_MAX;
        int c3 = INT_MAX;

        // If the last house was not red
        if (lastColor != 0) {
            c1 = cost[curHouse][0]; // Choose the red color
            c1 += minCostToPaint(cost, 0, curHouse+1, n-1);
        }

        // If the last house was not blue
        if (lastColor != 1) {
            c2 = cost[curHouse][1]; // Choose the blue color
            c2 += minCostToPaint(cost, 1, curHouse+1, n-1);
        }

        // If the last house was not green
        if (lastColor != 2) {
            c3 = cost[curHouse][2]; // Choose the green color
            c3 += minCostToPaint(cost, 2, curHouse+1, n-1);
        }

        return min(c1, min(c2, c3));
    }

    int minCostToPaint(int cost[][3], int n) {
        return minCostToPaint(cost, -1, 0, n);    
    }
}

namespace Memoization {

    int minCostToPaint(int cost[][3], int lastColor, int curHouse, int n, int **memo) {
        if (n == 0) {
            return 0;
        }
        // This is the memoization part
        if (lastColor != -1 and memo[lastColor][curHouse] != -1) {
            return memo[lastColor][curHouse];
        }

        int c1 = INT_MAX;
        int c2 = INT_MAX;
        int c3 = INT_MAX;
        // If the last house was not red
        if (lastColor != 0) {
            // Choose the red color
            c1 = cost[curHouse][0];
            c1 += minCostToPaint(cost, 0, curHouse+1, n-1, memo);
        }

        // If the last house was not blue
        if (lastColor != 1) {
            // Choose the blue color
            c2 = cost[curHouse][1];
            c2 += minCostToPaint(cost, 1, curHouse+1, n-1, memo);
        }

        // If the last house was not green
        if (lastColor != 2) {
            // Choose the green color
            c3 = cost[curHouse][2];
            c3 += minCostToPaint(cost, 2, curHouse+1, n-1, memo);
        }

        int ans = min(c1, min(c2, c3));
        if (lastColor != -1)
            memo[lastColor][curHouse] = ans;
        return ans;
    }

    int minCostToPaint(int cost[][3], int N) {
        // Create the memoization table
        int **memo = new int*[3];
        for(int i = 0; i < 3; i++) {
            memo[i] = new int[N];
            for(int j = 0; j < N; j++){
                memo[i][j] = -1;
            }
        }

        int ans = Memoization::minCostToPaint(cost, -1, 0, N, memo);

        // Delete the memo table
        for(int i = 0; i < 3; i++) {
            delete [] memo[i];
        }
        delete []memo;

        return ans;
    }
}


int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int N;
    cin >> N;
    int costs[N][3];
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> costs[i][j];
        }
    }
    int minCostMemo = Memoization::minCostToPaint(costs, N);
    cout << "Memo: " << minCostMemo << endl;

    int minCostBrute = Brute::minCostToPaint(costs, N);
    cout << "Brute: " << minCostBrute << endl;

    return 0;
}