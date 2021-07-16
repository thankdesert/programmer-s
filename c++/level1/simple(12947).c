/*
---------------------------------------------
simple(12947)
from : https://programmers.co.kr/learn/courses/30/lessons/12947
---------------------------------------------
*/


#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0, k = x;
    while(true) {
        sum += (k % 10);
        if(k / 10 == 0)
            break;
        k /= 10;
    }
    if(x % sum == 0)
        return true;
    else
        return false;
}
