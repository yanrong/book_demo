#include <stdio.h>

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

class Card:public Component{
public:
    Card(int p,char *n,int r=45):Component(p,n,r){}
};

class Monitor:public Component{
public:
    Monitor(int p, char *n,int r=0):Component(p,n,r){}
};

Card Network(600,"Network");
Card CDRom(1500,"CDRom");
Card Tape(1000,"Tape");
Monitor Color(1700,"Color");
Monitor Monochrome(500,"Mono");

class Computer{
    Card *card;
    Monitor *mon;
public:
    Computer(Card *,Monitor *);
    int netPrice();
    void print();
};

int Computer::netPrice()
{
    return mon->netPrice() + card->netPrice();
}

Computer::Computer(Card *c,Monitor *m)
{
    card=c;
    mon=m;
}

void Computer::print()
{
    printf("%s %s,net price = %d\n",card->name(),mon->name(),netPrice());
}
int main()
{
    Computer mn(&Network,&Monochrome);
    Computer mc(&CDRom,&Monochrome);
    Computer mt(&Tape,&Monochrome);
    Computer cn(&Network,&Color);
    Computer cc(&CDRom,&Color);
    Computer ct(&Tape,&Color);

    mn.print();
    mc.print();
    mt.print();
    cn.print();
    cc.print();
    ct.print();

    return 0;
}
