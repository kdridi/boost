#include <stdlib.h>
#include <iostream>

#include "puzzly.h"
#include "game.h"

int main() {
	if (true) {
		Game::Block block;
		{
			Game::Board board = Game::createBoard(1, 1);
			block = *(board->blocks().begin());
		}
	} else {
		BoardConfiguration *configuration = BoardConfiguration::GetInstance()->SetWidth(3)->SetHeight(5);
		std::cout << "########################################" << std::endl;
		{
			Board board = configuration->BuildBoard();
			std::cout << "width: 3 = " << board->GetWidth() << std::endl;
			std::cout << "height: 5 = " << board->GetHeight() << std::endl;
			std::cout << "BlocksForValue.size:  0 = " << board->GetBlocksForValue(1).size() << std::endl;
			std::cout << "BlocksForValue.size: 15 = " << board->GetBlocksForValue(0).size() << std::endl;
			std::cout << "BlocksForColor.size:  0 = " << board->GetBlocksForColor(1).size() << std::endl;
			std::cout << "BlocksForColor.size: 15 = " << board->GetBlocksForColor(0).size() << std::endl;
			std::cout << "BlocksForColumn.size: 5 = " << board->GetBlocksForColumn(0).size() << std::endl;
			std::cout << "BlocksForColumn.size: 0 = " << board->GetBlocksForColumn(10).size() << std::endl;
			std::cout << "BlocksForRow.size: 3 = " << board->GetBlocksForRow(0).size() << std::endl;
			std::cout << "BlocksForRow.size: 0 = " << board->GetBlocksForRow(10).size() << std::endl;
			std::cout << "# By row" << std::endl;
			for (unsigned int row = 0; row < board->GetHeight(); row++) {
				std::list<BoardBlock> blocks = board->GetBlocksForRow(row);
				for (std::list<BoardBlock>::iterator it = blocks.begin(); it != blocks.end(); ++it) {
					BoardBlock block = *it;
					std::cout << "row = " << block->getRow() << ", ";
					std::cout << "column = " << block->getColumn() << ", ";
					std::cout << "neighbors = " << block->GetNeighborBlocks().size() << std::endl;
				}
				std::cout << std::endl;
			}
			std::cout << "# By column" << std::endl;
			for (unsigned int column = 0; column < board->GetWidth(); column++) {
				std::list<BoardBlock> blocks = board->GetBlocksForColumn(column);
				for (std::list<BoardBlock>::iterator it = blocks.begin(); it != blocks.end(); ++it) {
					BoardBlock block = *it;
					std::cout << "row = " << block->getRow() << ", ";
					std::cout << "column = " << block->getColumn() << ", ";
					std::cout << "neighbors = " << block->GetNeighborBlocks().size() << std::endl;
				}
				std::cout << std::endl;
			}
		}
		std::cout << "########################################" << std::endl;
	}

	return EXIT_SUCCESS;
}
