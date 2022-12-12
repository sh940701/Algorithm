func solution(n int) []int {
    result := []int{}
    for i := 1; i <= n / 2; i++ {
        if n % i == 0 {
            result = append(result, i)
        }
    }
    result = append(result, n)
    return result
}