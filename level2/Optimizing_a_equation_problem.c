/*
---------------------------------------------
Optimizing_a_equation_problem
from : https://programmers.co.kr/learn/courses/30/lessons/67257
solved by using permutation.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string exp) {
    vector<char> v {'+', '-', '*'};
    sort(v.begin(), v.end());
    
    char op[100];
    long long number[100];
    
    int i, j, k, left, right;
    string line;
    for(i = 0, k =0; i<exp.size();) {
        if(exp[i] < '0' || exp[i] > '9') {
            op[k++] = exp[i];
            i++;
        }
        else {
            for(;;) {
                if(exp[i] >= '0' && exp[i] <= '9')
                    line.push_back(exp[i++]);
                else
                    break;
            }
            number[k] = stoi(line);
            line = "";
        }
    }
    
    long long max = -1;
    long long temp_n[100], temp_op[100], pos_n[100];
    do {
        for(i = 0; i<=k; i++) {
            temp_n[i] = number[i];
            pos_n[i] = i;
        }
        for(i = 0; i<k; i++)
            temp_op[i] = op[i];
        
        for(i = 0; i<3; i++) {
            for(j = 0; j < k; j++) {
                if(temp_op[j] == v[i]) {
                    left = j; right = j + 1;
                    for(;pos_n[left] != left; left = pos_n[left]);
                    for(;pos_n[right] != right; right= pos_n[right]);
                    if(v[i] == '+')
                        temp_n[left] += temp_n[right];
                    else if(v[i] == '-')
                        temp_n[left] -= temp_n[right];
                    else if(v[i] == '*')
                        temp_n[left] *= temp_n[right];
                    pos_n[right] = left;
                }
            }
        }
        
        if(abs(temp_n[0]) > max)
            max = abs(temp_n[0]);
    } while(next_permutation(v.begin(), v.end()));
    
    return max;
}
