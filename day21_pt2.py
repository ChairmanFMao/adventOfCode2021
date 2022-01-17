from functools import lru_cache

# Keep a dictionary with game states that have been processed before and constantly check it?
# I will store the outcomes of the game in the dictionary for each game object
# 4517662813452 is too low
# Getting big numbers as answers but they are off by about a factor of 100 I think, not sure why this is the case
# Answer should be about 15 digits long
# 121862889550792 is also too low
# 131888061854776 was the right answer, I had to look at someone else's answer to see if I could find the error, in the end I found it myself
# For some reason the approach I was trying with global variables wasn't working, I am going to try to implement my original method in a second python file (day21_pt2original.py)

# The p1 score is first, then the p2 score, then the p1 position, then the p2 position, then the turn(1 means p1, 0 means p2), then the weight(occurances of this position)
weights = [1,3,6,7,6,3,1]

@lru_cache(maxsize=None)
def process(firstScore, secondScore, firstPos, secondPos, turn, occurs):

    if firstScore >= 21:
        return [occurs, 0]
    if secondScore >= 21:
        return [0, occurs]

    global weights
    # This should hypothetically work as i iterates up to 7 making the numbers 3 to 9 as desired
    if turn:
        values = [process(firstScore + (firstPos + i + 3)%10 + 1, secondScore, (firstPos + i + 3)%10, secondPos, 0, occurs * weights[i]) for i in range(7)]
    else:
        values = [process(firstScore, secondScore + (secondPos + i + 3)%10 + 1, firstPos, (secondPos + i + 3)%10, 1, occurs * weights[i]) for i in range(7)]
    return [sum(i[0] for i in values), sum(i[1] for i in values)]

p1Wins, p2Wins = process(0,0,1,4,1,1)
print(max(p1Wins, p2Wins))