all:clean run 

.PHONY :run
run:
	gcc client.c -o ./bin/client
	gcc server.c -o ./bin/server

.PHONY:server
server:
	./bin/server

.PHONY:client
client:
	./bin/client 47.56.171.178
clean:
	rm -rf ./bin/*
