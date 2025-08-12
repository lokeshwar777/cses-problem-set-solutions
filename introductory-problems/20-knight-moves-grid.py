""" 777 """

# Approach 1: DFS -> RecursionError: maximum recursion depth exceeded
"""
neighbours = ([(x, y) for x in (1, -1) for y in (2, -2)] +
              [(x, y) for x in (2, -2) for y in (1, -1)])
n = int(input())
grid = [[-1] * n for _ in range(n)]
def is_valid(row, col):
    return 0 <= row < n and 0 <= col < n
def dfs(row, col, steps):
    if not is_valid(row, col):
        return
    prev_steps = grid[row][col]
    if prev_steps != -1 and prev_steps <= steps:
        return
    grid[row][col] = steps
    for next_row, next_col in neighbours:
        dfs(row + next_row, col + next_col, steps + 1)
dfs(0, 0, 0)
for row in grid:
    print(*row)
"""

# Approach 2: BFS


from collections import deque
neighbours = ([(x, y) for x in (1, -1) for y in (2, -2)] +
              [(x, y) for x in (2, -2) for y in (1, -1)])
n = int(input())
grid = [[-1] * n for _ in range(n)]


def is_valid(row, col):
    return 0 <= row < n and 0 <= col < n


def bfs(src_row, src_col, initial_steps):
    queue = deque([(src_row, src_col, initial_steps)])
    grid[src_row][src_col] = initial_steps
    while queue:
        row, col, steps = queue.popleft()
        for row_dist, col_dist in neighbours:
            next_row, next_col = row + row_dist, col + col_dist
            if (not is_valid(next_row, next_col)
                    or grid[next_row][next_col] != -1):
                continue
            grid[next_row][next_col] = steps + 1
            queue.append((next_row, next_col, steps + 1))


bfs(0, 0, 0)
for row in grid:
    print(*row)
