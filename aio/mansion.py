manin = open("manin.txt", "r")
manout = open("manout.txt", "w")

N, W = map(int, manin.readline().split())

houses = []

for i in range(N):
    houses.append(int(manin.readline()))

num = sum(houses[:W])
maximum = num

for i in range(W, N):
    num = num - houses[i-W] + houses[i]
    maximum = max(maximum, num)

manout.write(str(maximum))
