/*
---------------------------------------------
Kakao's_secret_map_problem
from : https://programmers.co.kr/learn/courses/30/lessons/17681
solved by shift operator.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i<n; i++) {
        string temp = "";
        for(int j = 0; j < n; j++, arr1[i] = arr1[i] >> 1, arr2[i] = arr2[i] >> 1) {
            if(((arr1[i] & 1) == (arr2[i] & 1)) && (arr1[i] & 1) == 0)
                temp.push_back(' ');
            else
                temp.push_back('#');
        }
        reverse(temp.begin(), temp.end());
        answer.push_back(temp);
    }
    return answer;
}
