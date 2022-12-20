#include <string>
#include <vector>
#include <map>

using namespace std;

// 1. 전체 결과 목록을 담을 map을 만든다. -> map[string]vector 여기서 string에는 "AN", "CF" 등 성격유형이 들어간다.
// 2. vector에는 string의 두 항목에 대한 점수가 들어간다. 
// 3. 마지막에는 map에서 각 string항목별 vector의 점수를 비교하여 더 높은쪽을 리턴하면 된다.
// 위 방법은 안된다. 왜냐하면 "AN", "NA" 이렇게 따로 있기 때문

// 1. 각 유형별을 Key로 하는 요소가 있는 map을 만들어놓는다. 값은 모두 0
// 2. 항목별로 들어오는 점수를 계산해서 map에서 값을 연산해준다.
// 3. 마지막에 map["R"] vs map["T"] 등으로 두 요소를 비교하여 answer에 넣어준다.

// map[string]int를 가지고 계산해주는 함수
void calculate(map<string, int>& m, string s, int num) {
    // 입력값이 3 이하면, 3 -> 1, 2 -> 2, 1 -> 3 으로 변경하여 계산해줌
    if (num == 3) {
        num = 1;
    } else if (num == 1) {
        num = 3;
    // 입력값이 4를 초과하면 4를 빼서 5 -> 1, 6 -> 2, 7 -> 3 으로 변경하여 계산해줌
    } else if (num > 4) {
        num -= 4;
    }
    m[s] += num;
}

// 결과적으로 map에 담긴 값을 비교하여 map[string]의 값이 더 큰 string을 반환해주는 함수
string compare(map<string, int>& m, string a, string b) {
    int aValue = m[a];
    int bValue = m[b];
    if (aValue > bValue) {
        return a;
    } else if (aValue < bValue) {
        return b;
    } else {
        if (a > b) {
            return b;
        } else {
            return a;
        }
    }
}

string solution(vector<string> survey, vector<int> choices) {
    // map 생성
    map<string, int> m;
    // 각 요소를 map에 Value == 0 으로 하여 넣어줌
    vector<string> elements{"R", "T", "C", "F", "J", "M", "A", "N"};
    for (int i = 0; i < elements.size(); ++i) {
        m.insert({elements[i], 0});
    }
    
    for (int i = 0; i < survey.size(); ++i) {
        int value = choices[i];
        // choices[i]의 값이 4라면, 연산할 필요가 없기 때문에 continue
        if (value == 4) {
            continue;
        // choices[i]의 값이 4 미만이면, survey[i]의 첫번째 요소에 대해서 값을 추가해주는 연산 실행
        } else if (value < 4) {
            string s (1, survey[i][0]);
            calculate(m, s, value);
        // choices[i]의 값이 4 초과이면, survey[i]의 두번째 요소에 대해서 값을 추가해주는 연산 실행
        } else if (value > 4) {
            string s (1, survey[i][1]);
            calculate(m, s, value);
        }
    }
    
    string answer = "";
    for (int i = 0; i < elements.size(); i = i + 2) {
        // 각 map[string]에 담긴 값을 비교하여, 더 큰 쪽의 string을 answer에 이어붙여줌
        string result = compare(m, elements[i], elements[i + 1]);
        answer += result;
    }
    
    return answer;
}
