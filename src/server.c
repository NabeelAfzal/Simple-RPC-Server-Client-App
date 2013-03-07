/* ************************************************************************* 
 * This file is a part of an exercise developed by xGridTech to explain the
 * functionality and usage of the Google Protobuf-RPC library to a beginner.
 * This is an open source code with no license or copyrights, and can be used,
 * changed, and implemented by anyone for their own purposes.
 *
 * 'server.c' implements the main functionality of an RPC server which
 * calculates the sum and product of the three inputs sent by the client.
 *
 * ************************************************************************* */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <google/protobuf-c/protobuf-c-rpc.h>
#include "task.pb-c.h"
#include "compare.h"

#define FilePath "./config_server.txt"

/* A variable argument list function which outputs the errors and exits
   the program. */
static void die(const char *format, ...) {
  va_list args;
  va_start(args, format);
  vfprintf(stderr, format, args);
  va_end(args);
  fprintf(stderr, "\n");
  exit(1);
}

/* Shows proper usage of the program to user in case of any error. */
static void usage(void) {
  die("\nusage: server \n"
       "\n"
       "Run a protobuf RPC server as specified by the Process service\n"
       "in the task.proto file in the project folder.\n"
       "\n"
       "No options or arguments are required.\n"
       "This program reads from the file 'config_server.txt' to determine the\n"
       "type of connection the user wants to set for the server.\n"
       "\n"
       "'config.txt' contains one of the following strings:\n"
       "'UNIX=PATH'   ;where PATH could be given as socket for\n"
       "               a unix-domain socket.\n"
       "               OR\n"
       "'Port=NUM'    ;where NUM is the port number (1025 to 65535) to bind\n"
       "               the server to for RPC clients.\n"
       "\n"
       "This task uses 'UNIX=socket' to send data to local socket instead of\n"
       "establishing a proper TCP connection to listen to RPC clients.\n"
       "\n");
}

/* Implements the 'add' process to calculate the sum. */
static void process__add(Task__Process_Service *service,
                          const Task__Input *input,
                          Task__Output_Closure closure,
                          void *closure_data) {
  (void) service;
  if (input == NULL) {
    /* Close the service by sending NULL. */
    closure(NULL, closure_data);
  } else {
      /* Initialize the Output message. */
      Task__Output output = TASK__OUTPUT__INIT;
      /* Add all the received Inputs. */
      output.sum = (input->a) + (input->b) + (input->c);
      /* Close the service by sending Output. */
      closure(&output, closure_data);
  }
}

/* Implements the 'multiply' process to calculate the product. */
static void process__multiply(Task__Process_Service *service,
                          const Task__Input *input,
                          Task__Output_Closure closure,
                          void *closure_data) {
  (void) service;
  if (input == NULL) {
    /* Close the service by sending NULL. */
    closure(NULL, closure_data);
  } else {
      /* Initialize the Output message. */
      Task__Output output = TASK__OUTPUT__INIT;
      /* Multiply all the received Inputs. */
      output.product = (input->a) * (input->b) * (input->c);
      /* Close the service by sending Output. */
      closure(&output, closure_data);
  }
}

/* Initializes the Process service. */
static Task__Process_Service process = TASK__PROCESS__INIT(process__);

/* Main Function: */
int main(int argc, const char* argv[]) {
  /* Initialize the Input message. */
  Task__Input input = TASK__INPUT__INIT;

  ProtobufCService *service;
  ProtobufC_RPC_Server *server;
  ProtobufC_RPC_AddressType address_type = 0;
  const char *name = NULL;

  FILE *fp;
  char buf[25];

  /* Print the usage function if user has given any arguments. */
  if (argc > 1) {
    usage();
  }
  /* Open 'config_server.txt' */
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
    die("Error:Check 'config_server.txt' file for proper parameters/syntax.");


/* The following code segment can be used to take command line arguments
   into the server program to implement similar functionality without
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
    die("missing --port=NUM or --unix=PATH");  */


/* This is the proper usage for the server program if command line
   arguments are to be incorporated in it. */
/*static void usage(void) {
  die("usage: server [--port=NUM | --unix=PATH]\n"
       "\n"
       "Run a protobuf RPC server as specified by the Process service\n"
       "in the task.proto file in the project folder.\n"
       "\n"
       "Options:\n"
       "  --port=NUM       Port to listen on for RPC clients.\n"
       "  --unix=PATH      Unix-domain socket to listen on.\n"
       "\n");
} */ 

/* Start the RPC server according to the parameters set by
   'config_server.txt' file. */
  server = protobuf_c_rpc_server_new(address_type, name,
                                     (ProtobufCService *) &process, NULL);

  printf("Server is running...\n");

  for (;;) {
      protobuf_c_dispatch_run(protobuf_c_dispatch_default());
  }
return 0;
}
