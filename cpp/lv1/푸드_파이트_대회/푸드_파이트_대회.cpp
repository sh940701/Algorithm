#include <string>
#include <vector>

using namespace std;

// 1. food 배열을 돌며 값이 홀수이면 1을 뺀다.
// 2. 모든 숫자를 반으로 나눈 배열을 2개 만든다.
// 3. 첫번째 배열의 arr[i]의 숫자만큼 쭉 string에 앞에서부터 더해준다.
// 4. 두번째 배열의 arr[i]의 숫자만큼 쭉 string에 뒤에서부터 더해준다.
// 5. 배열을 두개 만들어줄 필요 없이 그냥 한 배열로 앞에서 뒤, 뒤에서 앞 하면 되겠네?

string solution(vector<int> food) {
    string answer = "";
    // food배열을 다 짝수로 만들어주고, 1/2로 줄여줌
    for (int i = 1; i < food.size(); ++i) {
        if (food[i] % 2 == 1) {
            --food[i];
        }
        food[i] /= 2;
    }
    
    // i를 string화 하여 fooc[i]횟수만큼 answer에 더해준다.
    for (int i = 1; i < food.size(); ++i) {
        string value = to_string(i);
        for (int j = 0; j < food[i]; ++j) {
            answer += value;
        }
    }
    
    // 중간에 물을 넣어줘야지
    answer += "0";
    
    // 다시 뒤에서부터, 위에서 한 행동 반복
    for (int i = food.size() - 1; i > 0; --i) {
        string value = to_string(i);
        for (int j = 0; j < food[i]; ++j) {
            answer += value;
        }
    }
    return answer;
}