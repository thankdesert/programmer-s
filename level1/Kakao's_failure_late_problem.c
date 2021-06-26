/*
---------------------------------------------
Kakao's_failure_late_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42889#
solved by using vector.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<double> fail;
    int tr[501] = {0,};
    int i, j, max_index, people = stages.size();
    
    for(i = 0; i < stages.size(); i++)
        tr[stages[i]]++;
    
    for(i = 1; i<= N; i++) {
        if(people > 0) {
            fail.push_back((double)tr[i] / (double)people);
            people -= tr[i];    
        }
        else
            fail.push_back(0);        
    }
    
    for(i = 0; i< N; i++) {
        max_index = max_element(fail.begin(), fail.end()) - fail.begin();
        answer.push_back(max_index + 1);
        fail[max_index] = -1;
    }
    
    return answer;
}
