""" 777 """

# Approach 3: O(26 * N) + largest 2 frequencies, SC -> O(26)


def solve():
    input_str = input()
    N = len(input_str)
    F = 26

    freq = [0] * F
    for c in input_str:
        freq[ord(c) - ord('A')] += 1

    # standard pegion hole check

    def is_possible(holes, items): return 2 * items <= holes + 1

    smallest_str = [0] * N
    for index in range(N):
        is_impossible = True
        first_max = second_max = 0
        for cur_freq in freq:
            if cur_freq > first_max:
                first_max, second_max = cur_freq, first_max
            elif cur_freq > second_max:
                second_max = cur_freq

        for char_ind in range(F):
            if freq[char_ind] == 0 or (index and smallest_str[index - 1] == char_ind):
                continue
            cur_max = second_max if first_max == freq[char_ind] else first_max
            freq[char_ind] -= 1
            smallest_str[index] = char_ind
            if is_possible(N - (index + 1), cur_max):
                is_impossible = False
                break
            freq[char_ind] += 1

        if is_impossible:
            return -1

    return ''.join(chr(ord('A') + c) for c in smallest_str)


res = solve()
print(res)


# Approach 2: O(26 * N) + prefix max + suffix max , SC -> O(26 + N)
"""
def solve():
    input_str = input()
    N = len(input_str)
    F = 26

    freq = [0] * F
    for c in input_str:
        freq[ord(c) - ord('A')] += 1

    # standard pegion hole check

    def is_possible(holes, items): return 2 * items <= holes + 1

    smallest_str = [0] * N
    for index in range(N):
        is_impossible = True
        prefix_max = [0] * F
        for char_ind in range(F):
            prefix_max[char_ind] = freq[char_ind]
            if char_ind > 0:
                prefix_max[char_ind] = max(prefix_max[char_ind], prefix_max[char_ind - 1])

        suffix_max = [0] * F
        for char_ind in range(F - 1, -1, -1):
            suffix_max[char_ind] = freq[char_ind]
            if char_ind < F - 1:
                suffix_max[char_ind] = max(suffix_max[char_ind], suffix_max[char_ind + 1])

        for char_ind in range(F):
            if freq[char_ind] == 0 or (index and smallest_str[index - 1] == char_ind):
                continue
            freq[char_ind] -= 1
            smallest_str[index] = char_ind
            cur_max = freq[char_ind]
            if char_ind > 0:
                cur_max = max(cur_max, prefix_max[char_ind - 1])
            if char_ind < F - 1:
                cur_max = max(cur_max, suffix_max[char_ind + 1])
            if is_possible(N - (index + 1), cur_max):
                is_impossible = False
                break
            freq[char_ind] += 1

        if is_impossible:
            return -1

    return ''.join(chr(ord('A') + c) for c in smallest_str)


res = solve()
print(res)
"""

# Approach 1: O(26 * 26 * N)
"""
def solve():
    input_str = input()
    N = len(input_str)
    F = 26

    freq = [0] * F
    for c in input_str:
        freq[ord(c) - ord('A')] += 1

    # standard pegion hole check
    def is_possible(holes, items): return 2 * items <= holes + 1

    smallest_str = [0] * N
    for index in range(N):
        is_impossible = True
        for char_ind in range(F):
            if freq[char_ind] == 0 or (index and smallest_str[index - 1] == char_ind):
                continue
            freq[char_ind] -= 1
            smallest_str[index] = char_ind
            if is_possible(N - (index + 1), max(freq)):
                is_impossible = False
                break
            freq[char_ind] += 1

        if is_impossible:
            return -1

    return ''.join(chr(ord('A') + c) for c in smallest_str)


res = solve()
print(res)
"""

# Try 1 (WRONG): Initialisation: place the maximum frequency from right to left
"""
def solve():
    input_str = input()
    N = len(input_str)
    F = 26

    freq = [0] * F
    max_freq = 0
    for c in input_str:
        freq[ord(c) - ord('A')] += 1
        max_freq = max(max_freq, freq[ord(c) - ord('A')])

    if max_freq > (N - max_freq + 1):
        return -1

    max_char_ind = 0
    for i in range(F):
        if freq[i] == max_freq:
            max_char_ind = i

    smallest_str = [''] * N
    i = N - 1
    for _ in range(max_freq):
        smallest_str[i] = chr(ord('A') + max_char_ind)
        i -= 2
    freq[max_char_ind] = 0

    # small points to smaller char, large points to larger char
    # index points to the index in the smallest result string
    index = small = large = 0
    while small < F:
        if large <= small or (large < F and freq[large] == 0):
            large += 1
        elif index < N and smallest_str[index]:
            index += 1
        elif freq[small]:
            small_char = chr(ord('A') + small)
            large_char = chr(ord('A') + large)
            if not index or smallest_str[index - 1] != small_char:
                smallest_str[index] = small_char
                freq[small] -= 1
            else:
                smallest_str[index] = large_char
                freq[large] -= 1
        else:
            small += 1

    return ''.join(smallest_str)


res = solve()
print(res)
"""
