//
// Created by Phong Cao.
//

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <ios>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <forward_list>
#include <deque>
#include <queue>
#include <stack>
#include <tuple>
#include <iterator>
#include <utility>
#include <algorithm>
#include <memory>
#include <cctype>
#include <stdexcept>
#include <limits>
#include <numeric>

//----< iostream >--------------//
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

//----< cstdio >----------------//
using std::printf;
using std::fprintf;
using std::sprintf;
using std::snprintf;

//----< iomanip >---------------//
using std::setprecision;
using std::setw;

//----< ios >-------------------//
using std::hex;
using std::dec;
using std::oct;
using std::fixed;

//----< sstream >---------------//
using std::stringstream;
using std::ostringstream;
using std::istringstream;

//----< fstream >---------------//
using std::ofstream;
using std::ifstream;

//----< string >----------------//
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;

//----< cmath >-----------------//
using std::sqrt;
using std::pow;
using std::log;                 // log( <arg> )
using std::exp;                 // e ^ <arg>
using std::abs;
using std::floor;               // Round down to nearest integer double
using std::ceil;                // Round up to nearest integer double
using std::trunc;               // Truncate the fractional part to get the integer part
using std::round;               // Round to nearest integer double

//----< cstdlib >---------------//
using std::rand;
using std::srand;

//----< ctime >-----------------//
using std::time;

//----< functional >------------//
using std::hash;
using std::greater;             // lhs > rhs. Used for MinPQ
using std::less;                // lhs < rhs. Used for MaxPQ. Default for priority_queue<>
using std::less_equal;
using std::greater_equal;

//----< array >-----------------//
using std::array;               // Fixed & Unordered Array

//----< vector >----------------//
using std::vector;              // Resizable & Unordered Array

//----< map >-------------------//
using std::map;                 // Ordered Map (Red-Black Tree)
using std::multimap;            // Ordered Map (Red-Black Tree) & Allow duplicated keys

//----< unordered_map >---------//
using std::unordered_map;       // HashMap (SeparateChainingHashST)
using std::unordered_multimap;  // Ordered Map (Red-Black Tree) & Allow duplicated keys

//----< set >-------------------//
using std::set;                 // Ordered Set (Red-Black Tree)
using std::multiset;            // Ordered Set (Red-Black Tree) & Allow duplicated keys

//----< unordered_set >---------//
using std::unordered_set;       // HashSet (SeparateChainingHashST)
using std::unordered_multiset;  // HashSet (SeparateChainingHashST) & Allow duplicated keys

//----< list >------------------//
using std::list;                // Doubly-Linked List with size() ( O( 1 ) )

//----< forward_list >----------//
using std::forward_list;        // Singly-Linked List without size() function ( so O( N ) if we need to get size() )

//----< deque >-----------------//
using std::deque;               // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque

//----< queue >-----------------//
using std::queue;               // Non-Iterable & Use std::deque as underlying data structure
using std::priority_queue;      // MaxPQ (MaxHeap) & Non-Iterable.
//                              // => Pass std::greater<> as template params to create MinPQ (MinHeap)

//----< stack >-----------------//
using std::stack;               // Non-Iterable & Use std::deque as underlying data structure

//----< tuple >-----------------//
using std::tuple;               // Non-Iterable & Use std::pair as underlying data structure
using std::get;                 // Access & Set element in tuple using get< index >( tuple_var )

//----< iterator >--------------//
using std::next;                // Return an advanced iter without changing original iter
using std::prev;                // Return an decremented iter without changing original iter
using std::distance;            // Calculate distance between 2 iterators

//----< utility >---------------//
using std::pair;
using std::make_pair;
using std::move;                // Move resources between objects - typically used with std::unique_ptr<T>

//----< algorithm >-------------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;
using std::remove;
using std::swap;

//----< memory >----------------//
// using std::make_unique;
using std::unique_ptr;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

//----< cctype >----------------//
using std::isalnum;
using std::isalpha;
using std::islower;
using std::isupper;
using std::isdigit;
using std::isspace;             // Check whether char is whitespace character (space, newline, tab, etc. )
using std::isblank;             // Check whether char is blank character ( space or tab )
using std::tolower;
using std::toupper;

//----< stdexcept >-------------//
using std::runtime_error;
using std::invalid_argument;
using std::out_of_range;

//----< limits >----------------//
using std::numeric_limits;

//----< numeric >---------------//
using std::iota;
// using std::gcd;
// using std::lcm;

//------------------------------//

namespace Othello {

    class Square {
    public:
        static const char COLOR_EMPTY;
        static const char COLOR_BLACK;
        static const char COLOR_WHITE;

        int row = 0;
        int col = 0;
        char color = '-';

        Square() {
            // not implemented
        }

        Square( const Square& other )
            : row( other.row ),
              col( other.col ),
              color( other.color )
        {
            // not implemented
        }

        Square( int row, int col, char color = '-' )
            : row( row ),
              col( col ),
              color( color )
        {
            // not implemented
        }

        virtual ~Square() {
            // not implemented
        }

        void move( char color ) {
            this->color = color;
        }

