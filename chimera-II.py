chimin = open("chimin.txt", "r")
chimout = open("chimout.txt", "w")
 
length = int(chimin.readline())
word1 = chimin.readline().strip()
word2 = chimin.readline().strip()
target = chimin.readline().strip()
 
possible = True
splices = 0
same = False
 
for n in range(length):
    if n == 0 or same:
        if word1[n] == word2[n] and word1[n] == target[n]:
            same = True
        elif word1[n] == target[n]:
            same = False
            last = word1
        elif word2[n] == target[n]:
            same = False
            last = word2
        else:
            possible = False
            break
    else:
        if last[n] == target[n]:
            continue
        else:
            if word1[n] == target[n]:
                splices += 1
                last = word1
            elif word2[n] == target[n]:
                splices += 1
                last = word2
            else:
                possible = False
                break
 
if possible:
    chimout.write("SUCCESS\n")
    chimout.write(str(splices))
else:
    chimout.write("PLAN FOILED")
