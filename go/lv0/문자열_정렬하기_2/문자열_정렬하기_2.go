
// 이건 내가 푼 것.
// 진짜 lv 0인데도 왜케 조잡하지 ... ... ...... 더 열심히 해야겠다..
import "strings"
import "sort"

func solution(my_string string) string {
    my_string = strings.ToLower(my_string)
    var strSlice []string
    
    for i := 0; i < len(my_string); i++ {
        strSlice = append(strSlice, my_string[i:i+1])
    }
    
    sort.Strings(strSlice)
    
    result := strings.Join(strSlice, "")
    
    return result
}



// 다른사람 답변 중 내가 가장 좋게 보인 것
import (
    "strings"
    "sort"
)

func solution(my_string string) string {
	// "abCdE" 뭐 이런식의 스트링을 []byte(string) 으로 넣으면
	// 한 글자씩 원소인 byte의 배열이 되나보다..
    bytes := []byte(strings.ToLower(my_string))

	// Slice함수의 두번째 인자로 익명함수를 넣어줬다. 이런식으로도 정렬 설정이 되는구나..
    sort.Slice(bytes, func (i, j int) bool {
        return bytes[i] < bytes[j]
    })

	// []byte 배열을 string()으로 감싸면 string으로 돌려지는구나.. 신기하다 증말,,,,,
    return string(bytes)
}