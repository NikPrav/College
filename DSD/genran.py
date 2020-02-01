import random


file= open('input.txt','w')
invar=random.randrange(1,32)
ouvar=1

file.write('.i '+str(invar))
file.write('\n')
file.write('.o '+str(ouvar))
file.write('\n')
file.write('.ilb ')

for i in range (invar):
    file.write('a'+str(i)+' ')

file.write('\n')
file.write('.olb 1')
file.write('\n')

var=random.randrange(1,2**invar)

for i in range (var):
    print ("Doing job "+str(i) + " of " + str(var)) 
    for i in range (invar):
        file.write(str(random.randrange(0,2)))
    file.write(' ')
    for i in range (ouvar):
        file.write(str(random.randrange(0,2)))
    file.write('\n')
file.write('.e')



