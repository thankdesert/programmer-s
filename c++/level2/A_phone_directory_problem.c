/*
---------------------------------------------
A_phone_directory_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42577
solved by using the unordered_map.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a.size() < b.size();
}

bool solution(vector<string> phone_book) {
    unordered_map<string, int> um;
    int i, j, size = 0;
    sort(phone_book.begin(), phone_book.end(), cmp);
    for(i = 0; i< phone_book.size(); i++) {
        size = phone_book[i].size();
        um[phone_book[i]] = 1;
        for(j = i + 1; j <phone_book.size(); j++) {
            if(um[phone_book[j].substr(0, size)] == 1)
                return false;
            if(phone_book[j].size() == size) {
                um[phone_book[j]] = 1;
                i++;
            }
        }
    }           
    return true;
}
