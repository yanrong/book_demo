#include "link_queue.hpp"

int main()
{
    link_queue<float> float_queue;
    for(int i=0;i!=10;++i)
    {
        float_queue.en_queue(static_cast<float>(i*1.1));
    }
    float_queue.queue_info();

    for(int i=0;i!=4;++i)
    {
        float_queue.de_queue();
    }
    float_queue.queue_info();

    float_queue.make_empty();
    float_queue.queue_info();
    return 0;
}
