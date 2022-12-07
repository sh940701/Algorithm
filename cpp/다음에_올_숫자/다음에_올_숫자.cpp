#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int gap0 = common[1] - common[0];
    int gap1 = common[2] - common[1];
    // 갭이 같으면 등차수열이다.
    if (gap0 == gap1) {
        // 마지막 원소에 갭만큼 더해준다.
        answer = common[common.size() - 1] + gap0;
    // 갭이 다르면 등비수열이다.
    } else {
        // 마지막 원소에 갭만큼 곱해준다.
        int gap = gap1 / gap0;
        answer = common[common.size() - 1] * gap;
    }
    return answer;
}