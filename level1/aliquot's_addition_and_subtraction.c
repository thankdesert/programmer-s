/*
---------------------------------------------
aliquot's_addition_and_subtraction
from : https://programmers.co.kr/learn/courses/30/lessons/77884
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0, i, j;
    vector<int> v;
    for(i = 1; i<= right; i++)
        v.push_back(0);
    
    for(i = 1; i<= right; i++) {
        for(j = 1; j<=right; j++) {
            if(i*j <= right)
                v[i*j]++;
            else
                break;
        }
    }
    
    for(i = left; i <= right; i++) {
        if(v[i] % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    
    return answer;
}
