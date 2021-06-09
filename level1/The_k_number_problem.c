  
/*
---------------------------------------------
The_k_number_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42748
---------------------------------------------
*/


#include <string>
#include <vector>

using namespace std;

void init_arr(vector<int> array, int* arr) {
    for(int i = 0; i<array.size(); i++)
        arr[i] = array[i];
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int* arr;
    int left, right, rank, temp;
    arr = (int*)malloc(sizeof(int)*array.size());
    
    for(int i = 0; i<commands.size(); i++) {
        left = commands[i][0];
        right = commands[i][1];
        rank = commands[i][2];
        init_arr(array, arr);
        for(int j = left - 1; j < right; j++) {
            for(int k = j +1; k < right; k++) {
                if(arr[j] > arr[k]) {
                    temp = arr[j];
                    arr[j] = arr[k];
                    arr[k] = temp;
                }
            }
        }
        answer.push_back(arr[left + rank - 2]);
    }
    return answer;
}
