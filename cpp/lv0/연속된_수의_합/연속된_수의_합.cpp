#include <string>
#include <vector>

using namespace std;

// 1. 1부터 num - 1 번 만큼 1씩 커지는 등차수열의 형식으로 더해간다.
// 2. 더한 값을 total에서 뺀다.
// 3. 2번에서 나온 값을 num으로 나누면 배열의 0번 원소가 나온다.
// 4. 배열의 0번 원소로부터 1씩 커지는 등차수열로 num 번 까지 값을 answer에 넣는다.

vector<int> solution(int num, int total) {
    vector<int> answer;
    int sum = 0;
    
    for (int i = 1; i < num; ++i) {
        sum += i; // 위 1번의 값을 구해준다.
    }
    
    int start = (total - sum) / num; // 배열의 0번 원소 구하기
    
    for (int i = 0; i < num; ++i) {
        answer.push_back(start + i); // 배열의 0번 원소부터 n개만큼의 원소 answer에 추가
    }
    
    return answer;
}