/*
---------------------------------------------
Finding_all_prime_number
from : https://programmers.co.kr/learn/courses/30/lessons/12921
solved by the Sieve_of_Eratosthenes;
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int cnt = 0, i, j;
    int visit[1000001] = {0};
    for(i = 2; i <= n; i++) {
        if(visit[i] == 0) {
            cnt++;
            visit[i] = 1;
            for(j = i; j<=n; j+= i)
                visit[j] = 1;
        }
    }
    return cnt;
}
