/*
---------------------------------------------
Kakao's_tuple_problem
from : https://programmers.co.kr/learn/courses/30/lessons/64065
solved by using vector.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<string> tuple;
    int i, j, flag = 0;
    string temp;
    for(i = 0; i<s.size(); i++) {
        if(i != 0 && s[i] == '{') {
            temp = "{";
            flag = 1;
            continue;
        }
        if(flag == 1) {
            temp.push_back(s[i]);
            if(s[i] == '}') {
                flag = 0;
                tuple.push_back(temp);
            }
        }
    }
    
    for(i =0; i<tuple.size(); i++) {
        for(j = i; j<tuple.size(); j++) {
            if(tuple[i].size() > tuple[j].size()) {
                temp = tuple[i];
                tuple[i] = tuple[j];
                tuple[j] = temp;
            }
        }
    }
    
    for(i = 0; i < tuple.size(); i++) {
        temp = "";
        tuple[i].erase(0,1);
        do {
            if(tuple[i][0] != ',' && tuple[i][0] != '}')
                temp.push_back(tuple[i][0]);
            else {
                if(answer.size() != 0) {
                    auto it = find(answer.begin(), answer.end(), stoi(temp));
                    if(it == answer.end())
                        answer.push_back(stoi(temp));     
                }
                else
                    answer.push_back(stoi(temp));
                temp = "";
            }
            if(tuple[i][0] == '}')
                break;
            tuple[i].erase(0,1);
        }while(1);
    }
    return answer;
}
