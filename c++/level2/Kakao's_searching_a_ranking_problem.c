/*
---------------------------------------------
Kakao's_searching_a_ranking_problem
from : https://programmers.co.kr/learn/courses/30/lessons/72412
solved by using unordered_map & vector.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> score;
    
    int i, j, cur;
    char temp_jpc, temp_bf, temp_js, temp_pc;
    //info를 해석해 데이터 생성
    for(i = 0; i<info.size(); i++) {
        cur = 0;
        string line = "";
        switch(info[i][cur]) {
            case 'j':
                line.push_back('j');
                cur += 5;
                break;
            case 'p':
                line.push_back('p');
                cur += 7;
                break;
            case 'c':
                line.push_back('c');
                cur += 4;
                break;
        }
        
        switch(info[i][cur]) {
            case 'b':
                line.push_back('b');
                cur += 8;
                break;
            case 'f':
                line.push_back('f');
                cur += 9;
                break;
        }
        
        switch(info[i][cur]) {
            case 'j':
                line.push_back('j');
                break;
            case 's':
                line.push_back('s');
                break;
        }
        cur += 7;
        
        switch(info[i][cur]) {
            case 'p':
                line.push_back('p');
                cur += 6;
                break;
            case 'c':
                line.push_back('c');
                cur += 8;
                break;
        }
        
        string temp_score = "";
        for(; cur < info[i].size(); cur++)
            temp_score.push_back(info[i][cur]);
        int temp_i_score = stoi(temp_score);
        if(score.find(line) == score.end()) {
            score[line] = vector<int>();
        }
        score[line].push_back(temp_i_score);
    }
    
    for(auto it = score.begin(); it != score.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }
    
    char cjp[3] = {'c', 'j', 'p'};
    char bf[2] = {'b', 'f'};
    char js[2] = {'j', 's'};
    char cp[2] = {'c', 'p'};
    
    //query를 해석해 데이터 반환
    for(i = 0; i<query.size(); i++) {
        cur = 0;
        string line = "";
        switch(query[i][cur]) {
            case 'j':
                line.push_back('j');
                cur += 9;
                break;
            case 'p':
                line.push_back('p');
                cur += 11;
                break;
            case 'c':
                line.push_back('c');
                cur += 8;
                break;
            default:
                line.push_back('-');
                cur +=6;
        }
        
        switch(query[i][cur]) {
            case 'b':
                line.push_back('b');
                cur += 12;
                break;
            case 'f':
                line.push_back('f');
                cur += 13;
                break;
            default:
                line.push_back('-');
                cur +=6;
        }
        
        switch(query[i][cur]) {
            case 'j':
                line.push_back('j');
                cur += 11;
                break;
            case 's':
                line.push_back('s');
                cur += 11;
                break;
            default:
                line.push_back('-');
                cur +=6;
        }
        
        
        switch(query[i][cur]) {
            case 'p':
                line.push_back('p');
                cur += 6;
                break;
            case 'c':
                line.push_back('c');
                cur += 8;
                break;
            default:
                line.push_back('-');
                cur +=2;
        }
        
        string temp_score = "";
        for(; cur < query[i].size(); cur++)
            temp_score.push_back(query[i][cur]);
        int temp_i_score = stoi(temp_score);
        
        answer.push_back(0);
        string temp_line = "";
        int flag_cjp = 0, flag_bf = 0, flag_js = 0, flag_cp = 0;
        for(int k = 0; k<3 && flag_cjp != 1; k++) {
            if(line[0] != '-') {
                temp_line.push_back(line[0]);
                flag_cjp = 1;
            }                
            else {
                temp_line.push_back(cjp[k]);
            }
            for(int l = 0; l<2 && flag_bf != 1; l++) {
                if(line[1] != '-') {
                    temp_line.push_back(line[1]);
                    flag_bf = 1;
                }
                else {
                    temp_line.push_back(bf[l]);
                }
                for(int o = 0; o <2 && flag_js != 1; o++) {
                    if(line[2] != '-') {
                        temp_line.push_back(line[2]);
                        flag_js = 1;
                    }                        
                    else {
                        temp_line.push_back(js[o]);
                    }
                    for(int u = 0; u < 2 && flag_cp != 1; u++) {
                        if(line[3] != '-') {
                            temp_line.push_back(line[3]);
                            flag_cp = 1;
                        }                            
                        else {
                            temp_line.push_back(cp[u]);
                        }
                        if(score.find(temp_line) == score.end()) {
                            temp_line.pop_back();
                            continue;           
                        }                            
                        else {
                            
                            int v = lower_bound(score[temp_line].begin(), score[temp_line].end(), temp_i_score) - score[temp_line].begin();
                            if(v == 0 && score[temp_line][v] < temp_i_score) {
                                continue;
                            }
                            else {
                                answer.back() += score[temp_line].size() - v;
                            }
                        }
                        temp_line.pop_back();
                    }
                    flag_cp = 0;
                    temp_line.pop_back();
                }
                flag_js = 0;
                temp_line.pop_back();
            }
            flag_bf = 0;
            temp_line.pop_back();
        }
    }
    
    return answer;
}
