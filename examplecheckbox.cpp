#include "examplecheckbox.hpp"
#include "graphics.hpp"
#include "JatekMester.h"
using namespace genv;

ExampleCheckBox::ExampleCheckBox(int x, int y, int sx, int sy): Widget(x,y,sx,sy)
{
    checked=false;
    valtas=false;
    aktiv=true;
    kar=' ';
}

void ExampleCheckBox::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+4, _y+12) << color(255,255,255) << text(kar);
}

void ExampleCheckBox::handle(event ev)
{
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left && valtas && aktiv)
    {
        checked=true;
        kar='x';
    }
    else if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left && aktiv)
    {
        checked=true;
        kar='o';
    }
}

bool ExampleCheckBox::is_checked() const
{
    return checked;
}

void ExampleCheckBox::action(event ev)
{
}

bool ExampleCheckBox::visszaad1()
{
    return aktiv;
}
char ExampleCheckBox::visszaad2()
{
    return kar;
}

