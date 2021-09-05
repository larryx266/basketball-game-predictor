CXX = g++
CXXFLAGS = -g -Wall 
BIN_DIR = bin
BUILD_DIR = build
LIB_DIR = lib

OBJS = $(BUILD_DIR)/besgitbol.o $(BUILD_DIR)/player.o $(BUILD_DIR)/hashtable.o $(BUILD_DIR)/team.o $(BUILD_DIR)/playerParser.o

all: $(BIN_DIR)/besgitbol

$(BIN_DIR)/besgitbol: $(BIN_DIR) $(BUILD_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(BUILD_DIR)/besgitbol.o: besgitbol.cpp player.h hashtable.h team.h playerParser.h
	$(CXX) $(CXXFLAGS) -o $@ -c besgitbol.cpp

$(BUILD_DIR)/player.o: player.cpp player.h
	$(CXX) $(CXXFLAGS) -o $@ -c player.cpp

$(BUILD_DIR)/hashtable.o: hashtable.cpp  hashtable.h
	$(CXX) $(CXXFLAGS) -o $@ -c hashtable.cpp

$(BUILD_DIR)/team.o: team.cpp team.h
	$(CXX) $(CXXFLAGS) -o $@ -c team.cpp

$(BUILD_DIR)/playerParser.o: playerParser.cpp playerParser.h
	$(CXX) $(CXXFLAGS) -o $@ -c playerParser.cpp

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	rm -rf $(BIN_DIR)
	rm -rf $(BUILD_DIR)
