# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wshadow -Wconversion -Wfloat-equal \
           -Wduplicated-cond -Wlogical-op -Wshift-overflow=2 -Wduplicated-branches \
           -Wcast-qual -Wcast-align -fsanitize=address -fsanitize=undefined \
           -fstack-protector -g -O0 -DDEBUG

# Usage: make FILE=filename or make f=filename
f ?= solution
FILE ?= $(f)

BUILD_DIR := build
SRC := $(FILE)
OUT := $(BUILD_DIR)/$(basename $(SRC))
SRC_DIR := $(dir $(SRC))
OUT_DIR := $(dir $(OUT))
INPUT := input.txt

.PHONY: clean

$(OUT): $(SRC) $(OUT_DIR)$(INPUT)
	$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC)

$(OUT_DIR)$(INPUT):
	mkdir -p $(OUT_DIR)
	ln -s $(realpath $(SRC_DIR))/$(INPUT) $(OUT_DIR)$(INPUT)

run: $(OUT)
	$(OUT)

clean:
	@rm -rf $(BUILD_DIR)
