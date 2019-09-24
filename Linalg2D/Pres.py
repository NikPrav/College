import numpy as np
import matplotlib.pyplot as plt
from coeffs import *


#Plotting the circle
len=100

x=np.array([9,7])
r=2.828
x=np.zeros((len))
theta = np.linspace(0,2*np.pi,len)
x_circ = np.zeros((2,len))
x_circ[0,:] = r*np.cos(theta)+8
x_circ[1,:] = r*np.sin(theta)+6
plt.plot(x_circ[0,:],x_circ[1,:],label='$f(x)$')
plt.plot(10,8,'o')
plt.text(10,8,'X')

#Plotting the line
A = np.array([9,9])
B = np.array([1,17]) 
x=line_gen(A-(B-A)*5,(B-A)*5+A)

x1_extend = np.linspace(-5,40,100)
x2_extend = 40*np.ones(100) - x1_extend

bx=plt.plot(x[0],x[1],label="$x_1+x_2-18=0$")

plt.fill_between(x1_extend,x2_extend,color='grey')
plt.fill_between(x[0],x[1],color='white')
plt.axis('equal')
plt.grid()
plt.xlabel('$x_1$')
plt.ylabel('$x_2$')
plt.legend( loc='best')

plt.xlim(-5, 15)
plt.ylim(0, 22)


#plt.savefig('../figs/2.4.eps')
plt.show()



#plt.savefig('../figs/2.4.eps')
plt.show()
