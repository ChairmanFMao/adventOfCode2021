from functools import lru_cache

# The p1 score is first, then the p2 score, then the p1 position, then the p2 position, then the turn(1 means p1, 0 means p2), then the weight(occurances of this position)
# Actually, I think that the problem with this approach is that the lru_cache doesn't like global variables which stops my method of adding up the wins working
# Techincally it could be executed with the lru_cache however, it would lead to vastly increased execution time
weights = [1,3,6,7,6,3,1]

firstTotal = 0
secondTotal = 0

@lru_cache(maxsize=None)
def process(firstScore, secondScore, firstPos, secondPos, turn, occurs):
    global firstTotal
    global secondTotal
    if firstScore >= 21:
        firstTotal += occurs
        return
    if secondScore >= 21:
        secondTotal += occurs
        return

    global weights
    # This should hypothetically work as i iterates up to 7 making the numbers 3 to 9 as desired
    if turn:
        for i in range(7):
            process(firstScore + (firstPos + i + 3)%10 + 1, secondScore, (firstPos + i + 3)%10, secondPos, 0, occurs * weights[i])
    else:
        for i in range(7):
            process(firstScore, secondScore + (secondPos + i + 3)%10 + 1, firstPos, (secondPos + i + 3)%10, 1, occurs * weights[i])

process(0,0,1,4,1,1)
print(max(firstTotal, secondTotal))