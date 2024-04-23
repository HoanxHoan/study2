#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 1000
#define MAX_STRING_LENGTH 20

typedef struct {
    char* customerID;
    char* productID;
    int price;
    char* shopID;
    char* timePoint;
} Order;

Order orders[MAX_ORDERS];
int numOrders = 0;

void parseInput(char line[]) {
    orders[numOrders].customerID = strdup(strtok(line, " "));
    orders[numOrders].productID = strdup(strtok(NULL, " "));
    orders[numOrders].price = atoi(strtok(NULL, " "));
    orders[numOrders].shopID = strdup(strtok(NULL, " "));
    orders[numOrders].timePoint = strdup(strtok(NULL, " \n"));
    numOrders++;
}

int totalNumberOrders() {
    return numOrders;
}

int totalRevenue() {
    int total = 0;
    for (int i = 0; i < numOrders; i++) {
        total += orders[i].price;
    }
    return total;
}

int revenueOfShop(char shopID[]) {
    int total = 0;
    for (int i = 0; i < numOrders; i++) {
        if (strcmp(orders[i].shopID, shopID) == 0) {
            total += orders[i].price;
        }
    }
    return total;
}

int totalConsumeOfCustomerShop(char customerID[], char shopID[]) {
    int total = 0;
    for (int i = 0; i < numOrders; i++) {
        if (strcmp(orders[i].customerID, customerID) == 0 && strcmp(orders[i].shopID, shopID) == 0) {
            total += orders[i].price;
        }
    }
    return total;
}

int totalRevenueInPeriod(char fromTime[], char toTime[]) {
    int total = 0;
    for (int i = 0; i < numOrders; i++) {
        if (strcmp(orders[i].timePoint, fromTime) >= 0 && strcmp(orders[i].timePoint, toTime) <= 0) {
            total += orders[i].price;
        }
    }
    return total;
}

void freeOrders() {
    for (int i = 0; i < numOrders; i++) {
        free(orders[i].customerID);
        free(orders[i].productID);
        free(orders[i].shopID);
        free(orders[i].timePoint);
    }
}

int main() {
    char line[100];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        if (line[0] == '#') {
            break;
        }
        parseInput(line);
    }

    char query[50];
    while (scanf("%s", query) == 1) {
        if (strcmp(query, "?total_number_orders") == 0) {
            printf("%d\n", totalNumberOrders());
        } else if (strcmp(query, "?total_revenue") == 0) {
            printf("%d\n", totalRevenue());
        } else if (strcmp(query, "?revenue_of_shop") == 0) {
            char shopID[MAX_STRING_LENGTH];
            scanf("%s", shopID);
            printf("%d\n", revenueOfShop(shopID));
        } else if (strcmp(query, "?total_consume_of_customer_shop") == 0) {
            char customerID[MAX_STRING_LENGTH], shopID[MAX_STRING_LENGTH];
            scanf("%s %s", customerID, shopID);
            printf("%d\n", totalConsumeOfCustomerShop(customerID, shopID));
        } else if (strcmp(query, "?total_revenue_in_period") == 0) {
            char fromTime[MAX_STRING_LENGTH], toTime[MAX_STRING_LENGTH];
            scanf("%s %s", fromTime, toTime);
            printf("%d\n", totalRevenueInPeriod(fromTime, toTime));
        }
    }

    freeOrders();

    return 0;
}
