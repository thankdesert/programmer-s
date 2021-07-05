/*
---------------------------------------------
Repeating_the_binary_transformation_problem
from : https://programmers.co.kr/learn/courses/30/lessons/70129
---------------------------------------------
*/

#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    int i, length = s.size(), sum = 0, count = 0, c_0, c_1;
    while(length > 1) {
        count++;
        c_0 = 0, c_1 = 0;
        for(i = 0; i<length; i++) {
            if(s[i] == '0')
                c_0++;
            else
                c_1++;
        }
        sum += c_0;
        string bin = bitset<1000>(c_1).to_string();
        for(i = 0; i<1000; i++) {
            if(bin[0] == '0')
                bin.erase(0,1);
            else
                break;
        }
        s = bin;
        length = s.size();
    }
    return {count, sum};
}
