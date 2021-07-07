/*
---------------------------------------------
The_largest_square_problem
https://programmers.co.kr/learn/courses/30/lessons/12905
---------------------------------------------
*/

#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<vector<int>> board) {
    int x_m[3] = {-1, 0, -1}; //상좌, 상, 좌
    int y_m[3] = {-1, -1, 0}; //상좌, 상, 좌
    int i, j, r_l = board.size(), c_l = board[0].size();
    
    if(board.size() == 1 || board[0].size() == 1)
        return 1;
    
    int min, max = INT_MIN;
    for(i = 1; i< r_l; i++) {
        for(j = 1; j< c_l; j++) {
            if(board[i][j] == 0)
                continue;
            min = INT_MAX;
            for(int k = 0; k<3; k++) {
                if(board[i + y_m[k]][j + x_m[k]] < min)
                    min = board[i + y_m[k]][j + x_m[k]];
            }
            if(min + 1 > max)
                max = min + 1;
            board[i][j] = min + 1;
        }
    }
    return max*max;
}
