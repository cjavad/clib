#include <iostream>
#include <string>
#include <vector>
#include "../../socket/client.hpp"
#include "../../tools/base64.hpp"

class SMTP {
    private:
        /*
        Define host and port
        */
        std::string host;
        int port;
        /*
        Password and Username private varibles
        */
        bool auth = true;
        std::string username;
        std::string password;
    public:
        SMTP(std::string chost, int cport, std::string email, std::string pass);
        std::vector<std::string> compose(std::string to, std::string subject, std::string body); 
        std::string send(std::vector<std::string> msg); ///reworked version      
};

SMTP::SMTP(std::string chost, int cport, std::string email, std::string pass = "\0")
{
    host = chost;
    port = cport;
    username = email;
    if(pass == "\0"){
        auth = false;
    } else {
        password = pass;
    }
}
/*
Creates a SMTP message.
*/
std::vector<std::string> SMTP::compose(std::string to, std::string subject, std::string body)
{
    std::vector<std::string> msg;
    msg.push_back("HELO clib.mail.smtp\r\n");
    if(auth){
        msg.push_back("STARTTLS\r\n");
        msg.push_back("AUTH LOGIN\r\n");
        msg.push_back(b64_encode(username) + "\r\n");
        msg.push_back(b64_encode(password) + "\r\n");
    }
    msg.push_back("RCPT TO: " +  to + "\r\n");
    msg.push_back("MAIL FROM: " + username + "\r\n");
    msg.push_back(subject + "\r\n\r\n");
    msg.push_back(body + "\r\n");
    msg.push_back(".\r\n");
    // return message
    return msg;
}

/*
Sends smtp message
*/

std::string SMTP::send(std::vector<std::string> msg)
{
    Client sock(host, port, 2048);
    for (size_t i = 0; i < msg.size(); i++)
    {
        sock.send(msg[i]);
    }
    return sock.recv(true);
}