#include <iostream>
using std::cout;
using std::endl;

const int DefaultSize=100;

template <typename Type>
class SeqList{
    public:
        SeqList(int sz=DefaultSize):max_size(sz),cur_size(-1)
        {
            if(sz>0){
                elems = new Type[max_size];
            }
        }
        ~SeqList(){
            delete[] elems;
        }
        int Length() const{					//get the length
            return cur_size+1;
        }
        int Find(Type x) const;				//find the position of x
        int IsElement(Type x) const;		//is it in the list
        int Insert(Type x,int i);			//insert data
        int Remove(Type x);					//delete data
        int IsEmpty(){
            return cur_size ==-1;
        }
        int IsFull(){
            return cur_size == max_size-1;
        }
        Type Get(int i){					//get the ith data
            return i<0||i>cur_size?(cout<<"can't find the element"<<endl,0):elems[i];
        }
        void Print();

    private:
        Type *elems;
        const int max_size;
        int cur_size;
};

template <typename Type>
int SeqList<Type>::Find(Type x) const
{
	for(int i=0;i<cur_size;i++)
		if(elems[i]==x)
			return i;
	cout<<"can't find the element you want to find"<<endl;
	return -1;
}

template <typename Type>
int SeqList<Type>::IsElement(Type x) const
{
	if(Find(x)==-1)
		return 0;
	return 1;
}

template <typename Type>
int SeqList<Type>::Insert(Type x, int i)
{
	if(i<0||i>cur_size+1||cur_size==max_size-1)
    {
		cout<<"the operate is illegal"<<endl;
		return 0;
	}
	cur_size++;
	for(int j=cur_size;j>i;j--){
		elems[j]=elems[j-1];
	}
	elems[i]=x;
	return 1;
}

template <typename Type>
int SeqList<Type>::Remove(Type x)
{
	int sz=cur_size;
	for(int i=0;i<cur_size;)
    {
		if(elems[i]==x)
		{
			for(int j=i;j<cur_size;j++){
				elems[j]=elems[j+1];
			}
			cur_size--;
			continue;
		}
		i++;
	}
	if(sz==cur_size)
	{
		cout<<"can't find the element you want to remove"<<endl;
		return 0;
	}
	return 1;
}

template <typename Type>
void SeqList<Type>::Print()
{
	for(int i=0;i<=cur_size;i++)
		cout<<i+1<<":\t"<<elems[i]<<endl;
	cout<<endl<<endl;
}
