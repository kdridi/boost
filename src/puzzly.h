#ifndef PUZZLY_H_
#define PUZZLY_H_

#include <list>
#include <boost/shared_ptr.hpp>

class BoardBlockInterface;
typedef boost::shared_ptr<BoardBlockInterface> BoardBlock;

class BoardBlockInterface {
public:
	virtual ~BoardBlockInterface() {
		std::cout << "destroy: BoardBlockInterface" << std::endl;
	}
	virtual unsigned int getRow() = 0;
	virtual unsigned int getColumn() = 0;
	virtual unsigned int *getValue() = 0;
	virtual unsigned int *getColor() = 0;
	virtual std::list<BoardBlock> GetNeighborBlocks() = 0;
};

class BoardInterface;
typedef boost::shared_ptr<BoardInterface> Board;

class BoardInterface {
public:
	virtual ~BoardInterface() {
		std::cout << "destroy: BoardInterface" << std::endl;
	}
	virtual unsigned int GetWidth() = 0;
	virtual unsigned int GetHeight() = 0;
	virtual std::list<BoardBlock> GetBlocksForValue(unsigned int value) = 0;
	virtual std::list<BoardBlock> GetBlocksForColor(unsigned int color) = 0;
	virtual std::list<BoardBlock> GetBlocksForRow(unsigned int row) = 0;
	virtual std::list<BoardBlock> GetBlocksForColumn(unsigned int column) = 0;
	virtual std::list<BoardBlock> GetBlocksAroundRowAndColumn(unsigned int row, unsigned int column) = 0;
};

class BoardConfiguration {
public:
	static BoardConfiguration *GetInstance();
	virtual ~BoardConfiguration() {
		std::cout << "destroy: BoardConfiguration" << std::endl;
	}
	virtual BoardConfiguration *SetWidth(unsigned int width) = 0;
	virtual BoardConfiguration *SetHeight(unsigned int heigth) = 0;
	virtual Board BuildBoard() = 0;

};

#endif /* PUZZLY_H_ */
