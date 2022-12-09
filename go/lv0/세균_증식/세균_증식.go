import "math"

func solution(n int, t int) int {
    return n * (int(math.Pow(2.0, float64(t))))
}