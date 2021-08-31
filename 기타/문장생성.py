noun = ['I', 'She', 'He', 'This', 'That', 'It']
verb = ['loved', 'hated', 'liked', 'ate', 'had', 'want', 'need', 'hitted', 'punched']
obj = ['him', 'the man', 'her', 'that', 'it', 'me', 'you']
sub = ['very much', 'really', 'little bit', 'a bit', 'softly', 'right?', 'gorgeously']

for a in noun:
    for b in verb:
        for c in obj:
            for d in sub:
                print(f'    "{a} {b} {c} {d}",')
