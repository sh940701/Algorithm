#include <string>
#include <vector>
#include <deque>

using namespace std;

// 이 문제는 삭제와 삽입을 많이 해야 하니 list를 사용해서 풀어보자 -> 근데 계속해서 탐색도 이루어지기
// 때문에 list보다는 deque를 사용해보자
// 1. k를 담을 deque를 만든다.
// 2. score를 순회하면서 kDeque에 숫자를 정렬해가며 담는다.
// 3. kDeque의 길이가 k와 같아졌으면, 처음에는 맨 마지막, 맨 첨 원소랑 비교해서
//    맨 첨 원소보다 크면 맨 뒤 삭제하고 맨앞에 넣기, 맨 뒤 원소보다 작으면 버린다.
// 4. 맨 마지막 원소보다 크면 알맞은 자리에 넣고 다시 kDeque의 마지막 원소를 answer에 넣는다.

vector<int> solution(int k, vector<int> score) {
    vector<int> a;
    deque<int> kDq;
    vector<int> answer;
    for (int i = 0; i < score.size(); ++i) {
        // 일단은 kDq의 길이가 k보다 작을 때
        if (kDq.size() < k) {
            // kDq에 암것도 없을 때
            if (kDq.size() == 0) {
                kDq.push_back(score[i]);
                answer.push_back(score[i]);
            } // kDq에 하나만 있을 때
            else if (kDq.size() == 1) {
                if (kDq[0] < score[i]) {
                    kDq.push_front(score[i]);
                    answer.push_back(kDq.back());
                } else {
                    kDq.push_back(score[i]);
                    answer.push_back(kDq.back());
                }
            }
            // kDq에 두 개 이상 원소가 있을 때
            // 맨 앞 원소보다 클 때
            else {if (kDq.front() <= score[i]) {
                kDq.push_front(score[i]);
                answer.push_back(kDq.back());
            // 맨 뒤 원소보다 작을 때
            } else if (kDq.back() >= score[i]) {
                kDq.push_back(score[i]);
                answer.push_back(kDq.back());
            // 가운데일 때
            } else {
                for (int j = 1; j < kDq.size(); ++j) {
                    if (kDq[j - 1] >= score[i] && kDq[j] <= score[i]) {
                        auto iter = kDq.insert(kDq.begin() + j, score[i]);
                        answer.push_back(kDq.back());
                        break;
                    }
                }
            }
                 }
        // kDq의 길이가 k와 같을 때
        } else {
            // 맨 앞 원소보다 클 때
            if (kDq.front() <= score[i]) {
                kDq.pop_back();
                answer.push_back(kDq.back());
                kDq.push_front(score[i]);
            // 맨 뒤 원소보다 작을 때
            } else if (kDq.back() >= score[i]) {
                answer.push_back(kDq.back());
                continue;
            // 가운데일 때
            } else {
                for (int j = 1; j < kDq.size(); ++j) {
                    // 중간 범위에서 다룰 때, 같은 경우도 포함해줘야 한다...
                    // 여기서 <= 를 안 포함해주면 예를 들어 score[i]와 kDq[j]가 같은 값일 경우
                    // 아래 반복문에 if문에 잡히지 않고 그냥 넘어가게 된다. 시간 많이 썼네 ㅎㅎ ..
                    if (kDq[j - 1] >= score[i] && kDq[j] <= score[i]) {
                        kDq.pop_back();
                        kDq.insert(kDq.begin() + j, score[i]);
                        answer.push_back(kDq.back());
                        break;
                    }
                }
            }
        }
    }
    return answer;
}