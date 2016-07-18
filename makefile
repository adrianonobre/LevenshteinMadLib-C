IDIR =../include
CC = gcc
CFLAGS = -I.$(IDIR)

ODIR = obj
SRC_DIR = src
BUILD_DIR = build

_DEPS = levenshtein_calculator.h
DEPS = $(pathsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o levenshtein_calculator.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

madlib: $(OBJ)
	$(CC) -o $(BUILD_DIR)/$@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~ $(BUILD_DIR)/*	
