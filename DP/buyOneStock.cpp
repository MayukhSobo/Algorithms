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

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int N;
    cin >> N;
    int *prices = new int[N];
    for(int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    cout << "Brute: " << Brute::maxProfit(prices, N) << endl;
    delete []prices;
    return 0;
}