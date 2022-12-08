#include <string>
#include <vector>

using namespace std;

// 1. 반복문을 사용하여 my_str을 n만큼 잘라서 answer에 넣는다.

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string temp = my_str;
    while (true) {
        answer.push_back(temp.substr(0, n));
        temp = temp.substr(n);
        
        // 남은 길이가 0일때 push_back을 하면 ""을 집어넣는다. 그래서 그대로 리턴
        if (temp.length() == 0) {
            return answer;
        // 남은 길이가 n보다 작으면 그대로 다 넣고 리턴
        } else if (temp.length() < n) {
            answer.push_back(temp);
            return answer;
        }
    }
    return answer;
}