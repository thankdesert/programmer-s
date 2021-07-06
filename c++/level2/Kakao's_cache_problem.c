/*
---------------------------------------------
Kakao's_cache_problem
from : https://programmers.co.kr/learn/courses/30/lessons/17680
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int i, j, answer = 0, count = 0;
    vector<pair<int, string>> ch;
    for(i = 0; i<cacheSize; i++)
        ch.push_back(make_pair(-1, ""));
    
    if(cacheSize == 0)
        return cities.size()*5;
    
    for(i = 0; i<cities.size(); i++, count++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
        for(j = 0; j<cacheSize; j++) {
            if(ch[j].second.compare(cities[i]) == 0) {
                answer += 1;
                ch[j].first = count;
                break;
            }
            if(j == cacheSize - 1) {
                sort(ch.begin(), ch.end());
                ch[0] = make_pair(count, cities[i]);
                answer += 5;
            }                
        }
    }
    return answer;
}
