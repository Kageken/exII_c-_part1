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
INCLUDES = card.h cardset.h
BABAINCLUDES = $(INCLUDES) babastate.h

EX6OBJS = card.o cardset.o ex6.o
BABAOBJS = card.o cardset.o babastate.o babanuki.o 
BABAXOBJS = cardset_draw.o cardset_remove.o babastate_move.o


all: ex6

$(EX6OBJS): $(INCLUDES)
$(EX6ROBJS): $(INCLUDES)
$(BABAOBJS): $(BABAINCLUDES)
$(BABAXOBJS): $(BABAINCLUDES)

ex6: $(EX6OBJS) 
	$(CXX) $(CXXFLAGS) $(INCDIRS) -o ex6.exe $(EX6OBJS)

babanuki: $(BABAOBJS) 
	$(CXX) $(CXXFLAGS) $(INCDIRS) -o babanuki.exe $(BABAOBJS)

babax: $(BABAOBJS) $(BABAXOBJS) 
	$(CXX) $(CXXFLAGS) $(INCDIRS) -o babax.exe $(BABAOBJS) $(BABAXOBJS)

clean: 
	rm -rf *.o *.exe *.dSYM *~
