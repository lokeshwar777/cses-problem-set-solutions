"""777"""

# Approach 1 : Failing code
"""
from collections import deque
for _ in range(int(input())):
    n, a, b = map(int, input().split())
 
    # early exit for not possible case
    if (a + b > 0) and (a == 0 or b == 0 or (a + b > n)):
        print("NO")
        continue
 
    draw_rounds = n - (a + b)
    tot_cards = n
    a_b_cards = []
    while n - draw_rounds < tot_cards:
        a_b_cards.append((tot_cards, tot_cards))
        tot_cards -= 1
 
    rem_a = deque(list(range(1, tot_cards + 1)))
    rem_b = deque(list(range(1, tot_cards + 1)))
    # print(n, a, b, rem_a, rem_b)
 
    # imagine you are B, first let the A win for a times
    for _ in range(a):
        a_b_cards.append((rem_a.pop(), rem_b.popleft()))
 
    # now its your turn to win for b times
    for _ in range(b):
        # a_b_cards.append((rem_a.popleft(), rem_b.popleft())) # or
        a_b_cards.append((rem_a.pop(), rem_b.pop()))
 
    a_b_cards.sort()
    a_cards = [card[0] for card in a_b_cards]
    b_cards = [card[1] for card in a_b_cards]
 
    print("YES")
    print(*a_cards)
    print(*b_cards)
'''
you can optimise the space taken by queue by considering 2 pointers - O(n) -> O(1)
'''
"""

"""
why Approach 1 is failing is ?
we are already considering `draws`
for a times you are choosing 
    - cards of A from left to right (1 -> n)
    - cards of B from right to left (n -> 1)
failing case:
    consider n = 3, a = 2, b = 1
                    choosing 
    A - 1 2 3 -> 1 2
    B - 3 2 1 -> 3 2
    you can see there is a draw instead of a win for A
 
solution: use cyclicity and pick greedily
    - fix cards of A from 1 -> n
    - for each card of B -> i + a if it is <= n else 
"""

'''
nd=non-draws=a+b
n = 10, a = 4, b = 4
1 2 3 4 5 6 7 8 9 10
5 6 7 8 1 2 3 4 9 10
 
n = 10, a = 3, b = 6
1 2 3 4 5 6 7 8 9 10
4 5 6 7 8 9 1 2 3 10 <- i+a ... nd ... 1 ... a
                       <-b times->    <-a times->
'''


def is_valid(n, a, b):
    # all draws or at least 1 round win for each and win + lose rounds shouldn't exceed total rounds
    return a + b == 0 or (a > 0 and b > 0 and a + b <= n)


for _ in range(int(input())):
    total, a_wins, b_wins = map(int, input().split())

    # early exit for not possible case
    if not is_valid(total, a_wins, b_wins):
        print("NO")
        continue

    b_cards = []
    rem_b_wins = b_wins
    for card in range(1, total + 1):
        if rem_b_wins > 0:
            b_cards.append(card + a_wins)
            rem_b_wins -= 1
        elif a_wins > 0:
            b_cards.append(card - b_wins)
            a_wins -= 1
        else:
            b_cards.append(card)

    print("YES")
    print(*list(range(1, total + 1)))
    print(*b_cards)
