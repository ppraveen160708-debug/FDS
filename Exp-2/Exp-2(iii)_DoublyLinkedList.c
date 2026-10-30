#include<stdio.h>
#include<malloc.h>
struct node
{
 int data;
 struct node *prev,*next;
};
struct node *head,*newnode,*temp,*tail,*before,*curr;
int total_elements = 0;
void delete(int data)
{
 curr = head;
 while(curr != NULL && curr->data != data) curr = curr->next;
 if(curr == NULL) {
  printf("\n element not found \n");
  return;
 }
 if(curr->prev != NULL) curr->prev->next = curr->next;
 else head = curr->next;
 if(curr->next != NULL) curr->next->prev = curr->prev;
 else tail = curr->prev;
 free(curr);
 total_elements--;
 printf("the element deleted: %d \n",data);
}
void prepend(int data)
{
 newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data = data;
 newnode->next = newnode->prev = NULL;
 if(head == NULL) {
 head = tail = newnode;
 } else {
 newnode->next = head; head->prev = newnode;
 head = newnode;
 }
 total_elements++;
 printf("the element prepended: %d \n",data);
}
void append(int data)
{
 newnode = (struct node*)malloc(sizeof(struct node));
 newnode->data = data;
 newnode->next = newnode->prev = NULL;
 if(head == NULL) {
 head = newnode;
 tail = newnode;
 } else {
 temp = head;
 while(temp->next != NULL) {
 temp = temp->next;
 }
 temp->next = newnode;
 newnode->prev = temp;
 tail = newnode;
 }
 total_elements++;
 printf("the element appended: %d \n",data);
}
void display()
{
 temp = head;
 printf("\n NULL <->");
 while(temp != NULL) {
 printf("%d <->",temp->data);
 temp = temp->next;
 }
 printf("NULL \n");
}
void reverse() {
 temp = tail;
 printf("\n NULL <->");
 while(temp != NULL) {
 printf("%d <->",temp->data);
 temp = temp->prev;
 }
 printf("NULL\n");
}
int main() {
 append(10);
 append(20);
 append(30);
 display();
 prepend(40);
 display();
 printf("\n total elements:%d",total_elements);
 printf("\n----\n");
 delete(30); display();
 printf("\n total elements:%d",total_elements);
 reverse();
 return 0;
}