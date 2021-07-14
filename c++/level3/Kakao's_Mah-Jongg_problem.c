/*
---------------------------------------------
Kakao's_Mah-Jongg_problem
from : https://programmers.co.kr/learn/courses/30/lessons/1836
solved by using a_ordered_map
---------------------------------------------
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
string solution(int m, int n, vector<string> board) {
    string answer = "";
    int i, j;
    unordered_map<char, vector<pair<int, int>>> um;
    vector<char> alp;
    vector<int> visit;
    
    for(i = 0; i<board.size(); i++) {
        for(j = 0; j<board[0].size(); j++) {
            if(board[i][j] == '*' || board[i][j] == '.')
                continue;
            if(um.find(board[i][j]) == um.end())
                alp.push_back(board[i][j]);
            um[board[i][j]].push_back(make_pair(i, j));
        }        
    }
    sort(alp.begin(), alp.end());
    for(i = 0; i<um.size(); i++)
        visit.push_back(0);
    
    int cur_r, cur_c, target_r, target_c, f = alp.size(), prev_f = f;
    while(f > 0) {
        for(i = 0; i<alp.size(); i++) {
            if(visit[i] == 1)
                continue;
            prev_f = f;
            cur_r = um[alp[i]][0].first;
            cur_c = um[alp[i]][0].second;
            target_r = um[alp[i]][1].first;
            target_c = um[alp[i]][1].second;
            
            if(cur_r == target_r) {
                for(j = cur_c; j < target_c; j++) {
                    if(board[cur_r][j] != '.' && board[cur_r][j] != alp[i])
                        break;
                }
                if(j == target_c) {
                    f--;
                    break;
                }                    
            }
            else {
                for(j = cur_r; j < target_r; j++) {
                    if(board[j][cur_c] != '.' && board[j][cur_c] != alp[i])
                        break;                    
                }
                if(j == target_r) {
                    if(cur_c < target_c) {
                        for(j = cur_c; j < target_c; j++) {
                            if(board[target_r][j] != '.' && board[target_r][j] != alp[i])
                                break;
                        }
                    }
                    else if(cur_c == target_c) {
                        j = target_c;
                    }
                    else {
                        for(j = cur_c; j > target_c; j--) {
                            if(board[target_r][j] != '.' && board[target_r][j] != alp[i])
                                break;
                        }
                    }
                    if(j == target_c) {
                        f--;
                        break;
                    }
                }
                
                if(prev_f == f) {
                    if(cur_c < target_c) {
                        for(j = cur_c; j < target_c; j++) {
                            if(board[cur_r][j] != '.' && board[cur_r][j] != alp[i])
                                break;
                        }
                        if(j == target_c) {
                            for(j = cur_r; j < target_r; j++) {
                                if(board[j][target_c] != '.' && board[j][target_c] != alp[i])
                                    break;
                            }
                            if(j == target_r) {
                                f--;
                                break;
                            }
                        }
                    }
                    else if(cur_c == target_c) {
                        for(j = cur_r; j < target_r; j++) {
                            if(board[j][cur_c] != '.' && board[j][cur_c] != alp[i])
                                break;
                        }
                        if(j == target_r) {
                            f--;
                            break;
                        }
                    }
                    else {
                        for(j = cur_c; j > target_c; j--) {
                            if(board[cur_r][j] != '.' && board[cur_r][j] != alp[i])
                                break;
                        }
                        if(j == target_c) {
                            for(j = cur_r; j<target_r; j++) {
                                if(board[j][target_c] != '.' && board[j][target_c] != alp[i])
                                    break;
                            }
                            if(j == target_r) {
                                f--;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(prev_f != f) {
            answer.push_back(alp[i]);
            visit[i] = 1;
            board[cur_r][cur_c] = '.';
            board[target_r][target_c] = '.';
        }
        else
            break;
    }
    if(answer.size() == 0 || f > 0)
        answer = "IMPOSSIBLE";
    return answer;
}
