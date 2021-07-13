/*
---------------------------------------------
The_unmanned_camera_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42884
solved by using a greedy algorithm.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int i, j, cnt = 1;
    sort(routes.begin(), routes.end());
    
    for(i = 0; i < routes.size() - 1; i++) {
        for(j = i + 1; j<routes.size(); j++) {
            if(routes[j][0] > routes[i][1]) {
                cnt++;
                i = j - 1;
                break;
            }
        }
    }    
    return cnt;
}
