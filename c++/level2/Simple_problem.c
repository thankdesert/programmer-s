/*
---------------------------------------------
Simple_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12953
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> arr) {
    long long answer = 0;
    sort(arr.rbegin(), arr.rend());
    int i, k = 0;
    while(true) {
        k += arr[0];
        for(i = 1; i<arr.size(); i++) {
            if(k % arr[i] != 0)
                break;
            if(i == arr.size() - 1)
                return k;
        }        
    }
}
