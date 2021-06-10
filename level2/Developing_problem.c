/*
---------------------------------------------
Developing_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42586
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int* last = (int*)malloc(sizeof(int)*progresses.size());
    for(int i = 0; i<progresses.size(); i++) {
        last[i] = 100 - progresses[i];
        if(last[i] % speeds[i] == 0)
            last[i] = last[i]/speeds[i];
        else
            last[i] = last[i]/speeds[i] + 1;
    }
    
    for(int i = 0, cur = 0, result = 0; i<100 && cur < progresses.size(); i++, result = 0)
        if(last[cur] - i <= 0) {
            result++; cur++;
            for(;last[cur] - i <= 0 && cur < progresses.size(); cur++, result++);
            answer.push_back(result);       
        }
    return answer;
}
