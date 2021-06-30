/*
---------------------------------------------
H_index_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42747
solved by using sort.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int i, j, l_count, r_count, max = 0;
    for(i = 0; i<= citations.size(); i++) {
        l_count = 0, r_count = 0;
        for(j = 0; j<citations.size(); j++) {
            if(citations[j] < i)
                l_count++;
            else
                r_count++;
        }
        if(r_count >= i && l_count<= i)
            max = i;
        else
            break;
    }
    return max;
}
