s = input()
stack = []
n = len(s)
count = 0
for i in s:
    if i == "(":
        stack.append(i)
        continue
    else:
        if stack == []:
            continue
        else:
            if stack.pop() == "(" and i == ")":
                count += 1
print(count*2)
