CC = g++
CFLAGS = -Wall -g
DEPS = games.h

src_obj := game_obj
src_def := game_def

GAMES = connect4.o chess.o

all: init test run

init:
	mkdir -p $(src_obj)
run:
	./test

test: test.cpp games.o $(GAMES) $(DEPS)
	$(CC) $(CFLAGS) -o test test.cpp $(src_obj)/games.o $(src_obj)/connect4.o $(src_obj)/chess.o 

# test.o: $(DEPS) test.cpp 
# 	$(CC) $(CFLAGS) -c test.cpp -o test.o

# Game objs:
games.o: $(DEPS) $(src_def)/games.cpp
	$(CC) $(CFLAGS) -c $(src_def)/games.cpp -o $(src_obj)/games.o

# Games objs:
connect4.o: $(DEPS) $(src_def)/connect4.cpp
	$(CC) $(CFLAGS) -c $(src_def)/connect4.cpp -o $(src_obj)/connect4.o

chess.o: $(DEPS) $(src_def)/chess.cpp
	$(CC) $(CFLAGS) -c $(src_def)/chess.cpp -o $(src_obj)/chess.o

clean:
	rm -f *.o $(src_obj)/*.o test test.exe