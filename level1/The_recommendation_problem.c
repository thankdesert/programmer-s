/*
---------------------------------------------
The_recommendation_problem
from : https://programmers.co.kr/learn/courses/30/lessons/72410
---------------------------------------------
*/



#include <string>
#include <vector>

using namespace std;

string solution(string new_id) { 
    char* answer = (char*)malloc(sizeof(char)*new_id.size() + 10);
    int i, j;  
    
    for(i = 0; i<new_id.size(); i++) {
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] += 'a' - 'A';
    }    
    char* temp = (char*)malloc(sizeof(char)*new_id.size() + 10);
    int size_temp;

    for(i = 0, j = 0; i<new_id.size(); i++) {
        if((new_id[i] >= 'a' && new_id[i] <= 'z') ||
           (new_id[i] >= '0' && new_id[i] <= '9') ||
           new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            temp[j++] = new_id[i];
    }   
    size_temp = j;
    temp[size_temp] = '\0';
    
    if(size_temp == 0)
        return "aaa";    
    
    for(i = 1, j = 1; i<size_temp; i++) {
        if(temp[j - 1] != '.' && temp[i] != '.')
            temp[j++] = temp[i];
        else if(temp[j - 1] == '.' && temp[i] == '.')
            continue;
        else
            temp[j++] = temp[i];
    }
    size_temp = j;
    temp[size_temp] = '\0';
    
    if(temp[0] == '.') {
        for(i = 0; i<size_temp; i++)
            temp[i] = temp[i+1];
        size_temp--;
    }
        
    if(temp[size_temp - 1] == '.') {
        temp[--size_temp] = '\0';
    }
    
    if(size_temp == 0) {
        temp[size_temp++] = 'a';
        temp[size_temp] = '\0';
    }
            
    if(size_temp >= 16) {
        size_temp = 15;
        while(temp[size_temp - 1] == '.') {
            size_temp--;            
        }
        temp[size_temp] = '\0';
    }
    
    
    if(size_temp <= 2) {
        while(size_temp < 3) {
            temp[size_temp] = temp[size_temp - 1];
            size_temp++;
        }
        temp[size_temp] = '\0';
    }
    
    for(i = 0; i<size_temp; i++)
        answer[i] = temp[i];
    answer[size_temp] = '\0';
    
    return answer;
}
