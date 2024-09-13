chimpin = open("chimpin.txt", "r")
chimpout = open("chimpout.txt", "w")
 
coords = chimpin.readline().strip().split()
x = int(coords[0])
y = int(coords[1])
 
if x == 0 and y == 0:
    num = "0"
elif y < 0 and abs(y) >= abs(x):
    a = (2*y - 1) ** 2
    b = abs(y) + 1 - x
    num = str(a-b)
elif y > 0 and abs(y) >= abs(x):
    a = (y*2)**2
    b = y + x
    num = str(a-b)
elif x < 0 and abs(x) > abs(y):
    a = (x*2)**2
    b = abs(x) - y
    num = str(a+b)
elif x > 0 and abs(x) > abs(y):
    a = (x*2-1)**2
    b = x - 1 + y
    num = str(a+b)
 
chimpout.write(num)
chimpin.close()
chimpout.close()
