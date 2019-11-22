CF= g++ -c -std=c++11 -g

all: a4

a4: rope.o gold.o pit.o bat.o wumpus.o room.o event.o game.o driver.o
	g++ -g rope.o gold.o pit.o bat.o wumpus.o room.o event.o game.o driver.o -o a4

room.o: room.cpp
	$(CF) room.cpp
rope.o: rope.cpp
	$(CF) rope.cpp

gold.o: gold.cpp
	$(CF) gold.cpp

pit.o: pit.cpp
	$(CF) pit.cpp

bat.o: bat.cpp
	$(CF) bat.cpp

wumpus.o: wumpus.cpp
	$(CF) wumpus.cpp

event.o: event.cpp
	$(CF) event.cpp

game.o: game.cpp
	$(CF) game.cpp

driver.o: driver.cpp
	$(CF) driver.cpp

clean:
	rm *.o a4
