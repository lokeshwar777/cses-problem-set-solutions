""" 777 """
 
 
def solve():
    row, col = map(int, input().split())
    row -= 1
    col -= 1
    layer = max(row, col)
    if layer & 1:
        row, col = col, row
    if row == layer:
        return layer * layer + col + 1
    else:
        return (layer + 1) * (layer + 1) - row
 
 
T = 1
T = int(input())
for _ in range(T):
    res = solve()
    print(res)
 
 
"""
Nth layer -> N^2 + 1 to (N+1)^2 (0-based)
1. layer detection -> max(row, col)
2. swap odd layers to make the grid look consistent
3. return the value based on position in the grid
"""