        void flipColor() {
            if ( color == COLOR_BLACK ) {
                color = COLOR_WHITE;
            } else if ( color == COLOR_WHITE ) {
                color = COLOR_BLACK;
            }
        }

        friend bool operator <( const Square& s1, const Square& s2 ) {
            if ( s1.row < s2.row ) {
                return true;
            } else if ( s1.row > s2.row ) {
                return false;
            } else {
                if ( s1.col < s2.col ) {
                    return true;
                } else if ( s1.col > s2.col ) {
                    return false;
                } else {
                    return false;
                }
            }
        }

        friend bool operator ==( const Square& s1, const Square& s2 ) {
            return ( s1.row == s2.row && s1.col == s2.col );
        }
        
        friend bool operator !=( const Square& s1, const Square& s2 ) {
            return ! ( s1 == s2 );
        }
    };

    class Board {
    public:
        vector< vector< Square > > squaresVec;
        unordered_map< char, int > squaresCount;

        Board()
            : squaresVec( 8, vector< Square >( 8 ) ),
              squaresCount( { { '-', 0 }, { 'B', 0 }, { 'W', 0 } } )
        {
            for ( int i = 0; i < squaresVec.size(); i++ ) {
                for ( int j = 0; j < squaresVec[ i ].size(); j++ ) {
                    squaresVec[ i ][ j ].row = i;
                    squaresVec[ i ][ j ].col = j;
                }
            }
        }

        virtual ~Board() {
            // not implemented
        }

        void addSquare( int row, int col, char color = Square::COLOR_EMPTY ) {
            --squaresCount[ squaresVec[ row ][ col ].color ];
            squaresVec[ row ][ col ].color = color;
            ++squaresCount[ squaresVec[ row ][ col ].color ];
        }

        int getColorCount( char color = Square::COLOR_EMPTY ) {
            return squaresCount[ color ];
        }

        unordered_map< char, set< Square > > getSurroundSquares( int row, int col ) const {
            unordered_map< char, set< Square > > rvMap;
            rvMap.insert( { Square::COLOR_EMPTY, set< Square >() } );
            rvMap.insert( { Square::COLOR_BLACK, set< Square >() } );
            rvMap.insert( { Square::COLOR_WHITE, set< Square >() } );

            if ( row > 0 ) {
                rvMap[ squaresVec[ row - 1 ][ col ].color ].insert( squaresVec[ row - 1 ][ col ] );

                if ( col > 0 ) {
                    rvMap[ squaresVec[ row - 1 ][ col - 1 ].color ].insert( squaresVec[ row - 1 ][ col - 1 ] );
                }

                if ( col < squaresVec[ row - 1 ].size() - 1 ) {
                    rvMap[ squaresVec[ row - 1 ][ col + 1 ].color ].insert( squaresVec[ row - 1 ][ col + 1 ] );
                }
            }

            if ( col > 0 ) {
                rvMap[ squaresVec[ row ][ col - 1 ].color ].insert( squaresVec[ row ][ col - 1 ] );
            }

            if ( col < squaresVec[ row ].size() - 1 ) {
                rvMap[ squaresVec[ row ][ col + 1 ].color ].insert( squaresVec[ row ][ col + 1 ] );
            }

            if ( row < squaresVec.size() - 1 ) {
                rvMap[ squaresVec[ row + 1 ][ col ].color ].insert( squaresVec[ row + 1 ][ col ] );

                if ( col > 0 ) {
                    rvMap[ squaresVec[ row + 1 ][ col - 1 ].color ].insert( squaresVec[ row + 1 ][ col - 1 ] );
                }

                if ( col < squaresVec[ row + 1 ].size() - 1 ) {
                    rvMap[ squaresVec[ row + 1 ][ col + 1 ].color ].insert( squaresVec[ row + 1 ][ col + 1 ] );
                }
            }

            return rvMap;
        }

        bool move( int row, int col, char color = Square::COLOR_EMPTY ) {
            // Change the color of the square to the new color
            --squaresCount[ squaresVec[ row ][ col ].color ];
            squaresVec[ row ][ col ].move( color );
            ++squaresCount[ squaresVec[ row ][ col ].color ];

            // Look around ( row, col ) for non-empty square with different
            // colors.
            // If there's an adjacent square with different color, crawl on that
            // side till:
            // ( 1 ) Seeing a square of same color with ( row, col ),
            // in which case we should flipColor() of all squares in-between
            // ( 2 ) Seeing an empty square, in which we would break
            unordered_map< char, set< Square > > surroundMap = getSurroundSquares( row, col );
            char colorToFlip = color == Square::COLOR_BLACK ? Square::COLOR_WHITE : Square::COLOR_BLACK;
            bool moveMade = false;
            for ( const Square & sq : surroundMap[ colorToFlip ] ) {
                vector< Square * > squaresToFlip;
                // Check which direction is this square
                int stepRow = sq.row - row;
                int stepCol = sq.col - col;
                int curRow = sq.row;
                int curCol = sq.col;

                while ( curRow >= 0
                        && curCol >= 0
                        && curRow <= squaresVec.size() - 1
                        && curCol <= squaresVec[ curRow ].size() - 1
                        && squaresVec[ curRow ][ curCol ].color == colorToFlip ) {
                    squaresToFlip.push_back( &squaresVec[ curRow ][ curCol ] );
                    curRow += stepRow;
                    curCol += stepCol;
                }

                if ( curRow >= 0
                        && curCol >= 0
                        && curRow <= squaresVec.size() - 1
                        && curCol <= squaresVec[ curRow ].size() - 1
                        && squaresVec[ curRow ][ curCol ].color == color ) {
                    for ( int i = 0; i < squaresToFlip.size(); i++ ) {
                        --squaresCount[ squaresToFlip[ i ]->color ];
                        squaresToFlip[ i ]->color = color;
                        ++squaresCount[ squaresToFlip[ i ]->color ];
                        moveMade = true;
                    }
                }
            }

            return moveMade;
        }

