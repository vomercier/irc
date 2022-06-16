#ifndef SERVER_HPP
# define SERVER_HPP
# include "ft_irc.hpp"


class Server
{
    private:
        /* data */
    public:
        Server(/* args */);
        ~Server();

        void init();
        void run();
        void accept_client();
};

#endif