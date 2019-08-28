from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from funcs import *
import numpy as np
import math
len=100

#setting up plot
fig = plt.figure()


ax = fig.add_subplot(111,projection='3d')

#Taking points in xy plane
Ayz=np.array([1,0])
Byz=np.array([0,1])
Oyz=(Ayz+Byz)/2.0
Cyz=np.array([1,1])
Pyz=(Ayz+Cyz)/2.0
x=np.zeros((len))
CCyz=(Ayz+Byz+Cyz)/4.0

r=np.linalg.norm(CCyz-Ayz)
x=np.zeros((len))
theta = np.linspace(0,2*np.pi,len)
x_circ = np.zeros((2,len))
x_circ[0,:] = r*np.cos(theta)
x_circ[1,:] = r*np.sin(theta)
x_circ = (x_circ.T + CCyz).T


CCyz=(Ayz+Byz+Cyz)/4.0
Cent=(Ayz+Byz+Cyz)/3.0
Ortho=(Ayz+Byz+Cyz)/2.0




plt.plot(x,x_circ[0,:],x_circ[1,:],label='$circumcircle$')
plt.plot([0,0],[Ayz[0],Byz[0]],[Ayz[1],Byz[1]],label="Line $AB$")
plt.plot([0,0],[Byz[0],Cyz[0]],[Byz[1],Cyz[1]],label="Line $BC$")
plt.plot([0,0],[Ayz[0],Cyz[0]],[Ayz[1],Cyz[1]],label="Line $CA$")


p=np.zeros(2)
n1 = Byz-Cyz
p[0] = np.matmul(n1,Ayz)
#BQ
n2 = Cyz-Ayz
p[1] = np.matmul(n2,Byz)

#Intersection
N=np.vstack((n1,n2))
H=np.matmul(np.linalg.inv(N),p)

ax.scatter(0,H[0],H[1],'o',label="Orthocentre")
ax.scatter(0,CCyz[0],CCyz[1],'o',label="Circumcentre")
ax.scatter(0,Ayz[0],Ayz[1],'o',label="$A$")
ax.scatter(0,Byz[0],Byz[1],'o',label="$B$")
ax.scatter(0,Cyz[0],Cyz[1],'o',label="$C$")



plt.plot([0,0],[np.transpose(H)[0],Byz[0]],[np.transpose(H)[1],Byz[1]],label="Line $Altitude_1$")
plt.plot([0,0],[np.transpose(H)[0],Ayz[0]],[np.transpose(H)[1],Ayz[1]],label="Line $Altitude_2$")

plt.plot([0,0],[CCyz[0],H[0]],[CCyz[1],H[1]],label="Euler's Line")
Oyz=(Ayz+Byz+Cyz)/3.0
ax.scatter(0,Oyz[0],Oyz[1],'o',label="$Centroid$")

plt.xlabel('$x$');plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid()

plt.show()

