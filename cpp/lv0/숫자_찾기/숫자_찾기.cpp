#include <string>
#include <vector>

using namespace std;

// 숫자로 먼저 해보자, 계속 10으로 나누고 10나머지 연산을 해서 나머지가 num인 숫자를 찾는다.
// num인 숫자가 있다면 몇번째에 나왔는지 기록해놓고, 나머지연산과 나누기를 게속해서
// 전체 숫자는 몇자리수인지 기록한다.
// 이후 num인 숫자가 있다면, 전체 자리수에서 해당 숫자의 자리수를 빼서 리턴해면 된다.

int solution(int num, int k) {
    if (num == k) {
        return 1;
    }
    int answer = 0;
    int numlength = 0;
    
    while(true) {
        // 전체 숫자 자릿수를 +1한다.
        numlength++;
        if (num % 10 == k) {
            // 조건이 맞으면 k의 위치를 해당 현재 숫자의 길이로 초기화한다.
            answer = numlength;
        }
        num = num / 10;
        
        // 10 이하의 숫자를 10으로 나누면 int는 0이 되기 때문에 break한다.
        if (num == 0) {
            break;
        }
    }
    if (answer == 0) {
        return -1;
    }
    // 뒤에서부터 쟀기 때문에 전체 - 뒤에서부터 발견된 자리 + 1을 해줘야 앞에서부터의 값이 나온다.
    return numlength - answer + 1;
}