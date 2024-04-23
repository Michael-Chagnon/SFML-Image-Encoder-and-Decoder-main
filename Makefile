CC = g++
CFLAGS = -std=c++11 -Wall -Werror -pedantic
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
DEPS = FibLFSR.h
all: PhotoMagic	lint

lint:
	cpplint PhotoMagic.cpp FibLFSR.cpp FibLFSR.h

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $<

PhotoMagic: FibLFSR.o PhotoMagic.o
	$(CC) $(CFLAGS) -o PhotoMagic $^ $(LIBS) $(SFMLFLAGS)

clean:
	rm *.o PhotoMagic

