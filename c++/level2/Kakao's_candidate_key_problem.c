/*
---------------------------------------------
Kakao's_candidate_key_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42890#
solved by using a subset(implemented by a combination).
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<string> cands;
    vector<string> temp_keys;
    vector<int> it;
    
    int i, j, k, col_size = relation[0].size(), row_size = relation.size();
    
    for(i = 0; i<row_size; i++)
        for(j = 0; j<col_size; j++) {
            relation[i][j].push_back(j + 'A');
        }
    for(i = 0; i<col_size; i++) {
        it.clear();
        for(j = 0; j<i+1; j++)
            it.push_back(1);
        for(j = 0; j<col_size - i - 1; j++)
            it.push_back(0);
        
        do {
            for(k = 0; k<row_size; k++) {
                string line = "";
                for(j = 0; j<col_size; j++) {
                    if(it[j] == 1)
                        line.append(relation[k][j]);
                }
                temp_keys.push_back(line);
                line.clear();
            }
            
            int flag = 1;
            for(j = 0; j< temp_keys.size(); j++) {
                if(find(temp_keys.begin() + j + 1, temp_keys.end(), temp_keys[j]) != temp_keys.end()) {
                    flag = 0;
                    break;
                }
            }
            
            string temp, sub;
            if(flag == 1) {
                sub = "";
                vector<int> temp_it;
                for(j = 0; j<it.size(); j++) {
                    if(it[j] == 1)
                        sub.push_back(j + 'A');
                }
                for(j = 0; j < cands.size() && flag != 0; j++) {
                    temp_it.clear();
                    for(k = 0; k < cands[j].size(); k++) 
                        temp_it.push_back(1);
                    for(k = 0; k < sub.size() - cands[j].size(); k++)
                        temp_it.push_back(0);
                    
                    do{
                        temp = "";
                        for(k = 0; k < temp_it.size(); k++) {
                            if(temp_it[k] == 1)
                                temp.push_back(sub[k]);
                        }
                        
                        if(temp.compare(cands[j]) == 0) {
                            flag = 0;
                            break;
                        }
                    }while(prev_permutation(temp_it.begin(), temp_it.end()));    
                }
                
                if(flag == 1) {
                    cands.push_back(sub);
                    answer++;
                }
            }
            temp_keys.clear();
        }while(prev_permutation(it.begin(), it.end()));
    }
    
    for(i = 0; i <cands.size(); i++)
        printf("%s ", cands[i].c_str());
    
    return answer;
}
