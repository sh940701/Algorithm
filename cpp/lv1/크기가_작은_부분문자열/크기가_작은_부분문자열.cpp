#include <string>
#include <vector>

using namespace std;

// t에 대해서 for문을 반복하는데, t[i] ~ t[p.length()]까지만큼 중 t보다 작은 것의 숫자를 센다.
// 이 때 string을 int로 바꿔야할지는 아직 모르겠다.

// 안바꿔도 된다. ㅎㅎ

int solution(string t, string p) {
    int plen = p.length();
    int tlen = t.length();
    int answer = 0;
    for (int i = 0; i < tlen - plen + 1; ++i) {
        string str = t.substr(i, plen);
        if (str <= p) {
            ++answer;
        }
    }
    return answer;
}