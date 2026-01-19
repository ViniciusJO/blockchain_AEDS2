CPPFLAGS=-Wall -Wextra -ggdb

.PHONY: all run

all: blockchain

blockchain: blockchain.cpp
	${CXX} ${CPPFLAGS} -o $@ $^

run: blockchain
	./blockchain
