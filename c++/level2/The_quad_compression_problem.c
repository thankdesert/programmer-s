/*
---------------------------------------------
The_quad_compression_problem
from : https://programmers.co.kr/learn/courses/30/lessons/68936
solved by recursion.
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;
int sum_0 = 0, sum_1 = 0;

void check(vector<vector<int>>& arr, int length, int r, int l) {
    if(length == 1) {
        if(arr[r][l] == 0)
            sum_0++;
        else
            sum_1++;
        return;
    }
    
    int i, j, key = arr[r][l], flag = 0;
    for(i = r; i < r + length; i++) {
        for(j = l; j < l + length; j++) {
            if(arr[i][j] != key) {
                flag = 1;
                break;
            }
        }
    }
    
    if(flag == 0) {
        if(key == 0)
            sum_0 += 1;
        else
            sum_1 += 1;
        return;
    }
    else
        for(i = r; i < r + length; i += length/2)
            for(j = l; j < l + length; j += length/2)
                check(arr, length/2, i, j);
}

vector<int> solution(vector<vector<int>> arr) {
    check(arr, arr.size(), 0, 0);
    return {sum_0, sum_1};
}
