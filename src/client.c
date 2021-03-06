/* ************************************************************************* 
 * This file is a part of an exercise developed by xGridTech to explain the
 * functionality and usage of the Google Protobuf-RPC library to a beginner.
 * This is an open source code with no license or copyrights, and can be used,
 * changed, and implemented by anyone for their own purposes.
 *
 * 'client.c' implements the main functionality of an RPC client which
 * takes three inputs from the user and sends it to the server to get their
 * sum and product.
 *
 * ************************************************************************* */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <google/protobuf-c/protobuf-c-rpc.h>
#include "task.pb-c.h"
#include "compare.h"

#define FilePath "./config_client.txt"

/************************************************************************
*  
* @purpose variable argument list function which outputs the errors and
* 		     exits the program
*
* @param const char    *format        String to be output onto the stdout
*     
* @returns none  
* @notes none
* @end
*
***********************************************************************/
static void die(const char *format, ...) {
  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);
  fprintf(stderr, "\n");
  exit(1);
}

/************************************************************************
*  
* @purpose function used to show proper usage of the program to the user
*
* @param none      
* @returns none   
* @notes none
* @end
*
***********************************************************************/
static void usage(void) {
  die("\nusage: client \n"
       "\n"
       "Run a protobuf RPC client as specified by the Process service\n"
       "in the task.proto file in the project folder.\n"
       "\n"
       "No options or arguments are required.\n"
       "This program reads from the file 'config_client.txt' to determine the\n"
       "type of connection the user wants to set for the client.\n"
       "\n"
       "'config_client.txt' contains one of the following strings:\n"
       "'UNIX=PATH'     ;where PATH could be given as socket for\n"
       "                 a unix-domain socket.\n"
       "                 OR\n"
       "'Port=HOST:NUM' ;where HOST is the IP address of the server\n"
       "                 and NUM is the port number (1025 to 65535) to bind\n"
       "                 the RPC clients to the server.\n"
       "\n"
       "This task uses 'UNIX=socket' to send data to local socket instead of\n"
       "establishing a proper TCP connection to communicate with RPC servers.\n"
       "\n");
}

/******************************************************************************
*  
* @purpose user-defined 'add' function which prints the 'Sum' output message
*
* @param const Task__Output    *outputs      Output message defined in the
*                                            task.proto file which contains
*                                            the 'Sum' and 'Product' integers.
* @param void    *closure_data               A boolean integer which is used as
*                                            a flag to check if function has
*                                            succesfully printed out the sum.
*                                                 
* @returns none   
* @notes none
* @end
*
******************************************************************************/
static void add_inputs(const Task__Output *outputs, void *closure_data) {
  if (outputs == NULL) {
  /* Close the service by sending NULL. */
  * (protobuf_c_boolean *) closure_data = 0;
  } else {
  printf("Sum = %d\n", outputs->sum);
  /* Set value of closure flag to '1'. */
  * (protobuf_c_boolean *) closure_data = 1;
  }
}

/******************************************************************************
*  
* @purpose user-defined 'multiply' function which prints the 'Product'
*          output message
*
* @param const Task__Output    *outputs      Output message defined in the
*                                            task.proto file which contains
*                                            the 'Sum' and 'Product' integers.
* @param void    *closure_data               A boolean integer which is used as
*                                            a flag to check if function has
*                                            succesfully printed out the product
*                                                 
* @returns none   
* @notes none
* @end
*
******************************************************************************/
static void multiply_inputs(const Task__Output *outputs, void *closure_data) {
  if (outputs == NULL) {
  /* Close the service by sending NULL. */
  * (protobuf_c_boolean *) closure_data = 0;
  } else {
  printf("Product = %d\n", outputs->product);
  /* Set value of closure flag to '1'. */
  * (protobuf_c_boolean *) closure_data = 1;
  }
}

