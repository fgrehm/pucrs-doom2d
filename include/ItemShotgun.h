
#ifndef _INVITEM_H_
#define _INVITEM_H_

#include "Inventory.h"

class Inventory;

class InvItem {

public:

    virtual void visit(Inventory *) = 0;

private:

};

#endif // _INVITEM_H_
