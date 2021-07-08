/*
---------------------------------------------
Kakao's_string_of_number_problem
from : https://programmers.co.kr/learn/courses/30/lessons/81301
solved by using unordered_map.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    int answer = 0, i;
    vector<string> v = {"zero", "one", "two", "three", "four", "five",
                       "six", "seven", "eight", "nine"};
    unordered_map<string, int> um;
    for(i = 0; i<v.size(); i++)
        um.insert(make_pair(v[i], i));
    
    string temp = "";
    for(i = 0; i<s.size();) {
        if((s[i] == 'z' && s[i+1] == 'e') || (s[i] == 'f' && s[i+1] == 'o') ||
           (s[i] == 'f' && s[i+1] == 'i') || (s[i] == 'n' && s[i+1] == 'i')) {
            temp.push_back(um[s.substr(i, 4)] + '0');
            i += 4;
        }
        else if((s[i] == 't' && s[i+1] == 'h') || (s[i] == 's' && s[i+1] == 'e') || (s[i] == 'e' && s[i+1] == 'i')) {
            temp.push_back(um[s.substr(i, 5)] + '0');
            i += 5;
        }
        else if(s[i] >= '0' && s[i] <= '9')
            temp.push_back(s[i++]);         
        else {
            temp.push_back(um[s.substr(i, 3)] + '0');
            i += 3;
        }
    }
    answer = stoi(temp);
    return answer;
}
