from math import ceil

with open(".\\day18_input.txt") as f:
    lines = f.read().split("\n")

# Notes:
# Snailfish numbers are always in pairs
# To add two snailfishnumbers, form a pair from the left and right parameters of the additional operator
# Snailfish numbers must always be reduced, to reduce a snailfish number you must repeatedly do the first applicable action in the following list
# - If any pair is nested inside four pairs, the leftmost pair explodes
# - If any regular number is 10 or greater, the leftmost such regular number splits
# To explode a pair, the pair's left value is added to the first regular number to the left of the exploding pair, and the pair's right number to
# the first regular number to the right of the exploding pair, sometimes this results to nothing as there are no regular numbers there
# To split a regular number, replace it with a pair, the left element of the pair should be the regular number divided by two and rounded down,
# the right element of the pair should be the regular number divided by two and rounded up
# Thinking about doing exploding by turning the array into a string and then moving left and right and incrementing the ascii values, I think this will work, idk tho
# Arrays are passed by reference in python so, I can actually mutate them
# Thinking about redesigning the whole thing so that it is stored in a flat file
# Completely started over to use a flat file data structure
# I had a small bug where I started the depth from 1 instead of 0, it seems to be producing the right output for the test input
# I took a lot of inspiration from the pastebin in the line below, it really helped me to understand how to approach the problem
# https://topaz.github.io/paste/#XQAAAQDcDQAAAAAAAAA0m0pnuFI8c91qhwCZdcPCMbpot+Mza/IvV11AaBvW6RilZSuqWex5ZygfBXelhTcd9Rb+kVPR3zbL0H/2XicONHbp7N3WHTLkqt/RUXYzMPVtp4isXwvNG0K0yhh6yzKejgF7eS5U2OYiC2JEeh4/8EmcLrydTuyKh5HbzPmhNQ67hiLizf6tqwciLw7LqFUHU2hCXWACkUqFgZSdBixIfesjGaDp+KgirdqnqfV/UULb6QQrV2Gh0PThCJSmtjLETCjvpB5woQY73DDT+uWHI5KGNLAeqwQwZNeg9IZZfW5FnoMcMSCdA3SlLdGKFKF0/CV7ouX8AlpeCLgltdf7DR/QnRO2VK25nO/Fh1oZbb+TvZHGtndrwIHoyqYluaLvlvZ5OmFvCQCef/sYTlRar7TEsLrIAZupTEjcxlvwqnyDvbrIA/DZ1C3Mi6PszaGT4V7nGqS1KzB29UMCFA0eGJ3A4UPOO3tXHohJayrxIlPLdaiNyAfSL+GRTPLchcTYvNqzI7b8EkB7C3db0HdHZzCe2tgN2AjiqtYLqtjhDqmMhtlKbdtB8mgq1OseBkqchgmXgD+81dQ1p2+R83QGXBcNxX8444ZmtclpK3mxxqxTjGNwhuWzKLqwNd8tddbeuhtaoGtubTbIY8tRSE/+OozAxcqze15iaeJ6GRI++avBfFL0YiR0IhcnfiOlG5CwJJkvwCecB8PuWLvdh8SSoV8xCKFZwjqzzuwKUz0Z8tevUYEmA9tOfwZQglh+BaznFIcInX7DwGZky6wUyxURSjaRpm0YoLc6ITRW9Z7n1l6IwVNOHBj0nURyi1/fE/gRDa3Plkz21VHtYQX1/YUUf+k4cihtyoJ06wtW+xmnscR96VsbDU+0dOKKWcbK/6/a6JIgyMPUA3tW2Rm8xgo7mpk0UfQTjw+ErDKcL8JmkU0D2OgJ+GvgOOkaTgerU75rnkziGtSv4D4P1iKPQerhoDjrI/diIjj8VZXN2pQ6oSpJzFRknM+aQUiMTrdif06NqgsmwCDyaAMCuvcS1GndTB3GfYlfyexhSwymQj+gEEMvi6JFn+LMVRXtViFmOYqjcyjerzzeeXhY1TP2tS1ldDB7yes725gxJvgBsMR14V4fFQacsOsz1qO0ibZ7oGPfYIEsoHGqoReqpYSGfB9AqGqnAakl60O9b8jH1DeLeQFjwVW5ItIxA00vmqP9KXF064nOj1ePLAKpNejUcm9NVFlX5+1j2uT/K63qlndhTz2nD+aAkBbC5kQIkfAezHAyjylTNc7BiTz1Ch7yGI2wqryn6QJmSzs/NAy0Xdg3cnee8ypS7hXeKDyzjtg72TMHwpJlHDowliTWCz/ko1JXFZlfrN0YXmGN/7sKGUQ/aImSMq073zy+fVfxmMYFlCtjKfvBIjRkSfT6gf/EN6Hs
# This took a very long time to do and I was very happy that I managed to finish it in the end. :)

