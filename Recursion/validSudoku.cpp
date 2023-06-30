#include <bits/stdc++.h> 
using namespace std;
bool isValidSudoku(int board[9][9], int r, int c, int ch) {
    for (int i = 0; i < 9; i++) {
        if (board[r][i] == ch)
            return false;
        if (board[i][c] == ch)
            return false;
        if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch)
            return false;
    }
    return true;
}

bool isItSudoku(int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(board[i][j] == 0){
                for(int g=1;g<10;g++){
                    if (isValidSudoku(board, i, j, g)) {
                        board[i][j] = g;
                        if(isItSudoku(board)){
                            return true;
                        }else{
                            board[i][j]=0;
                        }
                    }
                }
                return false;
            }
            
        }
    }
    return true;
}
