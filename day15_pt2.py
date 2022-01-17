from functools import lru_cache

with open("day15_input_pt2.txt") as f:
    lines = f.read().split("\n")

# Need to implement dijkstra's algorithm I think, its going ok, idk why its not working
# I think that I actually implemented the Bellman-Ford algorithm, technically I couldv'e used dijkstra and it would've been faster

# To solve this part the problem I think I can just use the same algorithm, I just need to generate the "full grid"
# Full grid was generated in another file "day15_pt2_helper.py" and then fed in through another text file(day15_input_pt2.txt)
# The algorithm is not very efficient and took about 15-20 seconds to process the whole grid but, it works perfectly!

shortest = []
for i in range(len(lines)):
    shortest.append([1e9 for a in range(len(lines[0]))])
queue = []

@lru_cache(maxsize=None)
def solve():
    global queue
    while len(queue) != 0:
        processing = queue.pop(0)
        x = processing[0]
        y = processing[1]
        if x > 0:
            if shortest[x][y] + int(lines[x-1][y]) < shortest[x-1][y]:
                shortest[x-1][y] = shortest[x][y] + int(lines[x-1][y])
                queue.append((x-1, y))
        if x < 499:
            if shortest[x][y] + int(lines[x+1][y]) < shortest[x+1][y]:
                shortest[x+1][y] = shortest[x][y] + int(lines[x+1][y])
                queue.append((x+1, y))
        if y > 0:
            if shortest[x][y] + int(lines[x][y-1]) < shortest[x][y-1]:
                shortest[x][y-1] = shortest[x][y] + int(lines[x][y-1])
                queue.append((x, y-1))
        if y < 499:
            if shortest[x][y] + int(lines[x][y+1]) < shortest[x][y+1]:
                shortest[x][y+1] = shortest[x][y] + int(lines[x][y+1])
                queue.append((x, y+1))

shortest[0][0] = 0
queue.append((0,0))
solve()
print(shortest[499][499])