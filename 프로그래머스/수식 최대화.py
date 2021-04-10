def solution(expression):
    operations = [
        ('+', '-', '*'),
        ('+', '*', '-'),
        ('-', '+', '*'),
        ('-', '*', '+'),
        ('*', '+', '-'),
        ('*', '-', '+')
    ]
    answer = []

    for op in operations:
        a, b = op[0], op[1]
        temp_list = []

        for e in expression.split(a):
            temp = [f"({i})" for i in e.split(b)]
            temp_list.append(f'({b.join(temp)})')

        answer.append(abs(eval(a.join(temp_list))))

    return max(answer)
