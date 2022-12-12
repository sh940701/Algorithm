#include <string>
#include <vector>

using namespace std;

// 1. 좌측부터 읽어가면서 첫번째 문자열을 센다. 그 문자열은 temp이다.
// 2. 이후 문자가 temp와 같으면 tempCnt++, 아니면 otherCnt++ 한다.
// 3. 두 개가 같아지면 answer++하고 이후 문자열부터 다시 1번 반복

int solution(string s) {
    int answer = 0;
    char temp;
    int charCnt = 0;
    int otherCnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        // charCnt가 0이면 현재 문자로 초기화해준다.
        if (charCnt == 0) {
            temp = s[i];
            charCnt++;
        } else {
            // temp에 기준 문자가 있을 때
            // 같은 문자가 나오면 charCnt++
            if (temp == s[i]) {
                charCnt++;
            } else {
                // 다른 문자가 나오면 otherCnt++ 이후 charCnt와 otherCnt가
                // 같은지 판단하여, 같다면 둘 다 0으로 초기화해주고 answer++ 해준다.
                otherCnt++;
                if (charCnt == otherCnt) {
                    ++answer;
                    charCnt = 0;
                    otherCnt = 0;
                }
            }
        }
        // 마지막에 나누어떨어지지 않을 경우를 대비하여 answer++ 해주는 로직
        if ((i == s.length() - 1) && (charCnt != otherCnt)) {
            ++answer;
        }
    }
    return answer;
}