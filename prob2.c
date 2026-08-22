#include <stdio.h>

struct Node
{
    int n;
    char source;
    char auxiliary;
    char destination;
};

int main()
{
    int n;
    struct Node stack[100];
    int top = -1;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    stack[++top] = (struct Node){n, 'A', 'B', 'C'};

    while (top != -1)
    {
        struct Node current = stack[top--];

        if (current.n == 1)
        {
            printf("Move disk 1 from %c to %c\n",
                   current.source, current.destination);
        }
        else
        {
            stack[++top] = (struct Node){
                current.n - 1,
                current.auxiliary,
                current.source,
                current.destination
            };

            printf("Move disk %d from %c to %c\n",
                   current.n,
                   current.source,
                   current.destination);

            stack[++top] = (struct Node){
                current.n - 1,
                current.source,
                current.destination,
                current.auxiliary
            };
        }
    }

    return 0;
}