/************************************************************************
*  
* @purpose Main Function
*
* @param int    argc              Represents number of arguments passed by
*                                 user when client executable is run.
* @param const char*    argv[]    Array which contains the actual argument
*                                 strings passed by the user.
*    
* @returns 0 (SUCCESS) or 1 (FAILURE)
* @notes none
* @end
*
***********************************************************************/
int main(int argc, const char* argv[]) {
  /* Initialize the Input message. */
  Task__Input input = TASK__INPUT__INIT;
  /* Initialize the Output message. */
  Task__Output output = TASK__OUTPUT__INIT;

  ProtobufCService *service;
  ProtobufC_RPC_Client *client;
  ProtobufC_RPC_AddressType address_type = 0;
  const char *name = NULL;

  FILE *fp;
  char buf[25];
  /* Print the usage function if user has given any arguments. */
  if (argc > 1) {
    usage();
  }
  /* Open 'config_client.txt' */
  fp = fopen(FilePath, "r");

  if (fp == NULL) {
    fprintf(stderr, "Error: File empty or not present.\n");
    exit(1);
  }
  /* Read data from the file and set the appropriate parameters accordingly. */
  if (fscanf(fp, "%s", buf) == 0) {
    fprintf(stderr, "Error: Unable to open or read file.\n");
    exit(2);
  } else if (starts_with(buf, "Port=")) {
    address_type = PROTOBUF_C_RPC_ADDRESS_TCP;
    name = strchr(buf, '=') + 1;
  } else if (starts_with(buf, "UNIX=")) {
    address_type = PROTOBUF_C_RPC_ADDRESS_LOCAL;
    name = strchr(buf, '=') + 1;
  }

  if (name == NULL)
    die("Error:Check 'config_client.txt' file for proper parameters/syntax.");


/* The following code segment can be used to take command line arguments
   into the client program to implement similar functionality without
   reading from a file.
   In order to use this method, the usage function should also be changed
   as shown below. */
/*  for (unsigned i = 1; i < (unsigned) argc; i++) {
      if (starts_with(argv[i], "--port=")) {
        address_type = PROTOBUF_C_RPC_ADDRESS_TCP;
        name = strchr(argv[i], '=') + 1;
      } else if (starts_with(argv[i], "--unix=")) {
        address_type = PROTOBUF_C_RPC_ADDRESS_LOCAL;
        name = strchr(argv[i], '=') + 1;
      } else {
        usage();
      }
    }

  if (name == NULL)
    die("missing --tcp=HOST:PORT or --unix=PATH"); */


/* This is the proper usage for the client program if command line
   arguments are to be incorporated in it. */
/*static void usage(void) {
  die("usage: client [--port=NUM | --unix=PATH]\n"
       "\n"
       "Run a protobuf RPC client as specified by the Process service\n"
       "in the task.proto file in the project folder.\n"
       "\n"
       "Options:\n"
       "  --tcp=HOST:PORT  Port to listen on for RPC clients.\n"
       "  --unix=PATH      Unix-domain socket to listen on.\n"
       "\n");
} */

/* Start the RPC client according to the parameters set by
   'config_client.txt' file. */
  service = protobuf_c_rpc_client_new(address_type, name,
                                      &task__process__descriptor, NULL);

  if (service == NULL)
    die("error creating client");
  client = (ProtobufC_RPC_Client *) service;

  fprintf(stderr, "Connecting... ");
  while (!protobuf_c_rpc_client_is_connected(client))
    protobuf_c_dispatch_run(protobuf_c_dispatch_default());
  fprintf(stderr, "done.\n");

  for (;;) {
    int x;

    printf("\n");

/* Fill the Input message with the values given by the user. */
    printf("Enter the value of a = ");
    scanf("%d", &x);
    input.a = x;

    printf("Enter the value of b = ");
    scanf("%d", &x);
    input.b = x;

    printf("Enter the value of c = ");
    scanf("%d", &x);
    input.c = x;

/* Set the values of the closure flags to '0'. */
    protobuf_c_boolean add_done = 0;
    protobuf_c_boolean multiply_done = 0;

/* Start the 'Add' process service. */
    task__process__add(service, &input, add_inputs, &add_done);

    while (!add_done)
      protobuf_c_dispatch_run(protobuf_c_dispatch_default());

/* Start the 'Multiply' process service. */
    task__process__multiply(service, &input, multiply_inputs, &multiply_done);

    while (!multiply_done)
      protobuf_c_dispatch_run(protobuf_c_dispatch_default());
    }
return 0;
}
