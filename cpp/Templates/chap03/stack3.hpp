#include <vector>
#include <stdexcept>

template <typename T,typename CONT=std::vector<T> >
class Stack
{
    private:
        CONT elems;

    public:
        void push(T const&);
        T pop();
        T top() const;
        bool empty() const
        {
            return elems.empty();
        }
};

//template <typename T,typename CONT=std::vector<T> > // error
/*
You attempt to provide a default argument for the second template parameter to stack twice. Default template arguments, just like default function arguments, may only be defined once (per translation unit); not even repeating the exact same definition is allowed.

Just type the default argument at the beginning where you define the class template. After that, leave it out:
*/
template <typename T,typename CONT>
void Stack<T, CONT>::push(T const& elem)
{
    elems.push_back(elem);
}

template <typename T,typename CONT>
T Stack<T, CONT>::pop()
{
    if(elems.empty())
    {
        throw std::out_of_range("Stack<T,CONT>::pop(),stack empty!");
    }
    T e=elems.back();
    elems.pop_back();
    return e;
}

template <typename T,typename CONT>
T Stack<T, CONT>::top() const
{
    if(elems.empty())
    {
        throw std::out_of_range("Stack<T,CONT>::top():stack empty!");
    }
    return elems.back();
}
