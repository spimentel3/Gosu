LIBS= -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
#-I/usr/local/include -L/usr/local/lib -lnoise
CXX=g++
CXXFLAGS= -g -std=c++11 -Wall -W
PROG=gosu
MKDIR= mk

all: $(MKDIR) $(PROG)

debug: CXXFLAGS += -D DEBUG
debug: $(MKDIR) $(PROG)
debug_collision: CXXFLAGS += -D DEBUG_COLLISION
debug_collision: $(MKDIR) $(PROG)

$(MKDIR):
	mkdir $(MKDIR)

$(PROG): $(MKDIR)/game.o $(MKDIR)/world.o $(MKDIR)/entity.o $(MKDIR)/math.o
	$(CXX) $(CXXFLAGS) -o $(PROG) \
		$(MKDIR)/game.o \
		$(MKDIR)/world.o \
		$(MKDIR)/entity.o \
		$(MKDIR)/math.o \
		$(LIBS)


$(MKDIR)/game.o: game.cpp game.h world.h  entity.h math.h
	$(CXX) $(CXXFLAGS) -c -o $(MKDIR)/game.o game.cpp

$(MKDIR)/world.o: world.cpp world.h
	$(CXX) $(CXXFLAGS) -c -o $(MKDIR)/world.o world.cpp

$(MKDIR)/entity.o: entity.cpp entity.h
	$(CXX) $(CXXFLAGS) -c -o $(MKDIR)/entity.o entity.cpp

$(MKDIR)/math.o: math.cpp math.h
	$(CXX) $(CXXFLAGS) -c -o $(MKDIR)/math.o math.cpp

#$(MKDIR)/main.o: main.cpp game.h
	#$(CXX) $(CXXFLAGS) -c -o $(MKDIR)/main.o main.cpp

clean:
	rm -rf $(MKDIR) *.o $(PROG)
