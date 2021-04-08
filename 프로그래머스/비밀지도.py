def solution(n, arr1, arr2):
    answer = []
    for i in range(n):
        x = bin(arr1[i] | arr2[i])
        bin_row = str(x)[2:]
        bin_row = '0' * (n - len(bin_row)) + bin_row
        
        row = ''
        for j in bin_row:
            row += '#' if j == '1' else ' '
        answer.append(row)
        
    return answer
