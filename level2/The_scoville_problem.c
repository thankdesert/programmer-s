/*
---------------------------------------------
The_scoville_problem
from : https://programmers.co.kr/learn/courses/30/lessons/42626
solved by minimum_heap(implemented by array)
---------------------------------------------
*/

#include <string>
#include <vector>

using namespace std;

int heap[1000000];
int n = 0;

void insert(int key) {
    int target = ++n, temp;
    for(target; target > 1;) {
        if(heap[target/2] > key) {
            heap[target] = heap[target/2];
            target /= 2;
        }
        else
            break;
    }
    heap[target] = key;
}

int pop(void) {
    if(n == 0)
        return -1;
    int min = heap[1];
    heap[1] = heap[n--];
    int parent = 1, child, temp;
    
    for(;;) {
        child = parent*2;
        if(child + 1 <= n && heap[child+1] < heap[child])
            child += 1;
        
        if(heap[parent] < heap[child] || child > n)
            break;
        
        temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        parent = child;
    }
    
    return min;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int i = 0; i<scoville.size(); i++)
        insert(scoville[i]);
    
    int count = 0, temp_k, f, s;
    for(;;) {
        if(n <= 1 && heap[1] < K)
            return -1;
        f = pop(); s = pop();
        if(f >= K)
            return count;
        count++;
        temp_k = f + (s*2);
        insert(temp_k);
    }
}
