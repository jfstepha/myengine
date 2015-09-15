CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		myengine.o command.o bitops.o data.o board.o readfen.o move.o movegen.o displaymove.o

LIBS =

TARGET =	myengine.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
