/*
---------------------------------------------
The_number_of_furthest_nodes_problem.c
from : https://programmers.co.kr/learn/courses/30/lessons/49189
solved by using a bfs(implemeted by using queue & adjacency_list)
---------------------------------------------
*/


#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node* pnode;
typedef struct node {
    int key;
    pnode next;
}_node;

pnode* adj_list;

void insert(int from, pnode item) {
    if(adj_list[from] == NULL) {
        adj_list[from] = item;
        return;
    }
    
    pnode cur = adj_list[from];
    while(cur->next != NULL)
        cur = cur->next;
    cur->next = item;
}

int solution(int n, vector<vector<int>> edge) {
    int i, j, answer = 0;
    
    adj_list = (pnode*)malloc(sizeof(pnode)*(n+1));
    for(i = 1; i<=n; i++)
        adj_list[i] = NULL;
    
    //insert all edges to the adjacency list
    for(i = 0; i<edge.size(); i++) {
        node* temp = (node*)malloc(sizeof(node));
        temp->key = edge[i][1];
        temp->next = NULL;
        insert(edge[i][0], temp);
        node* temp2 = (node*)malloc(sizeof(node));
        temp2->key = edge[i][0];
        temp2->next = NULL;
        insert(edge[i][1], temp2);
    }
    
    vector<int> visit(20001, 0); //array for checking a target node was visited before
    queue<pair<int, int>> q; //queue for bfs
    q.push(make_pair(1, 0)); visit[1] = 1;
    pnode cur;
    do {
        cur = adj_list[q.front().first];
        while(cur != NULL) {
            if(visit[cur->key] == 0) {
                q.push(make_pair(cur->key, q.front().second + 1));
                visit[cur->key] = q.front().second + 1;
            }
            cur = cur->next;
        }
        q.pop();
    }while(q.empty() != true);
    
    sort(visit.rbegin(), visit.rend());
    
    for(i = 0; i<visit.size() && visit[i] == visit[0]; i++);
    
    return i;
}
