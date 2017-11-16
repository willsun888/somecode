INC = 
LIB = 

CFLAGS= -O0 -Wall -g -lpthread -fopenmp

SRCFILES:=$(wildcard *.cpp)
BIN:=$(patsubst %.cpp,%,$(SRCFILES))

all::$(BIN)

$(BIN):%:%.o
	$(CXX) $(CFLAGS) -o $@ $^ $(LIB) $(L)

%.o:%.cpp
	$(CXX) $(CFLAGS) -c $< $(INC)