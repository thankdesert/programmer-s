/*
---------------------------------------------
Taking_a_group_photo_problem
from : https://programmers.co.kr/learn/courses/30/lessons/1835
solved by using permutation.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check(int n, vector<string> data, vector<char> line) {
    //조건 하나라도 불만족시 return -1
    //모두 만족시 return 1
    char left, right, cond, dist;
    int l, r;
    for(int i = 0; i<n; i++) {
        left = data[i][0];
        right = data[i][2];
        cond = data[i][3];
        dist = data[i][4];
        
        //조건에 맞게 l, r을 지정
        for(int j = 0; j<8; j++) {
            if(line[j] == left)
                l = j;
            else if(line[j] == right)
                r = j;
        }
        
        if(cond == '<') { //l과 r의 간격이 dist 미만, 이 때 간격은 |l - r| - 1
            if(abs(l - r) - 1 >= dist - '0')
                return -1;
        }
        else if(cond == '=') { //l과 r의 간격이 dist
            if(abs(l - r) - 1 != dist - '0')
                return -1;
        }
        else if(cond == '>') { //l과 r의 간격이 dist 초과
            if(abs(l - r) - 1 <= dist - '0') {
                return -1;
            }
        }
    }
    return 1;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    int visit[8] = {0,};
    vector<char> f {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<char> line;
    
    do {
        line.clear();
        for(int i = 0; i<8; line.push_back(f[i++]));
        if(check(data.size(), data, line) == 1)
            answer++;
    } while(next_permutation(f.begin(), f.end()));
    
    return answer;
}
