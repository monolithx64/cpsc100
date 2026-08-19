// Assignment 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node 
{
	int data;
	struct Node* next; //pointer to the next node
};


// function to create and return a node 
// note the use of malloc
struct Node* createNode(int data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;    
    return new_node;
}

void printHelp()
{
    printf("Linked List Demo - Enter command\n");
    printf("h - print help (this list)\n");
    printf("p - print list\n");
    printf("s - search list\n");
    printf("a - add node after position\n");
    printf("d - delete node at position\n");
    printf("x - Exit program\n");
}

// Prints contents of linked list 
// use as an example for search_node
void printList(struct Node* n)
{
    int i = 1;
	while (n != NULL) {        
		printf("#%d, data: %d\n", i, n->data);
        i++;
		n = n->next;
	}
}

// Prints a single node. useful for debugging
void printNode(struct Node* n)
{
	printf("#data: %d\n", n->data);
}


// Adds a node to the beginning of the list. 
// use as an example for the general case
struct Node* add_node_beginning(int add_data, struct Node* head) 
{
    struct Node* new_node = createNode(add_data);
    new_node->next = head;
    return new_node;
}


// Delete head node. use as an example for the general case
struct Node* deleteHead(struct Node* head)
{
    // Base case if linked list is empty
    if (head == NULL)
        return NULL;

    // Store the current head in a temporary variable
    struct Node* temp = head;

    // Move the head to the next node
    head = head->next;

    // Free the memory of the old head node
    free(temp);

    // Return the new head
    return head;
}

struct Node* create_random_list(int num)
{
    struct Node* head = createNode(rand()%10 + 1);
    struct Node* n = head;
    for (int i = 1; i < num; i++)
    {
        struct Node* new_node = createNode(rand()%10 + 1);
        n->next = new_node;
        n = new_node;
    }

    return head;
}




/* ---------------------------------------------------------------------------------
DO NOT MODIFY CODE ABOVE THIS LINE
---------------------------------------------------------------------------------*/

// Returns the position of the node with the given data (search term)
// return 0 if not found
// (25 points)
int search_node(int search_term, struct Node* head) 
{
    // if list is empty
    if (head == NULL)
        return 0;

    struct Node* n = head;

    // your code here

    return 0;
}

// Adds a node list after a given position
// (35 points)
struct Node* add_node_after_position(int add_data, struct Node* head, int position) 
{    

    // if list is empty
    if (head == NULL)
        return NULL;
    
    if (position < 0)
    {
        printf("\nError! Position cannot be negative");
        return head;
    }
    else if (position == 0) // position equals 0 means inserting at head position
    {
        return add_node_beginning(add_data, head);
    }
    else 
    {

        struct Node* n = head;

        // your code here 

        return head;  
    }
}


// Deletes a node in a given position
// (40 points)
struct Node* delete_node_at_position(struct Node* head, int position) 
{
    // if list is empty
    if (head == NULL)
        return NULL;
    
    if (position <= 0)
    {
        printf("\nError! Position cannot be zero or negative");
        return head;
    }
    else if (position == 1)
    {
        return deleteHead(head);
    }
    else 
    {
        struct Node* n = head;
        // your code here


        return head;
    }   
}



/* ---------------------------------------------------------------------------------
DO NOT MODIFY CODE BELOW THIS LINE
---------------------------------------------------------------------------------*/
// Main Function
int main(int argc, char* argv[])
{
    
    time_t t;
    srand(time(&t));

    int user_data;
    int position;
    int result;

    printf("============================\n");
    printHelp();

    // int random_list = 10;
    struct Node* head;

    if (atoi(argv[1])) {
        head = create_random_list(atoi(argv[1]));
    }
    else {
        head = createNode(rand()%10 + 1);
    }
    
    printf("\nInitial List - \n");
    printList(head);

    char option;
    while (1) {
        printf("------------------\n");
        printf("\nEnter option - ");

        scanf(" %c", &option);
        if (option == 'h') 
        {
            printHelp();
        }
        else if (option == 'p')
        {
            printList(head);
        } 
        else if (option == 's')
        {
            printf("Enter search term: ");
            scanf("%d", &user_data);

            result = search_node(user_data, head);
            
            if(result != 0)
                printf("Data found at node with id= %d\n", result);
            else
                printf("Data not found\n");
        }
        else if (option == 'a')
        {
            printf("Enter new data: ");
            scanf("%d", &user_data);
            printf("Enter new node after position: ");
            scanf("%d", &position);
            
            head = add_node_after_position(user_data, head, position);
            
            printf("\nCurrent List:\n");
            printList(head);

        }
        else if (option == 'd')
        {
            printf("Enter position to delete: ");
            scanf("%d", &position);
            
            head = delete_node_at_position(head, position);
            
            printf("\nCurrent List:\n");
            printList(head);

        }
        else if (option == 'x')
        {
            printf("\nGoodbye!");
            break;
        }
        else 
        {
            printf("\nIncorrect option\n");
        }
    }
    

	return 0;
}
