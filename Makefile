.PHONY: clean $(BIN_DIR)/$(EXECUTABLE) exec

EXECUTABLE := spit

SHELL    := /bin/bash
CXXFLAGS  = -stdlib=libc++
CXXFLAGS += -std=c++11
CXXFLAGS += -I $(BOOST_ROOT)include
CXXFLAGS += -I $(INC_DIR)
CXXFLAGS += -L$(BOOST_ROOT)lib
CXXFLAGS += -lboost_program_options
CXXFLAGS += -lboost_filesystem
CXXFLAGS += -lboost_system

BIN_DIR    := bin
INC_DIR    := include
LIB_DIR    := lib
SRC_DIR    := src
CPP_DIR    := $(SRC_DIR)/cpp
BUILD_DIR  := build
BUILD_DIRS := $(BIN_DIR)
BUILD_DIRS += $(BUILD_DIR)
RUN_FLAGS  := --list

$(BIN_DIR)/$(EXECUTABLE):$(CPP_DIR)/$(EXECUTABLE).cpp
	@mkdir -p $(BUILD_DIRS)
	$(CXX) $(CXXFLAGS) -o $@ $<

run: $(BIN_DIR)/$(EXECUTABLE)
	@$(BIN_DIR)/$(EXECUTABLE) $(RUN_FLAGS)


clean:
	rm -rf\
		$(BUILD_DIRS)
