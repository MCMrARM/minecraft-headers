#pragma once

class ItemInstance;

class PlayerInventoryProxy {

public:
    ItemInstance* getSelectedItem();
    void clearInventory(int);

};