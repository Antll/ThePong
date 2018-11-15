SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
INCLUDE_DIR = ./headers

HDRS = $(wildcard $(INCLUDE_DIR)/*.h)
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
INCLUDES = -I$(INCLUDE_DIR)

CXX = g++
LIBS = -lGL -lSDL2 -lGLEW
CFLAGS = -g -Wall
NAME = ThePong
EXE = $(BIN_DIR)/$(NAME)

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(LIBS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean: $(OBJS)
	rm -f $^ 
