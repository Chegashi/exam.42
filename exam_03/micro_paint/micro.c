#include <unistd.h>
#include <stdio.h>

void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

int ft_error(char *str)
{
    ft_putstr(str);
    return (1);
}

int main(int ac, char **av)
{
    FILE *f;
    int count;
    int z_w;
    int z_H;
    char BACKGROUND_CHAR;
    char r;
    float X;
    float Y;
    float W;
    float H;
    char C;
    int i, j;

    if (ac != 2)
        return (ft_error("Error: argument\n"));
    if (!(f = fopen(av[1], "r")))
        return (ft_error("Error: Operation file corrupted\n"));
    if((count = fscanf(f, "%d %d %c\n", &z_w, &z_H, &BACKGROUND_CHAR)) != 3)
        return (ft_error("Error: Operation file corrupted\n"));
    if (z_w <= 0 || z_H <= 0 || z_w > 300 || z_H > 300)
        return (ft_error("Error: Operation file corrupted\n"));
    char zone[z_H][z_w + 2];
    for (i = 0; i < z_H; i++)
        {
            for (j = 0; j < z_w; j++)
                zone[i][j] = BACKGROUND_CHAR;
            zone[i][j] = '\n';
            zone[i][++j] = 0;
        }
    while ((count = fscanf(f, "%c %f %f %f %f %c\n", &r, &X, &Y, &W, &H, &C)) == 6)
    {
        if ((W <= 0 || H <= 0) && (r != 'r' && r != 'R'))
            return (ft_error("Error: Operation file corrupted\n"));
        for (i = 0; i < z_H; i++)
        {
            for (j = 0; j < z_w; j++)
                if (!(i < Y || j < X || i > Y + H || j > X + W))
                    if (r == 'R' || (i - Y < 1 || j - X < 1 || Y + H - i < 1 || X + W - j < 1))
                        zone[i][j] = C;
        }
    }
    if (count != EOF)
        return (ft_error("Error: Operation file corrupted\n"));
    for (i = 0; i < z_H; i++)
        write (1, zone[i], z_w + 1);
    return (0);
}
