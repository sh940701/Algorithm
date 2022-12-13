// 이번엔 더간단하게 만들어보자..
import "sort"

// 근데 먼가 이렇게 하라고 만든 문제가 아닌 것 같다 .. .. . .. . . . ... k도 안썼기 때무니지

func solution(k int, m int, score []int) int {
    answer := 0
    // 내림차순으로 정렬
    sort.Sort(sort.Reverse(sort.IntSlice(score)))
    // 그냥 m만큼 건너뛰며 해당 요소와 m을 곱한 값이 박스별 가격
    for i := m - 1; i < len(score); i += m {
        answer += score[i] * m
    }
    return answer
}