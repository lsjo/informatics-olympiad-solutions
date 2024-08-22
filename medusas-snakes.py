snakein = open("snakein.txt", "r")
snakeout = open("snakeout.txt", "w")
 
def checker(string, level):
    snake = "SNAKE"
    ticks = 0
    count = 0
    char = 0
    for n in string:
        if n == snake[char]:
            count += 1
        if count == level:
            ticks += 1
            char += 1
            count = 0
            if ticks == 5:
                break
    if ticks == 5:
        return True
    else:
        return False
 
N = int(snakein.readline())
string = snakein.readline().strip()

lo = 0
hi = N // 5

while lo != hi:
    mid = (hi + lo + 1) // 2
    if checker(string, mid):
        lo = mid
    else:
        hi = mid - 1
 
snakeout.write(str(lo))
snakeout.close()
snakein.close()
