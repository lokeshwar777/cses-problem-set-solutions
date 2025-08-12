""" 777 """


def get_digit(k):
    digits = 1
    multiplier = 1
    current_chunk_size = 9 * multiplier * digits
    remaining = k
    while remaining > current_chunk_size:
        remaining -= current_chunk_size
        digits += 1
        multiplier *= 10
        current_chunk_size = 9 * multiplier * digits

    # remaning - 1 -> 0-based
    offset = multiplier
    final_string = offset + ((remaining - 1) // digits)
    position = (remaining - 1) % digits
    return str(final_string)[position]


for _ in range(int(input())):
    k = int(input())
    res = get_digit(k)
    print(res)

"""
1->9 - 9 * 1
10->99 - 90 * 2
100->999 - 900 * 3
1000->9999 - 9000 * 4
100... -> 999... - 900... * n
 
123456789 | 1011121314151617181920212223242526272829303132333435363738
<-- 9  --> <---- 90 ---
 
if k <= 9:
    offset = 1
    final_string = string(offset + (k - 1)/1)
    i = k % 1
    ith position of final_string
elif 9 < k <= 189 # (189 = 90 * 2 + 9)
    offset = 10
    final_string = string(offset + (k - 1)/2)
    i = k % 2
    ith position of final_string
elif 189 < k <= 2889 # (2889 = 900 * 3 + 90 * 2 + 9)
    offset = 100
    final_string = string(offset + (k - 1)/3)
    i = k % 3
    ith position of final_string
"""
