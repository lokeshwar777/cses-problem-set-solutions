""" 777 """

# APPROACH 1: only passes till 5
"""
n = int(input())
 
grid = [[0] * n for _ in range(n)]
 
for row in range(1, n):
    start = row
    update_val = -1 if start & 1 else 1
    for col in range(row):
        square_val = start
        grid[row][col] = square_val
        grid[col][row] = square_val
        start += update_val
 
for row in grid:
    print(*row)
"""

# APPROACH 2: seen sets for each row & col
"""
n = int(input())
 
grid = [[0] * n for _ in range(n)]
row_seen_sets = [set() for _ in range(n)]
col_seen_sets = [set() for _ in range(n)]
 
for row in range(n):
    for col in range(n):
        seen_row_vals = row_seen_sets[row]
        seen_col_vals = col_seen_sets[col]
        mex_val = 0
        while mex_val in seen_row_vals or mex_val in seen_col_vals:
            mex_val += 1
        grid[row][col] = mex_val
        seen_row_vals.add(mex_val)
        seen_col_vals.add(mex_val)
 
for row in grid:
    print(*row)
"""

# APPROACH 3: Bit Manipulation (XOR) + grundy numbers
n = int(input())

grid = [[row ^ col for row in range(n)] for col in range(n)]

for row in grid:
    print(*row)
