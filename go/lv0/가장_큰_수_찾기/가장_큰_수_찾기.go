func solution(array []int) []int {
    result := []int{0, 0}
    for idx, value := range array {
        if value > result[0] {
            result[0] = value
            result[1] = idx
        }
    }
    return result
}