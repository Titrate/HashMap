CXXFLAGS =	-O2 -g -Wall -fmessage-length=0 -std=c++0x

OBJS =	StringMap.o Node.o LinkedList.o main.o

LIBS =

TARGET =	prog1


$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
