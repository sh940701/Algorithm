#include <string>
#include <vector>

// 숫자를 문자열로 바꾼 후, 각 byte를 숫자로 바꾼 후 더해주는 방식으로 계산해보자

using namespace std;

int solution(int n) {
    int answer = 0;
    string strnum = to_string(n);
    
    for (int i = 0; i < strnum.length(); ++i) {
        // 아래와 같이 const char* 타입으로 넘겨주면, strnum[i]은
        // strnum[i]를 포함하여 뒤로 이어진 모든 문자열이 된다. -> 1234일때
        // temp = 1234, temp = 234, temp = 34, temp = 4 이렇게
        // 아마 원본 배열의 주소값을 temp가 담게 되어서 그런 것 같다.
        // const char* temp = &strnum[i];
        // answer += atoi(temp);
        
        // 아래와 같이 실행하면 내가 원하는대로 한 byte의 값만 temp에 넘겨지게 된다.
        // 이는 아마도 주소값이 아니라 하나하나의 값이 "복사"되기 때문인 것 같다.
        // &temp에는 원본 주소값이 아니라 복사되어 한 char의 값이 담긴 변수의 주소값이 담기는 것이다.
        const char temp = strnum[i];
        answer += atoi(&temp);
    }
    return answer;
}