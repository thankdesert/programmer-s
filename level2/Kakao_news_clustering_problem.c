/*
---------------------------------------------
Kakao_news_clustering_problem
from : https://programmers.co.kr/learn/courses/30/lessons/17677
---------------------------------------------
*/

#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string str1, string str2) {
    vector<pair<char, char>> s1;
    vector<pair<char, char>> s2;
    int answer = 0;
    
    for(int i = 0; i<str1.size() - 1; i ++) {
        if((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z')) {
            if((str1[i + 1] >= 'a' && str1[i + 1] <= 'z') || (str1[i + 1] >= 'A' && str1[i + 1] <= 'Z'))
                s1.push_back(make_pair(str1[i], str1[i+1]));
        }
    }
    
    for(int i = 0; i<str2.size() - 1; i++) {
        if((str2[i] >= 'a' && str2[i] <= 'z') || (str2[i] >= 'A' && str2[i] <= 'Z')) {
            if((str2[i + 1] >= 'a' && str2[i + 1] <= 'z') || (str2[i + 1] >= 'A' && str2[i + 1] <= 'Z'))
                s2.push_back(make_pair(str2[i], str2[i+1]));
        }
    }
    
    if(s1.size() == 0 && s2.size() == 0)
        return 65536;
    
    double inter = 0, uni = 0;
    int* visit = (int*)malloc(sizeof(int) * s2.size());
    for(int i = 0; i<s2.size(); visit[i++] = 0);    
    for(int i = 0; i<s1.size(); i++) {
        for(int j = 0; j<s2.size(); j++) {
            if((s1[i].first == s2[j].first && s1[i].second == s2[j].second && visit[j] == 0) ||
                (abs(s1[i].first - s2[j].first) == 32 && abs(s1[i].second - s2[j].second) == 32 && visit[j] == 0) ||
                (abs(s1[i].first - s2[j].first) == 32 && s1[i].second == s2[j].second  && visit[j] == 0) ||
                (s1[i].first == s2[j].first && abs(s1[i].second - s2[j].second) == 32  && visit[j] == 0)){
                inter++;
                visit[j] = 1;
                break;
            }
        }
    }
    
    uni = s1.size() + s2.size() - inter;
    answer = trunc((inter/uni)*65536);
    return answer;
}
