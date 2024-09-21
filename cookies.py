cookiesin = open("cookiesin.txt", "r")
cookiesout = open("cookiesout.txt", "w")
 
D, C0 = map(int, cookiesin.readline().split())
P1, C1 = map(int, cookiesin.readline().split())
P2, C2 = map(int, cookiesin.readline().split())

baseline = D*C0

a = P1 // C0 + (1 if P1 % C0 != 0 else 0)
if a >= D:
    just1 = 0
else:
    just1 = a * C0 - P1 + (D-a) * (C0+C1)
 
a = P2 // C0 + (1 if P2 % C0 != 0 else 0)
if a >= D:
    just2 = 0
else:
    just2 = a * C0 - P2 + (D-a) * (C0+C2)

a = P1 // C0 + (1 if P1 % C0 != 0 else 0)
b = a * C0 - P1
daystil2 = (P2 - b) // (C1 + C0) + (1 if ((P2 - b) % (C1 + C0)) != 0 else 0)
if a + daystil2 >= D:
    firstsecond = 0
else:
    firstsecond = b + daystil2 * (C1+C0) + (D-a-daystil2) * (C1+C0+C2) - P2

a = P2 // C0 + (1 if P2 % C0 != 0 else 0)
b = a * C0 - P2
daystil = (P1 - b) // (C2 + C0) + (1 if ((P1 - b) % (C2 + C0)) != 0 else 0)
if a + daystil >= D:
    secondfirst = 0
else:
    secondfirst = b + daystil * (C2+C0) + (D-a-daystil) * (C1+C0+C2) - P1
 
nums = {baseline, just1, just2, firstsecond, secondfirst}
 
cookiesout.write(str(max(nums)))
print(max(nums))
