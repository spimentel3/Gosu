LIBS= -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
#-I/usr/local/include -L/usr/local/lib -lnoise
CXX=g++
CXXFLAGS= -g -std=c++11 -Wall -W
PROG=gosu
MKDIR= mk

all: $(MKDIR) $(PROG)

maptiles: CXXFLAGS += -D maptiles
maptiles: $(MKDIR) $(PROG)

$(MKDIR):
	mkdir $(MKDIR)

$(PROG): $(MKDIR)/game.o \
	$(MKDIR)/location.o \
	$(MKDIR)/world.o \
	$(MKDIR)/eventhandler.o \
	$(MKDIR)/entity.o \
	$(MKDIR)/player.o \
	$(MKDIR)/math.o 
	$(CXX) $(CXXFLAGS) -o $(PROG) \
		$(MKDIR)/game.o \
		$(MKDIR)/world.o \
		$(MKDIR)/eventhandler.o \
		$(MKDIR)/location.o \
		$(MKDIR)/entity.o \
		$(MKDIR)/player.o \
		$(MKDIR)/math.o \
		$(LIBS)


$(MKDIR)/game.o: game.cpp game.h world.h eventhandler.h entity.h math.h player.h
	$(CXX) $(CXXFLAGS) -c -o $(MKDIR)/game.o game.cpp

$(MKDIR)/world.o: world.cpp world.h location.h
	$(CXX) $(CXXFLAGS) -c -o $(MKDIR)/world.o world.cpp

$(MKDIR)/eventhandler.o: eventhandler.cpp eventhandler.h 
	$(CXX) $(CXXFLAGS) -c -o $(MKDIR)/eventhandler.o eventhandler.cpp

$(MKDIR)/location.o: location.cpp location.h
	$(CXX) $(CXXFLAGS) -c -o $(MKDIR)/location.o location.cpp

$(MKDIR)/entity.o: entity.cpp entity.h
	$(CXX) $(CXXFLAGS) -c -o $(MKDIR)/entity.o entity.cpp

$(MKDIR)/player.o: player.cpp player.h entity.h math.h
	$(CXX) $(CXXFLAGS) -c -o $(MKDIR)/player.o player.cpp

$(MKDIR)/math.o: math.cpp math.h
	$(CXX) $(CXXFLAGS) -c -o $(MKDIR)/math.o math.cpp

clean:
	rm -rf $(MKDIR) *.o $(PROG)
