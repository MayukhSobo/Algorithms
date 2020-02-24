#include "bits/stdc++.h"
using namespace std;

int maxProfitBrute(int *prices, int n) {
    int profit = INT_MIN;
    for (int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            profit = max(profit, prices[j]-prices[i]);
        }
    }
    return profit;
}

int maxProfitDivCon(int *prices, int start, int end) {
    if (start >= end) return 0;
    int mid = (start+end)/2;
    
    int maxInRight = INT_MIN;
    int minInLeft = INT_MAX;
    for(int i=start; i<=mid; i++) {
        minInLeft = min(minInLeft, prices[i]);
    }
    for(int i=mid+1; i<=end; i++) {
        maxInRight = max(maxInRight, prices[i]);
    }

    int profitEither = maxInRight - minInLeft;
    int profitLeft = maxProfitDivCon(prices, start, mid);
    int profitRight = maxProfitDivCon(prices, mid+1, end);

    return max(profitEither, max(profitLeft, profitRight));
}

int maxProfitDivCon(int *prices, int n) {
    return maxProfitDivCon(prices, 0, n-1);
}

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int *prices = new int[n];
    for (int i=0; i<n; i++){
        cin >> prices[i];
    }
    cout << "Brute Max profit: " << maxProfitBrute(prices, n) << endl;
    cout << "DivCon Max profit: " << maxProfitDivCon(prices, n) << endl;

    return 0;
}