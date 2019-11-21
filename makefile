CF= g++ -c -std=c++11 -g

all: a4

a4: room.o game.o driver.o
	g++ -g room.o game.o driver.o -o a4

room.o: room.cpp
	$(CF) room.cpp

#event.o: event.cpp
#	$(CF) event.cpp

game.o: game.cpp
	$(CF) game.cpp

driver.o: driver.cpp
	$(CF) driver.cpp

clean:
	rm *.o a4
