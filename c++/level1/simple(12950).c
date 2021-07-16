/*
---------------------------------------------
simple(12950)
from : https://programmers.co.kr/learn/courses/30/lessons/12950
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int i, j;
    for(i = 0; i<arr1.size(); i++) {
        vector<int> v;
        answer.push_back(v);
        for(j = 0; j<arr1[0].size(); j++)
            answer[i].push_back(arr1[i][j] + arr2[i][j]);
    }
    return answer;
}
