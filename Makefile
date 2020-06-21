CXX = g++
COMPILER_FLAGS = -Wall -Wextra -Werror
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
TARGET = sge
################################################################################
BUILD 	:= ./build
OBJ_DIR	:= $(BUILD)/objects
APP_DIR	:= $(BUILD)/apps
INCLUDE := -Iinclude/
################################################################################
SRC :=						\
$(wildcard src/core/*.cpp)	\
$(wildcard src/graphics/*.cpp)	\
$(wildcard src/*.cpp)		\
# AGREGAR TODAS LAS DEPENDENCIAS Y MODULOS ACA

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
TARGET	:= sge
################################################################################

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o : %.cpp
	@mkdir -p $(@D)
	$(CXX) $(COMPILER_FLAGS) $(INCLUDE) -c $< -o $@ $(LINKER_FLAGS)

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(COMPILER_FLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LINKER_FLAGS)
	./$(APP_DIR)/$(TARGET)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: COMPILER_FLAGS += -DDEBUG -g
debug: all

release: COMPILER_FLAGS += -02
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*