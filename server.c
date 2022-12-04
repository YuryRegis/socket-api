#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    char serverMessage[256] = "OK";
    
    // server socket
    int serverSocket;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    // server address
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9002);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // bind socket to address
    bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));   
    listen(serverSocket, 3);

    // accept connection
    int clientSocket;
    clientSocket = accept(serverSocket, NULL, NULL);

    // send message
    send(clientSocket, serverMessage, sizeof(serverMessage), 0);

    close(serverSocket);
    return 0;
}