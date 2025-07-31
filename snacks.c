#include <stdio.h>

float snacksMenu()
{
    float total = 0;

    while (1)
    {
        int choice, qty;

        printf("\n===== Snacks Menu =====\n");
        printf("1. Popcorn - Rs.100\n");
        printf("2. Puff - Rs.30\n");
        printf("3. Drink - Rs.50\n");
        printf("4. Skip snacks\n");

        printf("Enter your choice (4 to skip): ");
        if (scanf("%d", &choice) != 1)
        {
            printf("❌ You Entered Invalid Choice!\n");
            while (getchar() != '\n') // clear the input buffer
                ;
            continue;
        }

        if (choice < 1 || choice > 4)
        {
            printf("❗ You Selected Item Is Unavailable!\n");
            continue;
        }
        if (choice == 4)
            break;

        printf("\nEnter quantity: ");
        scanf("%d", &qty);

        switch (choice)
        {
        case 1:
            total += qty * 100;
            break;
        case 2:
            total += qty * 30;
            break;
        case 3:
            total += qty * 50;
            break;
        default:
            printf("❌ Invalid choice.\n");
        }
    }
    return total;
}
