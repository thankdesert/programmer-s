/*
---------------------------------------------
The_immigration_problem
from : https://programmers.co.kr/learn/courses/30/lessons/43238
solved by using a binary search.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    unsigned long long answer = 0, i, min_p = times[0], max_p = times[times.size() - 1], cnt, left = 1, right = times[times.size() - 1] * n, mid;
    sort(times.begin(), times.end());
    while(left <= right) {
        cnt = 0;
        mid = (left + right)/2;
        for(i = 0; i<times.size(); i++)
            cnt += mid/times[i];
        
        if(cnt < n)
            left = mid + 1;
        else {
            if(mid <= right)
                answer = mid;
            right = mid - 1;
        }
    }
    return answer;
}
