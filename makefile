all:clean run
.PHONY :run
run:
	gcc client.c -o ./run/client
	gcc server.c -o ./run/server
clean:
	rm -rf ./run/*
