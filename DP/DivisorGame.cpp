#include "bits/stdc++.h"
using namespace std;

// Simple Brute force approach
namespace Brute {
    static bool divisorGame(int N, bool turn) {
        if (turn and N == 2) {
            return true;
        }
        
        if (turn) {
            // If it is Alice's turn
            for(int x=1; x<N; x++) {
                if (N%x == 0) {
                    // Alice can take this x
                    bool ans1 = divisorGame(N-x, false);
                    if (ans1) {
                        // If Alice has won in any of the game
                        return true;
                    }
                }
            }
            // If Alice has not won in any of the game
            return false;
        }else{
            // If it is Bob's turn
            for(int x=1; x<N; x++) {
                if (N%x == 0) {
                    // Bob can take this x
                    bool ans2 = divisorGame(N-x, true);
                    if (!ans2) {
                        // If Bob made Alice lose the game
                        return false;
                    }
                }
            }
            // Bob was not successful to defeat Alice and Alice wons
            return true;
        }
    }
    bool divisorGame(int N) {
        return divisorGame(N, true);
    }
}

// Memoization with recursive approach (Top Down DP)
namespace Memoization {

    bool divisorGame(int N, bool turn, int **memo) {
        if (turn and N == 2) {
            return true;
        }
        int row = (int)turn;
        if (memo[row][N] == 1) {
            return true;
        }else if (memo[row][N] == 0) {
            return false;
        }else { // Not possible to get from the cache
            if (turn) {
                for(int x=1; x<N; x++) {
                    if (N%x==0) {
                        bool ans1 = divisorGame(N-x, false, memo);
                        if (ans1) {
                            memo[1][N] = 1;
                            return true;
                        }
                    }
                }
                memo[1][N] = 0;
                return false;
            }else{
                for(int x=1; x<N; x++) {
                    if(N%x==0) {
                        bool ans2 = divisorGame(N-x, true, memo);
                        if (!ans2) {
                            memo[0][N] = 0;
                            return false;
                        } 
                    }
                }
                memo[0][N] = 1;
                return true;
            }
        }

    }
    bool divisorGame(int N) {
        // Create the memoization table
        int **memo = new int*[2];
        for(int i=0; i<2; i++) {
            memo[i] = new int[N+1];
            // Initialize the table with all -1
            for(int j=0; j<=N; j++) {
                memo[i][j] = -1;
            }
        }

        // Call the recursive method
        bool aliceWon = divisorGame(N, true, memo);

        // Free the memory
        for(int i=0; i<2; i++) {
            delete []memo[i];
        }
        delete memo;

        return aliceWon;
    }
}

// Tabular DP (Bottom Up DP)
namespace DP {
    bool divisorGame(int N) {
        // Create the table
        int **table = new int*[2];
        for(int i=0; i<2; i++) {
            table[i] = new int[N+1];
        }
        
        // row 0 is for Bob and row 1 is for Alice
        bool turn = true; // Indicate the turn of Alice
        // There is no concept of N being 0, so the table values would be -1
        table[0][0] = table[1][0] = -1;

        // Whoever gets 1, loose the game because there is nothing in (0, 1)
        table[0][1] = 1; // Bob looses and alice wons
        table[1][1] = 0; // Alice loses
        
        // Whoever gets 2, wins the game
        table[0][2] = 0; // Bob wins and Alice loses
        table[1][2] = 1; // Alice wins
        
        for (int i=3; i<=N; i++) {
            for (int j=1; j*j<=i; j++) {
                if (i%j == 0) {
                    if (table[0][i-j] == 0) {
                        // If opponent is winning on this move
                        // Alice loses the game
                        table[1][i] = 0;
                        table[0][i] = 1;
                    }else if (table[0][i-j] == 1) {
                        // If Opponent is loosing
                        table[1][i] = 1;
                        table[0][i] = 0;
                    }
                }
                if (table[1][i] == 1) {
                    break;
                } 
            }
        }

        bool ans = (bool)table[1][N];
        // Free the memory
        for(int i=0; i<2; i++) {
            delete []table[i];
        }
        delete table;
        return ans;
    }
}



int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int n;
    cin >> n;

    bool ansMemo = Memoization::divisorGame(n);
    if (ansMemo) {
        cout << "Memo: true" << endl;
    }else{
        cout << "Memo: false" << endl;
    }
    // ------------------------- //
    bool ansDP = DP::divisorGame(n);
    if (ansDP) {
        cout << "DP: true" << endl;
    }else{
        cout << "DP: false" << endl;
    }
    // ------------------------- //
    
    bool ansBrute = Brute::divisorGame(n);
    if (ansBrute) {
        cout << "Brute: true" << endl;
    }else{
        cout << "Brute: false" << endl;
    }

    return 0;
}