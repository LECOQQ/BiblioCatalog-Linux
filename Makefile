TARGET = BiblioCatalog

CC = g++
CFLAGS = -Wall -W -s -pedantic-errors
LFLAG = -Wall

SRCDIR = ./src
BINDIR = ./bin

SRCLIST =$(wildcard $(SRCDIR)/*cpp)
INCLUDESLIST =$(wildcard $(SRCDIR)/*h)


$(TARGET): $(SRCLIST) $(INCLUDESLIST)
	@$(CC) $(CFLAGS) $(SRCLIST) -o $(BINDIR)/$(TARGET)
	@echo "Compilation complete"
