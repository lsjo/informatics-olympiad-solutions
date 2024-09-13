import math

cocoin = open("cocoin.txt", "r")
cocoout = open("cocoout.txt", "w")

IX, IY, ID = list(map(int, cocoin.readline().split()))
CX, CY, CD = list(map(int, cocoin.readline().split()))

dist = math.sqrt((IX-CX)**2 + (IY-CY)**2)
nums = math.sqrt((ID+CD)**2)


if nums >= dist and dist >= abs(ID-CD):
    cocoout.write("yes")
else:
    cocoout.write("no")

cocoout.close()
cocoin.close()
