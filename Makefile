SRCDIR = src
BINDIR = bin
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(BINDIR)/%.o, $(SRC))
EXEC = pokedex

CXX = g++
CXXFLAGS = -std=c++11

all: $(EXEC)

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BINDIR)/*.o $(EXEC)
