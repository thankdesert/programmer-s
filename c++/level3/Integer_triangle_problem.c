/*
---------------------------------------------
Integer_triangle_problem
from : https://programmers.co.kr/learn/courses/30/lessons/43105
solved by using a dynamic_programming
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int degree, i, j;
    for(degree = 1; degree < triangle.size(); degree++) {
        for(i = 0; i<=degree; i++) {
            if(i == 0)
                triangle[degree][i] += triangle[degree-1][i];
            else if(i == degree)
                triangle[degree][i] += triangle[degree-1][degree-1];
            else {
                if(triangle[degree-1][i-1] > triangle[degree-1][i])
                    triangle[degree][i] += triangle[degree-1][i-1];
                else
                    triangle[degree][i] += triangle[degree-1][i];
            }
        }
    }
    
    sort(triangle[triangle.size()-1].rbegin(), triangle[triangle.size()-1].rend());
    return triangle[triangle.size()-1][0];
}
