bankin = open('bankin.txt', "r")
bankout = open("bankout.txt", "w")
 
N = int(bankin.readline())
nums = bankin.readline().strip()

s = 1
e = 0

for n in range(N):
    if nums[n] == "M":
        e += s
    else:
        days_remaining = N - 1 - n
        if days_remaining * (s+1) + e > e + ((days_remaining+1) * s):
            s += 1
        else:
            e += s

bankout.write(str(e))
