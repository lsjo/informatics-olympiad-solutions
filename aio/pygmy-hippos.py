hippoin = open("hippoin.txt", "r")
hippoout = open("hippoout.txt", 'w')
 
N = int(hippoin.readline())
a, b, c = int(hippoin.readline()), int(hippoin.readline()), int(hippoin.readline())
 
four = N - c
three = c - b - 1
two = b - a - 1
one = a - 1
 
mid = max(three, two)
x = min(mid, four, one)
number = four + one + mid - x
 
hippoout.write(str(number))
