/*
---------------------------------------------
Kakao's_menu_renual_problem
from : https://programmers.co.kr/learn/courses/30/lessons/72411
solved by using unordered_map & combination.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<int> temp_i;
    unordered_map<string,int> um;
    
    int i, j, k, length, max;
    for(i = 0; i<orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());
    
    string line;
    for(i = 0; i<orders.size(); i++) {
        for(j = 0; j<course.size() && course[j] <= orders[i].size(); j++) {
            length = course[j];
            for(k = 0; k<length; k++)
                temp_i.push_back(1);
            for(k = 0; k < orders[i].size() - length; k++)
                temp_i.push_back(0);
            
            do {
                line = "";
		        for(k=0 ; k< orders[i].size(); k++){
			        if(temp_i[k] == 1)
                        line.push_back(orders[i][k]);
		        }
                auto item = um.find(line);
                if(item == um.end())
                    um.insert(make_pair(line, 1));        
                else
                    um[line]++;
	        }while(prev_permutation(temp_i.begin(), temp_i.end()));
            temp_i.clear();
        }
    }
    
    for(i = 0; i<course.size(); i++) {
        length = course[i];
        max = -1;
        for(pair<string,int> elem : um){
            if(elem.first.size() == length) {
                if(elem.second > max)
                    max = elem.second;
            }
        }
        if(max <= 1)
            continue;
        
        for(pair<string,int> elem : um){
            if(elem.first.size() == length && elem.second == max)
                answer.push_back(elem.first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
