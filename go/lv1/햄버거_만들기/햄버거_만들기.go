// 이번엔 아예 stack을 구현해서 사용해보자

// items라는 배열을 가지고 있는 Stack을 만들었다.
type Stack struct {
    items []int
}

// Stack은 data를 가장 위에 넣는다.
func (s *Stack) Push(i int) {
    s.items = append(s.items, i)
}

// Stack에서 Pop을 할 때에는 가장 마지막에 들어온 원소를 빼준다.
func (s *Stack) Pop() {
    items := s.items[0:len(s.items) - 1]
    s.items = items
}

// 가장 마지막 원소를 확인하는 Get 함수
func (s *Stack) Get(i int) int {
    return s.items[i]
}

// 현재 Stack의 길이를 알 수 있는 length 함수
func (s *Stack) length() int {
    return len(s.items)
}

func solution(ingredient []int) int {
    result := 0
    // stack을 하나 만들어준다.
    stack := &Stack{}
    for _, value := range ingredient {
        // ingredient 슬라이스를 돌며 stack에 값을 넣어준다.
        stack.Push(value)
        // stack 내의 길이가 4 이상일 때!
        if l := stack.length(); l > 3 {
            // stack내의 데이터 값이 역순으로 1-3-2-1인지 확인한다. -> 그렇다면 들어온 순서가 1-2-3-1일 테니까
            if stack.Get(l-1) == 1 && stack.Get(l-2) == 3 && stack.Get(l-3) == 2 && stack.Get(l-4) == 1 {
                // 조건을 충족하면, result++ 해주고, stack에서 상위 4개 값을 없애준다.
                result++
                stack.Pop()
                stack.Pop()
                stack.Pop()
                stack.Pop()
            }
        }
    }
    return result
}