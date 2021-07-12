/*
---------------------------------------------
The_Network_problem
from : https://programmers.co.kr/learn/courses/30/lessons/43162
solved by using a bfs(implemeted by using queue).
---------------------------------------------
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int adj_mtx[201][201] = {0,}, visit[201] = {0, };
    int cnt = 0, size = computers.size(), i, j, k;
    queue<int> q;
    
    for(i = 1; i<= size; i++)
        for(j = 1; j<= size; j++)
            adj_mtx[i][j] = computers[i - 1][j - 1];
    
    for(i = 1; i<= size; i++) {
        if(visit[i] == 1)
            continue;
        cnt++;
        visit[i] = 1;
        q.push(i);
        do {
            k = q.front();
            q.pop();
            for(j = 1; j<= size; j++) {
                if(adj_mtx[k][j] == 1 && visit[j] == 0) {
                    q.push(j);
                    visit[j] = 1;
                }
            }
        }
        while(q.empty() == false);
    }
    
    return cnt;
}
