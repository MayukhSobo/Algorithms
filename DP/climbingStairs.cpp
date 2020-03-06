#include "bits/stdc++.h"
using namespace std;


namespace Memoization {
    int minCostClimbingStairs(int *costs, int N, int *memo) {
        if (N<=0) {
            return 0;
        }
        
        if (memo[N] != -1){
            return memo[N];
        }
        
        // If taking the 0th stair
        int c1 = costs[0];
        c1 += minCostClimbingStairs(costs+1, N-1, memo);
        
        
        // If not taking the 0th stair
        int c2 = 0;
        if (N > 1) {
            c2 = costs[1];
            c2 += minCostClimbingStairs(costs+2, N-2, memo);
        }
        int ans = min(c1, c2);
        memo[N] = ans;
        return ans;
    }
    
    int minCostClimbingStairs(int *costs, int N) {
        int *memo = new int[N+1];
        for(int i=0; i<=N; i++) {
            memo[i] = -1;
        }
        return minCostClimbingStairs(costs, N, memo);
    }
}

namespace DP {
    int minCostClimbingStairs(int *costs, int N) {
        int *table = new int[N];
        table[0] = costs[0];
        table[1] = costs[1];
        for(int i=2; i<N; i++) {
            table[i] = costs[i] + min(table[i-1], table[i-2]);
        }
        int ans = min(table[N-2], table[N-1]);
        delete []table;
        return ans;
    }
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int N;
    cin >> N;
    int cost[N];
    for(int i = 0; i < N; ++i) {
        cin >> cost[i];
    }
    cout << "DP: " << DP::minCostClimbingStairs(cost, N) << endl;
    
    cout << "Memo: " << Memoization::minCostClimbingStairs(cost, N) << endl;
    return 0;
}