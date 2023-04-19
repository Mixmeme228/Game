#ifndef LIST_H
#define LIST_H
struct list
{
	int x;
	bool Car;
	list* next;
	list* prev;
};
class list1
{
public:
	list1();
	void addNode();
	list* Begin;
private:
};
extern list1 globallist;
#endif