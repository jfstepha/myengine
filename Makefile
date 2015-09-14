CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		myengine.o

LIBS =

TARGET =	myengine.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)