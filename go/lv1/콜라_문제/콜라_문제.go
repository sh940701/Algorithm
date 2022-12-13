func solution(a int, b int, n int) int {
    answer := 0
    for {
        // 병 n개로 받을 수 있는 콜라의 개수
        // float타입이어도 int로 바꾸면 소수점 이하가 잘림
        amount := int(n / a) * b
        // 받고 남은 병의 개수
        left := n % a
        // 받은 콜라의 개수를 answer에 업데이트해줌
        answer += amount
        // 받은 콜라도 곧 빈병이니, 받은 콜라의 개수와 아까 남은 병의 개수를 n으로 업데이트해줌
        n = amount + left
        // 탈출 조건 -> n이 a보다 작으면 콜라를 받을 수 없기 때문에 탈출
        if a > n {
            break
        }
    }
    return answer
}