//from : https://programmers.co.kr/learn/courses/30/lessons/86051


#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    /*
    int answer=0;
    int arr[10]={0,};
    for(int item:numbers)
        arr[item]++;
    for(int i=1;10>i;++i)
        arr[i]==0?answer+=i:answer;
    */
    int answer=45;
    for(int item:numbers)
        answer-=item;
    return answer;
}
