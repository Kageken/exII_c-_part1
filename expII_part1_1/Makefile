# Makefile 
CC	= gcc -std=c99
CFLAGS = -Wall -g
CXX = g++ -std=c++11
CXXFLAGS = -Wall -g
#
INCDIRS = -I./

.PHONY: clean

%.o:%.c
	$(CC) $(CCFLAGS) $(INCDIRS) -c $<

%.o:%.cpp
	$(CXX) $(CXXFLAGS) $(INCDIRS) -c $<

#
# C headers
EX1INCLUDES = c_vector2d.h
# C++ headers
EX2INCLUDES = vector2d.h

EX1OBJS = c_vector2d.o ex1.o
EX2OBJS = vector2d.o ex2.o
EX4OBJS = vector2d.o matrix2x2.o ex4.o


all: ex1.exe ex2.exe

$(EX1OBJS): $(EX1INCLUDES)

$(EX2OBJS): $(EX2INCLUDES)
$(EX4OBJS): $(EX2INCLUDES)

ex1.exe: $(EX1OBJS)
	$(CC) $(CCFLAGS) $(INCDIRS) -o ex1.exe $(EX1OBJS)

ex2.exe: $(EX2OBJS) 
	$(CXX) $(CXXFLAGS) $(INCDIRS) -o ex2.exe $(EX2OBJS)

ex4.exe: $(EX4OBJS) 
	$(CXX) $(CXXFLAGS) $(INCDIRS) -o ex4.exe $(EX4OBJS)

clean: 
	rm -rf *.o a.out *.exe *.gch *.dSYM *~
