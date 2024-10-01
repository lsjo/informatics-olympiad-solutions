snakein = open("snakein.txt", "r")
snakeout = open("snakeout.txt", 'w')
 
x, y = map(int, snakein.readline().split())
 
string = ""
 
reps = min(abs(x), abs(y))
 
if x > 0 and y > 0:
    string += "RL"*reps
elif x > 0 and y < 0:
    if reps != 0:  
        string += "RR"
        string += "LR"*(reps-1)
elif x < 0 and y > 0:
    string += "LR"*reps
elif x < 0 and y < 0:
    if reps != 0:
        string += "LL"
        string += "RL"*(reps-1)
 
if abs(y) > abs(x):
    if x == 0 and y < 0:
        y += 1
        string += "RRR"
        string += "LLRR"*(abs(y) // 2)
        string += "L" * (abs(y) % 2)
    else:
        a = abs(y) - abs(x)
        fulls = a // 2
        string += "LRRL"*fulls
        string += "LRR"*(a % 2)
 
if abs(x) > abs(y):
    if (x > 0 and y >= 0) or (x < 0 and y < 0):
        a = abs(x) - abs(y)
        string += (a//2)*"RRLL"
        string += (a % 2)*"R"
    else:
        a = abs(x) - abs(y)
        string += (a//2)*"LLRR"
        string += (a % 2) * "L"
 
snakeout.write(string)
