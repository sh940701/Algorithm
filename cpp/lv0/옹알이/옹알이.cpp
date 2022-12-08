#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 1. string의 모든 원소를 돌면서 첫 단어에 "aya", "ye", "woo", "ma"가 포함되어 있는지 확인
// 2. 첫 단어에 포함되어 있다면, 이어지는 단어에 위 4 단어가 포함되어 있는지 확인
// 3. 위 두 가지 경우를 만족한다면 answer++



int solution(vector<string> babbling) {
    std::vector<string> v{"aya", "ye", "woo", "ma"};
    
    int answer = 0;
    
    for (int i = 0; i < babbling.size(); ++i) {
        int j = 0;
        std::string temp = babbling[i];
        while (true) {
            // 첫 문자열이 v 원소와 같은지 파악 -> 같다면
            if (temp.rfind(v[j], 0) == 0) {

                // 같은 문자열을 제외하고 뒤부터 temp에 담음
                temp = temp.substr(v[j].length());

                // temp에 담은 결과값이 0이면 answer값을 올리고 break
                if (temp.length() == 0) {
                    ++answer;
                    break;
                }
                j = 0;
                continue;
            }
            else {
                ++j;
                if (j > v.size() - 1) {
                    break;
                }
            }
        }
    }
    return answer;
}


int main() {
    std::vector<string> v{"aya", "yee", "u", "maa", "wyeoo"};
    std::cout << solution(v) << std::endl;

    // std::string s {"hihihihello"};

    // std::string s1 = "hihihihello";

    // std::string s0 = s.substr(s1.length());

    // std::cout << s0.length() << std::endl;
}