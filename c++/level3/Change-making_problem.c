/*
---------------------------------------------
Change-making_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12907
solved by using a dynamic_programming
---------------------------------------------
*/

#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int dp[100001] = {0,};
    dp[0] = 1;
    
    for(auto item : money)
        for(int i = item; i <= n; ++i)
            dp[i] = (dp[i] + dp[i - item]) % 1000000007;
    
    return dp[n];
}
