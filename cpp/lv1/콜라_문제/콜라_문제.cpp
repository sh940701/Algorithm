#include <string>
#include <vector>

using namespace std;

// 빈 병이 n개 주어진다. n에서 a를 빼면 b 개의 콜라를 준다.
// 1. 먼저 n에서 a개를 나머지 연산 한다. 그럼 b 개의 콜라가 나온다.
// 2. 이것도 빈 병이기 때문에 n에 더한다. -> 다시 1번으로 돌아가서 n에서 a로 나머지연산한 값이
// a보다 작아질 때 까지 반복

int solution(int a, int b, int n) {
    int answer = 0;
    int value;
    
    while(true) {
        // 공병을 주고 받을 수 있는 콜라의 수
        value = n / a * b; // 10, 5, 2
        // 전체 받은 콜라의 수 업데이트
        answer += value; // 10, 15, 17
        // 남은 공병의 수
        n = n % a + value; // 10, 5, 2
        
        if (n < a) {
            break;
        }
    }
    return answer;
}