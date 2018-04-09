CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CSSFLAGS += -pendantic-errors
CXXFLAGS += -g

OBJS = Zoo.o Animal.o main.o

SRCS = Zoo.cpp Animal.cpp main.cpp

HEADERS = Zoo.hpp Animal.hpp

zootycoon: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o zootycoon

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm Zoo.o
	rm Animal.o
	rm main.o
	rm zootycoon
	