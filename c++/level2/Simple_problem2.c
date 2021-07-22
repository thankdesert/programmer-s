/*
---------------------------------------------
Simple_problem2
from : https://programmers.co.kr/learn/courses/30/lessons/12941
---------------------------------------------
*/

#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, i;
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    for(i = 0; i<A.size(); i++)
        answer += A[i]*B[i];

    return answer;
}
