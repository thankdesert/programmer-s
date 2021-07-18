/*
---------------------------------------------
Rotating_the_matrix_problem.c
from : https://programmers.co.kr/learn/courses/30/lessons/77485
---------------------------------------------
*/

#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int mtx[101][101];
    int i, j, cur = 1;
    for(i = 1; i<=rows; i++)
        for(j = 1; j<=columns; j++)
            mtx[i][j] = cur++;
    
    queue<int> q;
    int r_1, c_1, r_2, c_2, prev, temp;
    for(i = 0; i<queries.size(); i++) {
        r_1 = queries[i][0];
        c_1 = queries[i][1];
        r_2 = queries[i][2];
        c_2 = queries[i][3];
        prev = mtx[r_1][c_1];
        for(j = 1; j<= c_2 - c_1; j++) {
            q.push(prev);
            temp = mtx[r_1][c_1 + j];
            mtx[r_1][c_1 + j] = prev;
            prev = temp;
        }
        
        for(j = 1; j<= r_2 - r_1; j++) {
            q.push(prev);
            temp = mtx[r_1 + j][c_2];
            mtx[r_1 + j][c_2] = prev;
            prev = temp;
        }
        
        for(j = 1; j<= c_2 - c_1; j++) {
            q.push(prev);
            temp = mtx[r_2][c_2 - j];
            mtx[r_2][c_2 - j] = prev;
            prev = temp;
        }
        
        for(j = 1; j<= r_2 - r_1; j++) {
            q.push(prev);
            temp = mtx[r_2 - j][c_1];
            mtx[r_2 - j][c_1] = prev;
            prev = temp;
        }
        
        int min = INT_MAX;
        while(q.empty() != true) {
            if(q.front() < min)
                min = q.front();
            q.pop();
        }
        answer.push_back(min);
    }
    return answer;
}
