
#include "Projectile.h"

int Projectile::getXMultFromDir(int dir){

    switch (dir){

        case D2DEDIR_LEFT:
            return -1;
            break;
        case D2DEDIR_DOWN:
            return 0;
            break;
        case D2DEDIR_RIGHT:
            return 1;
            break;
        case D2DEDIR_UP:
            return 0;
            break;
        case D2DEDIR_LEFTDOWN:
            return -1;
            break;
        case D2DEDIR_DOWNRIGHT:
            return 1;
            break;
        case D2DEDIR_RIGHTUP:
            return 1;
            break;
        case D2DEDIR_UPLEFT:
            return -1;
            break;
        default:
            break;

    }

}

int Projectile::getYMultFromDir(int dir){

    switch (dir){

        case D2DEDIR_LEFT:
            return 0;
            break;
        case D2DEDIR_DOWN:
            return 1;
            break;
        case D2DEDIR_RIGHT:
            return 0;
            break;
        case D2DEDIR_UP:
            return -1;
            break;
        case D2DEDIR_LEFTDOWN:
            return 1;
            break;
        case D2DEDIR_DOWNRIGHT:
            return 1;
            break;
        case D2DEDIR_RIGHTUP:
            return -1;
            break;
        case D2DEDIR_UPLEFT:
            return -1;
            break;
        default:
            break;

    }

}
