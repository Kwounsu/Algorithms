def solution(n: int):
    answer = []

    def hanoi(_n, from_pos, aux_pos, to_pos):
        if _n == 1:
            answer.append([from_pos, to_pos])
            return
        hanoi(_n - 1, from_pos, to_pos, aux_pos)
        answer.append([from_pos, to_pos])
        hanoi(_n - 1, to_pos, aux_pos, from_pos)

    hanoi(n, 1, 2, 3)
    return answer
