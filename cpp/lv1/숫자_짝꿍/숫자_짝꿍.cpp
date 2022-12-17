#include <string>
#include <vector>

using namespace std;

// 1. X에 대해서 Y의 원소 하나하나 돌아가면서 있는지 파악한다.
// 2. 있다면 temp 벡터에 넣고, X의 그 자리 값을 엉뚱한 값으로 바꾼다(0~9가 아닌 다른)
// 3. temp는 int로 이루어져있는 vector이고, 그 배열을 내림차순으로 정렬한다.
// 4. 다 문자열로 만들어서 더해준다.

// string solution(string X, string Y) {
//     if (X.size() > Y.size()) {
//         swap(X, Y);
//     }
//     string answer = "";
//     // vector<int> temp;
//     vector<char> temp;
//     for (int i = 0; i < Y.length(); ++i) {
//         if (auto idx = X.find(Y[i]); idx != string::npos) {
//             X[idx] = 'a';
//             // char -> int의 방법. '1' - '0' == 숫자 1이 됨
//             // temp.push_back(Y[i] - '0');
//             temp.push_back(Y[i]);
//         }
//     }
//     // 이제 temp에는 int로 바뀐 짝꿍 숫자들이 들어있다.
//     if (temp.size() == 0) {
//         return "-1";
//     } else {
//         sort(temp.begin(), temp.end(), greater<char>());
//         if (temp[0] == '0') {
//             return "0";
//         } else {
//             string s(temp.begin(), temp.end());
//             return s;
//         }
//     }
//     return answer;
// }



// 실행해보니, 아예 아래 반복문을 실행하는 것 자체만으로 11~ 15번에서 시간초과가 발생한다.
// string solution(string X, string Y) {
//     int q = 0;
//     for (int i = 0; i < Y.length(); ++i) {
//         if (auto idx = X.find(Y[i]); idx != string::npos) {
//             // ++q;
//             X[idx] = 'a';
//         }
//     }
//     return "a";
// }





// 아래 for문도 실행이 된다. -> vector 객체의 길이를 계속 늘려가며 만드는 것도 별 문제가 되지 않는듯?
// 위 로직에서 X[idx]의 요소를 바꿔주는 행위가 뭔가 문제가 됐던걸까
// string solution(string X, string Y) {
//     vector<char> q;
//     for (int i = 0; i < Y.length(); ++i) {
//         if (auto idx = X.find(Y[i]); idx != string::npos) {
//             q.push_back(X[idx]);
//         }
//     }
    
//     string s(q.begin(), q.end());
//     return s;
// }




// 위에서는 이미 센 data를 다시 세지 않게 하기 위해 해당 위치의 요소 값을 바꿔주었다.
// 이번에는 아예 다른 방식으로 풀어보자
string solution(string X, string Y) {
    // X에서 각 0 ~ 9의 개수를 나타낼 vector와, 이와 같은 Y의 vector를 만든다.
    // 이 벡터는 0 ~ 9의 데이터를 index로 하여, 해당 data의 개수만큼 vector[index]에 값이 담긴다.
    vector<int> Xvector = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<int> Yvector = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    for (int i = 0; i < X.length(); ++i) {
        // byte형 숫자('5' 등) 를 int로 바꾸는 방법 -> '5' - '0' == 숫자 5
        int toInt = X[i] - '0';
        // Xvector를 순회하며, 각 데이터 '0' ~ '9' 가 나올때마다 Xvector[0 ~ 9]의 값을 1씩 추가해준다.
        Xvector[toInt] += 1;
    }
    
    // Yvector에 대해서도 같은 연산 진행
    for (int i = 0; i < Y.length(); ++i) {
        int toInt = Y[i] - '0';
        Yvector[toInt] += 1;
    }
    
    // 두 X, Y vector를 합칠 vector
    vector<int> merge;
    
    for (int i = 0; i < 10; ++i) {
        int Xvalue = Xvector[i];
        int Yvalue = Yvector[i];
        // 0 ~ 9에서 각 Xvector와 Yvector의 같은 vector[index]값 중 작은 값을 넣는다.
        // X에 '3'이 4개 있고, Y에 '3'이 40개 있다면, 짝꿍이 될 수 있는 것은 결국 4개 뿐이기 때문이다.
        if (Xvalue < Yvalue) {
            merge.push_back(Xvalue);
        } else {
            merge.push_back(Yvalue);
        }
    }
    
    // 결과 char요소들을 담을 result vector
    vector<char> result;
    
    // 가장 큰 수를 만들어야 하기 때문에, merge의 맨 뒤 요소부터 반복한다.
    // 예를 들어 merge[9]에는 X와 Y에서 짝꿍이 될 수 있는 '9'의 개수가 들어있다.
    for (int i = 9; i >= 0; --i) {
        // 만약 짝꿍이 될 수 있는 개수가 없으면 continue
        if (merge[i] == 0) {
            continue;
        }
        
        // 짝꿍이 있다면, 그 개수만큼 result vector에 넣어준다.
        // 예를 들어 merge[9] == 10 이라면 X와 Y에 최소 '9'가 10개 겹친다는 것이다.
        // 그러므로 반환값에 9를 10번 추가해주는 것이다.
        for (int j = 0; j < merge[i]; ++j) {
            result.push_back((char)(i + 48));
        }
    }
    
    // char 배열 result를 string 객체로 바꿔준다.
    string s(result.begin(), result.end());
    
    // 만약 겹치는 요소(짝꿍이 될 수 있는 요소)가 하나도 없다면 "-1" 리턴
    if (s.size() == 0) {
        return "-1";
    // 위에서 result에 9부터 시작하는 문자열을 만들어주었는데, 0이 맨 앞에 있다는 것은
    // 짝꿍이 될 수 있는 요소가 '0'밖에 없다는 것이다. 그러므로 "0"을 리턴
    } else if (s[0] == '0') {
        return "0";
    }
    
    return s;
}