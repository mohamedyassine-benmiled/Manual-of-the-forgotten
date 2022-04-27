#ifndef DEC
#define DEC

#define true 1
#define false 0
//Fps Count
#define FPS 60
//Character Size
#define CHAR_H 124
#define CHAR_W 124
//Variables
#define SPEED 12
#define GRAVITY 16
#define JUMP_POWER 40
#define maxJmpH 400
#define RELOAD 1000
#define MAX_ITEMS 4
#define START_y 499
#define START_x 100
#define MINIMAP 20
//Sprites Player[0]
#define SPRITEXP0_Run 3
#define SPRITEXP0_Walk 1
#define SPRITEXP0_Jump 2
#define SPRITEXP0_Idle 0
#define SPRITEYP0_Run 15
#define SPRITEYP0_Walk 11
#define SPRITEYP0_Jump 3
#define SPRITEYP0_Idle 7
//Sprites Enemy[0]
#define SPRITEXE0_Run 0
#define SPRITEXE0_Walk 3 // Non existant
#define SPRITEXE0_Jump 2 // Non existant
#define SPRITEXE0_Idle 1 // Non existant
#define SPRITEYE0_Run 3
#define SPRITEYE0_Walk 0
#define SPRITEYE0_Jump 0
#define SPRITEYE0_Idle 0

typedef struct
{
    //Movement
    int up;
    int down;
    int right;
    int left;
    int startJump;
    int jumpHeight;
    int reset;
    int fix;
    int movement;
    //Attacks
    int a1; //ATTACK1
    int a2; //ATTACK2
    int sj; //SPECIAL JUMP
    //Cheats for developer testing
    int ih;
    int fast;
    } Input;


#endif
