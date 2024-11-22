/*******************************************************************************
 *	FILE        :	server.h
 *	DESCRIPTION :	This file includes standard header files, macro definitions,
 *                  structure prototypes, global variables, and function 
 *                  prototypes utilized in server.c and serveroperation.c.
 * 						
 *	NAME        :	Group_5
 *	DATE        :	30-01-2020
 ********************************************************************************/

#ifndef __SERVER_H_
#define __SERVER_H_

/********************************************************************************
 *					INCLUDE STANDARD HEADER FILES
 ********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <pthread.h>
#include <errno.h>
#include <regex.h>

/********************************************************************************
 *					DECLARE GLOBAL VARIABLES
 ********************************************************************************/

extern int flag;

/********************************************************************************
 *						DEFINE MACROS
 ********************************************************************************/

#define SUCCESS                 (0)
#define FAILURE                 (-1)
#define TRUE                    (1)
#define PORT                    (8888)
#define MAX_BITS                (4)
#define DELIMITER               ":"
#define MAX_BUFFER              (1024)
#define MAX_NUM_SOCKETS         (5)
#define MASTER_INDEX            (0)
#define MAX_LEN                 (1024)
#define MAX_PASSWORD_LEN        (9)
#define IP_LENGTH               (16)

#define FILE_NAME               "../data/database.txt"
#define READ_MODE               "r"
#define UPDATE_MODE             "r+b"
#define COLON                   ":"
#define LOG_FILE                "./../log_files/log_server.txt"
#define APPEND                  "a+"  

#define SUCCESSFUL_REGISTRATION "Registration Successful\n"
#define REGISTRATION_FAILED     "Failed to register: either already existed or technical error"
#define INVALID_USERID          "UserId does not exist"
#define INVALID_PASSWORD        "Invalid password"
#define UNSUBSCRIBED_USER       "Unsubscribed user"
#define PASSWORD_CHANGED        "Password updated successfully"
#define INVALID_CREDENTIAL      "Invalid credentials entered"
#define LOGIN_SUCCESSFUL        "Login successful"
#define UNSUBSCRIBED            "Unsubscribed successfully"
#define ALREADY_UNSUBSCRIBED    "Already unsubscribed"
#define REQUEST_NEW_PASSWORD    "Enter new password"

#define ERR_SOCKET_STR          "Socket creation failed"
#define ERR_THREAD_STR          "Failed to create thread"
#define ERR_SETSOCKOPT_STR      "SetSockOpt failed"
#define ERR_BIND_STR            "Binding failed"
#define ERR_LISTEN_STR          "Listen failed"
#define ERR_SELECT_STR          "Select failed"
#define ERR_ACCEPT_STR          "Connection failed"
#define ERR_SEND_STR            "Failed to send message"
#define ERR_RECV_STR            "Failed to receive message"
#define ERR_SIGNAL_STR          "Failed to handle interrupt"

/********************************************************************************
 *							ENUM DECLARATION
 ********************************************************************************/

typedef enum userChoice {
    LOGIN,
    REGISTER,
    PASSWORD_RESET,
    UNSUBSCRIBE,
    INVALID
} USERCHOICE;

/********************************************************************************
 *							STRUCTURE PROTOTYPES
 ********************************************************************************/

typedef struct client {
    char userId[MAX_BUFFER];           // User ID needed by client to login
    char name[MAX_BUFFER];             // Name of client displayed to others
    char password[MAX_PASSWORD_LEN];   // Password for logging into the chat room
    unsigned int bits[MAX_BITS];       // Bits for custom use
} CLIENT;

typedef struct clientNode {
    int socketId;                      // Socket ID
    char ip[IP_LENGTH];                // Client's IP address
    char name[MAX_LEN];                // Client's name
    struct clientNode *next;           // Pointer to next node
    struct clientNode *prev;           // Pointer to previous node
} CLIENTNODE;

extern CLIENTNODE *head;

typedef struct threadData {
    struct clientNode *head;           // Head of the client list
    int newSocket;                     // New socket for the client
} THREADDATA;

/********************************************************************************
 *							FUNCTION PROTOTYPES
 ********************************************************************************/

extern USERCHOICE recvData(int newSocket, CLIENT **clientData, char *receiveStr);
extern int handleUserChoice(int newSocket, CLIENT *clientData, USERCHOICE option, 
                             char *ipAddress, CLIENTNODE **head);
extern void *handleClient(void *data);
extern void logHandler(char *level, char *message, const char *func);

#endif /* __SERVER_H_ */

