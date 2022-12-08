func solution(num int, total int) []int {
    var result []int
    sum := 0
    // x + (x + 1) + (x + 2) ... = total이다.
    // total에서 자연수만 빼면 num * x가 나온다.
    // total에서 자연수를 뺀 값을 num으로 나누면 x가 나오겠지? -> 그게 초기값
    for i := 1; i < num; i++ {
        sum += i
    }
    // 정답의 0번째 원소를 구한다.
    start := (total - sum) / num
    // append 함수를 사용해서 배열을 채워준다.
    for i := 0; i < num; i++ {
        result = append(result, start + i)
    }
    return result
}