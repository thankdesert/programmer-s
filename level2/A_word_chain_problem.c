/*
---------------------------------------------
A_word_chain_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12981
solved by using unordered_map.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    int i, j;
    vector<int> answer;
    unordered_map<string, int> um;
    
    um.insert(make_pair(words[0], 0));
    for(i = 1, j = 2; i<words.size(); i++, j++) {
        if(j > n)
            j = 1;
        if(um.find(words[i]) != um.end() || words[i-1].back() != words[i].front()) {
            answer.push_back(j);
            answer.push_back(i/n + 1);
            return answer;
        }
        um.insert(make_pair(words[i], i));
    }
    
    return {0, 0};
}
