#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int, int> dp[501][1024]; // Adjust dp size to 501 x 1024

// Modify the solve function to accept a 2D array grid using pointers
bool solve(int i, int k, int n, int m, int** grid) {
    // Base case: if we've considered all rows, check if k is 0 (XOR should be 0)
    if (i == n) return k != 0;

    // If this state has been computed, return the stored result
    if (dp[i][k].first != -1) return dp[i][k].first == 1;

    // Try all possible values from the grid in row i
    for (int l = 0; l < m; l++) {
        bool ans = solve(i + 1, k ^ grid[i][l], n, m, grid);
        if (ans) {
            dp[i][k] = {1, l};  // Mark this state as true (possible) and store the column index
            return true;
        }
    }

    dp[i][k] = {0, -1};  // Mark this state as false (not possible)
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Dynamically allocate memory for the grid
    int** grid = new int*[n];  // Array of pointers for rows
    for (int i = 0; i < n; i++) {
        grid[i] = new int[m];  // Array of m elements for each row
    }

    // Input the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Initialize dp with {-1, -1} (indicating uncomputed states)
    for (int i = 0; i < 501; i++) {
        for (int k = 0; k < 1024; k++) {
            dp[i][k] = {-1, -1};
        }
    }

    // Start the recursive check from the first row with an initial XOR state of 0
    if (solve(0, 0, n, m, grid)) {
        cout << "TAK" << endl;
        int ans[n];
        // Reconstruct the answer from dp table
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < m; c++) {
                if (dp[i][k].first == 1 && dp[i][k].second == c) {
                    ans[i] = c + 1;  // Store the column (1-based index)
                    k ^= grid[i][c];  // Update XOR value
                    break;
                }
            }
        }

        // Output the reconstructed answer
        for (int i : ans) cout << i << " ";
        cout << endl;
    } else {
        cout << "NIE" << endl;
    }

    // Deallocate the dynamically allocated memory for the grid
    for (int i = 0; i < n; i++) {
        delete[] grid[i];  // Free each row
    }
    delete[] grid;  // Free the array of row pointers

    return 0;
}
