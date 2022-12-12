#include <string>
#include <vector>

using namespace std;

// 1. 한 글자씩 돌아가면서 연산을 한다. 이 때 자기보다 앞에 있는 녀석들을 쭉 돌면서
// 같은 녀석이 있으면, 그 자리에 숫자를 넣는다.
// 2. 같은 녀석이 또 있으면 숫자를 업데이트하여 그 자리에 넣는다.

vector<int> solution(string s) {
    vector<int> answer;
    for (int i = 0; i < s.length(); ++i) {
        // 없을 경우를 대비해서 temp는 -1로 고정시켜놓는다.
        int temp = -1;
        // i 이전까지의 반복문을 실행한다.
        for (int j = 0; j < i; ++j) {
            // s[j]와 s[i]가 같으면 temp를 그 자리값의 차이로 업데이트한다.
            if (s[j] == s[i]) {
                temp = i - j;
            }
        }
        // 최종적으로 temp는 한 문자와 가장 가까운 같은 문자, 없으면 -1로 고정된다.
        answer.push_back(temp);
    }
    return answer;
}