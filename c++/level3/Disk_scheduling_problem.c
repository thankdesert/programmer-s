/*
---------------------------------------------
Disk_scheduling_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42627
solved by using SJF(implemented by the priority_queue)
---------------------------------------------
*/

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
 
using namespace std;
 
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};
 
int solution(vector<vector<int>> jobs) {
    int answer = 0, cur = 0, cnt = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    while (cur < jobs.size() || pq.empty() != true) {
        if (jobs.size() > cur && cnt >= jobs[cur][0]) {
            pq.push(jobs[cur++]);
            continue;
        }
        
        if (pq.empty() != true) {
            cnt += pq.top()[1];
            answer += cnt - pq.top()[0];
            pq.pop();
        }
        else
            cnt = jobs[cur][0];
    }
    return answer / jobs.size();
}
