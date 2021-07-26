/*
---------------------------------------------
Line_up_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12936
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

void func(int n, long long k, vector<int>& answer, vector<int>& v, vector<long long>& facto) {
    int i, idx, cnt;
    if(n == 1) {
        for(i = 0; v[i] == 1 && i < v.size(); i++);
        answer.push_back(i + 1);
        return;
    }
    
    idx = (k-1)/facto[n-1];
    for(i = 0, cnt = 0; i<v.size(); i++) {
        if(v[i] == 1)
            continue;
        if(cnt == idx) {
            answer.push_back(i + 1);
            v[i] = 1;
            break;
        }
        cnt++;
    }
    func(n-1, k - idx*facto[n-1], answer, v, facto);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v(n, 0);
    vector<long long> facto(21, 1);
    
    for(int i = 1; i<= 20; i++)
        facto[i] = facto[i-1]*i;
    
    func(n, k, answer, v, facto);
    return answer;
}
