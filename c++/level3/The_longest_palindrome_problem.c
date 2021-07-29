/*
---------------------------------------------
The_longest_palindrome_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12904
solved by a dynamic_programming.
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer=1, cnt, i, j;
    vector<pair<int, int>> v; //center_index, is_odd
    
    for(i = 0; i<s.size(); i++) {
        if(s[i] == s[i+1])
            v.push_back(make_pair(i, 0));
        if((i>0 && i<s.size()-1) && s[i-1] == s[i+1])
            v.push_back(make_pair(i, 1));
    }
    
    for(auto item : v) {
        if(item.second == 0) {
            cnt = 2;
            i = item.first - 1;
            j = item.first + 2;
        }            
        else {
            cnt = 1;
            i = item.first - 1;
            j = item.first + 1;
        }
        
        for(; i>=0 && j< s.size();) {
            if(s[i] == s[j]) {
                cnt += 2;
                i--; j++;
            }
            else
                break;
        }
        if(answer < cnt)
            answer = cnt;
    }
    
    return answer;
}
