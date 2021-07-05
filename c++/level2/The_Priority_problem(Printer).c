/*
---------------------------------------------
The_Priority_problem(Printer)
from : https://programmers.co.kr/learn/courses/30/lessons/42587
solved by using queue(implemented by vector).
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, flag = 0;
    vector <pair<int, int>> v;
    
    for(int i = 0; i<priorities.size(); i++)
        v.push_back(make_pair(i, priorities[i]));
    
    for(;;flag = 0) {
        if(v.size() == 1)
            return ++answer;
        for(int i = 1; i<v.size(); i++) {
            if(v[0].second < v[i].second) {
                v.push_back(v[0]);
                v.erase(v.begin());
                flag = 1;
                break;
            }
        }
        
        if(flag == 1)
            continue;
        
        if(v[0].first == location)
            return ++answer;
        else {
            answer++;
            v.erase(v.begin());
        }
    }
}
