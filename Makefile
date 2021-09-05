CXX = g++
CXXFLAGS = -g -Wall 
BIN_DIR = bin

OBJS = besgitbol.o player.o hashtable.o team.o playerParser.o

all: besgitbol

besgitbol: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

besgitbol.o: besgitbol.cpp player.h hashtable.h team.h playerParser.h
	$(CXX) $(CXXFLAGS) -o $@ -c besgitbol.cpp

player.o: player.cpp player.h
	$(CXX) $(CXXFLAGS) -o $@ -c player.cpp

hashtable.o: hashtable.cpp hashtable.h
	$(CXX) $(CXXFLAGS) -o $@ -c hashtable.cpp

team.o: team.cpp team.h
	$(CXX) $(CXXFLAGS) -o $@ -c team.cpp

playerParser.o: playerParser.cpp playerParser.h
	$(CXX) $(CXXFLAGS) -o $@ -c playerParser.cpp

clean:
	rm -f *.o besgitbol
