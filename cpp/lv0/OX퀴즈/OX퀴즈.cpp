#include <string>
#include <vector>
#include <sstream>

using namespace std;

// 1. quiz의 각 요소는 X [연산자] Y = Z 로 이루어져있다. 이 말은 즉 공백별로 단어를 분리하면
// X, 연산자, Y, =, Z 가 된다는 것이다.
// 2. 각 요소를 공백으로 나뉘는 배열로 치환한다. 그렇게 되면 arr[0] == "X", arr[1] == "연산자"
// arr[2] == "Y", arr[3] == "=", arr[4] == "Z" 가 된다.
// 3. 이에 맞춰서 각 X, Y, Z를 숫자로 바꾸고 연산자대로 계산한 결과값과 Z를 비교하면 된다. -> 굿


vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    for (int i = 0; i < quiz.size(); ++i) {
        // string문자열을 구분자로 자르기 위해 sstream을 include하여 istringstream 객체를
        // 만든다. 그리고 이 객체에 연산을 진행할 string을 담아준다.
        istringstream iss(quiz[i]);
        // split 연산의 결과값이 들어갈 string 객체
        string temp;
        // split된 string들이 담길 vector 객체
        vector<string> result;
        
        // getline함수를 실행하면, 첫번째 인자인 iss 객체에서 세번째 인자인 구분자로
        // 나눈 string 값을 temp 변수에 담아준다.
        while(getline(iss, temp, ' ')) {
            // result 벡터에 string 변수 temp의 값을 담아준다.
            result.push_back(temp);
        }
        
        // 각 값을 int로 변환
        int X = std::stoi(result[0]);
        int Y = std::stoi(result[2]);
        int Z = std::stoi(result[4]);
        
        // 연산자가 "-" 일 때 연산 결과가 맞는지 확인 후 answer 벡터에 넣어줌
        if (result[1] == "-") {
            if (X - Y == Z) {
                answer.push_back("O");
            } else {
                answer.push_back("X");
            }
            
        // 연산자가 "+" 일 때 연산 결과가 맞는지 확인 후 answer 벡터에 넣어줌
        } else if (result[1] == "+") {
            if (X + Y == Z) {
                answer.push_back("O");
            } else {
                answer.push_back("X");
            }
        }
    }
    return answer;
}