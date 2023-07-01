.PHONY: run clean
BUILD_DIR = build
SOURCE_DIR = source

$(BUILD_DIR)/main: $(SOURCE_DIR)/main.c $(SOURCE_DIR)/hello.c $(SOURCE_DIR)/hello.h
	gcc $(SOURCE_DIR)/hello.c $(SOURCE_DIR)/main.c -o $(BUILD_DIR)/main

run: $(BUILD_DIR)/main
	$(BUILD_DIR)/main

clean: 
	rm $(BUILD_DIR)/*
