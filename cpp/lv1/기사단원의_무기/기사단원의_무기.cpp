#include <string>
#include <vector>

using namespace std;

// 1. 약수의 개수를 구해주는 함수를 만든다.
// 2. main에서 약수를 구한 변수에 대해서 limit보다 크면 주어진 power로 값을 변경한다.
// 3. 각 연산된 값을 answer에 더해준다.

// 약수의 개수를 구해주는 함수
int getPiedges(int num) {
    // 맨 마지막 숫자도 있기 때문에 1을 먼저 더해줌
    int piedges = 1;
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            piedges++;
        }
    }
    return piedges;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    // vector<int> piedges;
    for (int i = 1; i <= number; ++i) {
        // 약수의 개수를 구해옴
        int piedge = getPiedges(i);
        // 약수의 개수가 limit보다 크면 power로 바꿔줌
        if (piedge > limit) {
            piedge = power;
        }
        // answer변수에 반복해서 더해줌
        answer += piedge;
    }
    return answer;
}