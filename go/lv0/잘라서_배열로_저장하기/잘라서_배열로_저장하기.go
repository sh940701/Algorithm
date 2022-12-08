func solution(my_str string, n int) []string {
    if len(my_str) < n {
        return []string{my_str}
    }
    // 정답을 담을 슬라이스
    var result []string
    // temp에 my_str을 복사
    temp := my_str
    for {
        // 예외처리 -> 만약 여기서 if와 else if의 내용이 바뀌면
        // 0도 < n 이기 때문에 result에 할당하고, 에러가 난다.
        if len(temp) == 0 {
            return result
        } else if len(temp) < n {
            result = append(result, temp)
            return result
        } 
        // 위에서 걸리지 않을 경우 result에 temp의 앞에서 n만큼을 담아줌
        result = append(result, temp[:n])
        temp = temp[n:]
        
    }
}