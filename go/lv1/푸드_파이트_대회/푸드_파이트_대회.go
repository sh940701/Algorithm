// C++과 똑같은 방식으로 풀었따.

import "strconv"

func solution(food []int) string {
    result := ""
    for idx, value := range food {
        if value % 2 == 1 {
            value--
        }
        food[idx] /= 2
    }
    
    for i := 1; i < len(food); i++ {
        value := strconv.Itoa(i)
        for j := 0; j < food[i]; j++ {
            result += value
        }
    }
    
    result += "0"
    
    for i := len(food) - 1; i > 0; i-- {
        value := strconv.Itoa(i)
        for j := 0; j < food[i]; j++ {
            result += value
        }
    }
    return result
}