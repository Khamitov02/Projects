#include<caSSERT>
struct subvector
{
int* mas;
unsigned int top;
unsigned int capacity;
};
bool init(subvector* qv)
{
    assert(qv!=nullptr);
    qv->mas=nullptr;
    qv->top=0;
    qv->capacity=0;
    return true;
};

void izm(int **a, unsigned int old, unsigned int new_capacity)
{
    if ((*a)!=nullptr){
        int* new_a = new int [new_capacity];
    for (int i=0;i<old;i++)
        new_a[i]=(*a)[i];
    delete[] *a;
    *a=new_a;
    }
};

bool push_back(subvector *qv, int d)
{
    assert(qv!=nullptr); assert((qv->capacity)>=(qv->top));
    if (qv->capacity == qv->top && qv->mas!=nullptr){
        qv->capacity+=1;
        izm(&(qv->mas),qv->top,qv->capacity);
        qv->top++;
        qv->mas[qv->top-1]=d;}
    if (qv->mas==nullptr){
        qv->top++;
        qv->capacity++;
        qv->mas[qv->top-1]=d;}
    if ((qv->capacity)>(qv->top)){
        qv->top++;
        qv->mas[qv->top-1]=d;
        }
    return true;
};
int pop_back(subvector *qv)
    {
    assert(qv!=nullptr);
    assert(qv->top!=0);
    qv->top-=1;
    return 0;
};
bool resize(subvector *qv, unsigned int new_capacity)
{
    assert(qv!=nullptr);
    if (new_capacity<=qv->capacity)
        return false;
    izm(&qv->mas, qv->capacity, new_capacity);
    qv->capacity=new_capacity;
    return true;
};
void shrink_to_fit(subvector *qv)
{
    assert(qv!=nullptr);
    assert((qv->top)<(qv->capacity));
    izm(&qv->mas,qv->top,qv->top);
    qv->capacity=qv->top;
};
void clear(subvector *qv)
{
    assert(qv!=nullptr);
    qv->top = 0;
    delete[] qv->mas;
};
void destructor(subvector *qv)
{
    assert(qv!=nullptr);
    assert(qv->mas!=nullptr);
    delete[] qv->mas;
    qv->mas = nullptr;
    qv->top = qv->capacity = 0;
};
