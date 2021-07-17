/*
---------------------------------------------
Travel_route_problem
from : https://programmers.co.kr/learn/courses/30/lessons/43164
solved by using a Backtracking(implemented by using dfs)
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num = 0;
void dfs(string start, vector<vector<string>>& tickets, vector<int>& visit, vector<string>& answer, vector<string>& temp, int cnt) {
    temp.push_back(start);
    
    if(cnt > num) {
        num = cnt;
        answer = temp;
    }
    
    for(int i = 0; i<tickets.size(); i++) {
        if(tickets[i][0].compare(start) == 0 && visit[i] == 0) {
            visit[i] = 1;
            dfs(tickets[i][1], tickets, visit, answer, temp, cnt + 1);
            visit[i] = 0;
        }
    }
    temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, temp;
    sort(tickets.begin(), tickets.end());
    vector<int> visit(tickets.size(), 0);
    for(int i = 0; i<tickets.size(); i++)
    
    dfs("ICN", tickets, visit, answer, temp, 0);
    return answer;
}
