#
# PROGRAM:    Sum of Odd Integers
# PROGRAMMER: Nicholas Inserra
# LOGON ID:   z1749082
# DATE DUE:   1/25/16
#

# Compiler variables
CCFLAGS = -std=c++11 -c -g -Wall -Wextra

# Rule to link object code files to create executable file
prog9: prog9.o
	g++ -o prog9 prog9.o

# Rules to compile source code files to object code
prog9.o: prog9.cc prog9.h
	g++ $(CCFLAGS) -c prog9.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o prog9
