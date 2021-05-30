//
// Created by Влад Почикалин on 30.05.2021.
//
#include <stdio.h>



int main() {
    int age;
    int nums[5] = {23,5};
    scanf("%d", &age);
    printf("%d", age);

    switch (age) {
        case 1:
            printf("1");
            break;
        case 2:
            printf("2");
            break;
        default:
            printf("default");
    }
    return 0;
}