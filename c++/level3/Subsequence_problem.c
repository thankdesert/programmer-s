/*
---------------------------------------------
Subsequence_problem
from : https://programmers.co.kr/learn/courses/30/lessons/70130?language=cpp
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = -1, i, j, result;
    vector<int> v(a.size() + 1, 0);
    
    for(auto item : a)
        v[item]++;
    
    for(i = 0; i<v.size(); i++) {
        if(v[i] <= answer || v[i] == 0)
            continue;
        result = 0;
        
        for (j = 0; j < a.size() - 1; j++) {
            if (a[j] != i && a[j + 1] != i)
                continue;
            if (a[j] == a[j + 1])
                continue;
            result++;
            j++;
        }
        answer = max(answer, result);
        
    }
    
    return answer * 2;
}
