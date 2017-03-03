#include<iostream>

class sort_tracer{
    private:
        int value;
        int generation;
        static long n_created;
        static long n_destoryed;
        static long n_assigned;
        static long n_compared;
        static long n_max_live;

        static void update_max_live(){
            if(n_created - n_destoryed > n_max_live){
                n_max_live = n_created - n_destoryed;
            }
        }

    public:
        static long creations(){
            return n_created;
        }

        static long destructions(){
            return n_destoryed;
        }

        static long assignments(){
            return n_assigned;
        }

        static long comparisons(){
            return n_compared;
        }

        static long max_live(){
            return n_max_live;
        }

    public:
        sort_tracer(int v=0):value(v),generation(1){
            ++n_created;
            update_max_live();
            std::cerr<<"sort_trace #"<<n_created<<",created generation "<<generation
            <<"(totla :"<<n_created-n_destoryed<<")\n";
        }

        sort_tracer(sort_tracer const& b):value(b.value),generation(b.generation+1){
            ++n_created;
            update_max_live();
            std::cerr<<"sort_trace #"<<n_created<<",copy as generation "<<generation
            <<"(totla :"<<n_created-n_destoryed<<")\n";
        }

        ~sort_tracer(){
            ++n_destoryed;
            update_max_live();
            std::cerr<<"sort_tracer generation "<< generation<<"destoryed (total :"
            <<n_created - n_destoryed<<")\n";
        }

        sort_tracer& operator=(sort_tracer const& b){
            ++n_assigned;
            std::cerr<<"sort_tracer assignment #"<<n_assigned<<" (generation "
            <<generation<<" = "<<b.generation<<")\n";
            value=b.value;
            return *this;
        }

        friend bool operator<(sort_tracer const& a,sort_tracer const& b){
            ++n_compared;
            std::cerr<<"sorta_tracer comparison #"<<n_compared<<" (generation "
            <<a.generation<<" < "<<b.generation<<")\n";
            return a.value<b.value;
        }

        int val() const{
            return value;
        }
};
