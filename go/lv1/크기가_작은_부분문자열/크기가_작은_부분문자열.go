func solution(t string, p string) int {
    result := 0
    for i := 0; i < len(t) - len(p) + 1; i++ {
        str := t[i:i+len(p)]
        if str <= p {
            result++
        }
    }
    return result
}