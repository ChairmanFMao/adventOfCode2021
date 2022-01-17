from functools import lru_cache
from queue import PriorityQueue

with open("day15_input_pt2.txt") as f:
    lines = f.read().split("\n")

# Need to implement dijkstra's algorithm I think, its going ok, idk why its not working
# I think that I actually implemented the Bellman-Ford algorithm, technically I couldv'e used dijkstra and it would've been faster

# To solve this part the problem I think I can just use the same algorithm, I just need to generate the "full grid"
# Full grid was generated in another file "day15_pt2_helper.py" and then fed in through another text file(day15_input_pt2.txt)
# This implementation of the algorithm actually uses dijkstra's algorithm with the help of PriorityQueue from the queue library, it executs in about 5 seconds, very good improvement

shortest = []
seen = []
for i in range(len(lines)):
    shortest.append([1e9 for a in range(len(lines[0]))])
    seen.append([0 for a in range(len(lines[0]))])
queue = PriorityQueue()

@lru_cache(maxsize=None)
def solve():
    global queue
    while not queue.empty():
        processing = queue.get()
        current = processing[0]
        x = processing[1]
        y = processing[2]
        if (x == 499 and y == 499):
            break
        seen[x][y] = 1
        if x > 0:
            if current + int(lines[x-1][y]) < shortest[x-1][y] and seen[x-1][y] == 0:
                shortest[x-1][y] = current + int(lines[x-1][y])
                queue.put((shortest[x-1][y],x-1, y))
        if x < 499:
            if current + int(lines[x+1][y]) < shortest[x+1][y] and seen[x+1][y] == 0:
                shortest[x+1][y] = current + int(lines[x+1][y])
                queue.put((shortest[x+1][y],x+1, y))
        if y > 0:
            if current + int(lines[x][y-1]) < shortest[x][y-1] and seen[x][y-1] == 0:
                shortest[x][y-1] = current + int(lines[x][y-1])
                queue.put((shortest[x][y-1],x, y-1))
        if y < 499:
            if current + int(lines[x][y+1]) < shortest[x][y+1] and seen[x][y+1] == 0:
                shortest[x][y+1] = current + int(lines[x][y+1])
                queue.put((shortest[x][y+1],x, y+1))

shortest[0][0] = 0
queue.put((0,0,0))
solve()
print(shortest[499][499])