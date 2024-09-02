shopin = open("shopin.txt", "r")
shopout = open("shopout.txt", "w")
 
N, K = map(int, shopin.readline().split())
prices = list(map(int, shopin.readline().split()))
 
i = 0
j = N-1
total = 0
while K > 0:
    K = K -1
    total += prices[i]
    i += 1
    j -= 1
while j >= i:
    if i % 2 == j % 2:
        total += prices[i]
    i += 1
  
shopout.write(str(total))
