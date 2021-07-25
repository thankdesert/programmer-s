/*
---------------------------------------------
Making_all_node's_keys_to_zero_problem.c
from : https://programmers.co.kr/learn/courses/30/lessons/76503
solved by using dfs.
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

long long answer = 0;

void DFS(vector<vector<int>>& adj_list, vector<long long>& sum, int cur, int parent) {  
    for (int i = 0; i < adj_list[cur].size(); i++)
        if (adj_list[cur][i] != parent)
            DFS(adj_list, sum, adj_list[cur][i], cur);
    
    sum[parent] += sum[cur];
    answer += abs(sum[cur]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    vector<long long> sum(a.size());
    for (int i = 0; i < a.size(); ++i)
        sum[i] = a[i];
    
    vector<vector<int>> adj_list(a.size());
    for (int i = 0; i < edges.size(); i++) {
        adj_list[edges[i][0]].push_back(edges[i][1]);
        adj_list[edges[i][1]].push_back(edges[i][0]);
    }
    
    DFS(adj_list, sum, 0, 0);
    
    if (sum[0] == 0)
        return answer;
    else
        return - 1;
}
