#define OLC_PGE_APPLICATION

#include "Game.h"

int main()
{
    FGame Game;
    Game.Construct(190, 160, 4, 4);
    Game.Start();
    return 0;
}
