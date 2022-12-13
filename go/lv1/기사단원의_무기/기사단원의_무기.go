// 약수의 개수를 구해 리턴해주는 함수 -> 원래 기법은 다음과 같았다.
// cpp와 같은 방식으로 풀었는데 타임오바가 걸려서 고루틴과 채널로 동시처리해주었다.
// func getPiedges(num, limit, power int) int {
//     result := 1
//     for i := 1; i <= num / 2; i++ {
//         if num % i == 0 {
//             result++
//             if result > limit {
//                 result = power
//                 break
//             }
//         }
//     }
//     return result
// }

// func solution(number int, limit int, power int) int {
//     result := 0
//     for i := 1; i <= number; i++ {
//         piedge := getPiedges(i, limit, power)
//         result += piedge
//     }
//     return result
// }

// 고루틴과 채널을 적용하여 동시성 처리를 진행해준 풀이 -> 이렇게 하니까 통과가 됐다;;
// 채널을 인자로 받는다.
func getPiedges(num, limit, power int, ch chan int) {
    result := 1
    for i := 1; i <= num / 2; i++ {
        if num % i == 0 {
            result++
            if (result > limit) {
                result = power
                break
            }
        }
    }
	// 함수가 끝나면 채널로 result를 전달해준다.
    ch <- result
}

func solution(number int, limit int, power int) int {
    count := 0
	// 채널 생성 -> number만큼의 버퍼를 가지고 있는
    ch := make(chan int, number)
    result := 0
    for i := 1; i <= number; i++ {
		// 돌아가면서 각각의 고루틴으로 getPiedges 함수를 실행한다.
        go getPiedges(i, limit, power, ch)
    }

    // 채널에서 계속 대기하며 데이터를 받아준다.
    for data := range ch {
        count++
        result += data

		// 이 때 탈출조건이 없으면, 데이터가 없는데도 계속 기다리게 되어 데드락이 발생한다.
		// 이를 방지하기 위해 탈출조건을 만들어주었다.
        if count == number {
            break
        }
    }
    return result
}