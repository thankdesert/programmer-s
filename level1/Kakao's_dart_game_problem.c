/*
---------------------------------------------
Kakao's_dart_game_problem
from : https://programmers.co.kr/learn/courses/30/lessons/17682
---------------------------------------------
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0, i, count = 0;
    vector<pair<int, int>> number; //key, 제곱수
    vector<int> sp; //*2 or *(-1)
    
    string temp = "";
    while(dartResult.empty() != 1) {
        temp.clear();
        count++;
        temp.push_back(dartResult[0]);
        dartResult.erase(0,1);
        if(dartResult[0] >= '0' && dartResult[0] <= '9') {
            temp.push_back(dartResult[0]);
            dartResult.erase(0,1);
        }
        
        if(dartResult[0] == 'S') {
            number.push_back(make_pair(stoi(temp), 1));
            dartResult.erase(0,1);
        }
        else if(dartResult[0] == 'D') {
            number.push_back(make_pair(stoi(temp), 2));
            dartResult.erase(0,1);
        }            
        else if(dartResult[0] == 'T') {
            number.push_back(make_pair(stoi(temp), 3));        
            dartResult.erase(0,1);
        }
        
        if(dartResult[0] == '*') {
            sp.push_back(2);
            if(count > 1)
                sp[count - 2] *= 2;
            dartResult.erase(0,1);
        }
        else if(dartResult[0] == '#') {
            sp.push_back(-1);
            dartResult.erase(0,1);
        }
        else
            sp.push_back(1);
    }
    
    for(i = 0; i<count; i++)
        answer += pow(number[i].first, number[i].second) * sp[i];
    
    return answer;
}
