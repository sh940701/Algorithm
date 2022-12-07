func solution(common []int) int {
    var result int
    gap0 := common[1] - common[0]
    gap1 := common[2] - common[1]
    
    // 등차수열일 경우
    if gap0 == gap1 {
        // common의 마지막 값에 차를 더한다.
        result = common[len(common) - 1] + gap0
        
    // 등비수열일 경우
    } else {
        // common의 마지막 값에 비를 곱한다.
        gap := gap1 / gap0
        result = common[len(common) - 1] * gap
    }
    
    return result
}