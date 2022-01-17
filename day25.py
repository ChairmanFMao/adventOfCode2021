with open("day25_input.txt") as f:
    lines = [list(i) for i in f.read().split("\n")]

moves = 0
moving = 1

# 249 is too low
# 296 too low as well
# 571 was right answer
# Completed the advent of code!
# This solution isn't that efficient but, it produces correct outputs
# https://en.wikipedia.org/wiki/Biham%E2%80%93Middleton%E2%80%93Levine_traffic_model
# The problem is bascially just to simulate what is put forward in this Wikipedia article

while moving:
    moved = []
    moving = 0
    for i in range(len(lines)):
        for j in range(len(lines[0])):
            if lines[i][j] == ">" and lines[i][(j+1)%len(lines[0])] == "." and [i,j] not in moved and [i,(j+1)%len(lines[0])] not in moved:
                lines[i][(j+1)%len(lines[0])] = ">"
                lines[i][j] = "."
                moved.append([i,(j+1)%len(lines[0])])
                moved.append([i,j])
                moving = 1
    
    moved = []
    for i in range(len(lines)):
        for j in range(len(lines[0])):
            if lines[i][j] == "v" and lines[(i+1)%len(lines)][j] == "." and [i,j] not in moved and [(i+1)%len(lines),j] not in moved:
                lines[(i+1)%len(lines)][j] = "v"
                lines[i][j] = "."
                moved.append([(i+1)%len(lines),j])
                moved.append([i,j])
                moving = 1
    
    moves += 1

print(moves)