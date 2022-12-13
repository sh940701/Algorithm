#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 한 상자에 적은 점수의 사과가 최대한 안 들어가야 하는거니까, 큰 숫자먼저로 정렬하고
// m개씩 잘라서 박스별 가장 작은 점수를 확인하고 곱하기 m개를 반복하면 되는게 아닌가?
// 아 이상하다 왜케 쉽게 풀리지,,, sort를 사용하면 안되는건가?
// set으로 <int>int 해서 k ~ 1까지 key에 0을 담아놓고 한바퀴 돌면서 숫자마다 개수를 세어준 후
// 그 결과값으로 있는대로 나누고 나누고 해서 구할수도 있긴 할 것 같다. 그치만 그걸 하기엔 지금 너무 늦었ㅇ어..

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int count = 0;
    sort(score.begin(), score.end(), greater<int>());
    for (int i = 0; i < score.size(); ++i) {
        count++;
        if (count == m) {
            // 가장 작은 점수는 m으로 나눴을 때 마지막 원소겠지? -> 그리고 그건 현재 원소겠지?
            answer += score[i] * m;
            count = 0;
        }
    }
    return answer;
}