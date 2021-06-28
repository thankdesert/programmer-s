/*
---------------------------------------------
A_truck_passing_through_a_bridge_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42583
solved by using queue.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, b_w = 0, i;
    queue<pair<int, int>> q; //weight, entering_timing
    queue<int> t;
    
    for(i = 0; i<truck_weights.size(); i++)
        t.push(truck_weights[i]);
        
    do {
        answer++;
        if(answer - q.front().second == bridge_length) {
            b_w -= q.front().first;
            q.pop();
        }
        
        if(t.empty() != 1 && b_w + t.front() <= weight) {
            b_w += t.front();
            q.push(make_pair(t.front(), answer));
            t.pop();
        }
    }
    while(q.empty() != 1);
    return answer;
}
