1#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int height;
    do
    {
        printf("Height of pyramid: ");
        height = get_int();
    }
    while(height < 0 || height > 23);

//increment variable until the height of the pyramid
for(int line = 0; line < height; line++)
{
    //for each iteration: print 1 less space than height
    for(int space = (height - line); space > 1; space--)
    {
        printf(" ");
    }

    //for each iteration: print 2 hashes and then 1 more until height
    for(int hash = 0; hash < (line + 2); hash++)
    {
        printf("#");
    }

    //line break
    printf("\n");
}
}