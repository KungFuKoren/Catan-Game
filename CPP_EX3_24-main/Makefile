CXX = g++
CXXFLAGS = -std=c++11 -Wall

# List of source files
SRCS = Junction.cpp Road.cpp Land.cpp Board.cpp Player.cpp DevelopmentCard.cpp Catan.cpp main.cpp

# List of object files (automatically generated)
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = main

# Main target
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

# Compile each source file into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(EXEC)
