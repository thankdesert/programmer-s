/*
---------------------------------------------
Reversing_a_natural_numbers_and_creating_an_array
from : https://programmers.co.kr/learn/courses/30/lessons/12932
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string line = to_string(n);
    string::iterator iter = line.end() - 1;
    for(;iter >= line.begin(); iter--)
        answer.push_back(*iter - '0');
    
    return answer;
}
