#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

void sort(struct Item items[], int n) {

    struct Item temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (items[j].ratio < items[j + 1].ratio) {

                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {

    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and profit of each item:\n");

    for (int i = 0; i < n; i++) {

        scanf("%d %d",
              &items[i].weight,
              &items[i].profit);

        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort according to profit/weight ratio
    sort(items, n);

    float totalProfit = 0;

    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {

            capacity -= items[i].weight;
            totalProfit += items[i].profit;
        }
        else {

            totalProfit +=
                items[i].ratio * capacity;

            capacity = 0;
            break;
        }
    }

    printf("Maximum Profit = %.2f\n", totalProfit);

    return 0;
}