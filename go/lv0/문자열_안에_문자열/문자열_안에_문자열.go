import "strings"

func solution(str1 string, str2 string) int {
    // strings.Contains() 함수는 첫번째 인자에 두번째 인자가 포함되어 있는지 검사하여
    // 그 포함 여부를 true / false로 반환한다.
    if strings.Contains(str1, str2) == true {
        return 1
    } else {
        return 2
    }
    return 0
}