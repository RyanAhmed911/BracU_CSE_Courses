#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Food {
    int quantity;
    int unit_price;
};

int main(void) {
    struct Food paratha;
    struct Food vegetable;
    struct Food mineral_water;

    printf("Quantity of paratha: ");
    scanf("%d", &paratha.quantity);

    printf("Unit price of paratha: ");
    scanf("%d", &paratha.unit_price);

    printf("Quantity of vegetable: ");
    scanf("%d", &vegetable.quantity);   

    printf("Unit price of vegetable: ");
    scanf("%d", &vegetable.unit_price);

    printf("Quantity of mineral water: ");
    scanf("%d", &mineral_water.quantity);

    printf("Unit price of mineral water: ");
    scanf("%d", &mineral_water.unit_price);

    printf("Number of people: ");
    int number_of_people;
    scanf("%d", &number_of_people);

    int total_cost = (paratha.quantity * paratha.unit_price) +
                     (vegetable.quantity * vegetable.unit_price) +
                     (mineral_water.quantity * mineral_water.unit_price);
    float cost_per_person = (float)total_cost / number_of_people;

    printf("Individual people will pay: %.2f tk\n", cost_per_person);
    return 0;
}