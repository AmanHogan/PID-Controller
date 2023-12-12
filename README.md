
### Author: Aman Hogan 
#  Project and Summary

### Assignment description: In this exercise you are going to perform system identification and implement a PD controller for a 1 degree-of-freedom robot manipulator.Again you are provided with a C library containing a dynamic simulator and a file in which you should imple-ment the controller. For this part of the assignment, download the corresponding code and uncompress i
# Set Up Ubuntu (Linux)

To install it under Ubuntu, you need to install a number of extra packages with the development libraries:
`apt-get install build-essential`
`apt-get install xutils-dev`
`apt-get install libxt-dev`
`apt-get install libxaw7-dev`
Put the tar file on your on your computer and uncompress it.
In a terminal:
- Go to the project folder (kin or dyn)
- Build the Makefile (you only have to do this once): `xmkmf`
- Compile the project: `make`
- This will produce a few warnings and show you whether there were errors (ignore the can not build Kinematics.man error - this is just that it does not find documentation to build)
- Run the executable: `./Kinematics`


# Documentation
- To view the documentation, you can go inside the html folder and open the `index.html`, whihc should open a doxygen page.


# Contributions
- Author:  Aman Hogan
- Professor: Manfred Huber, The University of Texas at Arlington

