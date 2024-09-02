bookin = open("bookin.txt", "r")
bookout = open("bookout.txt", "w")
 
N = int(bookin.readline())
word = bookin.readline().strip()
 
last = ""
score = 0
 
for n in range(N):
    if n == 0:
        if word[n] == "?":
            score += 1
        else:
            last = word[n]
    else:
        if word[n] == "?":
            last = word[n-1]
            score += 1
        else:
            if word[n] == last:
                score += 1
            else:
                last = word[n]
 
bookout.write(str(score))
