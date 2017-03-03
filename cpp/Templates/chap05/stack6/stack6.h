//stack6.h head file
#ifndef STACK_H
#define STACK_H

template <typename T ,typename CONT=std::deque<T> >
class Stack
{
    private:
        CONT elems;

    public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty(){
            return elems.empty();
        }

        template <typename T2,typename CONT2>
        Stack<T,CONT>& operator=(Stack<T2,CONT2> const&);
};

#endif // STACK_H
