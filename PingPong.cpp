#include "Command.hpp"
#include "Client.hpp"
#include "Server.hpp"
#include <ctime>

void PING(Command *command)
{
	if (command->getParameters().size() == 0)
		return command->reply(409);
	command->getClient().sendTo(command->getClient(), "PONG :" + command->getParameters()[0]);
}


void PONG(Command *command)
{
	if (command->getParameters().size() == 0)
		return command->reply(409);
	command->getClient().setLastPing(std::time(0));
}