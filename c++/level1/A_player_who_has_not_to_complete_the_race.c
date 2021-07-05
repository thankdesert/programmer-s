  
/*
---------------------------------------------
A_player_who_has_not_to_complete_the_race
from : https://programmers.co.kr/learn/courses/30/lessons/42576
solved by unordered_map.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> um;
    string answer = "";
    int i = 0;
    for(i = 0; i<completion.size(); i++) {
        if(um.find(completion[i]) != um.end())
            um[completion[i]]++;
        else
            um.insert(make_pair(completion[i], 1));
    }
        
    for(i = 0; i<participant.size(); i++) {
        if(um.find(participant[i]) != um.end() && um[participant[i]] > 1)
            um[participant[i]]--;
        else if(um.find(participant[i]) != um.end() && um[participant[i]] == 1)
            um.erase(participant[i]);
        else if(um.find(participant[i]) == um.end())
            return participant[i];     
    }
        
    return answer;
}
