var arr []string = []string{"R", "T", "C", "F", "J", "M", "A", "N"}

// 마지막 값을 비교하여 더 큰 값을 갖고 있는 string을 반환해주는 함수
func compare (table map[string]int, a, b string) string {
    var answer string
    if table[a] < table[b] {
        answer = b
    } else if table[a] > table[b] {
        answer = a
    } else {
        // 두 개의 값이 같으면, 더 빠른 녀석을 반환해준다.
        // 이 때 더 빠르다는 것은 값이 더 작다는 것을 의미한다.
        if a < b {
            answer = a
        } else if a > b {
            answer = b
        }
    }
    return answer
}

// table과 점수, string을 받아서 table의 string값에 num 만큼을 더해주는 함수
func update (table map[string]int, num int, value string) {
    table[value] += num
}

func solution(survey []string, choices []int) string {
    // 각 알파벳 별 점수를 담을 맵을 생성
    table := make(map[string]int)
    // table의 각 요소의 값을 0으로 초기화해준다.
    for _, value := range arr {
        table[value] = 0
    }
    
    for idx, value := range choices {
        // value가 4라면 둘 다 0점이니 그냥 무시
        if value == 4 {
            continue
        }
        // value가 4 이하라면 1일때 3점, 2일때 2점, 3일때 1점 부여
        if value < 4 {
            update(table, 4 - value, string(survey[idx][0]))
        // value가 4 이상이라면 7일때 3점, 6일때 2점, 5일때 1점 부여
        } else {
            update(table, value - 4, string(survey[idx][1]))
        }
    }
    
    result := ""
    
    for i := 0; i < len(arr); i = i + 2 {
        // 나올 수 있는 모든 경우의 수는 arr에 담겨있으므로, 두 개씩 쌍을 지어 비교하여 결과값을 리턴해준다.
        result += compare(table, arr[i], arr[i+1])
    }
    
    return result
}