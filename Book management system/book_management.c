#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int bookId;
    char bookName[50];
    char authorName[50];
    char category[50];
    float price;
    float rating;
};

struct Book books[MAX];
int count = 0;

// Add Book
void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &books[count].bookId);

    getchar();

    printf("Enter Book Name: ");
    fgets(books[count].bookName, sizeof(books[count].bookName), stdin);
    books[count].bookName[strcspn(books[count].bookName, "\n")] = 0;

    printf("Enter Author Name: ");
    fgets(books[count].authorName, sizeof(books[count].authorName), stdin);
    books[count].authorName[strcspn(books[count].authorName, "\n")] = 0;

    printf("Enter Category: ");
    fgets(books[count].category, sizeof(books[count].category), stdin);
    books[count].category[strcspn(books[count].category, "\n")] = 0;

    printf("Enter Price: ");
    scanf("%f", &books[count].price);

    printf("Enter Rating: ");
    scanf("%f", &books[count].rating);

    count++;

    printf("\nBook Added Successfully!\n");
}

// Display One Book
void displayBook(struct Book b) {
    printf("\n-----------------------------");
    printf("\nBook ID      : %d", b.bookId);
    printf("\nBook Name    : %s", b.bookName);
    printf("\nAuthor Name  : %s", b.authorName);
    printf("\nCategory     : %s", b.category);
    printf("\nPrice        : %.2f", b.price);
    printf("\nRating       : %.1f", b.rating);
    printf("\n-----------------------------\n");
}

// Display All Books
void displayAllBooks() {

    if (count == 0) {
        printf("\nNo Books Available!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        displayBook(books[i]);
    }
}

// Search by ID
void searchById() {
    int id;
    int found = 0;

    printf("\nEnter Book ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].bookId == id) {
            displayBook(books[i]);
            found = 1;
        }
    }

    if (!found)
        printf("\nBook Not Found!\n");
}

// Search by Name
void searchByName() {
    char name[50];
    int found = 0;

    getchar();

    printf("\nEnter Book Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(books[i].bookName, name) == 0) {
            displayBook(books[i]);
            found = 1;
        }
    }

    if (!found)
        printf("\nBook Not Found!\n");
}

// Remove Book
void removeBook() {
    int id;
    int found = 0;

    printf("\nEnter Book ID to Remove: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {

        if (books[i].bookId == id) {

            for (int j = i; j < count - 1; j++) {
                books[j] = books[j + 1];
            }

            count--;
            found = 1;

            printf("\nBook Removed Successfully!\n");
            break;
        }
    }

    if (!found)
        printf("\nBook Not Found!\n");
}

// Update Book
void updateBook() {
    int id;
    int found = 0;

    printf("\nEnter Book ID to Update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {

        if (books[i].bookId == id) {

            printf("Enter New Price: ");
            scanf("%f", &books[i].price);

            printf("Enter New Rating: ");
            scanf("%f", &books[i].rating);

            found = 1;

            printf("\nBook Updated Successfully!\n");
            break;
        }
    }

    if (!found)
        printf("\nBook Not Found!\n");
}

// Show Author Books
void showAuthorBooks() {
    char author[50];
    int found = 0;

    getchar();

    printf("\nEnter Author Name: ");
    fgets(author, sizeof(author), stdin);
    author[strcspn(author, "\n")] = 0;

    for (int i = 0; i < count; i++) {

        if (strcmp(books[i].authorName, author) == 0) {
            displayBook(books[i]);
            found = 1;
        }
    }

    if (!found)
        printf("\nNo Books Found!\n");
}

// Show Category Books
void showCategoryBooks() {
    char category[50];
    int found = 0;

    getchar();

    printf("\nEnter Category: ");
    fgets(category, sizeof(category), stdin);
    category[strcspn(category, "\n")] = 0;

    for (int i = 0; i < count; i++) {

        if (strcmp(books[i].category, category) == 0) {
            displayBook(books[i]);
            found = 1;
        }
    }

    if (!found)
        printf("\nNo Books Found!\n");
}

// Sort by Price
void sortByPrice() {
    struct Book temp;

    for (int i = 0; i < count - 1; i++) {

        for (int j = 0; j < count - i - 1; j++) {

            if (books[j].price > books[j + 1].price) {

                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

    printf("\nBooks Sorted By Price:\n");

    displayAllBooks();
}

// Sort by Rating
void sortByRating() {
    struct Book temp;

    for (int i = 0; i < count - 1; i++) {

        for (int j = 0; j < count - i - 1; j++) {

            if (books[j].rating < books[j + 1].rating) {

                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }

    printf("\nBooks Sorted By Rating:\n");

    displayAllBooks();
}

// Main Function
int main() {

    int choice;

    do {

        printf("\n========== BOOK MANAGEMENT SYSTEM ==========\n");

        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book By ID\n");
        printf("4. Search Book By Name\n");
        printf("5. Show Author's Books\n");
        printf("6. Show Category's Books\n");
        printf("7. Update Book Data\n");
        printf("8. Sort Books By Price\n");
        printf("9. Sort Books By Rating\n");
        printf("10. Display All Books\n");
        printf("11. Exit\n");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addBook();
                break;

            case 2:
                removeBook();
                break;

            case 3:
                searchById();
                break;

            case 4:
                searchByName();
                break;

            case 5:
                showAuthorBooks();
                break;

            case 6:
                showCategoryBooks();
                break;

            case 7:
                updateBook();
                break;

            case 8:
                sortByPrice();
                break;

            case 9:
                sortByRating();
                break;

            case 10:
                displayAllBooks();
                break;

            case 11:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 11);

    return 0;
}