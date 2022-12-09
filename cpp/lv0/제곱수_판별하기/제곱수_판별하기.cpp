#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int sqrt = std::sqrt(n);
    // C++에서는 다른 타입끼리 연산을 지원한다 후후
    if (static_cast<int>(sqrt) < std::sqrt(n)) {
        return 2;
    } else {
        return 1;
    }
}