""" 777 """

n = int(input())
arr = list(map(int, input().split()))
mx = max(arr)  # max element
tot = sum(arr) - mx  # sum of all elements except max element
min_t = mx + max(tot, mx)
print(min_t)

"""
case 1:
    if max element is greater than sum(rest of the elements)
    then A consumes all elements and waits for B to consume max element
    now B consumes the rest of elements while A still stays with max element
    at time t2max = 2 * max element both complete consumption
case 2:
    if max element is less than sum(rest of elements)
    then A completes consuming max element while B is consuming rest
    now max element is idle so B can consume it anytime after time t_max = max element
    at time tot = sum(all times) both complete consumption
"""
