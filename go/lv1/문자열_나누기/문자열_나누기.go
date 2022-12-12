func solution(s string) int {
    answer := 0
    // string을 하나씩 나누면 rune type data가 반환된다.
    var char rune
    charCnt := 0
    otherCnt := 0
    for idx, value := range s {
        // charCnt가 0이면 현재 rune으로 초기화해준다.
        if charCnt == 0 {
            char = value
            charCnt++
        // charCnt가 0이 아니면 현재 rune 값을 기준으로 나눠준다.
        } else {
            // 현재 rune이 char 값과 같을 때
            if char == value {
                charCnt++
            // 현재 rune이 char 값과 다를 때
            } else {
                otherCnt++
                // otherCnt++ 를 해준 후, charCnt와 otherCnt가 같을 때
                if charCnt == otherCnt {
                    answer++
                    charCnt = 0
                    otherCnt = 0
                }
            }
        }
        // 마지막에 나누어떨어지지 않고 나머지가 생길 때
        if (idx == len(s) - 1) && charCnt != otherCnt {
            answer++
        }
    }
    return answer
}