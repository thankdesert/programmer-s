//from : https://programmers.co.kr/learn/courses/30/lessons/87389


#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 2;
    for(;n > answer; ++answer) {
        if(n % answer == 1)
            return answer;
    }
    return answer;
}
