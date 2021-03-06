// ************************************************************************* //
// This file is a part of an exercise developed by xGridTech to explain the
// functionality and usage of the Google Protobuf-RPC library to a beginner.
// This is an open source code with no license or copyrights, and can be used,
// changed, and implemented by anyone for their own purposes.
//
// ************************************************************************* //

MAIN FEAUTURES:
===============
This program basically implements a client, which takes three integer values 
from a user and sends them to a server. The server processes the request of 
the client by calculating their sum and product, and sends a reply to the 
client, which then prints out the values it receives. The entire functionality 
of the program was implemented using Google's protocol buffers for RPC. 

The machine on which this application was developed had Ubuntu 12.04.1 LTS 
installed on it. C programming language was used for the development of this 
task.

Installation
=============
1. The download file will be in the format .tar.gz, which can be extracted in 
   the Command Terminal using the command: 
	$tar -zxvf <filename>

2. Open the extracted folder: 
	$cd /location/to/folder/

3. Compile the program:
	$make

NOTE: 'make clean' can be used to delete all the generated object and binary
      executable files.

4. The server is run by using the command:
	$./server

   The client is run on a separate machine (or a separate Command Terminal 
   window) by using the command:
	$./client

Program Files
==============
The application folder contains the following files (which are necessary for the
application to run and whose brief descriptions are mentioned):

1. server.c
This file contains the C code for the RPC server, which basically receives 
three integer inputs from the connected clients, calculates their sum and
product, and sends a reply with the results back to the respective client
which sent the request.

2. client.c
This file contains the C code for the RPC client. It mainly takes three input 
integers from the user, sends it to the server, and receives and displays 
the results (sum and product). 

3. task.proto
This file contains the definitions of the data structures being used for 
message serialization.

It is created as a simple text document which is renamed to a .proto file 
(in this case, task.proto). The syntax used in this file is very simple to 
follow and understand. 

It is compiled using the following command in the Command terminal:
	$protoc-c -I=$SRC_DIR --_out=. $DST_DIR $SRC_DIR/task.proto

This creates header (.h) and C (.c) files which contain the declarations and 
definitions of the required variables and functions to implement the messages 
and services declared in the .proto file.

4. task.pb-c.c
This file is generated by the Google Protobuf-RPC. It contains classes for the 
data structure and protocol format of the program used for serialization.

5. task.pb-c.h
This header file is generated by the Protocol buffer and it contains the 
required definitions for the classes declared in task.pb-c.c

6. compare.h
This header file contains the declaration and definition of the common functions
being used in 'server.c' and 'client.c' source files.

7. compare.c
This source file contains the implementation of the common functions being used 
in 'server.c' and 'client.c' source files.

8. config_*.txt
These files contain the parameters required by the program to determine the type 
of connection to establish between the server and the client.

This program reads from the file 'config_server.txt' to determine the type of 
connection the user wants to set for the server.
'config_server.txt' contains one of the following strings for the server:
       'UNIX=PATH'    ;where PATH could be given as socket for
                       a unix-domain socket.
                       OR
       'Port=NUM'     ;where NUM is the port number (1025 to 65535) to bind the
                       server to for RPC clients.

This program reads from the file 'config_client.txt' to determine the type of 
connection the user wants to set for the client.
'config_client.txt' contains one of the following strings for the client:
       'UNIX=PATH'     ;where PATH could be given as socket for
                        a unix-domain socket.
                        OR
       'Port=HOST:NUM' ;where HOST is the IP address of the server
                        and NUM is the port number (1025 to 65535) to bind the
                        RPC clients to the server.

All ports below 1024 are generally reserved. You can set any port number (NUM) 
above that, right up to 65535 (provided it is not already being used by 
another program).

The IP address (HOST) of the server varies for each machine. The user of this
program is required to identify the IP address of the machine on which the
server program would run and then edit the 'config_client.txt' file accordingly.
Any of the following commands can be executed in the command terminal of the
server machine to get its IP address:
  $curl icanhazip.com
  $curl -s myip.dk | grep '"Box"' | egrep -o '[0-9.]+'
  $curl http://ipecho.net/plain
  $curl ifconfig.me
  $wget -qO- ifconfig.me/ip

NOTE: There are many other methods and websites to get the external IP address
of your machine. You are free to use any method you find suitable.

Suppose the IP address of the server is '32.123.45.201' and it has binded to
the port '6789', then the contents of the file 'config_client.txt' would be:
Port=32.123.45.201:6789

This task uses 'UNIX=socket' in both files to send data to local socket instead 
of establishing a proper TCP connection to communicate with RPC servers.


Each of these files have all the necessary comments to understand the code being
used and the functionality it provides.

All of the required project files will be present in their respective folders. 
Each file's brief description is also written in its beginning.

// ************************************************************************* //
