#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <chrono>
#include <deque>
#include <functional>
#include <fstream>
#include <forward_list>
#include <iostream>
#include <iomanip>
#include <ios>
#include <istream>
#include <initializer_list>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <sstream>
#include <stack>
#include <strstream>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
#pragma GCC optimize("O3")
constexpr bool TC_1 = true;
//#pragma GCC target("avx2,tune=native")
using namespace std;
#define LOCAL
#define ar array
#define ll long long
#define ld long double
#define mp make_pair
#define fi first
#define se second
#define nline '\n'
// #define size(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();}
char TEMPORARY_CHAR;
#define readInt(x) int x; _readInt(x);
inline void _readInt(int &a) {a = 0; while (((TEMPORARY_CHAR = (char)getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = (char)getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = (a << 3) + (a << 1) + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = (char)getchar();} if (neg) a = -a;}
inline int nxt() {readInt(ret); return ret;}
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
template<typename T> ll sum(vector<T> &arr, ll init=0ll) {return accumulate(arr.begin(), arr.end(), init);}
#ifdef LOCAL
#define dbg(...) cerr << "\n(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
/*-----------------------------RANDOM NUMBER GENERATOR ---------------------*/
#ifdef RNG
unsigned seed=chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 rng(seed);
#endif
// ------------------------------------------------------------------------- //
/*------------------------------UNORDERED MAP HASH --------------------------------------------*/
//To make unordered_map unhackable
// use it as unordered_map<int,int,custom_hash> mapp;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        /* http://xorshift.di.unimi.it/splitmix64.c */
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// ------------------------------------------------------------------------- //
constexpr int MAX_N = 1e5 + 5;
constexpr ll MOD = 1e9 + 7;
constexpr ll INF = 1e9;
constexpr ld EPS = 1e-9;

void sUpper(string &s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
}
void sLower(string &s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}
template <typename T>
int LinearSearch(vector<T> &arr, T element) {
    int index = find(arr.begin(), arr.end(), element) - arr.begin();
    if (index >= arr.size()) return -1;
    return index;
}


// ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ //
// ⬜                    Code Starts Here                      ⬜
// ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ //


void solve() {
    // Code here

    readInt(n);
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        nums[i] = nxt();
    }
    int start = 0, end = n-1;
    int sc = 0, dc = 0;
    bool serejaTurn = true;

    while (start <= end) {
        if (nums[start] > nums[end]) {
            if (serejaTurn) {
                sc += nums[start];
                serejaTurn = false;
            }
            else{
                dc += nums[start];
                serejaTurn = true;
            }
            start++;
        }else{
            if (serejaTurn) {
                sc += nums[end];
                serejaTurn = false;
            }
            else{
                dc += nums[end];
                serejaTurn = true;
            }
            end--;
        }
    }
    cout << sc << " " << dc << nline;
}

// ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ //
// ⬜                    Code Ends Here                        ⬜
// ⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜⬜ //

int main() {
    FAST_IO
    int tc;
    if (TC_1) tc = 1;
    else cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}