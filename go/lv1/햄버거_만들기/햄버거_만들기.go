// 이번엔 아예 stack을 구현해서 사용해보자

type Stack struct {
    items []int
}

func (s *Stack) Push(i int) {
    s.items = append(s.items, i)
}

func (s *Stack) Pop() {
    items := s.items[0:len(s.items) - 1]
    s.items = items
}

func (s *Stack) Get(i int) int {
    return s.items[i]
}

func (s *Stack) length() int {
    return len(s.items)
}

func solution(ingredient []int) int {
    result := 0
    stack := &Stack{}
    for _, value := range ingredient {
        stack.Push(value)
        if l := stack.length(); l > 3 {
            if stack.Get(l-1) == 1 && stack.Get(l-2) == 3 && stack.Get(l-3) == 2 && stack.Get(l-4) == 1 {
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