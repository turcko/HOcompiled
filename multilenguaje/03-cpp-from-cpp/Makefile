.PHONY: default help object executable all clean
CXXC = g++

LD = $(CXXC)

SOURCE_CXX = $(wildcard *.cpp)
OBJECTS_CXX = $(patsubst %.cpp, %_cpp.o, $(SOURCE_CXX))

EXECUTABLE = cpp-main.e

default: help

help:
	@echo "\
Options:\n\n\
  make objects:       compiler makes objects for every *.c and *.f90\n\
  make executable:    compiler makes executable\n\
  make all:           build all previous\n\
  make clean:         delete output files\n\
  make help:          display this help"

objects: $(OBJECTS_CXX)

executable: $(EXECUTABLE)

all: objects executable

%_cpp.o: %.cpp
	$(CXXC) -c $^ -o $@

%.e: $(OBJECTS_CXX)
	$(LD) $^ -o $@

clean:
	rm -rfv $(OBJECTS_CXX) $(EXECUTABLE)
