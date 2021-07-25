/*
---------------------------------------------
The_night_overtime_index_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12927
solved by using a greedy algorithm.
---------------------------------------------
*/


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int i, j = 0, max;
    sort(works.rbegin(), works.rend());
    while(j < n) {
        max = works[0];
        if(max == 0)
            break;
        for(i = 0; i<works.size() && works[i] == max && works[i] != 0 && j < n; works[i++] -= 1, j++);
    }
    
    for(auto item : works)
        answer += (item*item);
    return answer;
}
