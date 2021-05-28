def solution(numbers):
    def bin_to_int(b):
        return int('0b' + ''.join(b), 2)

    def change_one_to_zero(b, k):
        for j in range(k, len(b)):
            if b[j] == '1':
                b[j] = '0'
                break

    answer = []

    for number in numbers:
        if number % 2 == 0:
            answer.append(number + 1)
        else:
            bin_num = list(bin(number)[2:])
            if '0' not in bin_num:
                bin_num = ['1', '0'] + bin_num[1:]
            else:
                for i in range(len(bin_num) - 1, -1, -1):
                    if bin_num[i] == '0':
                        bin_num[i] = '1'
                        change_one_to_zero(bin_num, i + 1)
                        break
            answer.append(bin_to_int(bin_num))

    return answer
