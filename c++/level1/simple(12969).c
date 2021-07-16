/*
---------------------------------------------
simple(12969)
from : https://programmers.co.kr/learn/courses/30/lessons/12969
---------------------------------------------
*/

#include <iostream>

using namespace std;

int main(void) {
    int i, j, a, b;
    cin >> a >> b;
    for(i = 0; i<b; i++) {
        for(j = 0; j<a; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
