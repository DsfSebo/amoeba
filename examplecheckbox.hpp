#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class ExampleCheckBox : public Widget {
public:
    bool checked;
    bool valtas;
    bool aktiv;
    char kar;
    ExampleCheckBox(int x, int y, int sx, int sy);
    virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual bool is_checked() const ;
    virtual void action(genv::event ev);
    virtual bool visszaad1();
    virtual char visszaad2();
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