allSnailfish = None

# This is the snailfish class, used to create snailfish objects
class Snailfish:
    depth = 0
    value = 0
    def __init__(self, value, depth):
        self.depth = depth
        self.value = value
    def __str__(self):
        return str(self.value) + ":" + str(self.depth) + ", "

# This function converts a list of pairs into a list of snailfish objects
def convertToList(data):
    asString = str(data)
    number = ""
    depth = 0
    out = []
    for i in asString:
        if i == "[":
            depth += 1
        elif i == "]":
            if number != "":
                out.append(Snailfish(int(number),depth))
                number = ""
            depth -= 1
        elif i == ",":
            if number != "":
                out.append(Snailfish(int(number),depth))
                number = ""
        else:
            number = i
    return out

# This function adds together two lists of snailfish
def add(original, toAdd):
    for i in range(len(original)):
        original[i].depth += 1
    for i in range(len(toAdd)):
        toAdd[i].depth += 1
        original.append(toAdd[i])
    return original

# This function handles explosions in the allSnailfish list
def explode():
    global allSnailfish
    for i in range(len(allSnailfish)-1):
        if allSnailfish[i].depth >= 5 and allSnailfish[i].depth == allSnailfish[i+1].depth:
            if i > 0:
                allSnailfish[i-1].value += allSnailfish[i].value
            if i+2 < len(allSnailfish):
                allSnailfish[i+2].value += allSnailfish[i+1].value
            allSnailfish.pop(i+1)
            allSnailfish[i].value = 0
            allSnailfish[i].depth -= 1
            return 1
    return 0

# This function handles splitting of elements in the allSnailfish list
def split():
    global allSnailfish
    for i in range(len(allSnailfish)):
        if allSnailfish[i].value > 9:
            allSnailfish.insert(i+1, Snailfish(ceil(allSnailfish[i].value/2), allSnailfish[i].depth+1))
            allSnailfish[i].value = int(allSnailfish[i].value/2)
            allSnailfish[i].depth += 1
            return 1
    return 0

# This function reduces the allSnailfish list by continuously calling explode and split when possible
def reduce():
    while True:
        if explode():
            continue
        elif split():
            continue
        break

def magnitude():
    global allSnailfish
    while len(allSnailfish) > 1:
        for i in range(len(allSnailfish)-1):
            if allSnailfish[i].depth == allSnailfish[i+1].depth:
                allSnailfish[i].depth -= 1
                allSnailfish[i].value = allSnailfish[i].value * 3 + allSnailfish[i+1].value * 2
                allSnailfish.pop(i+1)
                break
    return allSnailfish[0].value

largest = 0

for i in lines:
    for j in lines:
        if i != j:
            allSnailfish = None
            allSnailfish = add(convertToList(i), convertToList(j))
            reduce()
            if magnitude() > largest:
                largest = magnitude()


# This should print the largest magnitude
print(largest)