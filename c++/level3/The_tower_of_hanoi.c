/*
---------------------------------------------
The_tower_of_hanoi
from : https://programmers.co.kr/learn/courses/30/lessons/12946
---------------------------------------------
*/


#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int start, int to, int via, vector<vector<int>>& answer) {
    if(n == 1) {
        answer.push_back({start, to});
        return;
    }
    hanoi(n-1, start, via, to, answer);
    answer.push_back({start, to});
    hanoi(n-1, via, to, start, answer);
}
    

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 3, 2, answer);
    return answer;
}
