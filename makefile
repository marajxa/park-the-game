CC=g++

CFLAGS=-c -Wall

SOURCES=Object.cpp Item.cpp Key.cpp Room.cpp Inventory.cpp player.cpp Enemy.cpp DCooper.cpp Doug.cpp DXu.cpp Frosh.cpp Haverbro.cpp HMajor.cpp finalmain.cpp sammap.cpp srehrig_functions.cpp

OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=game



all: $(SOURCES) $(EXECUTABLE)



$(EXECUTABLE): $(OBJECTS)

	$(CC) $(OBJECTS) -o $@



.cpp.o:

	$(CC) $(CFLAGS) $< -o $@



clean:

	rm *.o *~ srehrig_test_main run
