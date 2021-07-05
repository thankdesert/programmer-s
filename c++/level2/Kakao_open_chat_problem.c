/*
---------------------------------------------
Kakao_open_chat_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42888
solved by using map(unordered_map)
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<char, string>> inst_list;
    unordered_map<string,string> from_id_to_user;
    
    int i, j, id_index, nick_index, left, right, temp;
    char inst;
    for(i = 0; i<record.size(); i++) {
        if(record[i][0] == 'E') {
            left = 6;
            inst = 'E';
        }
        else if(record[i][0] == 'L') {
            left = 6;
            inst = 'L';
        }
        else if(record[i][0] == 'C') {
            left = 7;
            inst = 'C';
        }
        
        for(j = 0, right = left; record[i][right] != ' '; j++, right++);
        string s_id = record[i].substr(left, j);
        
        if(inst != 'L') {
            right++;
            string s_nick = record[i].substr(right, record[i].size() - right);
            from_id_to_user[s_id] = s_nick;
        }
        
        //명령어 로그
        inst_list.push_back(make_pair(inst, s_id));
    }
    
    for(i = 0, j = 0; i<inst_list.size(); i++) {
        if(inst_list[i].first == 'E') {
            answer.push_back(from_id_to_user[inst_list[i].second] + "님이 들어왔습니다.");
            j++;
        }
        else if(inst_list[i].first == 'L') {
            answer.push_back(from_id_to_user[inst_list[i].second] + "님이 나갔습니다.");
            j++;
        }
        else if(inst_list[i].first == 'C') {
            continue;
        }
    }
    
    return answer;
}
