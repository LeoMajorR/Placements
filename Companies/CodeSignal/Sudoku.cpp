#include <bits/stdc++.h>
using namespace std;


/**
 * @param board: the sudoku puzzle
 * Given a 9 x 9 sudoku board, in which all rows, columns and 3 x 3 sub-boxes are filled with digits from 1 to 9, determine if it is a valid sudoku puzzle.
 * Check and verify whether the given grid of numbers represents a valid sudoku puzzle or not.
*/

bool solution(vector<vector<bool>> grid)
{
    //check rows
    for(int i=0;i<9;i++){
        vector<bool> row(9,false);
        for(int j=0;j<9;j++){
            if(grid[i][j] && row[grid[i][j]-1]) return false;
            row[grid[i][j]-1] = true;
        }
    }

    //check columns
    for(int i=0;i<9;i++){
        vector<bool> col(9,false);
        for(int j=0;j<9;j++){
            if(grid[j][i] && col[grid[j][i]-1]) return false;
            col[grid[j][i]-1] = true;
        }
    }

    //check sub-boxes
    for(int i=0;i<9;i+=3){
        for(int j=0;j<9;j+=3){
            vector<bool> box(9,false);
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    if(grid[i+k][j+l] && box[grid[i+k][j+l]-1]) return false;
                    box[grid[i+k][j+l]-1] = true;
                }
            }
        }
    }

    return true;
}