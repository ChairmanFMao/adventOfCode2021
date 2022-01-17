with open(".\\day16_input.txt") as f:
    lines = f.read()

# Not really sure how to tell where packets end and other packets begin
# Notes:
# The version of the packet is encoded in the first 3 bits
# The next 3 bits are the typeID
# If the typeID is 4, then it is a literal value and all of the value after except the last are preceeded by 1
# The last value is preceeded by a zero, there may also be trailing zeros after the number is finished
# For operators, there is another single bit after the typeID called the length type ID
# If the length type ID is zero then the next 15 bits are a number that represents the total length of bits of the sub-packets
# If the length type ID is one then, the next 11 bits are a number that represents the number of sub-packets immediately contained by this packet
# These sub-packets are just like the literal value packets

# Its not 33 or 164 as I tried both of these, unsure where my code may have errors
# 2114 also doesn't work, I ran the code with more changes and I have 210 as an answer, waiting on the cooldown for guessing rn
# Only the outer packet has the trailing zeros
# Turns out 210 is also not the answer, unsure of where to go from here

versionTotal = 0
ptr = 0

def processLiteralEasy():
    global binary
    global ptr
    while binary[ptr] != "0" and ptr < len(binary)-1:
        ptr += 5
    ptr += 5

def processPacket():
    global versionTotal
    global binary
    global ptr

    v = binary[ptr:ptr+3]
    versionTotal += int(v,2)
    ptr+=3
    t = binary[ptr:ptr+3]
    ptr+=3
    if t == "100":
        processLiteralEasy()
        return
    
    lengthTypeID = binary[ptr]
    ptr += 1
    if lengthTypeID == "0":
        totalLength = int(binary[ptr:ptr+15],2)
        ptr += 15
        start = ptr
        while ptr - start < totalLength:
            processPacket()
    else:
        packets = int(binary[ptr:ptr+11],2)
        ptr += 11
        for i in range(packets):
            processPacket()

def process():
    global versionTotal
    global ptr
    global binary
    while ptr < len(binary):
        if all(a == "0" for a in binary[ptr:]):
            break
        processPacket()
            

# 8A004A801A8002F478 string should have version number of 16, but I get 9 as output, I think I need to allow for there to be operator packets inside operator packets
# I have modified my code, there is still an error for the above string, it doesn't seem to count the last packet process which sucks
# Made a function that processes operator packages, maybe also one that does the literal packages as well to make the code more modular
# Code finally works!

binary = bin(int(lines,16))[2:]
process()
print(versionTotal)