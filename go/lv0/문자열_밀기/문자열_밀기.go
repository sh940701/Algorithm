func solution(A string, B string) int {
    if A == B {
        return 0
    }
    var result = 0
    temp := A
    for {
        // 여기서 좀 헷갈렸다. string에서 []안에 상수가 들어가면 byte데이터로 처리된다.
        // string type으로 유지하려면 범위 구분 연산자(?) ":" 로 나타내줘야 한다.
        temp = (temp[len(A) - 1 :] + temp[:len(A) - 1])
        result++
        if temp == B {
            return result
        } else if temp == A {
            return -1
        }
    }
}