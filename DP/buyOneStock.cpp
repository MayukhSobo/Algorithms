#include "bits/stdc++.h"
using namespace std;

namespace Brute {
    int maxProfit(int *prices, bool bought, int boughtPrice, int N) {
        if (N <= 1) {
            return 0;
        }
        int p1 = INT_MIN;
        int p2 = INT_MIN;
        int p3 = INT_MIN;

        // We can buy if not purchased already
        if (not bought) {
            // But it
            p1 = max(0, maxProfit(prices+1, true, prices[0], N-1));
        }else {
            // Sell it
            p2 = max(prices[0] - boughtPrice, maxProfit(prices+1, false, -1, N-1));
        }

        // Don't buy or sell
        p3 = maxProfit(prices+1, bought, boughtPrice, N-1);

        return max(p1, max(p2, p3));
    }
    int maxProfit(int *prices, int N) {
        return maxProfit(prices, false, -1, N);
    }
}

namespace Memoization {

    int maxProfit(int *prices, bool bought, int boughtPrice, int N, int **memo) {
        if (N <= 1) {
            return 0;
        }
        if (memo[(int)bought][N] != -1) {
            return memo[(int)bought][N];
        }
        int p1 = INT_MIN;
        int p2 = INT_MIN;
        int p3 = INT_MIN;
        if (bought) {
            // If purchased previously, then can sell
            p1 = max(prices[0]- boughtPrice, maxProfit(prices+1, false, -1, N-1, memo));
        }else{
            // If not purchased, then can buy
            p2 = max(0, maxProfit(prices+1, true, prices[0], N-1, memo));
        }

        // Can always retain
        p3 = maxProfit(prices+1, bought, boughtPrice, N-1, memo);

        // Store and return
        int ans = max(p1, max(p2, p3));
        memo[(int)bought][N] = ans;
        return ans;
    }

    int maxProfit(int *prices, int N) {
        int **memo = new int*[2];
        for(int i = 0; i < 2; i++) {
            memo[i] = new int[N+1];
            for(int j = 0; j <= N; j++) {
                memo[i][j] = -1;
            }
        }
        int ans = maxProfit(prices, false, -1, N, memo);
        for(int i=0; i<2; i++) {
            delete[] memo[i];
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
    int *prices = new int[N];
    for(int i = 0; i < N; i++) {
        cin >> prices[i];
    }
    cout << "Memo: " << Memoization::maxProfit(prices, N) << endl;
    cout << "Brute: " << Brute::maxProfit(prices, N) << endl;
    delete []prices;
    return 0;
}