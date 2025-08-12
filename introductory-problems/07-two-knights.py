""" 777 """

from math import comb


def get_possibilites(n):
    if n < 2:
        return 0

    total_possibilites = comb(n * n, 2)

    # 2 possibilites in each box(opposite corners)

    # total 3 x 2 boxes on the n x n board -> (rows - 2) * (cols - 1)
    boxes_3x2 = 2 * (n - 2) * (n - 1)
    # total 2 x 3 boxes on the n x n board -> (rows - 1) * (cols - 2)
    boxes_2x3 = 2 * (n - 1) * (n - 2)
    attacking_possibilities = boxes_3x2 + boxes_2x3

    return total_possibilites - attacking_possibilities


for i in range(1, int(input()) + 1):
    print(get_possibilites(i))
