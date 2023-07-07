.PHONY: run clean

BUILD_DIR = build
SOURCE_DIR = source


$(BUILD_DIR)/solution: $(SOURCE_DIR)/solution.c
	gcc $(SOURCE_DIR)/solution.c -o $(BUILD_DIR)/solution

run: $(BUILD_DIR)/solution
	./$(BUILD_DIR)/solution 1

clean:
	rm ./$(BUILD_DIR)/*
