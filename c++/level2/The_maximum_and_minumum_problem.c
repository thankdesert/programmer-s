/*
---------------------------------------------
The_maximum_and_minumum_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12939
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string temp = "";
    vector<int> v;
    for(int i = 0; i<s.size(); i++) {
        if(s[i] == ' ') {
            v.push_back(stoi(temp));
            temp = "";
        }
        temp.push_back(s[i]);
    }
    v.push_back(stoi(temp));
    sort(v.begin(), v.end());
    temp = "";
    temp.append(to_string(v[0]) + ' ' + to_string(v[v.size()-1]));
    return temp;
}
