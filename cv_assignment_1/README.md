#Assignement 1

##Problem statement

Contour moments are roughly unique for a shape, so, these can be compared to determine if 2 shapes are "similar".
You are given a template image containing 2 shapes: A circle and A square.
You need to extract normalised moments for both of these shapes, and use these values to determine whether a given image contains a circle or a square. 

You have to write a file named moments.cpp that takes 1 argument during execution:
	i.e. path to image under consideration
	
NOTE: this means that if the executable generated on compilation is "exec", 
the execution syntax should be 
	$ ./exec <path to image> 	e.g. if path is "image.png" 
						$ ./exec image.png
Your program should return "CIRCLE" if the input image contains a circle and "SQUARE" if the input image contains a square.

##Compiling your code

	//make a folder named build and navigate to it
	$ mkdir build
	$ cd build

	//generate makefile using the CMakeLists.txt provided
	$ cmake ..

	//compile
	$ make 

If there are no errors, you will see that an executable will be generated in the main folder.
You can test your code using this executable and the test image provided.

NOTE: you do not need to make build again and again. Just run 
	$ make 		
to recompile.
 
##Submission
go to build directory and run 
	$ make clean 

Now zip this folder and get xxx_cv_assignment1.zip where xxx is your roll number. Submit this file.
