IN = open("dictin.txt", "r")
OUT = open("dictout.txt", "w")
 
nums = list(map(int, IN.readline().split()))
 
translator = {}
 
for n in range(nums[0]):
    wow = IN.readline().split()
    a, b = wow[0], wow[1]
    translator[a] = b
 
print(translator)
 
for a in range(nums[1]):
    x = IN.readline().rstrip()
    try:
        OUT.write(translator[x]+"\n")
    except:
        OUT.write("C?\n")
 
OUT.close()
