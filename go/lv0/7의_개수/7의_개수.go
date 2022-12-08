// 이번엔 C++이랑 다른 방식으로 풀어보자 좀 더 수학적으로
func solution(array []int) int {
    // 결과값을 담을 변수
    result := 0
    // array의 인자만큼 반복한다.
    for i := 0; i < len(array); i++ {
        // temp는 array의 i번째 인자
        temp := array[i]
        for {
            // 예외처리 -> temp값이 10보다 작으면 7인지 아닌지만 판별하고 반복문을 멈춘다.
            if temp < 10 {
                if temp == 7 {
                    result++
                    break
                } else {
                    break
                }
            }
            // temp % 10은 temp의 1의자리만 반환한다. 7이라면 result++ 해준다.
            if temp % 10 == 7 {
                result++
            }
            // temp를 temp / 10으로 업데이트 해준다. 이 때 temp는 int type이기 때문에
            // 소숫점 자리는 버려지게 된다. 이런 방식으로 1의자리만 계속 비교를 해준다.
            temp = temp / 10
        }
    }
    return result
}