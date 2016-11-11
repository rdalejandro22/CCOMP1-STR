#include <iostream>
#include <vector>
#include <stdexcept>
#include <map>
using namespace std;
class Graph
{
private:
    map <int, vector <int> > adyacentes;

public:
    Graph(const vector <int> &starts, const vector <int> &ends)
    {
        if(starts.size()!=ends.size())
            throw std::invalid_argument("no son del mismo tamanio");
        for(int i = 0; i<starts.size();i++)
        {
            //int start = starts[i], end = ends[i];
            adyacentes[starts[i]].push_back(ends[i]);
        }
    }
    int numOutgoing(const int nodeID)
    {
        return adjacent(nodeID).size();
    }
    const vector<int> &adjacent(const int nodeID)
    {
        map <int,vector<int> >::iterator it;
        it = adyacentes.find(nodeID);
        return (*it).second;
    }
    int numOutgoing(const int nodeID)
    {
        return adjacent(nodeID);
    }
    const int &adjacent(const int nodeID)
    {
        map <int,vector<int> >::iterator it;
        it = adyacentes.find(nodeID);
        return (*it).first;
    }
};
template <typename T>
class Stack
{
private:
    vector <T> pila;
public:
    bool empty()
    {
        if (pila.empty()){
            cout << "El stack esta vacio\n";
            return true;}
        else
            cout << "El stack no esta vacio\n";
            return false;
    }
    void push(const T &element)
    {
        cout << "Se inserto el elemento: "<< element << "\n";
        pila.push_back(element);
    }
    T top()
    {
        cout << "El primer elemento es: ";
        return pila.back();
    }
    void pop()
    {
        if(pila.empty())
            cout<<"Esta vacio el stack";
        else
            pila.pop_back();
    }
};
template <typename T>
T Min(T a, T b)
{
    if(a>b)
        return a;
    else
        return b;
}
template <typename T>
T Min2(T a, T b)
{
    return (a>b)?a:b;
}
main()
{
    /*int x = Min(1,2);
    int y = Min2(3,4);
    cout << x << " " << y;*/
    /*Stack <int> s;
    s.empty();
    s.push(1);
    s.empty();
    cout << s.top()<<"\n";
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.top()<<"\n";*/
    vector <int> start,end;
    start.push_back(1);
    start.push_back(1);
    start.push_back(1);
    start.push_back(5);
    start.push_back(5);
    start.push_back(4);
    end.push_back(2);
    end.push_back(3);
    end.push_back(4);
    end.push_back(4);
    end.push_back(2);
    end.push_back(2);
    Graph gr(start, end);
    cout<<"Start: ";
    for(int i = 0; i<start.size();i++)
        cout<<start[i]<<" ";
    cout<<"\n";
    cout<<"End:   ";
    for(int i = 0; i<start.size();i++)
        cout<<end[i]<<" ";
    cout<<"\n";
    cout << gr.numOutgoing(1) << std::endl;

}

