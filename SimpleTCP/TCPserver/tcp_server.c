#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
//server message to the clients
char server_message[256]="you have reached the server!";

//create and setup a server socket
int server_socket;
server_socket=socket(AF_INET, SOCK_STREAM, 0);

//define the server address
struct sockaddr_in server_address;
server_address.sin_family=AF_INET;
server_address.sin_port=htons(9002);
server_address.sin_addr.s_addr=INADDR_ANY;

//bind the socket to our spesified IP address and port
bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

//wait for number of clients
listen(server_socket, 5); //5: the total number of clients

//get the address of client 
int client_socket;
client_socket=accept(server_socket, NULL, NULL); //first null is address of a client, second null is the size of client's address

//inform the client that he has connected us
send(client_socket, server_message, sizeof(server_message), 0); //0: is an optional flag

//close the socket
close(server_socket);

return 0;
}

