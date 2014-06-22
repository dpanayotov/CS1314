s = 'azcbobobegghakl'
l = list(s)
count = 0
for i in range(0, len(s)):
    if l[i] == 'a' or l[i] == 'e' or l[i] == 'i' or l[i] == 'o' or l[i] == 'u':
        count+=1

print "Number of vowels: " + str(count)
