/*
---------------------------------------------
Kakao's_n-numeric_method_problem.c
from : https://programmers.co.kr/learn/courses/30/lessons/17687
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char number[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string solution(int n, int t, int m, int p) {
    string answer = "", temp = "", line = "0";
    int i, j, tmp = 1;
    for(i = 1; i <= m*t; tmp = ++i, temp = "") {
        for(; tmp > 0; tmp /= n) {
            if(tmp % n == 0)
                temp.push_back('0');
            else
                temp.push_back(number[tmp%n]);
        }
        reverse(temp.begin(), temp.end());
        line.append(temp);
    }
    
    for(i = 0, j = p-1; i<t; i++, j+=m)
        answer.push_back(line[j]);
    
    return answer;
}
