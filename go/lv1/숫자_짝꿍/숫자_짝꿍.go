func solution(X string, Y string) string {
    Xslice := []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    Yslice := []int{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    
    for _, value := range X {
        Xslice[value - '0']++
    }
    
    for _, value := range Y {
        Yslice[value - '0']++
    }
    
    merge := make([]int, 10, 10)
    
    for i := 0; i < 10; i++ {
        if Xslice[i] < Yslice[i] {
            merge[i] = Xslice[i]
        } else {
            merge[i] = Yslice[i]
        }
    }
    
    
    // 원래 답은 아래와 같았다. 그런데 string을 만들어놓고 하나씩 int -> string으로 형변환하고 이어붙이니
    // 11 ~ 15번에서 시간초과가 발생했다. string을 + 연산으로 이어붙이면, 하나하나를 만들 때마다
    // string객체를 다시 만들어줘야하기 때문에 그만큼 엄청난 오버헤드가 생겨서 그랬던 것이다.
    //     answer := ""

    //     for i := 9; i >= 0; i-- {
    //         for j := 0; j < merge[i]; j++ {
    //             answer += strconv.Itoa(i)
    //         }
    //     }
    
    
    answer := []byte{}
    
    for i := 9; i >= 0; i-- {
        for j := 0; j < merge[i]; j++ {
            answer = append(answer, byte(i + '0'))
        }
    }
    
    if len(answer) == 0 {
        return "-1"
    } else if answer[0] == '0' {
        return "0"
    }
    
    // 그래서 byte배열로 저장한 다음에, return할 때만 한번에 string으로 바꿔주는 방식을 선택했다.
    return string(answer)
}