def solution(enroll, referral, seller, amount):
    answer = [0 for _ in range(len(enroll))]
    tree = {}

    for i, name in enumerate(enroll):
        tree[name] = i

    for i, name in enumerate(seller):
        money = amount[i] * 100

        while name != '-':
            if money == 0:
                break
            fee = int(money * 0.1)
            earn = money - fee
            answer[tree[name]] += earn
            name, money = referral[tree[name]], fee

    return answer
