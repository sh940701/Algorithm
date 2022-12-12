func solution(s1 []string, s2 []string) int {
    answer := 0
    for _, s1Value := range s1 {
        for _, s2Value := range s2 {
            if s1Value == s2Value {
                answer++
            }
        }
    }
    return answer
}