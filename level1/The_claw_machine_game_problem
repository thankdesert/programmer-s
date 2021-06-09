/*
---------------------------------------------
The_claw_machine_game_problem
from : https://programmers.co.kr/learn/courses/30/lessons/64061
solved by using stack.
---------------------------------------------
*/


#include <string>
#include <vector>

using namespace std;

int stack[910];
int top = -1;

int pop(void) {
    if(top == -1)
        return -1;
    return stack[top--];
}

void push(int item) {
    stack[++top] = item;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, prev;
        
    for(int i = 0, j; i<moves.size(); i++) {
        prev = pop();
        printf("%d ", prev);
        
        for(j = 0; board[j][moves[i] - 1] == 0 && j < board.size() - 1; j++);
        
        if(prev == -1) {
            if(board[j][moves[i] - 1] != 0) {
                push(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;
            }
            else
                continue;
        }
        else if(board[j][moves[i] - 1] == prev) {
            answer += 2;
            board[j][moves[i] - 1] = 0;
            continue;
        }
        else if(board[j][moves[i] - 1] == 0) {
            push(prev);
        }        
        else if(board[j][moves[i] - 1] != 0){
            push(prev);
            push(board[j][moves[i] - 1]);
            board[j][moves[i] - 1] = 0;
        }
    }
    
    return answer;
}
