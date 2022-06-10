#include "Server.hpp"
#include <iostream>
#include <csignal>

int stop = 0;

void sighandler(int sig) { 
    if (sig == SIGINT)
        stop = 1; 
    if (sig == SIGPIPE)
        stop = 2;
    }

int main(int argc, char **argv) {
	if (argc != 3)
	{
		std::cout << "./ircserv <port> <password>" << std::endl;
		return 1;
	}

	irc::Server server = irc::Server();
	signal(SIGINT, sighandler);
    signal(SIGPIPE, sighandler);

	server.getConfig().set("port", argv[1]);
	server.getConfig().set("password", argv[2]);

	server.init();
	while (!stop)
		server.execute();
    // a detailler pour nettoyage ou autre suivant signal
	return 0;
}