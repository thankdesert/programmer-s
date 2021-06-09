/*
---------------------------------------------
The_Trial_Examination
https://programmers.co.kr/learn/courses/30/lessons/42840
---------------------------------------------
*/


#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int a[5] = {1, 2, 3, 4, 5};
    int a_cur = 0, a_count = 0;
    int b[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int b_cur = 0, b_count = 0;
    int c[12] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3};
    int c_cur = 0, c_count = 0;
    
    for(int i = 0; i < answers.size(); i++) {
        if(a[a_cur++] == answers[i])
            a_count++;
        
        if(b[b_cur++] == answers[i])
            b_count++;
        
        if(c[c_cur++] == answers[i])
            c_count++;
        
        if(a_cur == 5)
            a_cur = 0;
        if(b_cur == 8)
            b_cur = 0;
        if(c_cur == 10)
            c_cur = 0;
    }
    
    int rank[3] = {a_count, b_count, c_count};
    int r[3] = {1, 2, 3};
    
    int temp;
    for(int i = 0; i<3; i++) {
        for(int j = i + 1; j<3; j++) {
            if(rank[i] < rank[j]) {
                temp = rank[i];
                rank[i] = rank[j];
                rank[j] = temp;
                temp = r[i];
                r[i] = r[j];
                r[j] = temp;
            }
        }
    }
    
    answer.push_back(r[0]);
    for(int i = 1; i<3; i++) {
        if(rank[i] == rank[0])
            answer.push_back(r[i]);
        else
            break;
    }
    
    sort(answer.begin(), answer.end());
    
    
    return answer;
}
