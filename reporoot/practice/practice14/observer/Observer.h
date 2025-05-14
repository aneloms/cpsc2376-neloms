#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(int grade) = 0;
};

#endif
