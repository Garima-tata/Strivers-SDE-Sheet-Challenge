#include <bits/stdc++.h>
using namespace std;

// Spiral Matrix
void rotateMatrix(vector<vector<int>>& mat, int row, int col) {
    if (row == 0 || col == 0) {
        return;
    }
    int top = 0;
    int bottom = row - 1;
    int left = 0;
    int right = col - 1;
    int prev, curr;

    
    while (top < bottom && left < right) {
        prev = mat[top + 1][left];

        // Move elements of top row from left to right
        for (int i = left; i <= right; i++) {
            curr = mat[top][i];
            mat[top][i] = prev;
            prev = curr;
        }
        top++;

        // Move elements of right column from top to bottom
        for (int i = top; i <= bottom; i++) {
            curr = mat[i][right];
            mat[i][right] = prev;
            prev = curr;
        }
        right--;

        // Move elements of bottom row from right to left
        for (int i = right; i >= left; i--) {
            curr = mat[bottom][i];
            mat[bottom][i] = prev;
            prev = curr;
        }
        bottom--;

        // Move elements of left column from bottom to top
        for (int i = bottom; i >= top; i--) {
            curr = mat[i][left];
            mat[i][left] = prev;
            prev = curr;
        }
        left++;
    }
}