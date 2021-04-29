def solution(enroll, referral, seller, amount):
    answer = [0 for _ in range(len(enroll))]
    tree = {}

    def sell(person, money):
        fee = int(money * 0.1)
        earn = money - fee
        answer[enroll.index(person)] += earn

        if tree[person] != '-':
            sell(tree[person], fee)

    for i in range(len(enroll)):
        tree[enroll[i]] = referral[i]

    for i in range(len(seller)):
        sell(seller[i], amount[i] * 100)

    return answer
