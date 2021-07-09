/*
---------------------------------------------
Kakao's_The_Song_I_heard_just_now
from : https://programmers.co.kr/learn/courses/30/lessons/17683
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int i, j, during, max = -1, count_s;
    
    string temp_hd, temp_m, temp_line;
    for(i = 0; i<musicinfos.size(); i++) {
        during = (stoi(musicinfos[i].substr(6, 2)) - stoi(musicinfos[i].substr(0, 2))) * 60 +
            (stoi(musicinfos[i].substr(9, 2)) - stoi(musicinfos[i].substr(3, 2)));
        temp_hd = "";
        for(j = 12; musicinfos[i][j] != ','; j++)
            temp_hd.push_back(musicinfos[i][j]);
        temp_m = "";
        count_s = 0;
        for(++j; j<musicinfos[i].size(); j++) {
            temp_m.push_back(musicinfos[i][j]);
            if(musicinfos[i][j+1] == '#') {
                temp_m.push_back('#');
                j++;
                count_s++;
            }
        }
        
        j = during;
        string full = "";
        int length = temp_m.size() - count_s;
        while(j - length >= 0) {
            full.append(temp_m);
            j -= length;
        }
        
        for(int k = 0; k < j && j > 0; k++) {
            full.push_back(temp_m[k]);
            if(temp_m[k] == '#')
                j++;
        }
        
        int id;
        do {
            id = full.find(m);
            if(id == string::npos)
                break;
            else {
                if(id + m.size() < full.size() && full[id + m.size()] == '#')
                    full.erase(0, id + m.size() + 1);
                else {
                    if(during > max) {
                        max = during;
                        answer = temp_hd;
                    }
                    break;
                }
            }
        }while(full.size() >= m.size());
    }
    
    return answer;
}
