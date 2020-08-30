#ifndef NODE_H
#define NODE_H
namespace Jogo{
	class Node{
	private:
		int x;
		int y;
		int peso;
	public:
		Node(int,int,int);
		~Node();
		int getX();
		int getY();
		int getPeso();
	};
}
#endif