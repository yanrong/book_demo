#include <cstdio>

enum CARD {CDROM,TAPE,NETWORK};
enum MONITOR {MONO,COLOR};

/*add a component class as top level base calss*/
class Component{
    public:
        virtual int price()=0;
        virtual char *name()=0;
        virtual int rebate();
        int netPrice();
};

class Card:public Component{
    public:
        virtual int price()=0;
        virtual char *name()=0;
        virtual int rebate();
};

class Monitor:public Component{
    public:
        virtual int price()=0;
        virtual char *name()=0;
};

/*when derive class inherent form base class Component,it default discount price is zero*/
class Network:public Card{
    public:
        int price();
        char *name();
};

class CDRom:public Card{
    public:
        int price();
        char *name();
        int rebate();
};

class Tape:public Card{
    public:
        int price();
        char *name();
};

class Color:public Monitor{
    public:
        int price();
        char *name();
};

class Monochrome:public Monitor{
    public:
        int price();
        char *name();
};

class Computer{
        Card *card;
        Monitor *mon;
    public:
        Computer(CARD,MONITOR);
        ~Computer();
        int netPrice();
        void print();
};

int Computer::netPrice()
{
    return mon->netPrice()+card->netPrice();
}

Computer::Computer(CARD c,MONITOR m)
{
    switch(c){
        case NETWORK:   card=new Network; break;
        case CDROM:     card=new CDRom; break;
        case TAPE:      card=new Tape;break;
    }
    switch(m){
        case MONO:  mon=new Monochrome;break;
        case COLOR: mon=new Color;break;
    }
}

Computer::~Computer()
{
    delete card;
    delete mon;
}

int Component::rebate(){return 0;}
int Component::netPrice()
{
    return price()-rebate();
}

//default car discount price is $40
int Card::rebate(){return 40;}

int Network::price(){return 500;}
char *Network::name(){return "Network";}

int CDRom::price(){return 1200;}
int CDRom::rebate(){return 200;}
char* CDRom::name(){return "CDRom";}

int Tape::price(){return 1000;}
char *Tape::name(){return "Tape";}

int Color::price(){return 2000;}
char *Color::name(){return "Color";}

int Monochrome::price(){return 500;}
char *Monochrome::name(){return "Mono";}

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
