CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2
TARGET = test

all: $(TARGET)

$(TARGET): test.cpp Polygon.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) test.cpp Polygon.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
