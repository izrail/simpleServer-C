all:clean run 

.PHONY :run
run:
<<<<<<< HEAD
	gcc client.c -o ./bin/client
	gcc server.c -o ./bin/server
=======
	gcc ./src/client.c -o ./bin/client
	gcc ./src/server.c -o ./bin/server
>>>>>>> new

.PHONY:server
server:
	./bin/server

.PHONY:client
client:
	./bin/client 47.56.171.178
<<<<<<< HEAD
clean:
	rm -rf ./bin/*
=======

clean:
	rm -rf ./bin/*

>>>>>>> new
