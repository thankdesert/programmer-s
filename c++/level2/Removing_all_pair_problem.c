/*
---------------------------------------------
Removing_all_pair_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12973
solved by using stack.
---------------------------------------------
*/

#include <iostream>
#include<string>
using namespace std;

int top;
int stack[1000000];

void push(int key) {
    stack[++top] = key;
}

int pop(void) {
    return stack[top--];
}

int solution(string s) {
    top = -1;
    
    for(int i = 0; i<s.size(); i++) {
        if(top == -1)
            push(s[i] - 'a');
        else
            if(stack[top] + 'a' == s[i])
                pop();
            else
                push(s[i] - 'a');
    }
    
    if(top == -1)
        return 1;
    else
        return 0;
}
