/*
---------------------------------------------
Kakao's_sorting_problem
from : https://programmers.co.kr/learn/courses/30/lessons/17686
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct name{
    string head;
    int number;
    int index;
}_name;

bool cmp(const _name& a, const _name& b) {
    if (a.head == b.head) {
        if (a.number == b.number)
            return a.index < b.index;
        else
            return a.number < b.number;
    }
    else
        return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<_name> v;
    int i, j, k, cnt;
    string line;
    
    if(files.size() == 1)
        return {files[0]};
    
    for(i = 0; i<files.size(); i++) {
        line = "";
        _name temp;
        for(j = 0; j<files[i].size(); j++) {
            if(files[i][j] >= '0' && files[i][j] <= '9')
                break;
            if(files[i][j] >= 'A' && files[i][j] <= 'Z')
                line.push_back(files[i][j] + 'a' - 'A');
            else
                line.push_back(files[i][j]);
        }
        temp.head = line;
        line = "";
        for(cnt = 0;j<files[i].size();j++) {
            if(cnt == 5 || files[i][j] < '0' || files[i][j] > '9')
                break;
            line.push_back(files[i][j]);
        }
        temp.number = stoi(line);
        temp.index = i;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(auto item : v)
        answer.push_back(files[item.index]);
    
    return answer;
}
