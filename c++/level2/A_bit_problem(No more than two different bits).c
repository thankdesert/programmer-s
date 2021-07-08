/*
---------------------------------------------
A_bit_problem(No more than two different bits)
https://programmers.co.kr/learn/courses/30/lessons/77885
---------------------------------------------
*/

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int i, k;
    long long j;
    for(i = 0; i<numbers.size(); i++) {
        for(k = 0; pow(2, k) <= numbers[i]; k++);
        k--;
        int r_0 = -1, cur;
        string temp = "";
        for(j = pow(2, k), cur = 0; j > 0 ; j /= 2, cur++) {
            if(numbers[i] - j >= 0) {
                temp.push_back('1');
                numbers[i] -= j;
            }
            else {
                temp.push_back('0');
                r_0 = cur;
            }
        }
        if(r_0 == -1) { //하위 비트에 0이 없음
            string temp2 = "1";
            temp2.append(temp);
            temp2[1] = '0';
            temp = temp2;
        }
        else { //하위 비트에 1이 있음
            temp[r_0] = '1';
            for(int k = r_0 + 1; k<temp.size(); k++) {
                if(temp[k] == '1') {
                    temp[k] = '0';
                    break;
                }
            }
        }
        answer.push_back(stoll(temp, 0, 2));
    }
    
    return answer;
}
