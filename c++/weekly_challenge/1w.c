#include <string>

using namespace std;

long long solution(int price, int money, int count) {
    int i;
    long long t_p = price, t_m = money;
    for(i = 1; i<=count ; t_m -= t_p*i, i++);
    return t_m < 0 ? abs(t_m) : 0;
}
