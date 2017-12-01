###@author - Bryce Bristow
###@description -  Makefile for TSP Group 45 project

#
# Project Name
# 
PROJ = TSP45

#
# Compiler
#
CXX = g++

#
# Compiler Flags
#
CXXFLAGS  = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
CXXFLAGS += -O2

#
# Source Files
#
SRCS = main.cpp

#
# Create Object for each source file
#
OBJS = $(SRCS:.cpp=.o)

$(PROJ): $(OBJS)
	@echo Compiling $(PROJ)
	@$(CXX) $(SRCS) -o $(PROJ)

%.o: %.cpp
	@echo Compiling source file for $@
	@$(CXX) $(CXXFLAGS) -c $^

zip:
	zip TSP_Group45.zip *.cpp *.txt *.tour makefile README.md

clean:
	rm *.o $(PROJ) *.zip *.tour

solutions:
	$(PROJ) test-input-1.txt
	$(PROJ) test-input-2.txt
	$(PROJ) test-input-3.txt
	$(PROJ) test-input-4.txt
	$(PROJ) test-input-5.txt
	$(PROJ) test-input-6.txt
	$(PROJ) test-input-7.txt