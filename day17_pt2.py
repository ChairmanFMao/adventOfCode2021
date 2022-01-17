# I did part 1 mathematically, the x coordinate doesn't matter, the y coord should just land at the lowest possible
# This means that it collides with the box at y = -93, to reach this the starting y velocity should be 92
# From this we can sum the triangle numbers from 1 to 92 and that would be the maximum height it reaches

# The bounds for the box are x = 195 to 238 and y = -93 to -67

# Program outputed 1787 but it is too low
# Ran again and got 1875 but it is also too low
# Unsure why 1875 is too low, keep getting that as the output from the program
# Found the bug, it was on line 26, I was checking if x was above zero instead of checking if xVel was above zero

landing = 0

# return value of 1 means that it is in the box, 0 means that it can still land in the box, -1 means that it is now impossible for it to land in the box
def valid(x, y):
    return 1 if x <= 238 and x >= 195 and y >= -93 and y <= -67 else (-1 if x > 238 or y < -93 else 0)

# This function calculates the positions of the probe on its path
def check(xVel, yVel):
    global landing
    x = 0
    y = 0
    working = 0
    # The working variable represents the position of the probe, 0 means that it could still land in the box, 1 means that its in the box and -1 means its impossilbe to land in the box
    while working == 0:
        x += xVel
        y += yVel
        xVel -= 1 if xVel > 0 else 0
        yVel -= 1
        working = valid(x,y)
    
    if working == 1:
        landing += 1

# The value for x can't be less than 20 otherwise it never reaches the box
for i in range(20, 239, 1):
    for j in range(-93, 93, 1):
        check(i,j)

print(landing)