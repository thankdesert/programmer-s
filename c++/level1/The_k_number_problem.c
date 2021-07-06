  
/*
---------------------------------------------
The_k_number_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42748
---------------------------------------------
*/


#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> temp;
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++) {
        temp.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
        sort(temp.begin(), temp.end());
        answer.push_back(temp[commands[i][2] - 1]);
    }
    
    return answer;
}
