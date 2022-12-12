func solution(s string) []int {
    var temp int
    var result []int
    for idx, value := range s {
        // temp값 -1로 초기화
        temp = -1
        for j := 0; j < idx; j++ {
            // s[j]는 byte 이고 value는 rune이다. 비교를 위해서 타입을 변경해줌
            if s[j] == byte(value) {
                temp = idx - j
            }
        }
        // result 슬라이스에 temp값 추가
        result = append(result, temp)
    }
    return result
}