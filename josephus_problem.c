/*
Write a program which finds the solution of Josephus problem using a circular linked list.
In Josephus problem, n people stand in a circle waiting to be executed. The counting starts at some
point in the circle and proceeds in a specific direction around the circle. In each step, a certain
number of people are skipped and the next person is executed (or eliminated). The elimination
of people makes the circle smaller and smaller. At the last step, only one person remains who is
declared the ‘winner’.
*/

#include <stdio.h>
#include <malloc.h>

struct node
{
    int player_id;
    struct node *next;
};

struct node *start, *ptr, *new_node;

int main()
{
    int n, k, i, count;
    printf("\n Enter the number of players : ");
    scanf("%d", &n);
    printf("\n Enter the value of k (every kth player gets eliminated): ");
    scanf("%d", &k);
    // Create circular linked list containing all the players
    start = malloc(sizeof(struct node));
    start->player_id = 1;
    ptr = start;
    for (i = 2; i <= n; i++)
    {
        new_node = malloc(sizeof(struct node));
        ptr->next = new_node;
        new_node->player_id = i;
        new_node->next = start;
        ptr = new_node;
    }
    for (count = n; count > 1; count--)
    {
        for (i = 0; i < k - 1; ++i)
            ptr = ptr->next;
        ptr->next = ptr->next->next; // Remove the eliminated player from thecircular linked list
    }
    printf("\n The Winner is Player %d", ptr->player_id);
    return 0;
}