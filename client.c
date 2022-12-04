#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){

    // socket
    int networkSocket;
    networkSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    // address socket
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9002);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // connection
    int connection = connect(networkSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    if(connection == -1){
        printf("\nErro de conexão!\n");
    } 

    // response
    char serverResponse[256];
    recv(networkSocket, &serverResponse, sizeof(serverResponse), 0);
    printf("\nResposta: %s\n", serverResponse);

    close(networkSocket);
    return 0;
}