#include "bits/stdc++.h"

using namespace std;

namespace Brute {
    int maxProfit(int prices[], int buyIndex, int curIndex, int N) {
      if (N <= 0) {
          return 0;
      }
      int p1 = INT_MIN;
      int p2 = INT_MIN;
      int p3 = INT_MIN;


      if (buyIndex == -1) {
        // Can buy now
        p1 = maxProfit(prices, curIndex, curIndex+1, N-1);
      }else{
        // Can sell now
        p2 = prices[curIndex] - prices[buyIndex];
      }

      // Ignore both buy ans sell
      p3 = maxProfit(prices, buyIndex, curIndex+1, N-1);

      return max(p1, max(p2, p3));
  }

  int maxProfit(int prices[], int N) {
      return maxProfit(prices, -1, 0, N);
  }
}

namespace Memoization {
  int maxProfit(int prices[], int buyIndex, int curIndex, int N, map<pair<int, int>, int> &memo) {
      if (N <= 0) {
          return 0;
      }

      if (buyIndex != -1){
        auto it = memo.find(make_pair(buyIndex, curIndex));
        if (it != memo.end()) {
            return it->second;
        }
      }
 
      int p1 = INT_MIN;
      int p2 = INT_MIN;
      int p3 = INT_MIN;


      if (buyIndex == -1) {
        // Can buy now
        p1 = maxProfit(prices, curIndex, curIndex+1, N-1, memo);
      }else{
        // Can sell now
        p2 = prices[curIndex] - prices[buyIndex];
      }

      // Ignore both buy ans sell
      p3 = maxProfit(prices, buyIndex, curIndex+1, N-1, memo);

      return memo[make_pair(buyIndex, curIndex)] = max(p1, max(p2, p3));
      // int ans = max(p1, max(p2, p3));
      // if (buyIndex != -1)
      // memo[buyIndex] = ans;
      // return ans;
  }

  int maxProfit(int prices[], int N) {
      // int *memo = new int[N+1];
      // for(int i=0; i<=N; i++) {
      //   memo[i] = -1;
      // }
      map<pair<int, int>, int> memo;
      int ans = maxProfit(prices, -1, 0, N, memo);
      // delete[] memo;
      return ans;
  }
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);

  int N;
  cin >> N;
  int prices[N];
  for(int i=0; i<N; i++) {
      cin >> prices[i];
  }
  
  cout << "Memoization: " << Memoization::maxProfit(prices, N) << endl;
  cout << "Brute: " << Brute::maxProfit(prices, N) << endl;

  return 0;
}
