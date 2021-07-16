/*
---------------------------------------------
simple(12901)
from : https://programmers.co.kr/learn/courses/30/lessons/12901
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    int mm[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 365};
    vector<string> v = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    return v[(b + mm[a-1]) % 7];
}
