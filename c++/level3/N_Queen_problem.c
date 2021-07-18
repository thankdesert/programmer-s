/*
---------------------------------------------
N_Queen_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12952
solved by using a Backtracking
---------------------------------------------
*/

#include <string>
#include <vector>

int cnt = 0;

using namespace std;

void f(int degree, int n, vector<int>& v) {
    if(degree == n) {
        cnt++;
        return;
    }
    for(int i = 0; i<n; i++) {
        int flag = 1;
        for(int j =0; j<degree; j++) {
            v[degree]=i;
            if(v[j]==v[degree]||((j-degree)==(v[j]-v[degree]))||((j-degree)==(v[degree]-v[j]))){
                flag = 0;
                break;
            }
        }
        if(flag == 1) {
            f(degree + 1, n, v);
        }
    }
}

int solution(int n) {
    vector<int> v(15, 0);
    for(int i = 0; i<n; i++) {
        v[0] = i;
        f(1, n, v);
    }
    return cnt;
}
