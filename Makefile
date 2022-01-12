OUT	= MyGKrellM
CC	 = g++

HEADER	= -I ./include/
SOURCE	= $(wildcard src/*.cpp)
OBJS	= $(SOURCE:.cpp=.o)
TRASH   = $(wildcard src/*~) $(wildcard include/*~) $(wildcard *~)

FLAGS	 = -g3 -c -Wall -std=c++20
LFLAGS	 = -lncurses 

all: bin

bin: $(OBJS)
	@$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)
	@echo "[OUT]" $(OUT)

.cpp.o:
	@$(CC) $(FLAGS) $< -o $@ $(HEADER)
	@echo "[G++]" $<

clean:
	@rm -f $(OBJS)
	@rm -f $(TRASH)

fclean: clean
	@rm -f $(OUT)


re: fclean all







.PHONY: all clean

SUFFIXES: .c .cpp .o
