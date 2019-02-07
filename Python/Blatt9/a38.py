#!user/bin/python3

import copy

def permutationen(seq):
    if len(seq) <= 1:
        yield seq

    else:
        for perm in permutationen(seq[1:]):
            for i in range(len(seq)):
                yield perm[:i] + seq[0:1] + perm[i:]




l = [1, 2, 3]
for ele in permutationen(l):
    print(ele)

