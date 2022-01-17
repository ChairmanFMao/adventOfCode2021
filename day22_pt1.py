# Very cool input parsing :)
with open(".\day22_input.txt") as f:
    lines = [[x.split(" ")[0] == "on", [int(a) for a in x.split(",")[0].split("=")[1].split("..")], [int(a) for a in x.split(",")[1].split("=")[1].split("..")], [int(a) for a in x.split(",")[2].split("=")[1].split("..")]] for x in f.read().split("\n")[:20]]

# 755 is too low

on = set()
for i in lines:
    if i[0]:
        for j in range(i[1][0], i[1][1]+1,1):
            for k in range(i[2][0], i[2][1]+1, 1):
                for l in range(i[3][0], i[3][1]+1, 1):
                    on.add((j,k,l))
    else:
        for j in range(i[1][0], i[1][1]+1,1):
            for k in range(i[2][0], i[2][1]+1, 1):
                for l in range(i[3][0], i[3][1]+1, 1):
                    if (j,k,l) in on:
                        on.remove((j,k,l))

print(len(on))