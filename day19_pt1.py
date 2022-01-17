# With the input parsed like this, empty strings('') separate the scanners information
# With more processing done in the parse, it now creates an array of all the positions as ints with empty lists to separate the scanners

with open(".\day19_input.txt") as f:
    lines = [[int(b) for b in a.split(",") if b != ''] for a in f.read().split("\n") if a.count("scanner") == 0]
# This line is to make sure that the last list of abs are appended to the array
lines.append([])

# Notes:
# Scanners can detect all beacons in a 1000 unit away cube from their location
# Positional data that we have from scanners are all relative to the scanner's location
# Scanner's don't know their own position
# To find pairs of scanners that overlap, there need to be at least 12 beacons that both scanners detect within the overlap
# Scanner's don't know their rotation or facing direction, one scanner might call a direction positive x while another scanner
# might call that direction negative y. Each scanner could be in 24 different orientations.
# I think that I need to look at the relative difference between the points for each scanner as they seem to be what dictates which scanners are joined together
# I can't use the abs function to do it all, I need to look at the transformation vectors for 90 rotation in each axis
# Honestly, unsure how to use the rotation matrices, try the points in all the matrices? idk
# I had dad help me with the problem and the method, I am going to use a cool thing
# Currently have two issues, which points do I compare to each other and the difference in the lengths of the lists
# I think the problem is about which points in the list need to be compared, idk tho

# This is a helper function that will check the number of repeated values
def check12(points, otherPoints):
    count = 0
    for a in points:
        if a in otherPoints:
            count += 1
    return count >= 12

def diffAndCheck(original, fresh):
    global scanners
    # Not sure which items in fresh and original to compare, sorting them doesn't seem to work well, nor does doing nothing to them
    for i in range(len(original)):
        for j in range(len(fresh)):
            # We assume that fresh[j] == original[i], the points are at the same place
            translation = [original[i][0]-fresh[j][0], original[i][1]-fresh[j][1], original[i][2]-fresh[j][2]]
            temp = []
            # I had a bug in this for loop where I used the wrong list name and it was screwing me over for so long
            for k in range(len(fresh)):
                temp.append([fresh[k][0]+translation[0],fresh[k][1]+translation[1],fresh[k][2]+translation[2]])
            if check12(temp, original):
                scanners.append(translation)
                return temp
    return []

scanners = [[0,0,0]]

# This stores an array of the identified scanners
good = []
# This stores an array of the scanners to still be identified
bad = []

current = []
for i in range(len(lines)):
    if (len(lines[i]) == 0):
        bad.append(current)
        current = []
    else:
        current.append(lines[i])

good.append(bad.pop(0))
counter = 0

# Change the if to a while later, the if is just for testing purposes
while len(bad) > 0:
    # Iterate over all of the scanners yet to be indentified
    finished = False
    for i in range(len(bad)):
        for c in range(8):
            medium = [[],[],[],[],[],[]]
            for j in range(len(bad[i])):
                x = int(bad[i][j][0] * pow(-1,(c//2)//2))
                y = int(bad[i][j][1] * pow(-1,c//2))
                z = int(bad[i][j][2] * pow(-1, c))
                medium[0].append([x,y,z])
                medium[1].append([x,z,y])
                medium[2].append([y,x,z])
                medium[3].append([y,z,x])
                medium[4].append([z,x,y])
                medium[5].append([z,y,x])
            
            for k in range(6):
                value = diffAndCheck(good[counter%len(good)], medium[k])
                if len(value) > 0:
                    bad.pop(i)
                    good.append(value)
                    finished = True
                    break
            if finished:
                break
        if finished:
            break
    counter += 1

# Currently I get the answer of 127 for the test input not 79
# The code executes well, just a little slow, it takes ages even for the sample input now, idk why
# Also answer of 357 was too high
# The right answer was 303 for my input, it took about 7-8 mins to execute but it was right!
beacons = set()
for i in range(len(good)):
    for j in range(len(good[i])):
        beacons.add(tuple(good[i][j]))
print(len(beacons))
print(scanners)