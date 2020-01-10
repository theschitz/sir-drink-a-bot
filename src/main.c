#include <stdio.h>

const int PUMP_PIN = 0;
const int MOTOR_PIN = 0;

struct Settings
{
    int max_width;
    int max_depth;
    int tray[4][6];
};

struct Tray
{
    int rows;
    int cols;
};
typedef struct Tray Tray;
typedef struct Settings Settings;

int main() 
{
    int no_of_drinks = 0;
    Tray tray = {4, 6};
    run_program(no_of_drinks, tray);
    return 0;
}

void run_program(int drinks_ordered, Tray tray)
{
    if (drinks_ordered == 0 || drinks_ordered > (tray.rows * tray.cols))
    {
        return;
    }
    
    printf("\n[*] Running Program\n\n");
    int drinks_poured = 0;    
    Settings s = {100, 100, 6};
    for (int row = 0; row < (int)( sizeof(s.tray) / sizeof(s.tray[0])); row++)
    {
        for (int col = 0; col < (int)(sizeof(s.tray[row][0])); col++)
        {
            unsigned long x = sizeof(s.tray[row][col]);
            printf("\n[*] Pouring drink in row %d col %d", row, col);
            pour_drink();
            drinks_poured += 1;
            if (drinks_ordered == drinks_poured)
            {
                printf("\n[*] Done! Poured %d of %d drinks.", drinks_poured, drinks_ordered);
            }
            
            move_col();
        }
        move_row();
    }
    printf("\n[*] Drinks poured %d\n.", drinks_poured);
}

void move_col() {
    printf("\n[*] Moving col-\n");
}

void move_row() {
    printf("\n\n[*] Moving row.");
}

void pour_drink() {
    printf("\n[*] Pouring.");
}