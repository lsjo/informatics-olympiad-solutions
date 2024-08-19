antsin = open("antsin.txt", "r")
antsout = open("antsout.txt", "w")
 
N = int(antsin.readline())
nums = [int(antsin.readline()) for n in range(N)]
sequences = 0
streak = 0
 
for n in range(1, N):
    if nums[n] > nums [n-1]:
        streak += 1
        if n == N-1:
            if streak >= 1:
                sequences += 1            
    else:
        if streak >= 1:
            sequences += 1
        streak = 0
 
antsout.write(str(sequences))
