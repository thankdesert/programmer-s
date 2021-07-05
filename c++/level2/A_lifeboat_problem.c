/*
---------------------------------------------
A_lifeboat_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42885
solved by using the greedy algorithm.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int solution(vector<int> people, int limit) {
    int i, j, answer = 0, sum, max;
    sort(people.begin(), people.end());

    vector<int> v; //key
    vector<int> n; //the number of keys
    for(i = 0; i<people.size(); i++) {
        auto it = find(v.begin(), v.end(), people[i]);
        if(it == v.end()) {
            v.push_back(people[i]);
            n.push_back(1);            
        }
        else
            n[it - v.begin()]++;
    }

    int left, right, cur_l, cur_r;
    for(i = 0; i<v.size();) {
        if(n[i] == 0) {
            i++;
            continue;
        }

        max = INT_MIN;
        for(j = i + 1 ; j<v.size(); j++) {
            if(n[j] == 0)
                continue;
            sum = v[i] + v[j];
            if(sum <= limit && sum > max) {
                max = sum;
                cur_l = i;
                cur_r = j;
            }
            else
                break;
        }
        if(max != INT_MIN) {
            answer++;
            n[cur_l]--;
            n[cur_r]--;
        }
        else {
            if(n[i] >= 2 && v[i] * 2 <= limit) {
                answer++;
                n[i] -= 2;
            }
            else {
                answer++;
                n[i]--;    
            }
        }
    }

    return answer;
}
