import numpy as np
import soundfile as sf

new_data = np.empty([25000,]) #creating an empty array for new file to be generated from original file
y1 = np.empty([25000,])

loc="forward"

ind = 1
for j in range(1,81):
	b= loc+"/"+loc+str(j)+".wav"
	data, samplerate = sf.read(b) #reading audio file using soundfile library
	#print(len(data), samplerate)
	x= len(data)
	#print(x)
	p = 25000-x
	d = int(p/26)
	
	for y in range(1 ,p, d):
		#print(y)   
		for i in range(0,y+1):      #adding empty elements in the array in the start
			new_data[i] =y1[i]
		for i in range(y,y+x):
			new_data[i] =data[i-y]
		for i in range(y+x , 24999):    #adding empty elements in the array in the end 
			new_data[i] = y1[i]	
		a = "Final/"+loc+"/"+loc+str(ind)+".wav"    #total length becomes 25000
		ind += 1
		sf.write(a, new_data, samplerate)  #audio files are written back to harddisk
		#print(len(new_data),j)
