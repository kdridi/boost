#include "puzzly.h"

////////////////////////////////////////////////////////////////////////////////
// BOARD BLOCK
////////////////////////////////////////////////////////////////////////////////
class BoardBlockImpl: public BoardBlockInterface {
private:
	BoardInterface *m_board;
	unsigned int m_row;
	unsigned int m_column;
	unsigned int m_value;
	unsigned int m_color;
public:
	BoardBlockImpl(BoardInterface *board, unsigned int row, unsigned int column) :
			m_board(board), m_row(row), m_column(column), m_value(0), m_color(0) {
	}
	virtual ~BoardBlockImpl() {
		std::cout << "destroy: BoardBlockImpl[row: " << m_row << ", column: " << m_column << "]" << std::endl;
	}
	unsigned int getRow() {
		return m_row;
	}
	unsigned int getColumn() {
		return m_column;
	}
	unsigned int *getValue() {
		return &m_value;
	}
	unsigned int *getColor() {
		return &m_color;
	}
	virtual std::list<BoardBlock> GetNeighborBlocks() {
		return m_board->GetBlocksAroundRowAndColumn(m_row, m_column);
	}
};

////////////////////////////////////////////////////////////////////////////////
// BOARD
////////////////////////////////////////////////////////////////////////////////
class BoardImpl: public BoardInterface {
private:
	unsigned int m_width;
	unsigned int m_height;
	std::list<BoardBlock> m_blocks;
public:
	BoardImpl(unsigned int width, unsigned int height) :
			m_width(width), m_height(height) {
		for (unsigned int row = 0; row < m_height; ++row) {
			for (unsigned int column = 0; column < m_width; ++column) {
				m_blocks.push_back(BoardBlock(new BoardBlockImpl(this, row, column)));
			}
		}
	}
	virtual ~BoardImpl() {
		std::cout << "destroy: BoardImpl" << std::endl;
	}
	unsigned int GetWidth() {
		return m_width;
	}
	unsigned int GetHeight() {
		return m_height;
	}
	virtual std::list<BoardBlock> GetBlocksForValue(unsigned int value) {
		std::list<BoardBlock> result;
		for (std::list<BoardBlock>::iterator it = m_blocks.begin(); it != m_blocks.end(); ++it) {
			if (*((*it)->getValue()) == value) {
				result.push_back(*it);
			}
		}
		return result;
	}
	virtual std::list<BoardBlock> GetBlocksForColor(unsigned int color) {
		std::list<BoardBlock> result;
		for (std::list<BoardBlock>::iterator it = m_blocks.begin(); it != m_blocks.end(); ++it) {
			if (*((*it)->getColor()) == color) {
				result.push_back(*it);
			}
		}
		return result;
	}
	virtual std::list<BoardBlock> GetBlocksForRow(unsigned int row) {
		std::list<BoardBlock> result;
		for (std::list<BoardBlock>::iterator it = m_blocks.begin(); it != m_blocks.end(); ++it) {
			if ((*it)->getRow() == row) {
				result.push_back(*it);
			}
		}
		return result;
	}
	virtual std::list<BoardBlock> GetBlocksForColumn(unsigned int column) {
		std::list<BoardBlock> result;
		for (std::list<BoardBlock>::iterator it = m_blocks.begin(); it != m_blocks.end(); ++it) {
			if ((*it)->getColumn() == column) {
				result.push_back(*it);
			}
		}
		return result;
	}
	virtual std::list<BoardBlock> GetBlocksAroundRowAndColumn(unsigned int row, unsigned int column) {
		std::list<BoardBlock> result;
		for (std::list<BoardBlock>::iterator it = m_blocks.begin(); it != m_blocks.end(); ++it) {
			BoardBlock block = *it;
			if (abs(block->getColumn() - column) == 1 && abs(block->getRow() - row) <= 1) {
				result.push_back(block);
			} else if (abs(block->getRow() - row) == 1 && abs(block->getColumn() - column) <= 1) {
				result.push_back(block);
			}
		}
		return result;
	}
};

////////////////////////////////////////////////////////////////////////////////
// BOARD CONFIGURATION
////////////////////////////////////////////////////////////////////////////////
class BoardConfigurationImpl: public BoardConfiguration {
private:
	unsigned int m_width;
	unsigned int m_height;
public:
	BoardConfigurationImpl() :
			m_width(8), m_height(8) {
	}
	virtual ~BoardConfigurationImpl() {
		std::cout << "destroy: BoardConfigurationImpl" << std::endl;
	}
	BoardConfiguration *SetWidth(unsigned int width) {
		m_width = width;
		return this;
	}
	BoardConfiguration *SetHeight(unsigned int heigth) {
		m_height = heigth;
		return this;
	}
	Board BuildBoard() {
		return Board(new BoardImpl(m_width, m_height));
	}
};

BoardConfiguration *BoardConfiguration::GetInstance() {
	static BoardConfigurationImpl configuration;
	return &configuration;
}
