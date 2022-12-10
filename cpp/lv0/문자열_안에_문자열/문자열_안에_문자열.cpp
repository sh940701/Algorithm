#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    // std::string::find 함수는, 첫번째 인자로 문자열 내에서 찾고자 하는 문자열을 받고
    // 두번째 인자로 어디서부터 찾을지 값을 받는다. 만약 찾게 된다면 찾은 위치(pos)를 반환하고
    // 찾지 못하면 std::string::npos 객체를 반환한다.
    if (str1.find(str2, 0) != std::string::npos) {
        answer = 1;
    } else {
        answer = 2;
    }
    return answer;
}