#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include <vector>
#include <string>
#include "JatekMester.h"
#include <iostream>

using namespace std;
using namespace genv;
const int mezoksz=20;       ///mezok szama(x*x-es negyzet)
const int xx=20+mezoksz*15;           ///a keret szélessége
const int yy=80+mezoksz*15;           ///a keret magassága

char nyeres(vector<Widget*>& wid)
{
    int vizx=0;                 ///vizszintesen
    int vizo=0;
    int db=0;

    for(int i=0; i<mezoksz; i++)
    {
        for(int j=0; j<mezoksz; j++)
        {
            if(wid[db]->visszaad2()=='x')
            {
                vizx++;
                vizo=0;
            }
            else if(wid[db]->visszaad2()=='o')
            {
                vizo++;
                vizx=0;
            }
            if(vizo==5)
            {
                return 'o';
            }
            if(vizx==5)
            {
                return 'x';
            }
            db++;
        }
        vizo=0;
        vizx=0;
    }

    int fuggx=0;
    int fuggo=0;

    for(int i=0; i<mezoksz; i++)         ///fuggolegesen
    {
        db=i;
        for(int j=0; j<mezoksz; j++)
        {
            if(wid[db]->visszaad2()=='x')
            {
                fuggx++;
                fuggo=0;
            }
            else if(wid[db]->visszaad2()=='o')
            {
                fuggo++;
                fuggx=0;
            }
            if(fuggo==5)
            {
                return 'o';
            }
            if(fuggx==5)
            {
                return 'x';
            }
            db+=mezoksz;
        }

    }
    return ' ';
}

///rekurzivan (nem keszult el)
/*int nyertes(vector<Widget*>& widgets,int focus)
{
    int db = 1;
    char irany = 'f';
    if(widgets[focus]->visszaad2()=='0' && widgets[focus-mezoksz]->visszaad2()=='0' && irany=='f')  ///fel
    {
        nyertes(widgets, focus-mezoksz);
        db++;
    }else{irany = 'a';}

    if(widgets[focus]->visszaad2()=='0' && widgets[focus-mezoksz+1]->visszaad2()=='0' && irany=='a')    ///jobbra fel
    {
        nyertes(widgets, focus-mezoksz+1);
        db++;
    }else{irany = 'j';}

    if(widgets[focus]->visszaad2()=='0' && widgets[focus+1]->visszaad2()=='0' && irany=='j')        ///jobbra
    {
        nyertes(widgets, focus+1);
        db++;
    }else{irany = 'b';}

    if(widgets[focus]->visszaad2()=='0' && widgets[focus+mezoksz+1]->visszaad2()=='0' && irany=='b')    ///jobbra le
    {
        nyertes(widgets, focus+mezoksz+1);
        db++;
    }
    if(db>=5)
    {
        return 1;
    }
    return 0;
}*/

void event_loop(vector<Widget*>& widgets)
{
    event ev;
    int focus = -1;
    bool vege=false;
    while(gin >> ev && ev.keycode != key_escape && !vege)
    {
        if (ev.type == ev_mouse && ev.button == btn_left)
        {
            for (size_t i=0; i<widgets.size(); i++)
            {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                }
            }
        }
        if (focus!=-1)
        {
            widgets[focus]->handle(ev);
            if(focus!=widgets.size()-1 && widgets[focus]->visszaad1())
            {
                widgets[widgets.size()-1]->handle(ev);      ///A jatekmester mindig fokuszban van
            }
        }
        for (size_t i=0; i<widgets.size(); i++)
        {
            widgets[i]->draw();
        }
        gout << refresh;
        if(nyeres(widgets)=='x')
        {
            cout << "x nyert";
            vege=true;
        }
        else if(nyeres(widgets)=='o')
        {
            cout << "o nyert";
            vege=true;
        }
    int betelt=0;
    for(int i=0; i<mezoksz*mezoksz; i++)
    {
        if(widgets[i]->visszaad2()!=' '){betelt++;}
    }
    if(betelt==mezoksz*mezoksz){cout << "dontetlen"; vege=true;}
    }

}


int main()
{
    gout.open(xx,yy);
    vector<Widget*> w;
    vector<ExampleCheckBox*> v;

    for(int i=0; i<mezoksz; i++)
    {
        for(int j=0; j<mezoksz; j++)
        {
            ExampleCheckBox * b1 = new ExampleCheckBox(10+j*15,50+i*15,17,17);
            v.push_back(b1);
            w.push_back(b1);
        }
    }

    Lambda* b2 = new Lambda(20,5,100,30,[&v]()
    {
        for(int i=0; i<mezoksz*mezoksz; i++)
        {
            v[i]->valtas = !v[i]->valtas;
            if(v[i]->checked)
            {
                v[i]->aktiv=false;
            }
        }
    });

    w.push_back(b2);
    event_loop(w);
    return 0;
}
