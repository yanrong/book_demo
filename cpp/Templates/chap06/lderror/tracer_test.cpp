#include <iostream>
#include <algorithm>
#include "tracer.hpp"

int main()
{
    sort_tracer input[]={0,1,2,3,4,5,6,7,8,9};
    for(int i=0;i<10;++i){
        std::cerr<<input[i].val()<<" ";
    }
    std::cout<<std::endl;

    long created_at_start=sort_tracer::creations();
    long max_live_at_start=sort_tracer::max_live();
    long assinged_at_start=sort_tracer::assignments();
    long compared_at_start=sort_tracer::comparisons();

    std::cerr<<"-----[ Start std::sort() ]-----------------------\n";
    std::sort<>(&input[0],&input[9]+1);
    std::cerr<<"-----[ End std::sort() ]-----------------------\n";

    for(int i=0;i<10;++i){
        std::cerr<<input[i].val()<<' ';
    }
    std::cerr<<std::endl;

    std::cerr<<"std::sort of 10 sortTracer's was performed by:\n"
    <<sort_tracer::creations()-created_at_start<<" tempoary tracers up to"
    <<sort_tracer::max_live()<<" tracers at the same time("<<max_live_at_start<<" before)\n"
    <<sort_tracer::assignments()-assinged_at_start<<" assignments\n"
    <<sort_tracer::comparisons()-compared_at_start<<" comparisons\n\n";

    return 0;
}
