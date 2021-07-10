/*
---------------------------------------------
A_tournament_table_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12985?language=java
solved by complete binary tree,
---------------------------------------------
*/

class Solution {
    public int solution(int n, int a, int b){
        int answer = 0;
        for(a += (n - 1), b += (n - 1) ;a != b; a/=2, b/=2, answer++);
        return answer;
    }
}
