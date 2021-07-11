/*
---------------------------------------------
Kakao's_Korean_Thanksgiving_Day_problem.c
from : https://programmers.co.kr/learn/courses/30/lessons/17676
---------------------------------------------
*/


#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int i, j, start_time, end_time, during, limit, cnt, max = -1;
    vector<pair<int, int>> v; //start_time, end_time
    string temp;
    for(i = 0; i<lines.size(); i++) {
        temp = "";
        end_time = stoi(lines[i].substr(11, 2))*3600*1000 + stoi(lines[i].substr(14, 2))*60*1000 +
            stoi(lines[i].substr(17, 2))*1000 + stoi(lines[i].substr(20, 3));
        if(lines[i].size() > 26) {
            for(j = 26; lines[i][j] != 's'; j++)
                temp.push_back(lines[i][j]);
            during = (lines[i][24] - '0')*1000 + stoi(temp);
        }
        else
            during = (lines[i][24] - '0')*1000;        
        start_time = end_time - during + 1;
        v.push_back(make_pair(start_time, end_time));
    }
    
    for(i = 0; i<v.size(); i++) {
        cnt = 1;
        limit = v[i].second + 999;
        for(j = i + 1; j<v.size(); j++) {
            if(v[j].first <= limit)
                cnt++;                
        }
        if(cnt > max)
            max = cnt;
    }
    return max;
}
