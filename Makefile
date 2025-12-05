# Makefile for aoc25
# Usage examples:
#   make            (build release)
#   make MODE=debug (build debug)
#   make run        (build then run)
#   make clean      (remove build artifacts)
#   make rebuild    (clean then build)
#   make debug      (convenience target for MODE=debug)

PROJECT      := aoc25
CXX          ?= g++
MODE         ?= release
BUILD_DIR    := build
BIN_DIR      := bin
INC_DIR      := include
SRC_DIR      := src

SOURCES      := main.cpp \
                $(SRC_DIR)/helpers.cpp \
                $(SRC_DIR)/one.cpp \
                $(SRC_DIR)/two.cpp \
                $(SRC_DIR)/three.cpp \
                $(SRC_DIR)/four.cpp
OBJECTS      := $(BUILD_DIR)/main.o \
                $(BUILD_DIR)/helpers.o \
                $(BUILD_DIR)/one.o \
                $(BUILD_DIR)/two.o \
                $(BUILD_DIR)/three.o \
                $(BUILD_DIR)/four.o

CXXFLAGS_COMMON := -std=c++20 -Wall -Wextra -Wpedantic
CXXFLAGS_DEBUG  := $(CXXFLAGS_COMMON) -Og -g
CXXFLAGS_RELEASE:= $(CXXFLAGS_COMMON) -O3

ifeq ($(MODE),debug)
  CXXFLAGS := $(CXXFLAGS_DEBUG)
else
  CXXFLAGS := $(CXXFLAGS_RELEASE)
endif

LDFLAGS := 

.PHONY: all run clean rebuild debug release

all: $(BIN_DIR)/$(PROJECT)

release: MODE=release
release: all

debug: MODE=debug
debug: all

run: $(BIN_DIR)/$(PROJECT)
	$(BIN_DIR)/$(PROJECT)

# Link
$(BIN_DIR)/$(PROJECT): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

# Object build rules
$(BUILD_DIR)/main.o: main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/helpers.o: $(SRC_DIR)/helpers.cpp $(INC_DIR)/helpers.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/one.o: $(SRC_DIR)/one.cpp $(INC_DIR)/one.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/two.o: $(SRC_DIR)/two.cpp $(INC_DIR)/two.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/three.o: $(SRC_DIR)/three.cpp $(INC_DIR)/three.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/four.o: $(SRC_DIR)/four.cpp $(INC_DIR)/four.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Ensure directories exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

rebuild: clean all

print-%:
	@echo $*=$($*)
