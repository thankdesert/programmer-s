/*
---------------------------------------------
The_base_station_problem
from : https://programmers.co.kr/learn/courses/30/lessons/12979
---------------------------------------------
*/

#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0, i, j, length = 2*w + 1;
    sort(stations.begin(), stations.end());

    for(i = 1, j = 0; i <= n && j < stations.size();) {
        if(i >= stations[j] - w && i <= stations[j] + w) {
            i = stations[j] + w + 1;
            j++;
        }
        else if(i + length - 1 < stations[j] - w) {
            answer += (stations[j] - w - i)/length;
            if((stations[j] - w - i)%length != 0)
                answer++;            
            i = stations[j] + w + 1;
            j++;
        }
        else if (i + length - 1>= stations[j] - w && i < stations[j] - w){
            answer++;
            i = stations[j] + w + 1;
            j++;
        }
    }

    if(i <= n) {
        answer += (n - i + 1)/length;
        if((n - i + 1) % length != 0)
            answer++;
    }

    return answer;
}
