#ifndef CYBERENEMY_H
#define CYBERENEMY_H

class CyberEnemy {
protected:
    int health;

public:
    CyberEnemy(int health) : health(health) {}

    virtual void attack() = 0;

    virtual ~CyberEnemy() {}
};

#endif