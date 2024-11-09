partyin = open("partyin.txt", "r")
partyout = open("partyout.txt", "w")

n, m, a, b= map(int, partyin.readline().split())

nums = {}

for i in range(n):
    nums[i+1] = set()

for i in range(m):
    x, y = map(int, partyin.readline().split())
    nums[x].add(y)
    nums[y].add(x)

changed = True

while changed:
    changed = False
    toremove = set()
    for i in nums:
        if len(nums[i]) < a or n - len(nums[i]) - 1 < b:
            print("removing " + str(i))
            changed = True
            toremove.add(i)
    for i in toremove:
        if i in nums:
            nums.pop(i)
        for q in nums:
            if i in nums[q]:
                nums[q].remove(i)
        n -= 1

print(len(nums))

partyout.write(str(len(nums)))
