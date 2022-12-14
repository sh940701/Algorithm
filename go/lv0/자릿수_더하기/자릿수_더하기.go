// 이번에는 나머지 연산을 통해 10, 100, 1000 으로 나머지를 더하는 방식으로 연산해보자.
// 그렇게 하면 안될 것 같다. 1000으로 나머지 연산을 하면 100, 10, 1의자리가 모두 포함된 숫자가 나온다.
// 방법을 바꿔서 10으로 나눈 다음에 10으로 나머지 연산을 하는 방식으로 해야겠다.
// 연산 대상은 int이기 때문에 10으로 나누는 매 연산마다 소숫점은 절삭될것이다.

func solution(n int) int {
    result := 0
    for {
        if n < 10 {
            result += n
            break
        }
        temp := n % 10
        result += temp
        n = n / 10
    }
    return result
}