#include<iostream>
#include<list>//cpp reference list
using namespace std;
// 0-----1
// |    /| \ 
// |  /  |   2
// | /   | /
// 4-----3
// (0,1)-->(bidirectional),(1,2),(2,3),(1,3),(1,4),(4,3),(0,4)
// (u,v)
class Graph{
	public:
		// pointer address of array->list
		list<int> *l;//yaha par header file use ki hain toh dena pdega ki kis datatype ki list create krna chahate ho
		int n;
		//constructor
		Graph(int N){
			n=N;
			l=new list<int>[N];
		}
		// adding edge
		void add_edge(int u,int v,int bidirectional=true){
			l[u].push_back(v);
			if(bidirectional){
				l[v].push_back(u);
			}
		}
		void print(){
			for(int i=0;i<n;i++){
				cout<<i<<"-->";
				for(auto n:l[i]){
					cout<<n<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
};
 int main(){
	int no_of_node,no_of_edge;
	cin>>no_of_node>>no_of_edge;
	Graph g(no_of_node);
	for(int i=0;i<no_of_edge;i++){
		int u,v;
		cin>>u>>v;
		g.add_edge(u,v);
	}
	g.print();
	return 0;
}