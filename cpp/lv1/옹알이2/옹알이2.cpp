#include <string>
#include <vector>
#include <deque>

using namespace std;

// 1. 원소를 돌며 각 원소가 babbling에 포함되어있는지 확인한다.
// 2. 이 때 원소의 길이가 2 이상일 경우, 한 글자씩 temp에 더해가며 4개 목록중 같은 문장이 있는지 확인한다.
// 3. 같은 문장이 있을 경우, temp에서 해당 문장을 빼고, 그 값을 prev에 넣어준다 -> 이어지는 문장이 temp와 같으면 실패이기 때문
// 4. temp에 대해서 계속 검사를 하며, 이어지지 않는 발음 가능한 문장들로 끝까지 구성되어 있을 경우 ++answer
// 5. 이외의 경우에는 그냥 통과한다.

const vector<string> pronunciation = {"aya", "ye", "woo", "ma"};

// 비교해주는 함수. string을 받아서 발음할 수 있는 string인지 여부를 반환한다.
bool compare(string s) {
    for (string p : pronunciation) {
        if (s == p) {
            return true;
        }
    }
    return false;
}

int solution(vector<string> babbling) {
    int answer = 0;
    string temp = "";
    string prev = "";
    
    // babbling 배열의 모든 요소에 대해 연산을 진행한다.
    for (int i = 0; i < babbling.size(); ++i) {
        // 발음할 수 있는 단어의 최소가 2이기 때문에 원소가 그 이하라면 continue한다.
        if (babbling[i].length() < 2) {
            continue;
        }
        // 원소를 구성하고 있는 각 글자에 대해 연산한다.
        for (int j = 0; j < babbling[i].length(); ++j) {
            // temp에 계속 더해준다.
            temp += babbling[i][j];
            // temp를 계속 compare함수에 넣어서 true라면(발음할 수 있다면)
            if (compare(temp) == true) {
                // 이전에 나온 발음 가능한 요소와 같은 요소인지 비교한다.
                if (temp == prev) {
                    break;
                }
                // 위를 통과했다면, prev를 temp로 담아주고, temp는 빈 문자열로 초기화한다.
                prev = temp;
                temp = "";
            // 아래는 최적화를 위한 연산 -> temp가 발음할 수 있는 최대 길이인 3을 초과했다면
            // 이미 해당 data는 발음할 수 없는 것이기 때문에 반복문을 바로 종료한다.
            } else if (temp.length() > 3) {
                break;
            } 
        }
        // 반복문이 종료된 후 temp가 빈 문자열이면 ++answer를 한다.
        // temp가 빈 문자열이 아니라는 것은 발음 가능한 문자열을 제외하고 나머지 문자가 있다는 것이다.
        if (temp.length() == 0) {
            ++answer;
        }
        // 반목문이 끝난 후 temp와 prev 초기화
        temp = "";
        prev = "";
    }
    return answer;
}