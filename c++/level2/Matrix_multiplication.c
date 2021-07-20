/*
---------------------------------------------
Matrix_multiplication
from : https://programmers.co.kr/learn/courses/30/lessons/12949
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size());
    int i, j, k, sum;
    
    for(i = 0; i<arr1.size(); i++) {
        for(j = 0; j<arr2[0].size(); j++) {
            sum = 0;
            for(k = 0; k<arr2.size(); k++) {
                sum += arr1[i][k]*arr2[k][j];
            }
            answer[i].push_back(sum);
        }
    }
    return answer;
}
