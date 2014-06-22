s = 'azcbobobegghakl'
sub = 'bob'
count = 0
for i in range(0, len(s)):
    if sub in s[i:i+3]:
        count+=1

print "Number of times bob occurs is: " + str(count)
