#ifndef JATEKMESTER_H_INCLUDED
#define JATEKMESTER_H_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"
#include "string"
#include "examplecheckbox.hpp"
#include "vector"
#include <functional>

class Jatekmester : public Widget {
protected:
    bool checked;
public:
    Jatekmester(int x, int y, int sx, int sy);
    virtual ~Jatekmester(){}
    virtual void draw() const ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
    virtual void action(){};
};

class Lambda : public Jatekmester{
protected:
    std::function<void()> lambda_fv;
public:
    Lambda(int x, int y, int sx, int sy, std::function<void()> funct);
    void action();
};


#endif // JATEKMESTER_H_INCLUDED
