#include <string>
#include <vector>

using namespace std;

// numlist를 돌며, n으로 나머지 연산을 했을 때 결과값이 0인 요소만 남김

vector<int> solution(int n, vector<int> numlist) {
    vector<int> answer;
    for (int i = 0; i < numlist.size(); ++i) {
        if (numlist[i] % n == 0) {
            answer.push_back(numlist[i]);
        }
    }
    return answer;
}