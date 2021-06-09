/*
---------------------------------------------
The_claw_machine_game_problem
from : https://programmers.co.kr/learn/courses/30/lessons/77484
---------------------------------------------
*/


#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int count_hit = 0, count_z = 0, total_hit = 0;
    for(int i = 0; i<6; i++) {
        if(lottos[i] == 0)
            count_z ++;
        else {
            for(int j = 0; j<6; j++) {
                if(lottos[i] == win_nums[j]) {
                    count_hit ++;
                    break;
                }                    
            }
        }
    }
    
    total_hit = count_hit + count_z;

    if(total_hit < 2) {
        answer.push_back(6);        
    }
    else {
        answer.push_back(7 - total_hit);
    }
    
    if(count_hit < 2) {
        answer.push_back(6);
    }
    else {
        answer.push_back(7 - count_hit);
    }
    return answer;
}
