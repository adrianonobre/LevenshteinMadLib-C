IDIR =../include
CC = gcc
CFLAGS = -I.$(IDIR)

ODIR = obj
SRC_DIR = src
BUILD_DIR = build

_DEPS = str_list.h levenshtein_calculator.h word_file_loader.h strsplit.h levenshtein_madlib.h
DEPS = $(pathsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = str_list.o main.o levenshtein_calculator.o word_file_loader.o strsplit.o levenshtein_madlib.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

madlib: $(OBJ)
	$(CC) -o $(BUILD_DIR)/$@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~ $(BUILD_DIR)/madlib
