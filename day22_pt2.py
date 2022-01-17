# Very cool input parsing :)
from types import coroutine
from typing import AsyncContextManager


with open("C:\\Users\\physicsuser\\Documents\\cpp\\aoc2021\\day22_input.txt") as f:
    lines = [[[int(a) for a in x.split(",")[0].split("=")[1].split("..")], [int(a) for a in x.split(",")[1].split("=")[1].split("..")], [int(a) for a in x.split(",")[2].split("=")[1].split("..")],1 if x.split(" ")[0] == "on" else -1] for x in f.read().split("\n")]

# I don't think that I can use the set method again as it will be way too slow, it also takes up all of my RAM
# Need to find out an efficient way of calculating how much intersection the cubiods will have
# Need to take the difference between the coordinates that intersect and then plus one, do this in all three planes to get area of intersection
# For some reason the memory useage of this program is literally insane, it goes up by hundreds of megabytes for second even on very small inputs

# This function will return the volume of intersection between the two cubes
def intersection(exists, new):
    out = []
    for i in range(3):
        if new[i][0] <= exists[i][0] and new[i][1] >= exists[i][1]:
            out.append([exists[i][0],exists[i][1]])
        elif new[i][0] <= exists[i][0] and new[i][1] <= exists[i][1] and new[i][1] > exists[i][0]:
            out.append([exists[i][0],new[i][1]])
        elif new[i][0] >= exists[i][0] and new[i][1] >= exists[i][1] and new[i][0] < exists[i][1]:
            out.append([new[i][0],exists[i][1]])
        elif new[i][0] > exists[i][0] and new[i][1] < exists[i][1]:
            out.append([new[i][0],new[i][1]])
    out.append(-1 if exists[3] == 1 else 1)
    return out

# Problem is that area that it is intersect is being intersected many times by off queries
# Potentially just check for intersection after all the queries?
# Thinking of storing all of the areas of overlap and then checking if they are overlapped with the off queries
# Code works for the smallest example but is generating very large negative numbers for the bigger sets of input
# I had to look online for some help but, I found the idea of having cubes of vector area(positive and negative)
# This works well as I can just place negative cubes in overlap areas

# 1206644425246111 was the right answer
# Very pleased that I managed to implement it, my code was close but just missing this crucial concept
# Another thing to remember is that python treats -1 as a truthy value whereas, I thought it would be falsy

on = 0
cubes = []
for i in lines:
    current = [[i[0][0], i[0][1]],[i[1][0], i[1][1]],[i[2][0], i[2][1]], i[3]]
    if i[3] == 1:
        for j in range(len(cubes)):
            a = intersection(cubes[j],current)
            if len(a) == 4:
                cubes.append(a)
        cubes.append(current)
    else:
        for j in range(len(cubes)):
            a = intersection(cubes[j],current)
            if len(a) == 4:
                cubes.append(a)

for i in cubes:
    on += (i[0][1] - i[0][0] + 1) * (i[1][1] - i[1][0] + 1) * (i[2][1] - i[2][0] + 1) * i[3]
print(on)