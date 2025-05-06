#pragma once

class Asset {
   public:
    virtual void load() = 0;
    virtual void save() = 0;
    virtual void getInfo() = 0;
};