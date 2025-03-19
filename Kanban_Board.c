/*
 ============================================================================
 Name        : ASG3.c
 Author      : Pranav
 Author      : Joey
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void Clear_Buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

typedef struct item
{
    char itemName[20];
    struct item *next1;
} item;

typedef struct list
{
    char name[20];
    struct list *next;
    struct item *itemPtr;
} list;

struct list *head = NULL;
struct list *current = NULL;
struct list *last = NULL;

int main(void)
{
    struct item *headItemA = malloc(sizeof(struct item));
    strcpy(headItemA->itemName, "3070");
    headItemA->next1 = NULL;

    struct list *head = malloc(sizeof(struct list));
    strcpy(head->name, "Nick");
    head->itemPtr = headItemA;
    head->next = NULL;


    struct item *headItemB = malloc(sizeof(struct item));
    strcpy(headItemB->itemName, "Oculus");
    headItemB->next1 = NULL;

    struct list *current = malloc(sizeof(struct list));
    strcpy(current->name, "Tim");
    current->itemPtr = headItemB;
    current->next = NULL;
    head->next = current;


    struct item *headItemC = malloc(sizeof(struct item));
    strcpy(headItemC->itemName, "Quest1");
    headItemC->next1 = NULL;

    struct item *current1 = malloc(sizeof(struct item));
    strcpy(current1->itemName, "3070RTX");
    current1->next1 = NULL;
    headItemC->next1 = current1;

    current = malloc(sizeof(struct list));
    strcpy(current->name, "Dante");
    current->itemPtr = headItemC;
    current->next = NULL;
    head->next->next = current;


    struct item *headItemD = malloc(sizeof(struct item));
    strcpy(headItemD->itemName, "OculusPro");
    headItemD->next1 = NULL;

    current1 = malloc(sizeof(struct item));
    strcpy(current1->itemName, "OculusQuest1");
    current1->next1 = NULL;
    headItemD->next1 = current1;

    current = malloc(sizeof(struct list));
    strcpy(current->name, "Abey");
    current->itemPtr = headItemD;
    current->next = NULL;
    head->next->next->next = current;


    current = head;
    while(current != NULL)
    {
        printf("%s\n", current->name);
        fflush(stdout);

        struct item *ptr = current->itemPtr;

        while (ptr != NULL)
        {
            printf("\t%s\n", ptr->itemName);
            fflush(stdout);
            ptr = ptr->next1;
        }

        current=current->next;
    }
    printf("\n");
    fflush(stdout);

    struct list *newList = (struct list*) malloc(sizeof(struct list));
    struct list *prevlist = NULL;
    struct list *dellist = NULL;
    int action_option_list;
    char edit_list_name[20];
    char add_list_name[20];
    char delete_list[20];

    struct item *newItem = (struct item*) malloc(sizeof(struct item));
    struct item *prevItem = NULL;
    struct item *delItem = NULL;
    int action_option_item; //Choice of what action to carry out in this function
    char name_edit_item[20];
    char edit_item_name[20];
    char new_item_name[20];
    char name_add_item[20];
    char name_delete_item[20];
    char delete_this_item[20];

    FILE *cfPtr;

    do
    {
         printf("\n\nOptions:\n1. Edit name of a list\n2. Add a new list\n3. Delete a list\n4. Edit item\n5. Add new item\n6. Delete item\n7. Display board\n8. Save to file\n9. Load from file\n");
         fflush(stdout);
         if(scanf("%d", &action_option_list) != 1) {
                Clear_Buffer();
                continue;
            }

    switch(action_option_list)
    {
    case 1:
        current = head;

        printf("Enter the name of the list to edit: ");
        fflush(stdout);
        scanf("%s", edit_list_name);

        while(current != NULL && strcmp(current->name, edit_list_name) != 0)
        {
           current = current->next;
        }

        if(current != NULL)
        {
            printf("Enter the new name for the list ");
            fflush(stdout);
            scanf("%s", current->name);
        }

        else
        {
            printf("Can't find list\n");
            fflush(stdout);
        }


        //PRINTING
        current = head;
    while(current != NULL)
    {
        printf("%s\n", current->name);
        fflush(stdout);

        struct item *ptr = current->itemPtr;

        while (ptr != NULL)
        {
            printf("\t%s\n", ptr->itemName);
            fflush(stdout);
            ptr = ptr->next1;
        }

        current=current->next;
    }
        //PRINTING

        break;
    case 2:
        current = head;

        printf("Enter name of new list to add ");
        fflush(stdout);
        scanf("%s", add_list_name);

        strcpy(newList->name, add_list_name);
        newList->next = NULL;


        while(current != NULL)
        {
            last = current;
            current = current->next;
        }

        last->next = newList;
        last = newList;
        last->next = NULL;

            //PRINTING
        current = head;
    while(current != NULL)
    {
        printf("%s\n", current->name);
        fflush(stdout);

        struct item *ptr = current->itemPtr;

        while (ptr != NULL)
        {
            printf("\t%s\n", ptr->itemName);
            fflush(stdout);
            ptr = ptr->next1;
        }

        current=current->next;
    }
        //PRINTING
        break;
    case 3:
        printf("Enter name of list you want to delete ");
        fflush(stdout);
        scanf("%s", delete_list);

        current = head;

        if(strcmp(head->name, delete_list) == 0)
        {
            dellist = head;
            head = head->next;
            free(dellist);
        }
        else
        {
            while(current != NULL && strcmp(current->name, delete_list) != 0)
            {
                prevlist = current;
                current = current->next;
            }
                    if(current != NULL)
                    {
                        dellist = current;
                        prevlist->next = dellist->next;
                        free(dellist);
                    }

                    else
                    {
                        printf("List not found\n");
                        fflush(stdout);
                    }
        }


            //PRINTING
        current = head;
    while(current != NULL)
    {
        printf("%s\n", current->name);
        fflush(stdout);

        struct item *ptr = current->itemPtr;

        while (ptr != NULL)
        {
            printf("\t%s\n", ptr->itemName);
            fflush(stdout);
            ptr = ptr->next1;
        }

        current=current->next;
    }
        //PRINTING
        break;


case 4:
    printf("Enter the name of the person's items you want to edit: ");
    fflush(stdout);
        scanf("%s", name_edit_item);

         current = head;

         // Find the list
        while (current != NULL && strcmp(current->name, name_edit_item) != 0)
         {
            current = current->next;
         }

        if (current != NULL)
        {
             printf("Enter the name of the item you want to edit: ");
             fflush(stdout);
                //fgets(edit_item_name, 20, stdin);
             scanf("%s", edit_item_name);


        /*THIS ONLY WORKS IF THE ITEMS ARE ONE WORD (NO WHITESPACE) DOES NOT WORK
        FOR MORE, EG OCULUS QUEST*/



        struct item *ptr = current->itemPtr;
        //create a new pointer set to current->itemPtr



        while (ptr != NULL && strcmp(ptr->itemName, edit_item_name) != 0) //ie current->itemPtr != NULL && (strcmp(current->itemPtr->itemName))
        {
            ptr = ptr->next1;
        }

        if (ptr != NULL)
        {
            printf("Enter the new name for the item: ");
            fflush(stdout);
            scanf("%s", new_item_name);

            strcpy(ptr->itemName, new_item_name);
            printf("Item '%s' edited successfully.\n", edit_item_name);
            fflush(stdout);
        }
        else
        {
            printf("Item '%s' not found in the list.\n", edit_item_name);
            fflush(stdout);
        }
        }
            else
            {
                 printf("List not found.\n");
                 fflush(stdout);
            }
        //PRINTING
        current = head;
    while(current != NULL)
    {
        printf("%s\n", current->name);
        fflush(stdout);

        struct item *ptr = current->itemPtr;

        while (ptr != NULL)
        {
            printf("\t%s\n", ptr->itemName);
            fflush(stdout);
            ptr = ptr->next1;
        }

        current=current->next;
    }
        //PRINTING
        break;
