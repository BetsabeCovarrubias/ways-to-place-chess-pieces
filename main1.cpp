#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

bool isValid(vector<int>& holder, int row, int column){
    for(int i = 0; i < row; i++){
        if(holder[i] == column) {
            return false;
        }
    }
    return true;
}

int Rec(vector<vector<char>>& board, vector<int>& holder, int size, int num, int row, int count){
    if(count == num){
        return 1;
    }

    if(row == size){
        return 0;
    }

    int pathways = 0; 

    for(int i = 0; i < size; i++){
        if(board[row][i] == '#' && isValid(holder, row, i)){ 
            holder[row] = i;
            pathways += Rec(board, holder, size, num, row+1, count+1);
            holder[row] = -1; 
        }
        
    }
    pathways += Rec(board, holder, size, num, row+1, count); //check next row, but without placing down a piece in cur row
    return pathways;
}

int main(int argc, char* argv[]) {
    int count = 0;
    int size, num;
    
    cin >> size >> num;
    vector<vector<char>> board(size, vector<char>(size));
    vector<int> holder(size,-1);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << Rec(board, holder, size, num, 0, 0) << endl; 
    return 0;
}
