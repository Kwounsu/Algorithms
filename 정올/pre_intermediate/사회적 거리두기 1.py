import sys
input = sys.stdin.readline


# check given social distance is possible
def is_possible(sd, cows):
    distance, moved_cow = 0, 2
    for i, cow in enumerate(cows):
        if cow == '1':
            distance = 1
        else:
            distance += 1
        if distance > sd:
            moved_cow -= 1
            distance = 1
        # print(f"{i}:{cow}, d:{distance}, mc: {moved_cow}")
    if moved_cow <= 0:
        return True
    return False


# print(is_possible(1, '1000001'))
# print(is_possible(2, '0000000'))

n = int(input())
c = input().strip()

s, e, ans = 1, n + 1, 1
while s <= e:
    m = (s + e) // 2
    if is_possible(m, c):
        ans = max(ans, m)
        s = m + 1
    else:
        e = m - 1

print(ans)