case 5:
    current = head;

        printf("Enter name where you would like to add new item ");
        fflush(stdout);
        scanf("%s", name_add_item);


            // Find the list
        while (current != NULL && strcmp(current->name, name_add_item) != 0)
        {
            current = current->next;
        }

        if(current != NULL)
        {
            printf("Enter new name of item ");
            fflush(stdout);
            scanf("%s", new_item_name);

            strcpy(newItem->itemName, new_item_name);
            newItem->next1 = NULL;

            if(current->itemPtr == NULL)
            {
                current->itemPtr = newItem;
            }
            else
            {
                struct item *ptr = current->itemPtr;
                while(ptr->next1 != NULL)
                {
                    ptr = ptr->next1;
                }
                ptr->next1 = newItem;

                //LOOP UNTIL NEXT ITEM IS NULL, AND INSERT THE NEW ITEM THERE
            }
        }
    //PRINTING
        current = head;
    while(current != NULL)
    {
        printf("%s\n", current->name);
        fflush(stdout);

        struct item *ptr = current->itemPtr;

        while (ptr != NULL)
        {
            printf("\t%s\n", ptr->itemName);
            fflush(stdout);
            ptr = ptr->next1;
        }

        current=current->next;
    }
        //PRINTING
        break;
case 6:
    printf("Enter name where you would like to delete an item ");
    fflush(stdout);

        scanf("%s", name_delete_item);


        current = head;
        // Find the list
        while (current != NULL && strcmp(current->name, name_delete_item) != 0)
        {
            current = current->next;
        }
        if(current == NULL)
        {
            printf("List not found");
            break;
        }
        printf("Enter the name of the item you'd like to delete");
        fflush(stdout);
        scanf("%s", delete_this_item);

        struct item *delItemPtr = current->itemPtr;

        if(delItemPtr->next1 == NULL)
        {
            current->itemPtr = NULL;
        }

        else
        {
            if(strcmp(delItemPtr->itemName, delete_this_item) == 0)
            {
                delItem = delItemPtr;
                current->itemPtr = delItemPtr->next1;
                free(delItem);
            }


            while(delItemPtr != NULL && strcmp(delItemPtr->itemName, delete_this_item) != 0)
            {
                prevItem = delItemPtr;
                delItemPtr = delItemPtr->next1;
            }

            if(delItemPtr != NULL)
            {
                delItem = delItemPtr;
                prevItem->next1 = delItemPtr->next1;
                free(delItem);
            }
            else
            {
                printf("Can't find item");
                fflush(stdout);
            }
        }
    //PRINTING
        current = head;
    while(current != NULL)
    {
        printf("%s\n", current->name);
        fflush(stdout);

        struct item *ptr = current->itemPtr;

        while (ptr != NULL)
        {
            printf("\t%s\n", ptr->itemName);
            fflush(stdout);
            ptr = ptr->next1;
        }

        current=current->next;
    }
        //PRINTING
        break;