        set< Square > getLegalMoves( char color = Square::COLOR_EMPTY ) const {
            // Loop through all squares and get the empty squares surrounding
            // and check whether that square is a legal move
            set< Square > rvSet;
            for ( const vector< Square >& sqVec : squaresVec ) {
                for ( const Square & emptySq : sqVec ) {
                    if ( emptySq.color != Square::COLOR_EMPTY ) continue;
                    unordered_map< char, set< Square > > surroundMap = getSurroundSquares( emptySq.row, emptySq.col );
                    char colorToSearch = color == Square::COLOR_BLACK ? Square::COLOR_WHITE : Square::COLOR_BLACK;
                    for ( const Square & sq : surroundMap[ colorToSearch ] ) {
                        int stepRow = sq.row - emptySq.row;
                        int stepCol = sq.col - emptySq.col;
                        int curRow = sq.row;
                        int curCol = sq.col;

                        while ( curRow >= 0
                                && curCol >= 0
                                && curRow <= squaresVec.size() - 1
                                && curCol <= squaresVec[ curRow ].size() - 1
                                && squaresVec[ curRow ][ curCol ].color == colorToSearch ) {
                            curRow += stepRow;
                            curCol += stepCol;
                        }

                        if ( curRow >= 0
                                && curCol >= 0
                                && curRow <= squaresVec.size() - 1
                                && curCol <= squaresVec[ curRow ].size() - 1
                                && squaresVec[ curRow ][ curCol ].color == color ) {
                            rvSet.insert( emptySq );
                        }
                    }

                }
            }
            return rvSet;
        }

        friend ostream& operator <<( ostream& out, const Board& board ) {
            for ( int i = 0; i < board.squaresVec.size(); i++ ) {
                for ( int j = 0; j < board.squaresVec[ i ].size(); j++ ) {
                    cout << board.squaresVec[ i ][ j ].color;
                }
                cout << endl;
            }
            return out;
        }
    };
};

const char Othello::Square::COLOR_EMPTY = '-';
const char Othello::Square::COLOR_BLACK = 'B';
const char Othello::Square::COLOR_WHITE = 'W';

int main( int argc, char ** argv ) {

    string line = "";
    int T = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> T;
    }

    int N = 8;
    for ( int t = 0; t < T; t++ ) {
        Othello::Board gameBoard;

        for ( int i = 0; i < N; i++ ) {
            if ( getline( cin, line ) ) {
                for ( int j = 0; j < line.size(); j++ ) {
                    gameBoard.addSquare( i, j, line[ j ] );
                }
            }
        }

        char curPlayer = 'W';
        if ( getline( cin, line ) ) {
            curPlayer = line[ 0 ];
        }

        while ( getline( cin, line ) ) {
            if ( line == "Q" ) {
                cout << gameBoard;
                if ( t < T - 1 ) {
                    cout << endl;
                }
                break;
            }

            stringstream ss( line );
            char command = 'Q';
            int row = -1;
            int col = -1;
            command = line[ 0 ];
            if ( line.size() > 1 ) {
                row = line[ 1 ] - '0';
                col = line[ 2 ] - '0';
            }

            switch ( command ) {
                case 'L':
                {
                    set< Othello::Square > legalMovesSet = gameBoard.getLegalMoves( curPlayer );
                    if ( legalMovesSet.empty() ) {
                        cout << "No legal move." << endl;
                    } else {
                        int idx = 0;
                        for ( const Othello::Square & sq : legalMovesSet ) {
                            cout << "(" << sq.row + 1 << "," << sq.col + 1 << ")";
                            if ( idx < legalMovesSet.size() - 1 ) {
                                cout << " ";
                            }
                            ++idx;
                        }
                        cout << endl;
                    }
                    break;
                }

                case 'M':
                {
                    if ( ! gameBoard.move( row - 1, col - 1, curPlayer ) ) {
                        curPlayer = curPlayer == 'W' ? 'B' : 'W';
                        gameBoard.move( row - 1, col - 1, curPlayer );
                    }
                    curPlayer = curPlayer == 'W' ? 'B' : 'W';
                    printf( "Black - %2d White - %2d\n",
                            gameBoard.getColorCount( 'B' ),
                            gameBoard.getColorCount( 'W' ) );
                    break;
                }

                default:
                {
                    break;
                }
            }
        }
    }

    return 0;
}
