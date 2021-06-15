/*
---------------------------------------------
The_shortest_distance_problem_in_the_game_map.c
from : https://programmers.co.kr/learn/courses/30/lessons/1844
solved by using bfs(implemented by queue)
---------------------------------------------
*/

#include<string>
#include<vector>
#include<queue>

using namespace std;

int solution(vector<vector<int> > maps) {
    int answer = -1;
    queue<pair<int, int>> q;
    
    int m_r[4] = {-1, 1, 0, 0};
    int m_c[4] = {0, 0, -1, 1};
    
    q.push(make_pair(0, 0));
    q.push(make_pair(1,0));
    
    int cur_r, cur_c, cur_dis, i, j, flag;
    while(q.empty() != 1) {
        cur_r = q.front().first;
        cur_c = q.front().second;
        q.pop();
        cur_dis = q.front().first;
        q.pop();
        
        if(cur_r == maps.size() - 1 && cur_c == maps[0].size() - 1) {
            answer = cur_dis;
            break;
        }
        
        for(i = 0; i<4; i++) {
            if(cur_r + m_r[i] >= 0 && cur_r + m_r[i] < maps.size() &&
               cur_c + m_c[i] >= 0 && cur_c + m_c[i] < maps[0].size() && 
               maps[cur_r + m_r[i]][cur_c + m_c[i]] == 1) {
                q.push(make_pair(cur_r + m_r[i], cur_c + m_c[i]));
                q.push(make_pair(cur_dis + 1, 0));
                maps[cur_r + m_r[i]][cur_c + m_c[i]] = 0;
            }
        } 
        maps[cur_r][cur_c] = 0;
    }
    
    return answer;
}
