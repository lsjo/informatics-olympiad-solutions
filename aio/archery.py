archin = open("archin.txt", "r")
archout = open("archout.txt", "w")
 
N, A, B = map(int, archin.readline().split())
 
best = (N - (N-A) - (N-B)) if (N - (N-A) - (N-B)) > 1 else 1
worst = ((A-1) + (B-1) + 1) if ((A-1) + (B-1) + 1) < N else N
 
archout.write(str(best)+" "+str(worst))
