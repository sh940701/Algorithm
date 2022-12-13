// cpp에서 deque로 풀었더니 ㄹㅇ 극혐이었따. 그냥 이번엔 슬라이스로 풀어보자
// 메모리 관리도 필요없다 걍 슬라이스 하나에 쌓아가면서 풀자
// 다 풀고 나니까 똑같이 복잡하다 ㅎ

func solution(k int, score []int) []int {
    var result []int
    var kSlice []int
    
    // 원소가 없을 때 처리를 따로 해주기 귀찮으니 그냥 하나를 넣어주고 시작하쟈
    result = append(result, score[0])
    kSlice = append(kSlice, score[0])
    
    for idx, value := range score {
        if idx == 0 {
            continue
        }
        // kSlice의 길이가 k보다 작은 경우
        if len(kSlice) < k {
            // 가장 앞 원소보다 크거나 같을 때
            if value >= kSlice[0] {
                // golang에는 insert함수가 없다. 그러므로 구현을 해줘야 한다.
                // 일단 0 을 추가하여 slice의 길이를 하나 늘려준다.
                kSlice = append(kSlice, 0)
                // kSlice의 [1:]에 [0:] 값을 복사해 넣어준다.
                copy(kSlice[1:], kSlice[0:])
                // 그리고 이제 kSlice[0]의 자리에 원하는 값을 넣어준다.
                kSlice[0] = value
                result = append(result, kSlice[len(kSlice) - 1])
            // 가장 뒤 원소보다 작을 때
            } else if value <= kSlice[len(kSlice) - 1] {
                kSlice = append(kSlice, value)
                result = append(result, value)
            // 중간일 때
            } else {
                for idx, kValue := range kSlice {
                    // idx 1부터 시작
                    if idx == 0 {
                        continue
                    } else {
                        if value < kSlice[idx - 1] && value >= kValue {
                            kSlice = append(kSlice, 0)
                            copy(kSlice[idx + 1:], kSlice[idx:])
                            kSlice[idx] = value
                            result = append(result, kSlice[len(kSlice) - 1])
                            break
                        }
                    }
                }
            }
        // kSlice의 길이와 k가 같은 경우
        // 맨 앞 원소보다 큰 경우
        } else {
            if value >= kSlice[0] {
                kSlice = append(kSlice, 0)
                copy(kSlice[1:], kSlice[0:])
                kSlice[0] = value
                result = append(result, kSlice[k - 1])
            // 맨 뒤 원소보다 작은 경우
            } else if value <= kSlice[len(kSlice) - 1] {
                result = append(result, kSlice[k - 1])
            // 중간인 경우
            } else {
                for idx, kValue := range kSlice {
                    // idx 1부터 시작
                    if idx == 0 {
                        continue
                    } else {
                        if value < kSlice[idx - 1] && value >= kValue {
                            kSlice = append(kSlice, 0)
                            copy(kSlice[idx + 1:], kSlice[idx:])
                            kSlice[idx] = value
                            result = append(result, kSlice[k - 1])
                            break
                        }
                    }
                }
            }
        }
    }
    return result
}