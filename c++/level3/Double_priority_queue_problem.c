/*
---------------------------------------------
Double_priority_queue_problem.c
from : https://programmers.co.kr/learn/courses/30/lessons/42628
solved by using multiset.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    
    for(int i = 0; i<operations.size(); i++) {
        if(operations[i][0] == 'I')
            ms.insert(stoi(operations[i].substr(2, operations[i].size()-2)));
        else {
            if(ms.empty() == true)
                continue;
            if(operations[i][2] == '1')
                ms.erase(--ms.end());
            else
                ms.erase(ms.begin());
        }
    }
    
    if(ms.empty() == true)
        return {0, 0};
    else {
        multiset<int>::iterator iter = --ms.end();
        answer.push_back(*iter);
        iter = ms.begin();
        answer.push_back(*iter);
        return answer;
    }
}
