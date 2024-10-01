lscin = open("lscin.txt", "r")
lscout = open("lscout.txt", "w")

N, L = map(int, lscin.readline().split())
pos = list(map(int, lscin.readline().split()))
perm = list(map(int, lscin.readline().split()))

order = []
perm = perm[::-1]

for i in range(N):
    order.append(pos[perm[i] - 1])

lo = 1
hi = L
poss = True

for n in range(1, N):
    mid = abs(order[n]-order[n-1]) // 2
    if order[n] > order[n-1]:
        lo = max(order[n] - mid, lo)
    else:
        hi = min(hi, order[n] + mid)

if lo > hi:
    lscout.write("-1")
else:
    lscout.write(str(lo))
