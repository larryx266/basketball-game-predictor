all: besgitbol

besgitbol: besgitbol.cpp
	g++ -g -Wall player.h player.cpp besgitbol.cpp -o bes

clean:
	-@rm besgitbol