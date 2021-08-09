#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    unordered_map<int, int> um;
    int i, j, k, min, max, sum, sz;
    
    for(i = 0; i<scores.size(); i++) {
        min = scores[i][i]; max = scores[i][i]; sum = 0; sz = scores.size();
        um.clear();
        for(j = 0; j<scores.size(); j++) {
            scores[j][i] >= max ? max = scores[j][i] : 1;
            scores[j][i] <= min ? min = scores[j][i] : 1;
            if(um.find(scores[j][i]) == um.end())
                um.insert(make_pair(scores[j][i], 1));
            else
                um[scores[j][i]] += 1;
        }
        
        if((min == scores[i][i] || max == scores[i][i]) && um[scores[i][i]] == 1) {
            scores[i][i] = 0;
            sz -= 1;
        }
        for(j = 0; j<scores.size(); sum += scores[j][i], j++);
        sum /= sz;
        for(j = 'A', k = 90; sum / k == 0 && k >=70; j += 1, k -= 10);
        sum < 50 ? j = 'F' : 1;
        answer.push_back(j);
    }
    return answer;
}
