// #include <stdio.h>
#include <Keypad.h>

#define ROWS 4
#define COLS 4

#define ROW_PINS {39, 41, 43, 45}
#define COL_PINS {47, 49, 51, 53}
#define KEYMAP {{'1','2','3','A'}, {'4','5','6','B'}, {'7','8','9','C'}, {'*','0','#','D'}}

// File argument will be unused.
int numpad_getchar(FILE*); 
