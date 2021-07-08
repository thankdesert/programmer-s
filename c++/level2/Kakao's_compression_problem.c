/*
---------------------------------------------
Kakao's_compression_problem
from : https://programmers.co.kr/learn/courses/30/lessons/17684#
solved by using a unordered_map
---------------------------------------------
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> um;
    int i, j, k, cur = 26;
    
    for(i = 1; i<=26; i++) {
        string line = "";
        line.push_back(i + 'A' - 1);
        um.insert(make_pair(line, i));
    }
    
    for(i = 0; i<msg.size();i += k) {
        for(k = 1; k < msg.size() - i; k++) {
            if(um.find(msg.substr(i, k + 1)) == um.end())
                break;
        }
        answer.push_back(um[msg.substr(i, k)]);
        um.insert(make_pair(msg.substr(i, k + 1), ++cur));
    }
    
    return answer;
}
