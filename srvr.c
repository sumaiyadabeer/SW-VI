#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT_NUMBER     5000
#define SERVER_ADDRESS  "192.168.1.7"
#define FILENAME        "/home/toc/foo.c"

int main(int argc, char **argv)
{
        int client_socket;
        ssize_t len;
        struct sockaddr_in remote_addr;
        char buffer[BUFSIZ];
        int file_size;
        FILE *received_file;
        int remain_data = 0;

        /* Zeroing remote_addr struct */
        memset(&remote_addr, 0, sizeof(remote_addr));

        /* Construct remote_addr struct */
        remote_addr.sin_family = AF_INET;
        inet_pton(AF_INET, SERVER_ADDRESS, &(remote_addr.sin_addr));
        remote_addr.sin_port = htons(PORT_NUMBER);

        /* Create client socket */
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
                fprintf(stderr, "Error creating socket --> %s\n", strerror(errno));

                exit(EXIT_FAILURE);
        }

        /* Connect to the server */
        if (connect(client_socket, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) == -1)
        {
                fprintf(stderr, "Error on connect --> %s\n", strerror(errno));

                exit(EXIT_FAILURE);
        }

        /* Receiving file size */
        recv(client_socket, buffer, BUFSIZ, 0);
        file_size = atoi(buffer);
        //fprintf(stdout, "\nFile size : %d\n", file_size);

        received_file = fopen(FILENAME, "w");
        if (received_file == NULL)
        {
                fprintf(stderr, "Failed to open file foo --> %s\n", strerror(errno));

                exit(EXIT_FAILURE);
        }

        remain_data = file_size;

        while (((len = recv(client_socket, buffer, BUFSIZ, 0)) > 0) && (remain_data > 0))
        {
                fwrite(buffer, sizeof(char), len, received_file);
                remain_data -= len;
                fprintf(stdout, "Receive %d bytes and we hope :- %d bytes\n", len, remain_data);
        }
        fclose(received_file);

        close(client_socket);

        return 0;
}
printf( "File Size: \n%d bytes\n", file_stat.st_size);

        sock_len = sizeof(struct sockaddr_in);
        /* Accepting incoming peers */
        peer_socket = accept(server_socket, (struct sockaddr *)&peer_addr, &sock_len);
        if (peer_socket == -1)
        {
                fprintf(stderr, "Error on accept --> %s", strerror(errno));

                exit(EXIT_FAILURE);
        }
        fprintf(stdout, "Accept peer --> %s\n", inet_ntoa(peer_addr.sin_addr));

        sprintf(file_size, "%d", file_stat.st_size);

        /* Sending file size */
        len = send(peer_socket, file_size, sizeof(file_size), 0);
        if (len < 0)
        {
              fprintf(stderr, "Error on sending greetings --> %s", strerror(errno));

              exit(EXIT_FAILURE);
        }

        fprintf(stdout, "Server sent %d bytes for the size\n", len);

        offset = 0;
        remain_data = file_stat.st_size;
        /* Sending file data */
        while (((sent_bytes = sendfile(peer_socket, fd, &offset, BUFSIZ)) > 0) && (remain_data > 0))
        {
                fprintf(stdout, "1. Server sent %d bytes from file's data, offset is now : %d and remaining data = %d\n", sent_bytes, offset, remain_data);
                remain_data -= sent_bytes;
                fprintf(stdout, "2. Server sent %d bytes from file's data, offset is now : %d and remaining data = %d\n", sent_bytes, offset, remain_data);
        }

        close(peer_socket);
        close(server_socket);

        return 0;
}

