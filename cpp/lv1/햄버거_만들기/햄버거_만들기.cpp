// 진짜 개고생했다.
// 1231찾고, 그 이후에 계속 1231을 찾은다음에 다시 남은 녀석들에서 1231을 찾고 이런식으로 반복했는데 안되길래 완벽한데 뭐가 문제지 고민했다.
// [1, 2, 1, 2, 3, 1, 3, 1, 2, 3, 1, 2, 3, 1] -> [1, 2, (1, 2, 3, 1), 3, 1, 2, 3, 1, 2, 3, 1] -> [(1, 2, 3, 1), 2, 3, 1, 2, 3, 1] -> [2, 3, 1, 2, 3, 1] -> 
// [2, 3, (1, 2, 3, 1)] -> [2, 3] 답은 3 이런 식으로 하는건데 나는
// [1, 2, (1, 2, 3, 1,) 3, 1, 2, 3, 1, 2, 3, 1] -> // [1, 2, 3, (1, 2, 3, 1,) 2, 3, 1] -> [1, 2, 3, 2, 3, 1] 답은 2 이렇게 하니까 당연히 안되지.......
// 너무 많은 에너지를 이 방식대로 하는데 쏟았다. 그치만 방법을 알았으니 풀긴 풀어야겠지......... .. ..  . .. .. . . .

// #include <string>
// #include <vector>

// using namespace std;

// // 1. 그냥 반복하면서 1231이면 answer++하고 그 공백을 메꾼담에 다시 첨부터 하면 안되나

// int solution(vector<int> ingredient) {
//     int answer = 0;

//         int count = 0;
        
//         int frontBread = 0;
//         int fbIdx;
        
//         int vegtable = 0;
//         int vegIdx;
        
//         int meat = 0;
//         int meatIdx;
        
//         int lastBread = 0;
        
//         for (int i = 0; i < ingredient.size(); ++i) {
//             if (ingredient[i] == 0) {
//                 continue;
//             }
//             if (frontBread == 0 && vegtable == 0 && meat == 0 && lastBread == 0) {
//                 if (ingredient[i] == 1) {
//                     frontBread = 1;
//                     fbIdx = i;
//                 }
//                 continue;
//             } else if (frontBread == 1 && vegtable == 0 && meat == 0 && lastBread == 0) {
//                 if (ingredient[i] == 1) {
//                     fbIdx = i;
//                 } else if (ingredient[i] == 2) {
//                     vegtable = 1;
//                     vegIdx = i;
//                 } else {
//                     frontBread = 0;
//                     fbIdx = -1;
//                 }
//                 continue;
//             } else if (frontBread == 1 && vegtable == 1 && meat == 0 && lastBread == 0) {
//                 if (ingredient[i] == 1) {
//                     fbIdx = i;
//                     vegtable = 0;
//                     vegIdx = -1;
//                 } else if (ingredient[i] == 2) {
//                     frontBread = 0;
//                     vegtable = 0;
//                     fbIdx = -1;
//                     vegIdx = -1;
//                 } else if (ingredient[i] == 3) {
//                     meat = 1;
//                     meatIdx = i;
//                 }
//                 continue;
//             } else if (frontBread == 1 && vegtable == 1 && meat == 1 && lastBread == 0) {
//                 if (ingredient[i] == 1) {
//                     ++count;
//                     frontBread = 0;
//                     vegtable = 0;
//                     meat = 0;
//                     ingredient[i] = 0;
//                     ingredient[fbIdx] = 0;
//                     ingredient[vegIdx] = 0;
//                     ingredient[meatIdx] = 0;
//                     fbIdx = -1;
//                     vegIdx = -1;
//                     meatIdx = -1;
//                     i = -1;
//                 } else {
//                     frontBread = 0;
//                     vegtable = 0;
//                     meat = 0;
//                     fbIdx = -1;
//                     vegIdx = -1;
//                     meatIdx = -1;
//                 }
//             }
//             // if (ingredient[i] == 1) {
//             //    if (frontBread == 1 && vegtable == 1 && meat == 1) {
//             //         ++count;
//             //         frontBread = 0;
//             //         vegtable = 0;
//             //         meat = 0;
//             //         ingredient[i] = 0;
//             //         ingredient[fbIdx] = 0;
//             //         ingredient[vegIdx] = 0;
//             //         ingredient[meatIdx] = 0;
//             //         continue;
//             //     } else {
//             //        frontBread = 1;
//             //        vegtable = 0;
//             //        meat = 0;
//             //        fbIdx = i;
//             //        vegIdx = -1;
//             //        meatIdx = -1;
//             //     }
//             // } else if (ingredient[i] == 2) {
//             //     if (frontBread == 1 && vegtable == 0) {
//             //         vegtable = 1;
//             //         vegIdx = i;
//             //     } else {
//             //         frontBread = 0;
//             //         vegtable = 0;
//             //         meat = 0;
//             //         fbIdx = -1;
//             //         vegIdx = -1;
//             //         meatIdx = -1;
//             //     }
//             // } else if (ingredient[i] == 3) {
//             //     if (frontBread == 1 && vegtable == 1 && meat == 0) {
//             //         meat = 1;
//             //         meatIdx = i;
//             //     } else {
//             //         frontBread = 0;
//             //         vegtable = 0;
//             //         meat = 0;
//             //         fbIdx = -1;
//             //         vegIdx = -1;
//             //         meatIdx = -1;
//             //     }
//             // }
//         }
//         answer += count;
//     return answer;
// }









// stack개념을 이용해서 다시 푼 문제 -> 너무 쉽게 풀린다. 자료구조의 중요성을 알게 됨..

#include <string>
#include <vector>
#include <deque>

using namespace std;

// 1. 먼저, 돌면서 1231을 찾는다.
// 2. 1231을 찾으면, 그 이전과 그 이후를 이어붙인다.
// 3. idx 최대 4까지 돌아가면서 1이 있는지 찾고, 있다면 거기서부터 다시 i를 시작한다. -> 이딴거 필요없다. 그냥 스택으로 하면됨...

// 일단 이건 배열을 뭐 이어붙이고 뭐고 하는 문제가 아니었다. 그냥 스택 쓰면 슥 - 삭 풀리는 문제.. 였다

int solution(vector<int> ingredient) {
    // 임시 temp 벡터를 만들어준다. 이 벡터를 stack형식으로 사용해준다.
    vector<int> temp;
    int answer = 0;
    for (int i = 0; i < ingredient.size(); ++i) {
        // temp에 ingredient의 요소를 하나씩 넣어준다.
        temp.push_back(ingredient[i]);
        // temp에 4개 이상의 원소가 모이면, 그때부터 계속 검사를 해준다.
        if (temp.size() > 3) {
            int size = temp.size();
            // temp 마지막부터 4개의 원소가 1321 순서로 정렬되어있다면, 원본 배열에서 1231이었다는 것이기 때문에
            // 해당 4개를 빼주고 answer++한다. 이후에도 계속 같은 방식으로 진행하면 answer가 정답이 된다.
            if (temp[size - 1] == 1 && temp[size - 2] == 3 && temp[size - 3] == 2 && temp[size - 4] == 1) {
                ++answer;
                temp.pop_back();
                temp.pop_back();
                temp.pop_back();
                temp.pop_back();
            }
        }
    }
    return answer;
}