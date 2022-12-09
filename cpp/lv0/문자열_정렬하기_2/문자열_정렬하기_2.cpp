#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = my_string;
    for (int i = 0; i < answer.length(); ++i) {
        // tolower함수를 이용해 대문자를 모두 소문자로 바꿔준다.
        answer[i] = tolower(answer[i]);
    }
    
    // sort 함수객체를 이용해 정렬해준다.
    std::sort(answer.begin(), answer.end());
    
    return answer;
}