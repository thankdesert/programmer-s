  
/*
---------------------------------------------
Su-Bak_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12922
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "", line = "수박";
    for(int i = 0; i < n/2; i++)
        answer.append(line);
    if(n % 2 != 0)
        answer.append("수");
    return answer;
}
