#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"
#include <string>
#include <vector>

class Widget
{
protected:
    int _x, _y, _size_x, _size_y;
public:
    Widget(int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual void action(genv::event ev);
    virtual bool visszaad1();
    virtual char visszaad2();
};


#endif // WIDGETS_HPP_INCLUDED
