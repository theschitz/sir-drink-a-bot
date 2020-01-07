#include <stdio.h>

struct Setting_s
{
    int max_width;
    int max_depth;
    int tray[3][3];
};

typedef struct Setting_s Settings;

int main() 
{
    run_program();
    return 0;
}

void run_program()
{
    printf("\n[*] Running Program\n\n");
    int drinks_poured = 0;    
    Settings s = {100, 100, 6};
    for (int row = 0; row < (int)( sizeof(s.tray) / sizeof(s.tray[0])); row++)
    {
        for (int col = 0; col < (int)(sizeof(s.tray[row][0]) - 1); col++)
        {
            unsigned long x = sizeof(s.tray[row][col]);
            printf("\n[*] Pouring drink in row %d col %d", row);
            pour();
            drinks_poured += 1;
            move_col();
        }
        move_row();
    }
    printf("\n[*] Drinks poured %d\n", drinks_poured);
}

void move_col() {
    printf("\n[*] Moving col\n");
}

void move_row() {
    printf("\n\n[*] Moving row");
}

void pour() {
    printf("\n[*] Puring.");
}