/*
---------------------------------------------
Rotating_a_bracket_problem
from : https://programmers.co.kr/learn/courses/30/lessons/76502
solved by using stack.
---------------------------------------------
*/

#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0, i;
    string v = "";
    stack<char> st;
    
    for(i = 0; i<s.size(); i++)
        v.push_back(s[i]);
    
    for(int k = 0; k <v.size() - 1; k++) {
        for(i = 0; i<v.size(); i++) {
            if(v[i] == '{' || v[i] == '[' || v[i] == '(')
                st.push(v[i]);
            else if(v[i] == '}' && st.top() == '{')
                st.pop();
            else if(v[i] == '}' && st.top() != '{') {
                st.push('X');
                break;
            }
            else if(v[i] == ']' && st.top() == '[')
                st.pop();
            else if(v[i] == ']' && st.top() != '[') {
                st.push('X');
                break;
            }
            else if(v[i] == ')' && st.top() == '(')
                st.pop();
            else if(v[i] == ')' && st.top() != '[') {
                st.push('X');
                break;
            }
        }
        
        if(st.size() == 0)
            answer++;
        
        while(!st.empty())
            st.pop();
        
        string temp = "";
        for(i = 1; i<v.size(); i++)
            temp.push_back(v[i]);
        temp.push_back(v[0]);
        v = temp;
    }
    
    return answer;
}
