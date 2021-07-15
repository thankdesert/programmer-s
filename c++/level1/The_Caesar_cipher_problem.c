/*
---------------------------------------------
The_Caesar_cipher_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12926
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i = 0; i<s.size(); i++) {
        char c = s[i];
        if(c == ' ')
            continue;
        if(c>='A' && c<='Z') {
            c += n;
            c -= 'A';            
            c %= 26;
            s[i] = 'A' + c;
        }
        else {
            c += n;
            c -= 'a';
            c %= 26;
            s[i] = 'a' + c;
        }
    }
    return s;
}
