// 이번엔 cpp랑 다른 방식으로 풀어보자.
// 1. 한 요소에 대해서 함수를 돌린다. 그 함수는 문자열을 받아서, 발음 가능한 string으로 계속해서 반복하며
// prefix에 발음 가능한 요소가 있을 경우 그 길이만큼 자른다.
// 2. 자를 수 있을만큼 자른 후, 그 길이가 0이라면 result++를 해준다.

import "strings"

// string을 받아 처리해주는 함수
func compare(s string) int {
    // 발음할 수 있는 문자열들
    pronunciation := []string{"aya", "ye", "woo", "ma"}
    prev := ""
    for {
        // for문을 돌았을 때, 접두어가 한번이라도 겹치는지 확인하기 위한 hit 변수
        hit := 0
        for _, value := range pronunciation {
            // 발음할 수 있는 요소들을 계속 대입하며, 접두어인지 확인한다.
            if strings.HasPrefix(s, value) {
                // 이전 접두어와 현재 value가 같다면, s 문자열을 수정하기 전에 바로 종료해버린다.
                if value == prev {
                    hit = 0
                    break
                }
                // 만약 그렇다면, s를 그 이후 길이만 남겨준다.
                // 또한 prev에 겹친 value를 넣어주고 hit의 값을 올려준다.
                s = s[len(value):]
                prev = value
                hit = 1
            }
        }
        // hit가 0이라면 -> 이는 겹치는 접두어가 없었을 수도 있고, s의 길이가 0이 되어 hit가 0일 수도 있다.
        if hit == 0 {
            break;
        }
    }
    // 위 for문이 종료된 이후, s의 길이를 return한다. 만약 s가 연속되지 않은 발음할 수 있는 요소로 이루어져 있었다면
    // 그 길이는 0이었을 것이다.
    return len(s)
}

func solution(babbling []string) int {
    result := 0
    for _, value := range babbling {
        // 각 요소에 대해서 compare함수에 대입하며, 그 반환값이 0이라면 result++ 한다.
        if compare(value) == 0 {
            result++
        }
    }
    return result
}