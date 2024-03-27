#include <stdio.h>

void input(char *pro, float *price, int *qty, int arr_size);
void calculate_bill(float *price, int *qty, float *amount, int arr_size, float *sales_tax, float *total_payable);
void display(char *pro, float *price, int *qty, int arr_size, float total_payable);

int main() {
    int arr_size;
    printf("Please enter the amount of products: ");
    scanf("%d", &arr_size);

    char pro[arr_size];
    float price[arr_size];
    int qty[arr_size];

    input(pro, price, qty, arr_size);
    
    float sales_tax, total_payable;
    float amount = 0;
    calculate_bill(price, qty, &amount, arr_size, &sales_tax, &total_payable);
    
    display(pro, price, qty, arr_size, total_payable);

    return 0;
}

void input(char *pro, float *price, int *qty, int arr_size) {
    for(int i = 0; i < arr_size; i++) {
        printf("Enter product name (one char): ");
        scanf(" %c", &pro[i]); // space before %c helps to skip any whitespace characters
        printf("Enter price for %c: $", pro[i]);
        scanf("%f", &price[i]);
    }
    
    for(int i = 0; i < arr_size; i++) {
        printf("Enter qty for product %c, the price is $%.2f: ", pro[i], price[i]);
        scanf("%d", &qty[i]);
    }
}

void calculate_bill(float *price, int *qty, float *amount, int arr_size, float *sales_tax, float *total_payable) {
    for(int i = 0; i < arr_size; i++) {
        *amount += price[i] * qty[i];
    }
    *sales_tax = *amount * 0.05;  // Assuming 5% sales tax
    *total_payable = *amount + *sales_tax;
}

void display(char *pro, float *price, int *qty, int arr_size, float total_payable) {
    for(int i = 0; i < arr_size; i++) {
        float sub_total = price[i] * qty[i];
        printf("%c Product has $%.2f price and %d quantity is selected, sub-total: $%.2f\n", pro[i], price[i], qty[i], sub_total);
    }

    printf("\nThe total bill amount is: $%.2f\n", total_payable - (total_payable * 0.05));  // Subtracting sales tax to get original amount
    printf("Sales tax: $%.2f\n", total_payable * 0.05);
    printf("Total Payable: $%.2f\n", total_payable);
}

