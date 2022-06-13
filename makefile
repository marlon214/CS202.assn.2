# Make file for operator overloading assignment

OBJS	= main.o animal.o cage.o
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g
ANIMAL_DEPS	= animal.h
CAGE_DEPS = cage.h animal.h

all: main

main: $(OBJS)
	@echo "Linking Objects..."
	$(CC) $(CCFLAGS) -o zoo $(OBJS)
	@echo "Done! Finished building zoo program"

main.o:	main.cpp $(CAGE_DEPS)
	@echo "Compiling Main..."
	$(CC) $(CCFLAGS) -c main.cpp
animal.o: animal.cpp $(ANIMAL_DEPS)
	@echo "Compiling Animal..."
	$(CC) $(CCFLAGS) -c animal.cpp
cage.o: cage.cpp $(CAGE_DEPS)
	@echo "Compiling Cage..."
	$(CC) $(CCFLAGS) -c cage.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS) zoo
