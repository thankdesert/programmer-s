
/*
---------------------------------------------
The_gym_clothes_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42862
solved by using greedy.
---------------------------------------------
*/


#include <string>
#include <vector>

using namespace std;

int check_lost(int k, int size_lost, vector<int> lost) {
    for(int i = 0; i<size_lost; i++) {
        if(lost[i] == k)
            return i;
    }
    return -1;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i = 0; i<reserve.size(); i++) {
        int temp = check_lost(reserve[i], lost.size(), lost);
        if(temp != -1) {
            lost.erase(lost.begin() + temp);
            reserve.erase(reserve.begin() + i);
            i--;
        }
    }
    
    if(lost.size() > 0) {
        for(int i = 0; i<reserve.size(); i++) {
            int temp = 0;
            if(reserve[i] > 1) {
                temp = check_lost(reserve[i] - 1, lost.size(), lost);
                if(temp != -1) {
                    lost.erase(lost.begin() + temp);
                    reserve.erase(reserve.begin() + i);
                    i--;
                    continue;
                }            
            }            
            if(reserve[i] < n) {
                temp = check_lost(reserve[i] + 1, lost.size(), lost);
                if(temp != -1) {
                    lost.erase(lost.begin() + temp);
                    reserve.erase(reserve.begin() + i);
                    i--;
                }                 
            }
            
       
        }
        answer = n - lost.size();
    }
    else
        answer = n;
    
    return answer;
}
