#include <string>
#include <vector>

// 이게 머야..
using namespace std;

int solution(int n, int t) {
    // int answer = 1;
    for (int i = 0; i < t; ++i) {
        n *= 2;
    }
    return n;
}