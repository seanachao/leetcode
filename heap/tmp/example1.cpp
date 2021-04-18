#include<iostream>
#include<queue>
using namespace std;
template<class T, class C = vector< T >, class P = less<typename C::value_type> >
struct heapq :std::priority_queue<T,C,P> {
    using priority_queue<T,C,P>::priority_queue;
    typename C::iterator begin() { return std::priority_queue<T, C, P>::c.begin(); }
    typename C::iterator end() { return std::priority_queue<T, C, P>::c.end(); }
};
int main(){
    heapq<int> q;
    q.push(100);
    q.push(80);
    q.push(90);
    for(auto e:q) cout<<e<<endl;
}