all: driver.cpp
	g++ -g -Wall --std=c++11 -o driver driver.cpp ast.cpp

clean: 
	$(RM) driver
