/*
---------------------------------------------
Converting_a_word_problem
from : https://programmers.co.kr/learn/courses/30/lessons/43163
solved by using a BFS(implemented by using unordered_map & queue)
---------------------------------------------
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> orin) {
    int i, j, k, cnt, answer = 0;
    vector<int> visit;
    unordered_map<string, int> um;
    vector<string> words;
    words.push_back(begin);
    int adj_mtx[50][50] = {0, };
    for(i = 0; i<orin.size(); i++)
        words.push_back(orin[i]);    
    
    for(i = 0; i<words.size(); i++) {
        um.insert(make_pair(words[i], i));
        visit.push_back(0);
    }
    
    for(i = 0; i<words.size(); i++) {
        for(j = i + 1; j<words.size(); j++) {
            cnt = 0;
            for(k = 0; k<words[i].size(); k++) {
                if(words[i][k] != words[j][k])
                    cnt++;
                if(cnt >= 2)
                    break;
            }
            if(cnt <= 1) {
                int l = um[words[i]];
                int r = um[words[j]];
                adj_mtx[l][r] = 1;
                adj_mtx[r][l] = 1;
            }
        }
    }
    
    cnt = 0;
    queue<pair<string, int>> q;
    q.push(make_pair(begin, cnt));
    while(q.empty() == false) {
        string line = q.front().first;
        int cur_index = um[line];
        cnt = q.front().second;
        q.pop();
        if(line.compare(target) == 0)
            return cnt;
        for(i = 0; i<words.size(); i++) {
            if(adj_mtx[cur_index][um[words[i]]] == 1) {
                if(visit[um[words[i]]] == 1)
                    continue;
                visit[um[words[i]]] = 1;
                q.push(make_pair(words[i], cnt + 1));
            }
        }
    }
    
    return 0;
}
