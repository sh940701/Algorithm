func solution(n int, numlist []int) []int {
    // 여기서 var result []int 로 생성해주면 1번문제가 틀렸다고 나온다 머가 문젠지..
    result := []int{}
    for _, num := range numlist {
        if num % n == 0 {
            result = append(result, num)
        }
    }
    return result
}