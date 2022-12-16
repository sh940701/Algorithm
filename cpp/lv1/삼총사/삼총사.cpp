#include <string>
#include <vector>

using namespace std;

// number의 길이가 3 <= num <= 13이라서 그냥 무지성 for문을 해도 될 것 같다 ㅎㅎ
// 1. 각 원소에 대해서 이후 모든 원소들과 만들 수 있는 쌍을 만들고, 그 합이 0인지 확인한다.
// 함수를 하나 만들어서 재귀를 써도 될 것 같긴 하지만, 그냥 for문으로 해결하는게 나는 더 깔끔한 것 같다.

int solution(vector<int> number) {
    int answer = 0;
    // i는 세 개 중 첫번째이기 때문에 마지막에서 세번째 까지만 갈 수 있다.
    for (int i = 0; i < number.size() - 2; ++i) {
        // j는 세 개 중 두번째이기 때문에 마지막에서 두번째 까지만 갈 수 있다.
        // 또한 i보다 최소 1 앞에 있어야 한다. -> i와 겹치면 안됨
        for (int j = i + 1; j < number.size() - 1; ++j) {
            // z는 세 개 중 세번째이기 때문에 마지막까지 갈 수 있다.
            // 또한 j보다 최소 1 앞에 있어야 한다. -> i, j와 겹치면 안됨
            for (int z = j + 1; z < number.size(); ++z) {
                if (number[i] + number[j] + number[z] == 0) {
                    ++answer;
                }
            }
        }
    }
    return answer;
}