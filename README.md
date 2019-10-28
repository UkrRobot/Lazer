# Lazer
Crystallization after laser treatment of the metal surface

The following program allows us to model the solidification of the melt hemisphere that arose after irradiation of the sample surface with a laser beam. The equation of thermal conductivity in the case of spherical symmetry for the region of the solid phase bordering on the melt is considered. The solution is the method of running after recording the derivatives because of the temperature values at the nodes of the grid (see expressions for B[i] in the program). The second expression for B[i] is the correction of the mixing of nodes as the grid is reconstructed at each time step due to the movement of the crystallization front.
At the boundary of the melt-solid phase is set the melting temperature, and at the outer, conditional hemispherical boundary in the solid phase is room temperature. The rate of growth is based on the condition of heat balance on the interfacial boundary (see expression v:=xt*(T[2]-T[1])/(dR*L); in the program). The values of the basic parameters are: g - density, L - melting heat per unit volume, xt - thermal conductivity, c - specific heat, at - solid-state thermal conductivity assigned to the program, characteristic of aluminum (in units SI).

![alt text](https://github.com/UkrRobot/Lazer/blob/master/Scrn_Lazer.png)


This program was developed under the guidance of Professor A. Ovrutsky.
