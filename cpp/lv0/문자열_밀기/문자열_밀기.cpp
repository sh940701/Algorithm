#include <string>
#include <vector>

using namespace std;

// 1. 문자열을 뒤에서 1 자르고 앞에 붙인다. -> temp
// 2. for문을 사용해 반복하면서 횟수를 센다.
// 3. temp와 B가 같으면 횟수 리턴, temp와 A가 다시 같아지면 -1 리턴
// 4. 만약 A와 B가 같으면 시작할 때 바로 0을 리턴

int solution(string A, string B) {
    if (A == B) {
        return 0;
    }
    int answer = 0;
    string temp = A;
    while (true) {
        temp = temp.substr(temp.length() - 1) + temp.substr(0, temp.length() - 1);
        answer++;
        if (temp == B) {
            return answer;
        } else if (temp == A) {
            return -1;
        }
    }
}