# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -Werror -O2 -Iinclude
COVFLAGS = -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov
GCOVR = $(if $(wildcard .venv/bin/gcovr),.venv/bin/gcovr,$(if $(wildcard .venv/Scripts/gcovr.exe),.venv/Scripts/gcovr.exe,gcovr))
CLANG_FORMAT = $(if $(wildcard .venv/bin/clang-format),.venv/bin/clang-format,$(if $(wildcard .venv/Scripts/clang-format.exe),.venv/Scripts/clang-format.exe,clang-format))

# Directories
SRC_DIR := src
OUT_DIR := build
TEST_DIR := test
UNITY_DIR := $(TEST_DIR)/unity
HTML_DIR := html
COV_HTML_DIR := $(HTML_DIR)/cov
DOCS_HTML_DIR := $(HTML_DIR)/docs
TARGET := $(OUT_DIR)/program.exe
TEST_TARGET := $(OUT_DIR)/run_tests.exe

# Recursive wildcard function (pure GNU make)
rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

# Source and object files
SRCS := $(call rwildcard,$(SRC_DIR)/,*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

# Unity test sources and objects
UNITY_SRCS := $(call rwildcard,$(UNITY_DIR)/,*.c)
TEST_SRCS := $(filter-out $(UNITY_SRCS),$(call rwildcard,$(TEST_DIR)/,*.c))
TEST_OBJS := $(TEST_SRCS:$(TEST_DIR)/%.c=$(OUT_DIR)/test/%.o)
UNITY_OBJS := $(UNITY_SRCS:$(UNITY_DIR)/%.c=$(OUT_DIR)/unity/%.o)

# Default build
all: $(TARGET)

# Link main program
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Compile C sources (with coverage)
$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(COVFLAGS) -c $< -o $@

# --- Unit Testing ---

# Build test runner
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Link test executable (exclude main.o to avoid conflict)
$(TEST_TARGET): $(filter-out $(OUT_DIR)/main.o,$(OBJS)) $(UNITY_OBJS) $(TEST_OBJS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(COVFLAGS) $(LDFLAGS) -o $@ $^


# Compile test sources (no coverage)
$(OUT_DIR)/test/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(UNITY_DIR) -I$(SRC_DIR) -Iinclude -c $< -o $@

# Compile Unity sources (no coverage)
$(OUT_DIR)/unity/%.o: $(UNITY_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(UNITY_DIR) -Iinclude -c $< -o $@


# --- Coverage Report ---
coverage: test
	@mkdir -p $(COV_HTML_DIR)
	$(GCOVR) -r . --exclude test --exclude unity --html --html-details -o $(COV_HTML_DIR)/coverage.html
	@echo "Coverage report generated: $(COV_HTML_DIR)/coverage.html"


# --- Documentation ---
docs:
	@mkdir -p $(DOCS_HTML_DIR)
ifneq ("$(wildcard Doxyfile)","")
	@echo "Generating Doxygen documentation..."
	@if command -v doxygen >/dev/null 2>&1; then \
		doxygen Doxyfile; \
	elif command -v Doxygen >/dev/null 2>&1; then \
		Doxygen Doxyfile; \
	else \
		echo "Error: doxygen not found in PATH."; \
		exit 127; \
	fi
else
	@echo "Error: No Doxyfile found in the current directory."
endif





# --- Formatting ---
format:
ifneq ("$(wildcard .clang-format)","")
	@echo "Formatting all source and header files..."
	@$(CLANG_FORMAT) -i $(call rwildcard,$(SRC_DIR)/,*.c) $(call rwildcard,$(SRC_DIR)/,*.h) $(call rwildcard,$(SRC_DIR)/internal/,*.h) $(call rwildcard,include/,*.h)
	@echo "Formatting complete."
else
	@echo "Error: No .clang-format file found in the project root."
endif


# Clean
clean:
	rm -rf $(OUT_DIR) $(HTML_DIR) *.gcno *.gcda *.gcov

.PHONY: all clean test coverage docs format
