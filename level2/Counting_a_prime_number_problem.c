  
/*
---------------------------------------------
Counting_all_prime_number_problem.c
from : https://programmers.co.kr/learn/courses/30/lessons/42839
solved by using permutation and combination.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(string numbers) {
    int answer = 0;
    int i, j;
    vector<int> v;
    for(i = 0; i<numbers.size(); i++)
        v.push_back(numbers[i] - '0');
    sort(v.begin(), v.end());
    
    vector<int> temp; //v의 각 조합을 담는 컨테이너
    vector<int> temp_p; //v의 각 조합의 순열을 담는 컨테이너
    vector<int> it; //조합 생성 용 컨테이너
    vector<int> list; //중복 체크용 컨테이너
    
    int length, cur;
    for(i = 0; i<v.size(); i++) { //1~v.size()의 조합을 생성 후 순열
        length = i+1; //length == 순열을 구할 조합의 길이
        it.clear();
        for(j = 0; j<length; j++)
            it.push_back(1);
        for(j = 0; j<v.size() - length; j++)
            it.push_back(0);
        
        do {
            temp.clear();
            for(j = 0; j<v.size(); j++) {
                if(it[j] == 1)
                    temp.push_back(v[j]); //조합 생성
            }
            sort(temp.begin(), temp.end());
            
            do {
                temp_p.clear();
                
                //temp의 각 순열 생성
                for (auto item = temp.begin(); item != temp.end(); ++item)
                    temp_p.push_back(*item);
                
                cur = 0;
                int temp_length = temp_p.size();
                for(int k = 0; k < temp_length; k++) {
                    cur += (temp_p.back() * pow(10, k));
                    temp_p.pop_back();
                }
                //소수 & 중복 판정
                for(int k = 2; k <= cur; k++) {
                    if(k != cur && cur % k == 0)
                        break; //소수 아님
                    else if(k == cur) { //소수임
                        auto item = find(list.begin(), list.end(), cur);
                            if (item == list.end()) {
                                list.push_back(cur);
                                answer++;
                            }
                    }
                }
            } while (next_permutation(temp.begin(), temp.end()));
        } while(prev_permutation(it.begin(), it.end()));
    }
    return answer;
}
