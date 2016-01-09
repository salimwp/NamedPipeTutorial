all: simpleInPipe simpleOutPipe

simpleInPipe: simpleInPipe.cpp 
	g++ -std=c++11 -o simpleInPipe simpleInPipe.cpp helper.cpp -lpthread

simpleOutPipe: simpleOutPipe.cpp 
	g++ -std=c++11 -o simpleOutPipe simpleOutPipe.cpp helper.cpp -lpthread

clean:
	rm simpleInPipe simpleOutPipe
