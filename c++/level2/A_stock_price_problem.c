/*
---------------------------------------------
A_stock_price_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42584
solved by using a stack.
---------------------------------------------
*/

#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<pair<int, int>> v; //result, 삽입 시점
    stack<pair<int, int>> s; //key, 삽입 시점
    int count, size = prices.size(), i;
    
    for(count = 1; count <= size; count++) {
        while(s.empty() != 1 && s.top().first > prices[count - 1]) {
            v.push_back(make_pair(count - s.top().second, s.top().second));
            s.pop();
        }
        s.push(make_pair(prices[count-1], count));
    }
    
    while(s.empty() != 1) {
        v.push_back(make_pair(size - s.top().second, s.top().second));
        s.pop();
    }
    
    sort(v.begin(), v.end(), cmp);
    for(i = 0; i<v.size(); i++)
        answer.push_back(v[i].first);
    
    return answer;
}
