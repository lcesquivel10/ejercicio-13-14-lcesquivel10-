import numpy as np
import matplotlib.pyplot as plt


DATA_14 = np.loadtxt("Poincare_1.400000.dat")
DATA_144 = np.loadtxt("Poincare_1.440000.dat")
DATA_1465 = np.loadtxt("Poincare_1.465000.dat")

Omega_14 = DATA_14[:,[0,0]]
Theta_14 = DATA_14[:,[1,1]]
time_14 = DATA_14[:,[2,2]]

Omega_144 = DATA_144[:,[0,0]]
Theta_144 = DATA_144[:,[1,1]]
time_144 = DATA_144[:,[2,2]]

Omega_1465 = DATA_1465[:,[0,0]]
Theta_1465 = DATA_1465[:,[1,1]]
time_1465 = DATA_1465[:,[2,2]]

plt.figure()
plt.scatter(Omega_14,Theta_14,s=2)
plt.xlabel("Theta")
plt.ylabel("Omega")
plt.savefig("Poincare_14.png")

plt.figure()
plt.scatter(Omega_144,Theta_144,s=2)
plt.xlabel("Theta")
plt.ylabel("Omega")
plt.savefig("Poincare_144.png")

plt.figure()
plt.scatter(Omega_1465,Theta_1465,s=2)
plt.xlabel("Theta")
plt.ylabel("Omega")
plt.savefig("Poincare_1465.png")

DATA_Bifur = np.loadtxt("Bifurcation.dat")
Omega_Bifur = DATA_Bifur[:,[0,0]]
Theta_Bifur = DATA_Bifur[:,[1,1]]

plt.figure()
plt.scatter(Omega_Bifur,Theta_Bifur,s=2)
plt.xlabel("FD")
plt.ylabel("Theta")
plt.savefig("Bifurcation.png")
