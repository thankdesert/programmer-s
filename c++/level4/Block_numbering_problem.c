/*
---------------------------------------------
Block_numbering_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12923
---------------------------------------------
*/


#include <string>
#include <vector>
#include <cmath>

using namespace std;

int check(int n){
    int num = sqrt(n);
    for(int i = 2; i <= num; i++)
        if(n % i == 0 && n / i <= 10000000)
            return n / i;
    return 1;
}

vector<int> solution(long long begin, long long end) { 
    vector<int> answer;
    
    for(int i = begin; i <= end; i++)
        answer.emplace_back(check(i));
    
    if(begin == 1)
        answer[0] = 0;
    return answer;
}
