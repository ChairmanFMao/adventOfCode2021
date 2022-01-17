p1Pos = 1
p2Pos = 4
p1Score = 0
p2Score = 0
die = 0
turn = 1
rolls = 0

# 1095468 too high
# 956880 also too high
# 869400 still too high
# 576600 was right :)

# Might be calculating points wrong for loser, idk
# The problem was just that the die didn't go to zero pretty much

while p1Score < 1000 and p2Score < 1000:
    if turn:
        p1Pos += ((die) % 100 + (die+1) % 100 + (die+2) % 100) + 3
        p1Pos %= 10
        p1Score += p1Pos + 1
        turn = 0
    else:
        p2Pos += ((die) % 100 + (die+1) % 100 + (die+2) % 100) + 3
        p2Pos %= 10
        p2Score += p2Pos + 1
        turn = 1
    die += 3
    die %= 100
    rolls += 3

print(rolls * min(p1Score,p2Score))