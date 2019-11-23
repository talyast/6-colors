#pragma once
#include "Players.h"
#include "Shapes.h"
class Computer:public Players
{
public:
	Computer(Shapes*shape);
	~Computer();
	//checks the color that increases the area the most
	void doTurn(colors color, colors c) override;
	//colors the area with the chosen color
	void updateArea(colors color);
	//finds the color that increses the most
	void findLargestArea(int arr[]);
	//runs through neighbors of neighbors to insert into m_area
	void checkNeighborInsert(Shapes* it, colors color);
	//runs through neighbors of neighbors to find the best color
	virtual void checkNeighbor(Shapes* it, colors color) override;
	virtual colors getLastColor()const override { return last_color; };
	//number symbolyzes an enum
	colors convertIndexToColor(int i) const ;
	
private:
	std::unordered_set<Shapes*> m_temp;
	colors last_color =WHITE ;
	bool next;
	int arr[6];
};

