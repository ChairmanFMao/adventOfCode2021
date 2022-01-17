with open(".\day20_input.txt") as f:
    lines = f.read().split("\n")

# This removes the line for encoding and an empty line
encoder = lines.pop(0)
lines.pop(0)

# 5510 too low, as wasn't applying the algorithm twice, 6005 is too high, 5868 also too high
# I am going to add like 5 more lines of dots on every side of the image I think
for i in range(len(lines)):
    lines[i] = list("." + lines[i] + ".")

extra = len(lines[0]) * "."

lines.insert(0,list(extra))
lines.append(list(extra))

# Somehow this function is spotting hashes that aren't actually there
def calculateNew(row, column, first):
    global lines
    index = ""
    row -= 1
    column -= 1
    for i in range(3):
        for j in range(3):
            if row + i >= 0 and column + j >= 0:
                try:
                    index += "1" if lines[row+i][column+j] == "#" else "0"
                except IndexError:
                    index += "0" if first else "1"
            else:
                index += "0" if first else "1"
    return encoder[int(index,2)]

# I was initially having a problem with trying to assign one list to another, passing by reference ;-;
for k in range(2):
    nextLines = []
    for i in range(len(lines)):
        mini = []
        for j in range(len(lines[0])):
            mini.append(calculateNew(i,j, k % 2 == 0))
        nextLines.append(mini)
    
    for i in range(len(lines)):
        for j in range(len(lines[0])):
            lines[i][j] = nextLines[i][j]

    # This needs to be done because the outside of the whole shape will be # as # as the first characters in the encode string
    if k % 2 == 0:
        for i in range(len(lines)):
            lines[i].insert(0,'#')
            lines[i].append('#')
        extra = "#" * len(lines[0])
        lines.insert(0,list(extra))
        lines.append(list(extra))



light = 0
for i in lines:
    for j in i:
        if j == "#":
            light += 1

print(light)