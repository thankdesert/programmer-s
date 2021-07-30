/*
---------------------------------------------
Kakao's_moving_a_robot_problem
from : https://programmers.co.kr/learn/courses/30/lessons/60063
solved by bfs(customized)
---------------------------------------------
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board) {
    int i, j, answer = 0;
    vector<vector<int>> v(board.size() + 2, vector<int>(board[0].size() + 2, 1));
    vector<vector<int>> visit_h(board.size() + 2, vector<int>(board.size() + 2, 0));
    vector<vector<int>> visit_v(board[0].size() + 2, vector<int>(board.size() + 2, 0));
    vector<pair<int, int>> move_h_l = {{0, -1}, {0, 0}, {0, 0}, {-1, 1}, {1, 1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<pair<int, int>> move_h_r = {{0, -1}, {-1, -1}, {1, -1}, {0, 0}, {0, 0}, {0, 1}, {-1, 0}, {1, 0}};
    vector<pair<int, int>> move_v_t = {{-1, 0}, {0, 0}, {0, 0}, {1, -1}, {1, 1}, {1, 0}, {0, -1}, {0, 1}};
    vector<pair<int, int>> move_v_b = {{-1, 0}, {-1, -1}, {-1, 1}, {0, 0}, {0, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q_l,  q_r, q_is_h;
    
    for(i = 1; i<= board.size(); i++)
        for(j = 1; j<=board[0].size(); j++)
            v[i][j] = board[i-1][j-1];
    
    visit_h[1][1] = 1;
    visit_h[1][2] = 1;
    q_l.push(make_pair(1,1));
    q_r.push(make_pair(1,2));
    q_is_h.push(make_pair(1, 0));
    
    //bfs
    pair<int, int> temp_l, temp_r;
    int temp_is_h, temp_cnt, min = 1000000;
    while(q_l.empty() != true) {
        temp_l = q_l.front();
        temp_r = q_r.front();
        temp_is_h = q_is_h.front().first;
        temp_cnt = q_is_h.front().second;
        q_l.pop();
        q_r.pop();
        q_is_h.pop();
        if(temp_is_h == 1) {
            if(temp_r.first == board.size() && temp_r.second == board[0].size())
                return temp_cnt;
            for(i = 0; i<8; i++) {
                if(v[temp_l.first + move_h_l[i].first][temp_l.second + move_h_l[i].second] == 1 ||
                  v[temp_r.first + move_h_r[i].first][temp_r.second + move_h_r[i].second] == 1)
                    continue;
                if(i == 0 || i == 5 || i>=6) {
                    if(visit_h[temp_l.first + move_h_l[i].first][temp_l.second + move_h_l[i].second] != 0 &&
                       visit_h[temp_r.first + move_h_r[i].first][temp_r.second + move_h_r[i].second] != 0)
                        continue;
                    visit_h[temp_l.first + move_h_l[i].first][temp_l.second + move_h_l[i].second] = 1;
                    visit_h[temp_r.first + move_h_r[i].first][temp_r.second + move_h_r[i].second] = 1;
                    q_l.push(make_pair(temp_l.first + move_h_l[i].first, temp_l.second + move_h_l[i].second));
                    q_r.push(make_pair(temp_r.first + move_h_r[i].first, temp_r.second + move_h_r[i].second));
                    q_is_h.push(make_pair(1, temp_cnt + 1));
                }
                else if(i == 1 || i == 4) {
                    if(visit_v[temp_l.first + move_h_l[i].first][temp_l.second + move_h_l[i].second] != 0 &&
                       visit_v[temp_r.first + move_h_r[i].first][temp_r.second + move_h_r[i].second] != 0)
                        continue;
                    if(i == 1 && v[temp_r.first - 1][temp_r.second] == 1)
                        continue;
                    else if(i == 4 && v[temp_l.first + 1][temp_l.second] == 1)
                        continue;                    
                    visit_v[temp_l.first + move_h_l[i].first][temp_l.second + move_h_l[i].second] = 1;
                    visit_v[temp_r.first + move_h_r[i].first][temp_r.second + move_h_r[i].second] = 1;
                    q_l.push(make_pair(temp_l.first + move_h_l[i].first, temp_l.second + move_h_l[i].second));
                    q_r.push(make_pair(temp_r.first + move_h_r[i].first, temp_r.second + move_h_r[i].second));
                    q_is_h.push(make_pair(0, temp_cnt + 1));
                }
                else {
                    if(visit_v[temp_l.first + move_h_l[i].first][temp_l.second + move_h_l[i].second] != 0 &&
                       visit_v[temp_r.first + move_h_r[i].first][temp_r.second + move_h_r[i].second] != 0)
                        continue;
                    if(i == 2 && v[temp_r.first + 1][temp_r.second] == 1)
                        continue;
                    else if(i == 3 && v[temp_l.first - 1][temp_l.second] == 1)
                        continue;
                    visit_v[temp_l.first + move_h_l[i].first][temp_l.second + move_h_l[i].second] = 1;
                    visit_v[temp_r.first + move_h_r[i].first][temp_r.second + move_h_r[i].second] = 1;
                    q_r.push(make_pair(temp_l.first + move_h_l[i].first, temp_l.second + move_h_l[i].second));
                    q_l.push(make_pair(temp_r.first + move_h_r[i].first, temp_r.second + move_h_r[i].second));
                    q_is_h.push(make_pair(0, temp_cnt + 1));
                }
            }
        }
        
        if(temp_is_h == 0) {
            if(temp_l.first == board.size() && temp_l.second == board[0].size())
                return temp_cnt;
            for(i = 0; i<8; i++) {
                if(v[temp_l.first + move_v_b[i].first][temp_l.second + move_v_b[i].second] == 1 ||
                  v[temp_r.first + move_v_t[i].first][temp_r.second + move_v_t[i].second] == 1)
                    continue;
                if(i == 0 || i == 5 || i>=6) {
                    if(visit_v[temp_l.first + move_v_b[i].first][temp_l.second + move_v_b[i].second] != 0 &&
                       visit_v[temp_r.first + move_v_t[i].first][temp_r.second + move_v_t[i].second] != 0)
                        continue;
                    visit_v[temp_l.first + move_v_b[i].first][temp_l.second + move_v_b[i].second] = 1;
                    visit_v[temp_r.first + move_v_t[i].first][temp_r.second + move_v_t[i].second] = 1;
                    q_l.push(make_pair(temp_l.first + move_v_b[i].first, temp_l.second + move_v_b[i].second));
                    q_r.push(make_pair(temp_r.first + move_v_t[i].first, temp_r.second + move_v_t[i].second));
                    q_is_h.push(make_pair(0, temp_cnt + 1));
                }
                else if(i == 1 || i == 4) {
                    if(visit_h[temp_l.first + move_v_b[i].first][temp_l.second + move_v_b[i].second] != 0 &&
                       visit_h[temp_r.first + move_v_t[i].first][temp_r.second + move_v_t[i].second] != 0)
                        continue;
                    if(i == 1 && v[temp_l.first][temp_l.second - 1] == 1)
                        continue;
                    else if(i == 4 && v[temp_r.first][temp_r.second + 1] == 1)
                        continue;                    
                    visit_h[temp_l.first + move_v_b[i].first][temp_l.second + move_v_b[i].second] = 1;
                    visit_h[temp_r.first + move_v_t[i].first][temp_r.second + move_v_t[i].second] = 1;
                    q_l.push(make_pair(temp_l.first + move_v_b[i].first, temp_l.second + move_v_b[i].second));
                    q_r.push(make_pair(temp_r.first + move_v_t[i].first, temp_r.second + move_v_t[i].second));
                    q_is_h.push(make_pair(1, temp_cnt + 1));
                }
                else {
                    if(visit_h[temp_l.first + move_v_b[i].first][temp_l.second + move_v_b[i].second] != 0 &&
                       visit_h[temp_r.first + move_v_t[i].first][temp_r.second + move_v_t[i].second] != 0)
                        continue;
                    if(i == 2 && v[temp_l.first][temp_l.second + 1] == 1)
                        continue;
                    else if(i == 3 && v[temp_r.first][temp_r.second - 1] == 1)
                        continue;
                    visit_h[temp_l.first + move_v_b[i].first][temp_l.second + move_v_b[i].second] = 1;
                    visit_h[temp_r.first + move_v_t[i].first][temp_r.second + move_v_t[i].second] = 1;
                    q_r.push(make_pair(temp_l.first + move_v_b[i].first, temp_l.second + move_v_b[i].second));
                    q_l.push(make_pair(temp_r.first + move_v_t[i].first, temp_r.second + move_v_t[i].second));
                    q_is_h.push(make_pair(1, temp_cnt + 1));
                }
            }
        }
    }
    
    return answer;
}
