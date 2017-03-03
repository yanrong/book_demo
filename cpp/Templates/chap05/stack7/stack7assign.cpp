#include <stdexcept>
#include <deque>
#include "stack7.hpp"

template <typename T, template <typename> class CONT>
void Stack<T,CONT>::push(T const& elem)
{
    elems.push_back(elem);
}

template <typename T, template <typename> class CONT>
void Stack<T,CONT>::pop()
{
    if(elems.empty()){
        throw std::out_of_range("empty stack,Stack<T,CONT>::pop()");
    }
    elems.pop_back();
}

template <typename T, template <typename> class CONT>
T Stack<T,CONT>::top() const
{
    if(elems.empty())
    {
        throw std::out_of_range("empty stack,Stack<T,CONT>::top()")
    }
    return elems.back();
}
