#ifndef IHACKABLE_H
#define IHACKABLE_H

class IHackable {
public:
    virtual void applyHack(int techLevel) = 0;
    virtual bool isHacked() const = 0;
    virtual ~IHackable() {}
};

#endif