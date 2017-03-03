#include <stdio.h>

enum { RED, GREEN, BLUE };
void OutputSignal(int sig)
{
    printf("The signal you /'ve input is: ");
    switch(sig)
    {
    case RED:
        puts("RED!");
        break;
    case GREEN:
        puts("GREEN!");
        break;
    case BLUE:
        puts("BLUE!");
        break;
    }
}

void ( *signal( int sig, void (*func)(int) ) ) (int)
{
    puts("Hello, world!");
    func(sig);
    return func;
}

int main(void)
{
    (*signal(GREEN, &OutputSignal))(RED);
    return 0;
}
