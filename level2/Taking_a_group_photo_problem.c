/*
---------------------------------------------
Taking_a_group_photo_problem
from : https://programmers.co.kr/learn/courses/30/lessons/1835
solved by using permutation(implemented by for_loop).
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int check(int n, vector<string> data, vector<char> line) {
    char left, right, cond, dist;
    int l, r;
    for(int i = 0; i<n; i++) {
        left = data[i][0];
        right = data[i][2];
        cond = data[i][3];
        dist = data[i][4];
        
        for(int j = 0; j<8; j++) {
            if(line[j] == left)
                l = j;
            else if(line[j] == right)
                r = j;
        }
        
        if(cond == '<') {
            if(abs(l - r) - 1 >= dist - '0') {
                return -1;
            }
        }
        else if(cond == '=') {
            if(abs(l - r) - 1 != dist - '0') {
                return -1;
            }
        }
        else if(cond == '>') {
            if(abs(l - r) - 1 <= dist - '0') {
                return -1;
            }
        }
    }
    return 1;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    int visit[8] = {0,};
    char f[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<char> line;
    
    for(int i = 0; i<8; i++) {
        visit[i] = 1; //0
        line.push_back(f[i]);
        for(int j = 0; j<8; j++) {
            if(visit[j] == 1)
                continue;
            visit[j] = 1; //1
            line.push_back(f[j]);
            for(int k = 0; k<8; k++) {
                if(visit[k] == 1)
                    continue;
                visit[k] = 1; //2
                line.push_back(f[k]);
                for(int v = 0; v<8; v++) {
                    if(visit[v] == 1)
                        continue;
                    visit[v] = 1; //3
                    line.push_back(f[v]);
                    for(int l = 0; l<8; l++) {
                        if(visit[l] == 1)
                            continue;
                        visit[l] = 1; //4
                        line.push_back(f[l]);
                        for(int r = 0; r<8; r++) {
                            if(visit[r] == 1)
                                continue;
                            visit[r] = 1; //5
                            line.push_back(f[r]);
                            for(int x = 0; x<8; x++) {
                                if(visit[x] == 1)
                                    continue;
                                visit[x] = 1; //6
                                line.push_back(f[x]);
                                for(int y = 0; y<8; y++) {
                                    if(visit[y] == 1)
                                        continue;
                                    visit[y] = 1; //7
                                    line.push_back(f[y]);
                                    if(check(n, data, line) == 1)
                                        answer++;
                                    visit[y] = 0;
                                    line.pop_back();
                                }
                                visit[x] = 0;
                                line.pop_back();                                
                            }
                            visit[r] = 0;
                            line.pop_back();                            
                        }
                        visit[l] = 0;
                        line.pop_back();                                
                    }
                    visit[v] = 0;
                    line.pop_back();                    
                }
                visit[k] = 0;
                line.pop_back();                   
            }
            visit[j] = 0;
            line.pop_back();               
        }
        visit[i] = 0;
        line.pop_back();           
    }
    
    return answer;
}
