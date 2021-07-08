/*
---------------------------------------------
Kakao's_social_distancing_problem
from : https://programmers.co.kr/learn/courses/30/lessons/81302
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int i, j, k, flag;
    
    for(i = 0; i< places.size(); i++) {
        flag = 1;
        for(j = 0; j < 5 && flag == 1; j++) { //행
            for(k = 0; k < 5 && flag == 1; k++) { //열
                if(places[i][j][k] == 'P') {
                    for(int u = 1; u <= 2 && u + k < 5 && flag == 1; u++) { //right
                        if(places[i][j][k + u] == 'X')
                            break;
                        if(places[i][j][k + u] == 'P') {
                            answer.push_back(0);
                            flag = 0;
                            break;
                        }
                    }
                    for(int u = 1; u <= 2 && u + j < 5 && flag == 1; u++) { //bottom
                        if(places[i][j + u][k] == 'X')
                            break;
                        if(places[i][j + u][k] == 'P') {
                            answer.push_back(0);
                            flag = 0;
                            break;
                        }
                    }
                    if(j < 4 && k < 4 && flag == 1) { //right-bottom
                        if(places[i][j][k + 1] != 'X' || places[i][j + 1][k] != 'X') {
                            if(places[i][j+1][k+1] == 'P') {
                                answer.push_back(0);
                                flag = 0;
                                break;
                            }
                        }
                    }
                    if(j < 4 && k > 0 && flag == 1) { //left-bottom
                        if(places[i][j][k - 1] != 'X' || places[i][j + 1][k] != 'X') {
                            if(places[i][j+1][k - 1] == 'P') {
                                answer.push_back(0);
                                flag = 0;
                                break;
                            }
                        }
                    }
                    
                }
            }
        }
        if(flag == 1)
            answer.push_back(1);
    }
    return answer;
}
