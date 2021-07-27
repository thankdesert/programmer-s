/*
---------------------------------------------
The_number_game_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12987
solved by using greedy_algorithm.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, i = 0, j = 0;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    
    while(true) {
        if(i == A.size() || j == B.size())
            break;
        if(A[i] < B[j]) {
            i++; j++;
            answer++;
        }
        else
            i++;
    }
    
    return answer;
}
