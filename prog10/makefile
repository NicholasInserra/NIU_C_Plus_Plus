OPT = -std=c++11 -c -g -Wall -Wextra

DRV = prog$N.cc
BAS = Shape.h

SRC1 = ${DRV}
HDR1 = ${SRC1:.cc=.h}
OBJ1 = prog$N.o

SRC2 = Shape2.cc Shape3.cc
HDR2 = ${SRC2:.cc=.h}
OBJ2 = ${SRC2:.cc=.o}

SRC = ${SRC1} ${SRC2}
HDR = ${HDR1} ${HDR2} ${BAS}
OBJ = ${OBJ1} ${OBJ2}
EXE = ${OBJ1:.o=.exe}
OUT = prog$N.out

${EXE}: ${OBJ}
	g++ -o $@ ${OBJ}

${OBJ1}: ${SRC1} ${HDR}
	g++ ${OPT} ${SRC1}

Shape2.o: Shape2.cc Shape2.h ${BAS}
	g++ ${OPT} Shape2.cc

Shape3.o: Shape3.cc ${HDR2} ${BAS}
	g++ ${OPT} Shape3.cc

execute:
	${EXE} 2>&1 | tee ${OUT}

clean:
	/bin/rm -f *.o *.exe
