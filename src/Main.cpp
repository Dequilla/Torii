#include <Socket.h>

/*
    Based on: http://www.linuxhowtos.org/C_C++/socket.htm
    Test with telnet: https://netbeez.net/blog/telnet-to-test-connectivity-to-tcp/
*/

int main(int argc, char** argv)
{
    tor::Socket socket(8080);
    socket.Listen();    

    return 0;
}