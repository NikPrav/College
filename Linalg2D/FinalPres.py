from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from funcs import *
import numpy as np
len=100;

#creating x,y for 3D plotting
xx, yy = np.meshgrid([10,50], range(50))
#setting up plot
fig = plt.figure()
ax = fig.add_subplot(111,projection='3d',aspect='auto')

#defining points
A = np.array([5,-1,4])
B = np.array([4,-1,3])

#defining line L : x(k) = A + k*l
A1 = np.array([-1,0,0]).reshape((3,1))
l1 = np.array([1,0,0]).reshape((3,1))

A2 = np.array([0,-1,1]).reshape((3,1))
l2 = np.array([0,1,0]).reshape((3,1))

A3 = np.array([1,1,-3]).reshape((3,1))
l3 = np.array([0,0,1]).reshape((3,1))


#generating points in line 
l1_p = line_dir_pt(l1,A1)
l2_p = line_dir_pt(l2,A2)
l3_p = line_dir_pt(l3,A3)

#Generating P,Q and R
P1=np.zeros((3,4))
Q1=np.zeros((3,4))
R1=np.zeros((3,4))
#for i in range(0,len):
#	P[1,i]=1/(i+1)
#	Q[2,i]=1
#	Q[1,i]=1/(i+2)
#	R[0,i]=1
#	R[1,i]=1
#	R[2,i]=(i+2)

P1[0,0]=-1
P1[0,1]=1/(3)
P1[0,3]=1

Q1[1,0]=0.5
Q1[1,1]=-0.5
Q1[1,2]=-1


for i in range(4):
	Q1[2,i]=1
	R1[0,i]=1
	R1[1,i]=1

R1[2,0]=2
R1[2,1]=-2
R1[2,2]=1
R1[2,3]=0





#plotting points
for i in range(2):
	ax.scatter(P1[0,i],P1[1,i],P1[2,i],'o',label="P")
	ax.scatter(Q1[0,i],Q1[1,i],Q1[2,i],'o',label="Q")
	ax.scatter(R1[0,i],R1[1,i],R1[2,i],'o',label="R")
	
	ax.scatter(R1[0,3],R1[1,3],R1[2,3],'o',label="R4")
	ax.scatter(R1[0,2],R1[1,2],R1[2,2],'o',label="R4")
	ax.scatter(P1[0,3],P1[1,3],P1[2,3],'o',label="P4")
	ax.scatter(Q1[0,2],Q1[1,2],Q1[2,2],'o',label="Q4")
	

#plotting line
plt.plot(l1_p[0,:],l1_p[1,:],l1_p[2,:],label="Line L1")
plt.plot(l2_p[0,:],l2_p[1,:],l2_p[2,:],label="Line L2")
plt.plot(l3_p[0,:],l3_p[1,:],l3_p[2,:],label="Line L3")

#plotting collinear lines
#for i in range(2):
	#plt.plot([P1[0,i],Q1[0,i],R1[0,i]],[P1[1,i],Q1[1,i],R1[1,i]],[P1[2,i],Q1[2,i],R1[2,i]],label="Given Lines")
plt.plot([P1[0,0],R1[0,0],Q1[0,0]],[P1[1,0],R1[1,0],Q1[1,0]],[P1[2,0],R1[2,0],Q1[2,0]],label="Line A")
plt.plot([P1[0,1],R1[0,1],Q1[0,1]],[P1[1,1],R1[1,1],Q1[1,1]],[P1[2,1],R1[2,1],Q1[2,1]],label="Line B")	
	
	

#plotting extremum values
plt.plot([R1[0,2],Q1[0,2]],[R1[1,2],Q1[1,2]],[R1[2,2],Q1[2,2]],label="Extremum 1")
plt.plot([P1[0,3],R1[0,3]],[P1[1,3],R1[1,3]],[P1[2,3],R1[2,3]],label="Extremum 2")



#show plot
plt.xlabel('$x$');plt.ylabel('$y$')
plt.legend(loc='best');plt.grid()
plt.show()

