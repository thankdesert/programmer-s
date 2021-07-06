/*
---------------------------------------------
A_skill_tree_problem.c
from : https://programmers.co.kr/learn/courses/30/lessons/49993
solved by using unordered_map
---------------------------------------------
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int i, j, answer = 0;
    unordered_map<char, int> um;
    unordered_map<char, int> sk;
    for(i = 0; i<skill.size(); i++)
        sk.insert(make_pair(skill[i], i));
    
    for(i = 0; i<skill_trees.size(); i++) {
        um.clear();
        for(j = 0; j<skill_trees[i].size(); j++) {
            char temp = skill_trees[i][j];
            if(sk.find(temp) == sk.end()) {
                um.insert(make_pair(temp, j));
                continue;
            }
            else {
                int flag = 1;
                for(auto elem : sk) {
                    if(elem.second >= sk[temp])
                        continue;
                    else {
                        if(um.find(elem.first) == um.end()) {
                            flag = 0;
                            break;
                        }
                    }
                }
                if(flag == 1)
                    um.insert(make_pair(temp, j));
            }
        }
        if(um.size() == skill_trees[i].size())
            answer += 1;
    }
    
    return answer;
}
