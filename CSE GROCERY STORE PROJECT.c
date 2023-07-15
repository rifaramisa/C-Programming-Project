#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float price;
    int quantity;
} Item;

Item groceryList[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount == MAX_ITEMS) {
        printf("Grocery list is full. Cannot add more items.\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    groceryList[itemCount] = newItem;
    itemCount++;

    printf("Item added successfully.\n");
}

void viewGroceryList() {
    if (itemCount == 0) {
        printf("Grocery list is empty.\n");
        return;
    }

    printf("Grocery List:\n");
    printf("------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item Name: %s\n", groceryList[i].name);
        printf("Price: $%.2f\n", groceryList[i].price);
        printf("Quantity: %d\n", groceryList[i].quantity);
        printf("------------------------------\n");
    }
}

void setPrice() {
    char itemName[50];
    printf("Enter the name of the item to set the price: ");
    scanf("%s", itemName);

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(groceryList[i].name, itemName) == 0) {
            printf("Enter the new price for %s: ", itemName);
            scanf("%f", &groceryList[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found in the grocery list.\n");
    } else {
        printf("Price updated successfully.\n");
    }
}

void removeItem() {
    char itemName[50];
    printf("Enter the name of the item to remove: ");
    scanf("%s", itemName);

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(groceryList[i].name, itemName) == 0) {
            for (int j = i; j < itemCount - 1; j++) {
                groceryList[j] = groceryList[j + 1];
            }
            itemCount--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found in the grocery list.\n");
    } else {
        printf("Item removed successfully.\n");
    }
}

void requestItem() {
    char itemName[50];
    printf("Enter the name of the item to request: ");
    scanf("%s", itemName);

    int found = 0;
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(groceryList[i].name, itemName) == 0) {
            printf("Item found. Quantity available: %d\n", groceryList[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found in the grocery list.\n");
    }
}

void viewItemCount() {
    printf("Number of items left: %d\n", itemCount);
}

int main() {
    int choice;
    int exit = 0;

    while (!exit) {
        printf("\n-------- Grocery Store Task Manager --------\n");
        printf("1. Add item\n");
        printf("2. View grocery list\n");
        printf("3. Set item price\n");
        printf("4. Remove item\n");
        printf("5. Request item\n");
        printf("6. View number of items left\n");
        printf("7. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewGroceryList();
                break;
            case 3:
                setPrice();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                requestItem();
                break;
            case 6:
                viewItemCount();
                break;
            case 7:
                exit = 1;
                printf("Exiting... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}
