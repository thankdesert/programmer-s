  
/*
---------------------------------------------
The_Keypad_problem
from : https://programmers.co.kr/learn/courses/30/lessons/67256
solved by using naive.
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int i, left = 10, right = 12, left_m = 0, right_m = 0, l_d, r_d;
    for(int i = 0; i<numbers.size(); i++) {
        if(numbers[i] % 3 == 1) {
            left = numbers[i];
            answer.push_back('L');
            left_m = 0;
        }
        else if(numbers[i] % 3 == 0 && numbers[i] != 0) {
            right = numbers[i];
            answer.push_back('R');
            right_m = 0;
        }
        else {
            if(left == 0)
                left = 11;
            else if(right == 0)
                right = 11;
            
            if(numbers[i] == 0)
                numbers[i] = 11;
                        
            l_d = abs(left - numbers[i]);
            
            if(right_m == 0)
                r_d = abs((right-2) - numbers[i]);
            else
                r_d = abs(right - numbers[i]);
            
            if(numbers[i] == 11)
                numbers[i] = 0;
                        
            if(left_m == 0)
                l_d = (l_d / 3) + (l_d % 3);
            else
                l_d = l_d/3;
            
            if(right_m == 0)
                r_d = (r_d / 3) + (r_d % 3);
            else
                r_d = r_d/3;
            
            if(l_d < r_d) {
                left = numbers[i];
                answer.push_back('L');
                left_m = 1;
            }
            else if(l_d > r_d) {
                right = numbers[i];
                answer.push_back('R');
                right_m = 1;
            }
            else {
                if(hand.compare("left") ==0) {
                    left = numbers[i];
                    answer.push_back('L');
                    left_m = 1;
                }
                else {
                    right = numbers[i];
                    answer.push_back('R');
                    right_m = 1;
                }
            }
        }
    }
    return answer;
}
