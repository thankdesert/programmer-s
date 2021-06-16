/*
---------------------------------------------
Kakao_coloring_book_problem
from : https://programmers.co.kr/learn/courses/30/lessons/1829
solved by using bfs(implemented by queue)
---------------------------------------------
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = -1;
    queue <pair<int, int>> q;    
    int r_m[4] = {-1, 1, 0, 0}; int c_m[4] = {0, 0, -1, 1}; //상-하-좌-우    
    int i, j, k, terr, row, col;
    int check[102][102];
    
    for(i = 0; i <= n + 1; i++) {
        check[0][i] = 1;
        check[m + 1][i] = 1;
    }
    for(i = 0; i <= m + 1; i++) {
        check[i][0] = 1;
        check[i][n + 1] = 1;
    } 
          
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
            check[i][j] = 0;  
    
    for(i = 1; i<= m; i++) {
        for(j = 1; j<= n; j++) {
            if(check[i][j] == 1 || picture[i - 1][j - 1] == 0)
                continue;
            else {
                q.push(make_pair(i, j)); //row, col
                terr = 1;
                number_of_area++;
                while(q.empty() == 0) {
                    row = q.front().first;
                    col = q.front().second;
                    check[row][col] = 1;
                    for(k = 0; k<4; k++) {
                        if(check[row + r_m[k]][col + c_m[k]] == 0 &&
                           picture[row - 1][col - 1] == picture[row + r_m[k] - 1][col + c_m[k] - 1]) {
                            q.push(make_pair(q.front().first + r_m[k], q.front().second + c_m[k]));
                            check[q.front().first + r_m[k]][q.front().second + c_m[k]] = 1;
                            terr++;
                        }
                    }
                    q.pop();
                }
                if(terr > max_size_of_one_area)
                    max_size_of_one_area = terr;
            }
        }
    }
    
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
