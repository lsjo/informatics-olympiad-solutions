rpsin = open("rpsin.txt", "r")
 
rounds = int(rpsin.readline())
ops = list(map(int, rpsin.readline().rstrip().split()))
yours = list(map(int, rpsin.readline().rstrip().split()))
 
wins = 0
draws = 0
losses = 0
 
for n in range(3):
    if ops[n] > yours[(n+1) % 3]:
        cwins = yours[(n+1) % 3]
    else:
        cwins = ops[n]
    yours[(n+1) % 3] -= cwins
    ops[n] -= cwins
    wins += cwins
 
for n in range(3):
    if ops[n] > yours[n]:
        cdraws = yours[n]
    else:
        cdraws = ops[n]
    ops[n] = ops[n] - cdraws
    yours[n] = yours[n] - cdraws
    draws += cdraws
 
score = wins + (-1*(rounds-wins-draws))
rpsout = open("rpsout.txt", "w")
rpsout.write(str(score))
