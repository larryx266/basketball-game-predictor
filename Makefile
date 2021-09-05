CXX = g++
CXXFLAGS = -g -Wall 
BIN_DIR = bin

OBJS = $(BIN_DIR)/besgitbol.o $(BIN_DIR)/player.o $(BIN_DIR)/hashtable.o $(BIN_DIR)/team.o $(BIN_DIR)/playerParser.o

all: $(BIN_DIR)/besgitbol

$(BIN_DIR)/besgitbol: $(BIN_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(BIN_DIR)/besgitbol.o: besgitbol.cpp player.h hashtable.h team.h playerParser.h
	$(CXX) $(CXXFLAGS) -o $@ -c besgitbol.cpp

$(BIN_DIR)/player.o: player.cpp player.h
	$(CXX) $(CXXFLAGS) -o $@ -c player.cpp

$(BIN_DIR)/hashtable.o: hashtable.cpp hashtable.h
	$(CXX) $(CXXFLAGS) -o $@ -c hashtable.cpp

$(BIN_DIR)/team.o: team.cpp team.h
	$(CXX) $(CXXFLAGS) -o $@ -c team.cpp

$(BIN_DIR)/playerParser.o: playerParser.cpp playerParser.h
	$(CXX) $(CXXFLAGS) -o $@ -c playerParser.cpp

$(BIN_DIR):
	mkdir $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)
