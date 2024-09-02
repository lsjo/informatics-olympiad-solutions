javelin = open("javelin.txt", "r")
javelout = open("javelout.txt", "w")
 
N = int(javelin.readline())
throws = list(map(int, javelin.readline().split()))
 
nums = [throws[0]]
leaders = 1
 
for n in range(1, N):
    a = throws[n]
    if a > nums[-1]:
        leaders += 1
        nums.append(a)
 
javelout.write(str(leaders))
