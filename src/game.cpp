#include "game.h"

struct BlockImpl: Game::BlockInterface {
	explicit BlockImpl(Game::BoardInterface *board, unsigned char row, unsigned char column) :
			m_board(board), m_row(row), m_column(column) {
	}
	virtual ~BlockImpl() {
//		std::cout << "destroy: BlockImpl [row: " << (int) m_row << ", column: " << (int) m_column << ", width: " << (int) m_board->width() << ", height: " << (int) m_board->height() << "]" << std::endl;
		std::cout << "destroy: BlockImpl [row: " << (int) m_row << ", column: " << (int) m_column << "]" << std::endl;
	}
	unsigned char row() {
		return m_row;
	}
	unsigned char column() {
		return m_column;
	}
private:
	Game::BoardInterface *m_board;
	unsigned char m_row;
	unsigned char m_column;
};

struct BoardImpl: public Game::BoardInterface {
	explicit BoardImpl(unsigned char width, unsigned char height) :
			m_width(width), m_height(height) {
		for (unsigned char column = 0; column < m_width; ++column) {
			for (unsigned char row = 0; row < m_height; ++row) {
				m_blocks.push_back(Game::Block(new BlockImpl(this, row, column)));
			}
		}
	}
	virtual ~BoardImpl() {
		std::cout << "destroy: BoardImpl" << std::endl;
	}
	unsigned char width() {
		return m_width;
	}
	unsigned char height() {
		return m_height;
	}
	Game::Blocks blocks() {
		return m_blocks;
	}
private:
	Game::Blocks m_blocks;
	unsigned char m_width;
	unsigned char m_height;
};

Game::Board Game::createBoard(unsigned char width, unsigned char height) {
	Game::Board result(new BoardImpl(width, height));
	return result;
}
