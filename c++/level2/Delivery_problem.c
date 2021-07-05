/*
---------------------------------------------
Delivery_problem
https://programmers.co.kr/learn/courses/30/lessons/12978
solved by using a dijkstra algorithm(implemented by a adjacency matrix).
---------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0, i, j, min_index, min;
    int mat[51][51] = {0,};
    int d[51] = {0,};
    int visit[51] = {0,};
    
    for(i = 0;  i< road.size(); i++) {
        if(mat[road[i][0]][road[i][1]] == 0 || mat[road[i][0]][road[i][1]] > road[i][2]) {
            mat[road[i][0]][road[i][1]] = road[i][2];
            mat[road[i][1]][road[i][0]] = road[i][2];
        }
    }
    
    visit[1] = 1;
    while(true) {
        min = 10000000;
        for(i = 1; i<=N; i++) {
            if(visit[i] == 1) {
                for(j = 1; j<=N; j++) {
                    if(mat[i][j] != 0 && visit[j] == 0) {
                        if(mat[i][j] + d[i] < min) {
                            min = mat[i][j] + d[i];
                            min_index = j;
                        }
                    }
                }
            }
        }
        
        if(min == 10000000)
            break;
        
        visit[min_index] = 1;
        d[min_index] = min;
    }
    
    for(i = 1; i<=N; i++) {
        if(d[i] <= K)
            answer++;
    }
    
    return answer;
}
