#include <stdio.h>

enum CARD{CDROM,TAPE,NETWORK};
enum MONITOR{MONO,COLOR};

class Component{
    int _price;
    char *_name;
    int _rebate;

public:
    Component(int p,char *n,int r=0);
    int netPrice();
    int price(){return _price;}
    char *name(){return _name;}
    int rebate(){return _rebate;}
};

Component::Component(int p,char *n,int r):_price(p),_name(n),_rebate(r){}

int Component::netPrice()
{
    return _price - _rebate;
}

Component Network(600,"Network",45);
Component CDRom(1500,"CDRom",150);
Component Tape(1000,"Tape",45);
Component Color(1700,"Color");
Component Monochrome(50,"Mono");

class Computer{
    Component *card;
    Component *mon;
public:
    Computer(CARD,MONITOR);
    int netPrice();
    void print();
};

int Computer::netPrice()
{
    return mon->netPrice() + card->netPrice();
}

Computer::Computer(CARD c,MONITOR m)
{
    switch(c){
        case NETWORK:   card=&Network; break;
        case CDROM:     card=&CDRom; break;
        case TAPE:      card=&Tape;break;
    }
    switch(m){
        case MONO:  mon=&Monochrome;break;
        case COLOR: mon=&Color;break;
    }
}

void Computer::print()
{
    printf("%s %s,net price = %d\n",card->name(),mon->name(),netPrice());
}
int main()
{
    Computer mn(NETWORK,MONO);
    Computer mc(CDROM,MONO);
    Computer mt(TAPE,MONO);
    Computer cn(NETWORK,COLOR);
    Computer cc(CDROM,COLOR);
    Computer ct(TAPE,COLOR);

    mn.print();
    mc.print();
    mt.print();
    cn.print();
    cc.print();
    ct.print();

    return 0;
}
