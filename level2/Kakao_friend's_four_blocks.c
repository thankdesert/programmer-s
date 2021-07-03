/*
---------------------------------------------
Kakao_friend's_four_blocks
from : https://programmers.co.kr/learn/courses/30/lessons/17679
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int i, j, k, answer = 0, d_count, t_count, p_count;
    char field[m+2][n+2];
    int move_r[4] = {0, -1, 0, -1}, move_c[4] = {0, 0, 1, 1}; //current, bottom, right, right & bottom
    
    for(i = 0; i < m +2; i++) {
        field[i][0] = 'X'; field[i][n+1] = 'X';
    }
    for(i = 0; i < n+2; i++) {
        field[0][i] = 'X'; field[m+1][i] = 'X';
    }
    
    for(i = 1; i<= m; i++) {
        for(j = 1; j<= n; j++)
            field[i][j] = board[i-1][j-1];
    }
    
    do {
        d_count = 0;
        for(i = 1; i<= m; i++) {
            for(j =1; j<= n; j++) {
                char cur = field[i][j];
                if(cur == 'X')
                    continue;
                t_count = 0; p_count = 0;
                for(k = 1; k<4; k++) {
                    if(field[i+move_r[k]][j+move_c[k]] == cur || abs(field[i+move_r[k]][j+move_c[k]] - cur) == 'a' - 'A')
                        t_count++;
                }
                if(t_count == 3) {
                    for(k = 0; k<4; k++) {
                        if(field[i+move_r[k]][j+move_c[k]] >= 'A' && field[i+move_r[k]][j+move_c[k]] <= 'Z') {
                            field[i+move_r[k]][j+move_c[k]] += ('a' - 'A');
                            p_count++;
                        }
                    }
                }
                d_count += p_count;
            }
        }
        answer += d_count;
        
        for(int c = 1; c <= n; c++) {
            for(int r = m; r >= 1 && field[r][c] != 'X'; r--) {
                if(field[r][c] >= 'A' && field[r][c] <= 'Z')
                    continue;
                else {
                    for(k = r; k >= 1; k--)
                        field[k][c] = field[k-1][c];
                    r++;
                }
            }
        }
    }while(d_count > 0);
        
    return answer;
}
