.PHONY: all run_full run_lib_depend clean
BUILD_DIR = build
SOURCE_DIR = source

all: lib_depend full

lib_depend: $(SOURCE_DIR)/main.c $(SOURCE_DIR)/solution.h sharedlib
	gcc $(SOURCE_DIR)/main.c -L./$(BUILD_DIR) -lsolution -o $(BUILD_DIR)/exe_lib_depend

full: $(SOURCE_DIR)/main.c $(SOURCE_DIR)/solution.c $(SOURCE_DIR)/solution.h
	gcc $(SOURCE_DIR)/main.c $(SOURCE_DIR)/solution.c $(SOURCE_DIR)/solution.h -o $(BUILD_DIR)/exe_full

sharedlib: $(SOURCE_DIR)/solution.c $(SOURCE_DIR)/solution.h
	gcc $(SOURCE_DIR)/solution.c -shared -o $(BUILD_DIR)/libsolution.so -fPIC

run_full: full
	./$(BUILD_DIR)/exe_full

run_lib_depend: lib_depend
	./$(BUILD_DIR)/exe_lib_depend

clean:
	rm $(BUILD_DIR)/*
