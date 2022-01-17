with open(".\\day16_input.txt") as f:
    lines = f.read()

# Notes:
# typeID = 0 - sum, the sum of all the sub-packets
# typeID = 1 - product, the results of multiplying together all the sub-packets
# typeID = 2 - minimum, their value is the minimum of all the sub-packets
# typeID = 3 - maximum, their value is the maximum of all the sub-packets
# typeID = 4 - literal value, the packet is just a numeric value
# typeID = 5 - greater than, their value is one if the value of the first sub-packet is greater than the value of the second sub-packet, exactly two sub-packets
# typeID = 6 - less than, their value is one if the value of the first sub-packet is less than the value of the second sub-packet, exactly two sub-packets
# typeID = 7 - equal to, their vlaue is ont if the value of the first sub-packet is equal to the value of the second sub-packet, exactly two sub-packets

# This worked first try and I am so happy about it, the steps I used in part 1 to make the code more modular really paid off as it was easy to implement part 2
# Python is also so nice for this as these 80 lines of python would be literally hundreds of lines of cpp, shows the true simplicity of a high level language

ptr = 0

def processLiteral():
    global binary
    global ptr

    value = ""
    while binary[ptr] != "0" and ptr < len(binary)-1:
        value += binary[ptr+1:ptr+5]
        ptr += 5
    value += binary[ptr+1:ptr+5]
    ptr += 5
    return int(value,2)

def processPacket():
    global versionTotal
    global binary
    global ptr

    v = binary[ptr:ptr+3]
    ptr+=3
    t = int(binary[ptr:ptr+3],2)
    ptr+=3
    if t == 4:
        return processLiteral()
    
    values = []
    lengthTypeID = binary[ptr]
    ptr += 1
    if lengthTypeID == "0":
        totalLength = int(binary[ptr:ptr+15],2)
        ptr += 15
        start = ptr
        while ptr - start < totalLength:
            values.append(processPacket())
    else:
        packets = int(binary[ptr:ptr+11],2)
        ptr += 11
        for i in range(packets):
            values.append(processPacket())
    # Need to implement something that processes the values that you have into something useful
    # I have stored all of the values of the sub-packets in the array values, time to then process them depending on the typeID of the packet
    if t == 0:
        return sum(values)
    elif t == 1:
        out = 1
        for i in values:
            out *= i
        return out
    elif t == 2:
        return min(values)
    elif t == 3:
        return max(values)
    elif t == 5:
        return 1 if values[0] > values[1] else 0
    elif t == 6:
        return 1 if values[1] > values[0] else 0
    elif t == 7:
        return values[0] == values[1]


# Made some changes from the part 1 to make the code a little cleaner
binary = bin(int(lines,16))[2:]
print(processPacket())