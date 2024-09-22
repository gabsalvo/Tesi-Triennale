CC = gcc
CFLAGS = -std=c11 -Wall -g -O -Ilib -pthread
LIBS = -lm -lrt -pthread

# Sorgenti e oggetti
SRCS = src/algorithmC.c src/algorithmD.c
OBJS = src/algorithmC.o src/algorithmD.o

# Target principale
all: burrows-wheeler

# Regola per creare l'eseguibile
burrows-wheeler: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) main.c $(LIBS)

# Regola per compilare il file .o specifico nella directory src
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regola per pulire i file generati
clean:
	rm -f $(OBJS) burrow-wheeler
	rm -f matrices/*.txt
