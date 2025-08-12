""" 777 """
moves = []
"""
a=source, b=auxillary, c=destination
Our goal is to move n from a to c using b
for that we need to first move the n-1 th tower to b and then move this (n-1 th tower) back to c
**trust your recursive function**
 
1. move n-1 from a -> b using c
2. move n from a -> c using b (print move here for answer)
3. move n-1 from b -> c using a
"""


def rec(n, a, b, c):
    if n > 1:
        rec(n - 1, a, c, b)
    moves.append((a, c))
    # print(f"move {n} from {a} -> {c}")
    if n > 1:
        rec(n - 1, b, a, c)


n = int(input())
# rec(n, 'a', 'b', 'c')
rec(n, 1, 2, 3)

print(len(moves))
for move in moves:
    print(*move)
