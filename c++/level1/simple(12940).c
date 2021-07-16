/*
---------------------------------------------
simple(12940)
from : https://programmers.co.kr/learn/courses/30/lessons/12940
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int l = n, r = m, temp;
    if(n > m) {
        l = m;
        r = n;
    }
    
    if(r%l == 0) {
        answer.push_back(l);
        answer.push_back(r);
        return answer;
    }        
    
    for(int k = 1; k <= l; k++) {
        if(l%k == 0 && r%k ==0)
            temp = k;
    }
    answer.push_back(temp);
    answer.push_back(l*r/temp);
    
    return answer;
}
