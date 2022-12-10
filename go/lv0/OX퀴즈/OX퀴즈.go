import "strings"
import "strconv"

func solution(quiz []string) []string {
    var result []string
    // quiz 슬라이스를 돌면서
    for _, value := range quiz {
        // strings.Split 메소드를 사용하면, 첫번째 인자인 스트링 값을 두 번째 인자인
        // 구분자로 구분한 슬라이스가 반환된다.
        temp := strings.Split(value, " ")
        
        // 각 문자(로 된 숫자)를 int타입으로 바꿔준다.
        X, _ := strconv.Atoi(temp[0])
        Y, _ := strconv.Atoi(temp[2])
        Z, _ := strconv.Atoi(temp[4])
        
        // 연산자가 - 일 때의 액션 -> switch-case 문으로 구현해보았다.
        if temp[1] == "-" {
            boolValue := (X - Y == Z)
            switch boolValue{
                case true:
                result = append(result, "O")
                case false:
                result = append(result, "X")
            }
        // 연산자가 + 일 때의 액션 -> switch-case 문으로 구현해보았다.
        } else if temp[1] == "+" {
            boolValue := (X + Y == Z)
            switch boolValue{
                case true:
                result = append(result, "O")
                case false:
                result = append(result, "X")
            }
        }
    }
    return result
}