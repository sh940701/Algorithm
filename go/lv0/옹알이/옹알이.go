import "strings"

func solution(babbling []string) int {
    result := 0
    // 발음할 수 있는 단어를 담은 slice 생성
    words := []string {"aya", "ye", "woo", "ma"}
    
    for _, value := range babbling {
        i := 0
        // 현재 보고있는 value를 temp라는 변수에 할당
        temp := value
        // 문자열의 접두어가 words중 포함되어있는지 확인
        for {
            // 만약 있다면
            if strings.HasPrefix(temp, words[i]) {
                
                // 접두어의 길이만큼 temp를 앞에서부터 잘라냄
                temp = temp[len(words[i]):]
                // 잘라냈을 때, 길이가 0이라면
                if len(temp) == 0 {
                    // 발음할 수 있는 것이기 때문에 result값을 ++함
                    result++
                    // 반복문 종료
                    break
                }
                // 길이가 0이 아니라면, 남은 잘려진 temp 문자열에 대해
                // word[0]번 요소부터 다시 검사 시작
                i = 0
                
            // 포함되어 있지 않다면
            } else {
                // i를 증가해가며 word[i]가 temp의 접두어인지 확인
                i++
                // 만약 i가 words slice의 길이를 초과한다면 break
                if i > len(words) - 1 {
                    break
                }
            }
        }
    }
    return result
}