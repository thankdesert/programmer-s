/*
---------------------------------------------
The_Largest_number_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42883
solved by the greedy algorithm(implemented by recursive)
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

vector<int> v;
vector<int> v_true;

void find(int index, int right, int length) {
    if(length == 0)
        return;
    
    int i;
    for(i = index; i < right; i++) {
        if(v[i] > v[index]) {
            if(right - i >= length) {
                find(i, right, length);
                return;
            }
            else {
                find(index, i, length - (right - i));
                find(i, right, (right - i));
                return;
            }
        }
    }
    v_true[index] = 1;
    find(index + 1, right, length - 1);
    return;
}



string solution(string number, int k) {
    string answer = "";
    int i;
    for(i = 0; i<number.size(); i++) {
        v.push_back(number[i] - '0');
        v_true.push_back(0);
    }
    
    find(0, number.size(), number.size() - k);
    
    for(i = 0; i<v_true.size(); i++)
        if(v_true[i] == 1)
            answer.push_back(v[i] + '0');
    
    return answer;
}
