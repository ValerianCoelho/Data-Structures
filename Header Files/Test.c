#include <stdio.h>
#include "TUI.h"
int main()
{
    char Header[40] = "Choose One of the Following Options :-";
    char Options[5][20] = {"Addition", "Subtractions", "Multiplication", "Division", "Modulus"};
    printf("%d", WhiteHighlight(Header, Options, 5, 1));
    return 0;
}