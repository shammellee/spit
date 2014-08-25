.PHONY: clean $(BIN_DIR)/$(EXECUTABLE) exec

EXECUTABLE := spit

SHELL    := /bin/bash
CXXFLAGS := -stdlib=libc++
CXXFLAGS += -std=c++11
CXXFLAGS += -I $(BOOST_ROOT)include
CXXFLAGS += -L$(BOOST_ROOT)lib
CXXFLAGS += -lboost_program_options
CXXFLAGS += -lboost_filesystem
CXXFLAGS += -lboost_system

BIN_DIR    := bin
BUILD_DIRS := $(BIN_DIR)
BUILD_DIRS += build
BUILD_DIRS += include
BUILD_DIRS += lib
SRC_DIR    := src
CPP_DIR    := $(SRC_DIR)/cpp
RUN_FLAGS  := -l

$(BIN_DIR)/$(EXECUTABLE):$(CPP_DIR)/$(EXECUTABLE).cpp
	@mkdir -p $(BUILD_DIRS)
	$(CXX) $(CXXFLAGS) -o $@ $<

run: $(BIN_DIR)/$(EXECUTABLE)
	@$(BIN_DIR)/$(EXECUTABLE) $(RUN_FLAGS)


clean:
	rm -rf\
		$(BUILD_DIRS)
