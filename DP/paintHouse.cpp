#include "bits/stdc++.h"
using namespace std;


namespace Brute {
    int minCostToPaint(int cost[][3], char lastColor, int curHouse, int n) {
        /*
        R G B
        R B G

        G R B
        G B R

        B R G
        B G R
        */

        if (n == 0) {
            return 0;
        }

        int c1 = INT_MAX;
        int c2 = INT_MAX;
        int c3 = INT_MAX;

        // If the last house was not red
        if (lastColor != 'r') {
            c1 = cost[curHouse][0]; // Choose the red color
            c1 += minCostToPaint(cost, 'r', curHouse+1, n-1);
        }

        // If the last house was not blue
        if (lastColor != 'b') {
            c2 = cost[curHouse][1]; // Choose the blue color
            c2 += minCostToPaint(cost, 'b', curHouse+1, n-1);
        }

        // If the last house was not green
        if (lastColor != 'g') {
            c3 = cost[curHouse][2]; // Choose the green color
            c3 += minCostToPaint(cost, 'g', curHouse+1, n-1);
        }

        return min(c1, min(c2, c3));
    }

    int minCostToPaint(int cost[][3], int n) {
        return minCostToPaint(cost, ' ', 0, n);    
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

    int minCost = Brute::minCostToPaint(costs, N);
    cout << minCost << endl;

    return 0;
}