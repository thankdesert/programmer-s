/*
---------------------------------------------
The_ranking_problem.c
from : https://programmers.co.kr/learn/courses/30/lessons/49191
solved by using a floyd-warshall_algorithm
---------------------------------------------
*/


#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int i, j, k, win, defeat, cnt = 0;
    int arr[101][101] = {0, };
    
    for(i=0; i<results.size(); i++)
        arr[results[i][0]][results[i][1]] = 1;
    
    for(i=1; i<=n; i++)
        for(j = 1; j<=n; j++)
            for(k = 1; k<=n; k++)
                if(arr[j][i] && arr[i][k])
                    arr[j][k] = 1;
    
    for(i = 1; i<=n; i++) {
        win = 0, defeat = 0;
        for(j = 1; j<=n; j++) {
            if(arr[i][j] == 1)
                win++;
            if(arr[j][i] == 1)
                defeat++;
        }
        if(win + defeat == n - 1)
            cnt++;
    }
    
    return cnt;
}
