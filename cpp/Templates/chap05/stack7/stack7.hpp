//stack7.cpp

#ifndef STACK_H
#define STACK_H

template <typename T, template <typename ELEM> class CONT = std::deque >
class Stack
{
    private:
        CONT<T> elems;

    public:
        void push(T const&);
        void pop();
        T top() const;
        bool empty() const{
            return elems.empty();
        }
};

#endif // STACK_H
