import "strings"
import "strconv"

func solution(my_string string) int {
    // 공백을 없앤 문자열 배열 생성
    s := strings.Split(my_string, " ")
    // result에 s[0]값을 int로 바꿔 초기화
    result, _ := strconv.Atoi(s[0])
    
    for idx, value := range s {
        // value가 + 연산자일 때
        if value == "+" {
            temp, _ := strconv.Atoi(s[idx + 1])
            result += temp
        // value가 - 연산자일 때
        } else if value == "-" {
            temp, _ := strconv.Atoi(s[idx + 1])
            result -= temp
        }
    }
    return result
}