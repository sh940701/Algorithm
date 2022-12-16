// 이것도 무지성 for문 돌리기 ㅎㅎ C++ 풀이와 같다

func solution(number []int) int {
    result := 0
    
    for i := 0; i < len(number) - 2; i++ {
        for j := i + 1; j < len(number) - 1; j++ {
            for z := j + 1; z < len(number); z++ {
                if number[i] + number[j] + number[z] == 0 {
                    result++
                }
            }
        }
    }
    return result
}