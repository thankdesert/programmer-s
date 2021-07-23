  
/*
---------------------------------------------
Distance_of_first_visited_way_problem
from : https://programmers.co.kr/learn/courses/30/lessons/49994
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int direction(char dir) {
        switch(dir) {
            case 'U':
                return 0;
            case 'D':
                return 1;
            case 'L':
                return 2;
            case 'R':
                return 3;
            case '0':
                return 1;
            case '1':
                return 0;
            case '2':
                return 3;
            case '3':
                return 2;
        }
}

int solution(string dirs) {
    int i, j, answer = 0, temp, cur, cur_x = 5, cur_y = 5;
    int move_x[4] = {0, 0, -1, 1}; //상, 하, 좌, 우
    int move_y[4] = {-1, 1, 0, 0}; //상, 하, 좌, 우
    vector<vector<int>> visit(121, vector<int>(4, 0));
    
    for(i = 0; i<dirs.size(); i++) {
        cur = cur_y*11 + cur_x;
        temp = direction(dirs[i]);
        if((cur_x + move_x[temp] >= 0 && cur_x + move_x[temp] <= 10) && (cur_y + move_y[temp] >= 0 && cur_y + move_y[temp] <= 10)) {
            cur_x += move_x[temp];
            cur_y += move_y[temp];
            if(visit[cur][temp] == 0) {
                visit[cur][temp] = 1;
                answer++;
                temp = direction(temp + '0');
                visit[cur_y*11 + cur_x][temp] = 1;
            }
        }
    }
    
    
    return answer;
}
