/*
---------------------------------------------
Kakao's_bracket_problem
from : https://programmers.co.kr/learn/courses/30/lessons/60058
solved by using stack.
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int stack[1000];
int top;

void push(char key) {
    stack[++top] = key;
}

char pop(void) {
    return stack[top--];
}

int check(string p) {
    int i;
    char temp;
    for(i = 0; i<p.size(); i++) {
        if(top > -1 && p[i] == ')' && stack[top] == '(') {
            pop();
        }
        else
            push(p[i]);
    }
    
    if(top == -1)
        return 1;
    else {
        top = -1;
        return 0;
    }
        
}

string alg(string p) {
    if(p.size() == 0)
        return "";
    
    string u = "", v = "";
    
    int i = 0, left = 0, right = 0;
    do{
        if(p[i] == '(') {
            left++;
            u.push_back('(');
        }            
        else {
            right++;
            u.push_back(')');
        }
        i++;
    }while(i < p.size() && left != right);
    
    for(i; i<p.size(); i++)
        v.push_back(p[i]);
    
    if(check(u) == 1)
        return u.append(alg(v));
    else {
        string temp = "(";
        temp.append(alg(v));
        temp.push_back(')');
        u.erase(0,1);
        u.pop_back();
        for(i = 0; i<u.size(); i++) {
            if(u[i] == '(')
                temp.push_back(')');
            else
                temp.push_back('(');
        }
        return temp;
    }
}

string solution(string p) {
    top = -1;
    string answer = "";
    
    return alg(p);
}
