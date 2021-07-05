/*
---------------------------------------------
Compressing_a_string_problem
from : https://programmers.co.kr/learn/courses/30/lessons/60057
solved by using stack.
---------------------------------------------
*/


#include <string>
#include <vector>

using namespace std;

int top = -1;
int stack[1000];
void push(int key) {
    stack[++top] = key;
}

int solution(string s) {
    int answer = 0;
    int sum;
    int result = 0;
    int left, right, i = 0, count = 0, temp = 0;
    for(sum = 1; sum <= s.size() / 2; sum++, i =0, temp = 0, count = 0, top = -1) {
        for(left = 0; left < s.size(); left += sum) {
            for(right = left; right < left + sum && right < s.size(); right++) {
                if(top + 1 < sum) {
                    push(s[right] - 'a');
                }
                else if(top + 1 == sum) {
                    if(stack[i] + 'a' == s[right] && i != top) {
                        i++;
                        if(right == s.size() - 1) {
                            if((count > 1 && sum == 1) || (count >= 1 && sum > 1)) {
                                if((count + 1) < 10) {
                                    temp += sum * count - 1;
                                }
                                else {
                                    int v = 0;
                                    for(int k = 10; (count + 1) / k > 0; v++, k*= 10);
                                    temp += sum * count - v - 1;
                                }
                            }
                        }                        
                    }
                    else if(stack[i] + 'a' == s[right] && i == top) {
                        count++;
                        i = 0;
                        if(right == s.size() - 1) {
                            if((count > 1 && sum == 1) || (count >= 1 && sum > 1)) {
                                if((count + 1) < 10) {
                                    temp += sum * count - 1;
                                }
                                else {
                                    int v = 0;
                                    for(int k = 10; (count + 1) / k > 0; v++, k*= 10);
                                    temp += sum * count - v - 1;
                                }
                            }
                        }
                    }
                    else if(stack[i] + 'a' != s[right]) {
                        left -= sum;
                        if((count > 1 && sum == 1) || (count >= 1 && sum > 1)) {
                            if((count + 1) < 10) {
                                temp += sum * count - 1;
                            }
                            else {
                                int v = 0;
                                for(int k = 10; (count + 1) / k > 0; v++, k*= 10);
                                temp += sum * count - v - 1;
                            }                            
                        }
                        count = 0; i = 0; top = -1;
                        break;
                    }
                }
            }
            if(temp >= result) {
                result = temp;
            }
        }
    }
    answer = s.size() - result;
    return answer;
}
