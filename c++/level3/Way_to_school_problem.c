/*
---------------------------------------------
Way_to_school_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42898
solved by using a dynamic_programming
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<vector<int>> puddles) {
    int i, j, cnt = 0;
    vector<vector<pair<int, int>>> v(n); //distance, 방문 횟수
    for(i = 0; i<n; i++)
        for(j = 0; j<m; j++)
            v[i].push_back(make_pair(-2,0));
    for(i = 0; i<puddles.size(); i++)
        v[puddles[i][0]-1][puddles[i][1]-1].first = -1;
    v[0][0] = {0, 1};
    int flag;
    while(v[n-1][m-1].first == -2) {
        flag = 0;
        for(i = 0; i<n; i++) {
            for(j = 0; j<m; j++) {
                if(v[i][j].first == -1)
                    continue;
                if(v[i][j].first == cnt) {
                    flag = 1;
                    if(i+1 < n) {
                        if(v[i+1][j].first != -1) {
                            if(v[i+1][j].first == v[i][j].first + 1) {
                                v[i+1][j].second += v[i][j].second;
                                v[i+1][j].second %= 1000000007;
                            }
                            else if(v[i+1][j].first == -2) {
                                v[i+1][j].first = v[i][j].first + 1;
                                v[i+1][j].second += v[i][j].second;
                                v[i+1][j].second %= 1000000007;
                            }

                        }
                    }
                    if(j+1 < m) {
                        if(v[i][j+1].first != -1) {
                            if(v[i][j + 1].first == v[i][j].first + 1) {
                                v[i][j + 1].second += v[i][j].second;
                                v[i][j + 1].second %= 1000000007;
                            }
                            else if(v[i][j+1].first == -2) {
                                v[i][j+1].first = v[i][j].first + 1;
                                v[i][j+1].second += v[i][j].second;
                                v[i][j+1].second %= 1000000007;
                            }
                        }
                    }
                }
            }
        }
        cnt++;
        if(flag == 0)
            return 0;
    }
    
    return v[n-1][m-1].second%1000000007;
}
