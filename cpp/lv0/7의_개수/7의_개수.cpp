#include <string>
#include <vector>

using namespace std;

// 1. 배열을 돌며 int를 string으로 바꾼다.
// 2. 바꿈과 동시에 7이 얼마나 포함되어 있는지 검사하고 answer++한다.

int solution(vector<int> array) {
    int answer = 0;
    for (int i = 0; i < array.size(); ++i) {
        string temp = to_string(array[i]);
            for (int j = 0; j < temp.length(); ++j) {
                if (temp[j] == '7') {
                    answer++;
                }
            }
    }
    return answer;
}