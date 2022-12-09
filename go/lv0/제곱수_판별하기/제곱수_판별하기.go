import "math"

func solution(n int) int {
    // math.Sqrt는 float64만 받는다. 결과값도 그렇다.
    sqrt := math.Sqrt(float64(n))
    // sqrt를 int로 바꾸면 소수점이 잘린다. 이를 다시 float64로 바꾸면
    // n.000...0 이 된다. 만약 sqrt가 자연수라면 둘이 같을 것이다.
    if float64(int(sqrt)) == sqrt {
        return 1
    } else {
        return 2
    }
}