/*
---------------------------------------------
Expressing_only_with_N_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42895
solved by using a dynamic_programming(implemented by the set)
---------------------------------------------
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    int i, j;
    vector<set<int>> v(9);
    for(i = 1; i<=8; i++) {
        string line = "";
        for(j=0;j<i;j++)
            line.push_back(N + '0');
        v[i].insert(stoi(line));
    }
    
    for(i = 1; i<= 8; i++) {
        for(j = 1; j < i; j++) { //1 i-1, 2 i-2, ..., j i-j
            for(auto item_l : v[j]) {
                for(auto item_r : v[i-j]) {
                    v[i].insert(item_l + item_r);
                    v[i].insert(item_l - item_r);
                    v[i].insert(item_l * item_r);
                    if(item_r != 0)
                        v[i].insert(item_l / item_r);
                }
            }
        }
        if(v[i].find(number) != v[i].end())
            return i;
    }
    
    return -1;
}
