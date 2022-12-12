// golang은 cpp와 다르게 숫자를 문자로 바꾸는 식으로 진행해보자
import "strconv"

func solution(num int, k int) int {
    // num을 문자열로 바꿈
    str := strconv.Itoa(num)
    // k를 문자열로 바꿈
    kStr := strconv.Itoa(k)
    for idx, value := range str {
        // 발견된 첫번째 위치의 값을 리턴해야 하기 때문에 발견되는 즉시 리턴을 해줌
        // 이 때 value는 rune타입이기 때문에 string으로 바꿔줘야 한다.
        if kStr == string(value){
            return idx + 1
        }
    }
    // 일치하는 값이 없으면 그대로 -1 리턴
    return -1
}