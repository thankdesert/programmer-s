/*
---------------------------------------------
simple(12934)
from : https://programmers.co.kr/learn/courses/30/lessons/12934
---------------------------------------------
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {    
    return powl(sqrt(n), 2) == n ? pow(sqrt(n) + 1, 2) : -1;
}
