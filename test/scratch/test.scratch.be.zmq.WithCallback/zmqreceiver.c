/* client reads incoming messages */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <zmq.h>

volatile int keepRunning = 1;
/* void intHandler(int dummy) { */
/*    printf( "Entered intHandler.\n"); */
/*    keepRunning = 0; */
/* } */

int main (int argc, char *argv [])
{
   if(argc != 4) {
      printf ("Usage: <socket_type> <connect_type> <socket_addr>\n");
      return(EXIT_FAILURE);
   }
   int socket_type = 0, connect_type = 0;
   if(strcmp(argv[1], "ZMQ_SUB") == 0) { socket_type = ZMQ_SUB; }
   else if (strcmp(argv[1], "ZMQ_REQ") == 0) { socket_type = ZMQ_REQ; }
   else {
      printf ("Usage: <socket_type> <connect_type> <socket_addr>\n");
      return(EXIT_FAILURE);
   }
   if(strcmp(argv[2], "connect") == 0) { connect_type = 0; }
   else if(strcmp(argv[2], "bind") == 0) { connect_type = 1; }
   else {
      printf ("Usage: <socket_type> <connect_type> <socket_addr>\n");
      return(EXIT_FAILURE);
   }
   // Socket to talk to server
   printf ("Expecting messages …\n");
   void *context = zmq_ctx_new ();
   void *subscriber = zmq_socket (context, socket_type);
   char* socket_addr = argv[3];
   if(connect_type == 0) {
      printf ("Connecting to '%s'.\n", socket_addr);
      int rc = zmq_connect (subscriber, socket_addr);
      if (rc == -1) {
         printf ("E: connnect failed: %s\n", strerror (errno));
         return -1;
      }
   }
   else {
      printf ("Binding to '%s'.\n", socket_addr);
      int rc = zmq_bind (subscriber, socket_addr);
      if (rc == -1) {
         printf ("E: bind failed: %s\n", strerror (errno));
         return -1;
      }
   }

   assert( printf("Asserts active!\n") );
   if( socket_type == ZMQ_SUB ) {
      char *filter = "";
      int rc = zmq_setsockopt (subscriber, ZMQ_SUBSCRIBE, filter, strlen (filter));
      assert (rc == 0);
   }

   int nrMsgReceived = 0;
   while(keepRunning) {
      char buffer [256];
      int size = zmq_recv (subscriber, buffer, 255, 0);
      if(size > 255) {
         size = 255; buffer[size] = '\0'; // end string.
      }
      printf("Received:'%s'\n", buffer);

      ++nrMsgReceived;
      if( nrMsgReceived  % 50 == 0) {
         printf("Already received %d messages.\n", nrMsgReceived);
      }
   }
   printf( "Received %d messages.\n", nrMsgReceived);

   zmq_close (subscriber);
   zmq_ctx_destroy (context);
   return EXIT_SUCCESS;
}

