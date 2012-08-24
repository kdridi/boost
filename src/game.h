#ifndef GAME_H_
#define GAME_H_

#include <boost/shared_ptr.hpp>
#include <list>

struct Game {
	struct BlockInterface;
	struct BoardInterface;

	typedef boost::shared_ptr<BlockInterface> Block;
	typedef boost::shared_ptr<BoardInterface> Board;
	typedef std::list<Block> Blocks;
	typedef Blocks::iterator BlocksIterator;

	struct BlockInterface {
		virtual ~BlockInterface() {
			std::cout << "destroy: BlockInterface]" << std::endl;
		}
		virtual unsigned char row() = 0;
		virtual unsigned char column() = 0;
	};

	struct BoardInterface {
		virtual ~BoardInterface() {
			std::cout << "destroy: BoardInterface]" << std::endl;
		}
		virtual unsigned char width() = 0;
		virtual unsigned char height() = 0;
		virtual Blocks blocks() = 0;
	};

	static Board createBoard(unsigned char width, unsigned char height);
};

#endif /* GAME_H_ */
