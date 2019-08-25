EXE = chess

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

CPPFLAGS += -Iinclude
CXXFLAGS += -Wall -std=c++17 -Wextra -O3 
LDFLAGS += -lm -lglut -lGLU -lGL

CC = g++
.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ_FILES)
	g++ -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJ_DIR)/*.o