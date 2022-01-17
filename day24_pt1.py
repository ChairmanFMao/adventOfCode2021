with open(".\day24_input.txt") as f:
    lines = f.read().split("\n")

# I think that I might try to implement this in cpp with multithreading
# I ended up looking at some people's techniques on reddit, and I found that you can do it manually on paper
# https://topaz.github.io/paste/#XQAAAQDfAgAAAAAAAAArGEmHiIpGP4zhdCY8NCMXKZ3lLpDi5Igah0EK7diCw7OWAw8n/BXLbnT9lav/oRLs+mvRxr7KW9j55Ed7pao5NGfg++ISskyF8aChRBEtyXbWorPE+CcBpg3OqUJRrGK6DkFPweLmr/2pM4FtlBZ5OCQzJ0C3esGAsy/8/sUIjCLwGbad5hr4+FhBwDB+gvha0m3vj1QrrpNb6aVL8nv6E77wnaosOp6cE9NXbk8UKoo4s61P3GIxgw1yQs74g9tCjzyuoDM5ECi1KYF42VUXFVvC6Dy82gUIIhdzQ/qj8Fm4H98jjVpOkldjnoVhWnYzFY9FwBMBsr2azDmSj7qBDETjcaHIb+dIainG6TGxIx7auG4CkBCqLjn4fNz/YYNwAA==
# https://github.com/mrphlip/aoc/blob/master/2021/24.md
# Were very helpful posts that helped me to understand what was being asked of me
# This problem was quite easy to solve manually if you realised what was actually happening and did it intelligently
# The rabbit hole was to do brute force like I did, you won't end up getting anywhere without taking literal years
# After going through the whole input manually I found that the inputs have to obey these equations:
# (a is the first input, b is second and so on)
# d = c - 7
# f = e + 1
# i = h + 5
# k = j
# l = g + 8
# m = b + 7
# n = a - 8
# And from there it was very simple to complete both parts one and two of the proble

variables = [0,0,0,0]

def check(test):
    ptr = 0

    for i in range(252):
        current = lines[i].split(" ")

        if current[0] == "inp":
            variables[0] = int(test[ptr])
            ptr += 1
            continue
        
        current[1] = ord(current[1])-119
        secondary = int(current[2]) if current[2].lstrip("-").isnumeric() else variables[ord(current[2])-119]
        if current[0] == "add":
            variables[current[1]] += secondary
        elif current[0] == "mul":
            variables[current[1]] *= secondary
        elif current[0] == "div":
            variables[current[1]] //= secondary
        elif current[0] == "mod":
            variables[current[1]] %= secondary
        elif current[0] == "eql":
            variables[current[1]] = 1 if (variables[current[1]] == secondary) else 0
        
        if variables[3] > 1000000:
            return 0

    return variables[3] == 0

# This is stupid but it works, it is also very inefficient
# Initially had impression that the string had to have characters in descending order but I was being silly
def main():
    for a in range(9,8,-1):
        for b in range(9,0,-1):
            for c in range(9,8,-1):
                for d in range(6,5,-1):
                    for e in range(7,6,-1):
                        for f in range(9,8,-1):
                            for g in range(9,0,-1):
                                for h in range(3,2,-1):
                                    for i in range(9,8,-1):
                                        for j in range(1,0,-1):
                                            for k in range(9,8,-1):
                                                for l in range(9,0,-1):
                                                    for m in range(9,0,-1):
                                                        for n in range(9,8,-1):
                                                            if check(str(a)+str(b)+str(c)+str(d)+str(e)+str(f)+str(g)+str(h)+str(i)+str(j)+str(k)+str(l)+str(m)+str(n)):
                                                                print(str(a)+str(b)+str(c)+str(d)+str(e)+str(f)+str(g)+str(h)+str(i)+str(j)+str(k)+str(l)+str(m)+str(n))
                                                                return

main()