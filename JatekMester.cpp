#include "JatekMester.h"
#include "graphics.hpp"
#include "string"
#include "vector"
using namespace genv;

Lambda::Lambda(int x, int y, int sx, int sy,std::function<void()> funct):Jatekmester(x, y, sx, sy)
{
    lambda_fv = funct;
}
void Lambda::action()
{
    lambda_fv();
}


Jatekmester::Jatekmester(int x, int y, int sx, int sy): Widget(x,y,sx,sy)
{
    checked=false;
}

void Jatekmester::draw() const
{

    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+10, _y+_size_y-10) << color(0,0,0) << text("'o' jon");

    if (checked)
    {

        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(255,255,255) << box(_size_x-4, _size_y-4);
        gout << move_to(_x+10, _y+_size_y-10) << color(0,0,0) << text("'x' jon");
    }
}

void Jatekmester::handle(event ev )
{
    if (ev.type == ev_mouse && ev.button==btn_left)
    {
        checked = !checked;
        action();
    }
}
bool Jatekmester::is_checked() const
{
    return checked;
}
