#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

/*
    So I can get the maximum profit if I buy at 
    least price and sell at highest price as possible.
    
    ------- Initial Thought --------
    Generally it seems that just getting the maximum price
    and the minimum price is good enough because I can 
    buy at min price and sell at max price. But this is not
    right because it may happen that the max prices comes before
    the min price. So practically it is like selling before buying
    which is not possible.

    -------- The Key Constraint ----------
    The key idea is to hence not only get the as highest profit as
    possible but at the same time keep in mind that selling price
    comes after the buying price.

    --------- The Solution ----------
    The main crux of the solution is to PROCESS WHILE MOVING AHEAD.
    This means as discussed earlier, I would keep a track of the
    minimum value as I move ahead because this minimum value can
    be used for buying the stock but as I don't know what bigger
    values come after this minimum value, so I would calculate the
    profit for every values that and store the maximum of these values.

    ----- Recap ----
    So in the loop I would do
        
        1.  The minimum value that I would get
        2.  The current profit that I get
        3.  Store this profit if it is bigger.
    
    Finally, return the profit.

    The way it keeps a track of the key constraint, which is that the
    selling prices should come after the buying is that we are calulating
    the buying price (minimum price) in the loop and selling price we are
    getting after that index where we got the min price as we are moving
    ahead in the loop and not getting back.

*/
int maxProfit(vector<int>& prices) {
    int minTillNow = INT_MAX;
    int maxProfit = INT_MIN;
    for(auto &each: prices) {
        minTillNow = min(minTillNow, each);
        maxProfit = max(maxProfit, each-minTillNow);
    }
    return maxProfit;
}