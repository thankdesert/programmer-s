/*
---------------------------------------------
Linking_all_islands_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42861
solved by using a Kruskal's algorithm.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0, i, j, min, next, temp_p;
    int adj_mtx[100][100] = {0, };
    int visit[100] = {0, };
    
    min = INT_MAX;
    for(i = 0; i<costs.size(); i++) {
        adj_mtx[costs[i][0]][costs[i][1]] = costs[i][2];
        adj_mtx[costs[i][1]][costs[i][0]] = costs[i][2];
        if(costs[i][2] < min) {
            temp_p = costs[i][0];
            min = costs[i][2];
        }
    }
    visit[temp_p] = 1;
    
    while(true) {
        min = INT_MAX;
        for(i = 0; i<n; i++) {
            if(visit[i] == 0)
                continue;
            for(j = 0; j<n; j++) {
                if(adj_mtx[i][j] == 0 || visit[j] == 1)
                    continue;
                if(min > adj_mtx[i][j]) {
                    min = adj_mtx[i][j];
                    next = j;
                }
            }
        }        
        if(min == INT_MAX)
            break;
        answer += min;
        visit[next] = 1;
    }
    
    return answer;
}
