/*
---------------------------------------------
The_best_album_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42579
solved by using a unordered_map
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> um_g_cnt;
    unordered_map<string, pair<int, int>> um_g_s;
    int i, j, tmp;
    
    for(i = 0; i<plays.size(); i++) {
        if(um_g_cnt.find(genres[i]) == um_g_cnt.end()) {
            um_g_cnt.insert(make_pair(genres[i], 0));
            um_g_s.insert(make_pair(genres[i], make_pair(-1, -1)));
        }
        um_g_cnt[genres[i]] += plays[i];
        
        if(um_g_s[genres[i]].first == -1) {
            um_g_s[genres[i]].first = i;
            continue;
        }            
        else if(um_g_s[genres[i]].second == -1) {
            if(plays[i] > plays[um_g_s[genres[i]].first]) {
                tmp = um_g_s[genres[i]].first;
                um_g_s[genres[i]].first = i;
                um_g_s[genres[i]].second = tmp;
            }
            else
                um_g_s[genres[i]].second = i;
            continue;
        }
        
        tmp = i;
        if(plays[i] > plays[um_g_s[genres[i]].first]) {
            tmp = um_g_s[genres[i]].first;
            um_g_s[genres[i]].first = i;
        }            
        if(plays[tmp] > plays[um_g_s[genres[i]].second])
            um_g_s[genres[i]].second = tmp;
    }
    
    vector<pair<int, string>> temp;
    for(auto item : um_g_cnt)
        temp.push_back(make_pair(item.second, item.first));
    sort(temp.rbegin(), temp.rend());
    
    for(i = 0; i<temp.size(); i++) {
        if(um_g_s[temp[i].second].first > -1)
            answer.push_back(um_g_s[temp[i].second].first);
        if(um_g_s[temp[i].second].second > -1)
            answer.push_back(um_g_s[temp[i].second].second);
    }
    
    return answer;
}