case 7:
       current = head;

    while(current != NULL)
    {
        printf("%s\n", current->name);
        fflush(stdout);

        struct item *ptr = current->itemPtr;

        while (ptr != NULL)
        {
            printf("\t%s\n", ptr->itemName);
            fflush(stdout);
            ptr = ptr->next1;
        }

        current=current->next;
    }
    printf("\n");
    fflush(stdout);

    break;

case 8:



    if((cfPtr = fopen("board.txt", "wb")) == NULL) {
        puts("File could not be opened.");
        fflush(stdout);
    }

    else {
        current = head;



            while(current != NULL)
            {
                struct item *ptr = current->itemPtr;
                fprintf(cfPtr, "%s\n", current->name);
                fflush(stdout);
                while(ptr != NULL)
                {
                    fprintf(cfPtr, "\t%s\n", ptr->itemName);
                    fflush(stdout);
                    ptr = ptr->next1;
                }
                current = current->next;
            }

        fclose (cfPtr);
    }
    break;

case 9:
     if((cfPtr = fopen("load.txt", "rb")) == NULL)
    {
        puts("File could not be opened");
        fflush(stdout);
    }
    else {
        current = head;

           char temp[30];
           int counter = 0;


            current = head;
            struct item *ptr = current->itemPtr;
            struct item *tempPtr = NULL;
         
            while(fscanf(cfPtr, "%s", temp) == 1)
            {
                if(strchr(temp, ':'))
                {
                    //ptr->next1 = NULL;
                    strcpy(current->name, temp);
                    struct item *ptr = current->itemPtr;
                    current = current->next;
                    
                    counter = 0;
                }

                else
                {
                    if(ptr == NULL)
                    {
                        ptr = (struct item *)malloc(sizeof(struct item));
                        continue;
                    }

                    if(counter == 0)
                    {
                        strcpy(ptr->itemName, temp);
                        ptr->next1 = NULL;
                        tempPtr = ptr;
                        ptr = ptr->next1;
                    }
                    
                    else if(counter == 1)
                    {
                        strcpy(ptr->next1->itemName, temp);
                        ptr->next1 = NULL;
                        tempPtr->next1 = ptr;
                        tempPtr = ptr;
                        ptr = ptr->next1;
                    }

                    counter++;
                }
            }
        }

    printf("File loaded successfully");
        fclose(cfPtr);

        break;
       }//switch close
    }while(action_option_list != 10);

    return 0;
}
