src=$(wildcard ./cpp/*.cpp)
 
obj=$(patsubst %.cpp,%.o,$(src))

.PHONY=app
target=app 

$(target):$(obj)
	g++ -std=c++11 $^ -o $@
%.o:%.cpp 
	g++ -std=c++11 -I ./include/ -c $^ -o $@ 
