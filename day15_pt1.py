from functools import lru_cache

with open("day15_input.txt") as f:
    lines = f.read().split("\n")

# Need to implement dijkstra's algorithm I think, its going ok, idk why its not working

# Thinking about setting all of the values for visited to be infinite and then doing the cool comparison
# I got 722 as output but apparently its too high, ;-;
# Turns out I was ending the algorithm prematurely, I had to just let it fully run, I got 720 as the output in the end and it was right :)

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
        if x < 99:
            if shortest[x][y] + int(lines[x+1][y]) < shortest[x+1][y]:
                shortest[x+1][y] = shortest[x][y] + int(lines[x+1][y])
                queue.append((x+1, y))
        if y > 0:
            if shortest[x][y] + int(lines[x][y-1]) < shortest[x][y-1]:
                shortest[x][y-1] = shortest[x][y] + int(lines[x][y-1])
                queue.append((x, y-1))
        if y < 99:
            if shortest[x][y] + int(lines[x][y+1]) < shortest[x][y+1]:
                shortest[x][y+1] = shortest[x][y] + int(lines[x][y+1])
                queue.append((x, y+1))

shortest[0][0] = 0
queue.append((0,0))
solve()
print(shortest[99][99])