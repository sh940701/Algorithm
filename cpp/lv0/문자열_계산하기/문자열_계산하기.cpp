
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    // string객체에서 공백을 기준으로 split하여 vector에 넣어주는 과정
    istringstream iss(my_string);
    string temp;
    vector<string> v;
    while(getline(iss, temp, ' ')) {
        v.push_back(temp);
    }
    
    for(int i = 0; i < v.size(); ++i) {
        if (v[i] == "+" || v[i] == "-") {
            int X = std::stoi(v[i-1]);
            int Y = std::stoi(v[i+1]);
            if (v[i] == "+") {
                // 이 때 v[i+1]에 X + Y를 넣어주면, 다음 연산자에서 계산을 할 때 v[i-1]에 대해
                // stoi 함수를 실행중 문제가 생긴다. -> 이미 int이기 때문
                // 이 부분을 간과해서 시간을 좀 많이 잡아먹었다.
                v[i+1] = to_string(X + Y);
                answer = X + Y;
            } else {
                v[i+1] = to_string(X - Y);
                answer = X - Y;
                }
            } else {
                continue;
            }
        }
    return answer;
}