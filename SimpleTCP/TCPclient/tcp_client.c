#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
//create and setup a client socket
int client_socket;
client_socket=socket(AF_INET, SOCK_STREAM, 0); //AF_INET: internet socket, SOCK_STREAM: tcp socket, 0: default protocol("TCP" is a default protocol)

//specify an address of the server where we want to connect
struct sockaddr_in server_address;
server_address.sin_family=AF_INET;
server_address.sin_port=htons(9002); //htons: convert number into binary, 9002: port number
server_address.sin_addr.s_addr=INADDR_ANY; //sin_addr: is another structure which has elements in it

//connect to the server
int connect_status;
connect_status=connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));

//check for an error with the connection
if(connect_status==-1)
{
printf("could not connect\n\n");
}

//receive an information from the server side
char server_response[256];
recv(client_socket, &server_response, sizeof(server_response), 0); //0: an optional flag

//print out the server's response
printf("the server sent: %s \n", server_response);

//close the socket
close(client_socket);

return 0;
}
