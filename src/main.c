/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <arpa/inet.h>

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

int main(void)
{
  char *ip = "10.42.0.1";
  int port = 5566;
 
  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  char buffer[250];
  char buffer1[250];
  int n,r,t;
 
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");
 
  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);


  n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if (n < 0)
  {
    perror("[-]Bind error");
    exit(1);
  }
  printf("[+]Bind to the port number: %d\n", port);
 
 
  listen(server_sock, 5);
  printf("Listening...\n");
  addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
    printf("[+]Client connected.\n");
    
   while(1)
   {   
   bzero(buffer,250);
    bzero(buffer1,250);
    r=recv(client_sock, buffer1, sizeof(buffer), 0);
    t=recv(client_sock, buffer, sizeof(buffer), 0);
    if(t>0)
    {
       if(r!=0)
       {
       printf("%s\n", buffer1);       
       }    
    printf("%s\n", buffer);
  
    bzero(buffer,250);
    bzero(buffer1,250);
   }
   else
   break;
 }
    close(client_sock);
    printf("[+]Client disconnected.\n\n");
 
  return 0;
    //xTaskCreate(&vTask1, "Task 1", 1024, NULL, 1, NULL);
    //xTaskCreate(&vTask2, "Task 2", 1024, NULL, 1, NULL);

   // vTaskStartScheduler();

    return 0;
}

void vTask1(void *pvParameters)
{
    for (;;)
    {
        char *ip = "10.42.0.1";
  int port = 5566;
 
  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t addr_size;
  char buffer[250];
  char buffer1[250];
  int n,r,t;
 
  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0){
    perror("[-]Socket error");
    exit(1);
  }
  printf("[+]TCP server socket created.\n");
 
  memset(&server_addr, '\0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = port;
  server_addr.sin_addr.s_addr = inet_addr(ip);


  n = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
  if (n < 0)
  {
    perror("[-]Bind error");
    exit(1);
  }
  printf("[+]Bind to the port number: %d\n", port);
 
 
  listen(server_sock, 5);
  printf("Listening...\n");
  addr_size = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
    printf("[+]Client connected.\n");
    
   while(1)
   {   
   bzero(buffer,250);
    bzero(buffer1,250);
    r=recv(client_sock, buffer1, sizeof(buffer), 0);
    t=recv(client_sock, buffer, sizeof(buffer), 0);
    if(t>0)
    {
       if(r!=0)
       {
       printf("%s\n", buffer1);       
       }    
    printf("%s\n", buffer);
  
    bzero(buffer,250);
    bzero(buffer1,250);
   }
   else
   break;
 }
    close(client_sock);
    printf("[+]Client disconnected.\n\n");
 
  return 0;
    }
}

void vTask2(void *pvParameters)
{
    for (;;)
    {
        printf("Task 2\r\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
