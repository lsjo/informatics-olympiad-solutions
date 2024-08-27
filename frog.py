frogin = open("frogin.txt", "r")
frogout = open("frogout.txt", 'w')
 
N = int(frogin.readline())
heights = []
 
for n in range(N):
    heights.append(int(frogin.readline()))
 
back = []
 
for n in range(N):
    if n == 0:
        back.append(heights[0])
    else:
        back.append(min(back[-1], heights[n]))
 
front = []
 
for n in range(N-1, -1, -1):
    if n == N-1:
        front.append(heights[n])
    else:
        front.append(min(front[-1], heights[n]))
 
front = front[::-1]
 
diff = 0
 
for i in range(1, N-1):
    if heights[i] > back[i-1] and heights[i] > front[i+1]:
        num = (heights[i] - back[i-1]) + (heights[i] - front[i+1])
        diff = max(diff, num)
 
frogout.write(str(diff))
frogout.close()
frogin.close()
