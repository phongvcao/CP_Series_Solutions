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

class Cell {
public:

    static const char PEG;
    static const char HOLE;
    static const char INVALID;

    int num = -1;
    int row = -1;
    int col = -1;
    char status = INVALID;

    Cell() {
        // not implemented
    }

    Cell( const Cell& other )
        : num( other.num ),
          status( other.status ),
          row( other.row ),
          col( other.col )
    {
        // not implemented
    }

    virtual ~Cell() {
        // not implemented
    }
};

class Jump {
public:

    Cell * source = NULL;
    Cell * target = NULL;
    Cell * over = NULL;

    Jump( Cell * source, Cell * target, Cell * over )
        : source( source ),
          target( target ),
          over( over )
    {
        // not implemented
    }

    Jump( const Jump& other )
        : source( other.source ),
          target( other.target ),
          over( other.over )
    {
        // not implemented
    }

    virtual ~Jump() {
        // not implemented
    }

    bool isValid() const {
        return ( source->status == Cell::PEG && over->status == Cell::PEG && target->status == Cell::HOLE );
    }

    void commit() {
        // Commit the jump
        //   - Exchange source & target
        //   - Remove jump.over (Make it a HOLE)
        target->status = Cell::PEG;
        source->status = Cell::HOLE;
        over->status = Cell::HOLE;
    }

    friend bool operator <( const Jump& j1, const Jump& j2 ) {
        if ( j1.target->num < j2.target->num ) {
            return true;
        } else if ( j1.target->num > j2.target->num ) {
            return false;
        } else {
            if ( j1.source->num < j2.source->num ) {
                return true;
            } else if ( j1.source->num > j2.source->num ) {
                return false;
            } else {
                return false;
            }
        }
        return false;
    }

    friend bool operator >( const Jump& j1, const Jump& j2 ) {
        if ( j1.target->num > j2.target->num ) {
            return true;
        } else if ( j1.target->num < j2.target->num ) {
            return false;
        } else {
            if ( j1.source->num > j2.source->num ) {
                return true;
            } else if ( j1.source->num < j2.source->num ) {
                return false;
            } else {
                return false;
            }
        }
        return false;
    }

    friend bool operator ==( const Jump& j1, const Jump& j2 ) {
        return ( j1.target->num == j2.target->num && j1.source->num == j2.source->num );
    }

    friend bool operator !=( const Jump& j1, const Jump& j2 ) {
        return ! ( j1 == j2 );
    }

};

const char Cell::PEG = 'X';
const char Cell::HOLE = 'O';
const char Cell::INVALID = 'I';

int main( int argc, char ** argv ) {

    int N = 0;
    string line = "";
    stringstream ss( line );

    if ( getline( cin, line ) ) {
        ss.clear();
        ss.str( line );
        ss >> N;
    }

    cout << "HI Q OUTPUT" << endl;
    for ( int t = 0; t < N; t++ ) {
        int holeNum = -1;
        
        // Game begins

        // Construct game board
        vector< Cell > cellsVec( 33 );
        for ( int i = 0; i < cellsVec.size(); i++ ) {
            cellsVec[ i ].num = i;
            cellsVec[ i ].status = Cell::HOLE;
        }

        vector< vector< int > > board( 7, vector< int >( 7, -1 ) );

        int num = 0;
        for ( int i = 0; i < 2; i++ ) {
            for ( int j = 2; j < 5; j++ ) {
                cellsVec[ num ].row = i;
                cellsVec[ num ].col = j;
                board[ i ][ j ] = num++;
            }
        }

        for ( int i = 2; i < 5; i++ ) {
            for ( int j = 0; j < 7; j++ ) {
                cellsVec[ num ].row = i;
                cellsVec[ num ].col = j;
                board[ i ][ j ] = num++;
            }
        }

        for ( int i = 5; i < 7; i++ ) {
            for ( int j = 2; j < 5; j++ ) {
                cellsVec[ num ].row = i;
                cellsVec[ num ].col = j;
                board[ i ][ j ] = num++;
            }
        }

        int pegCount = 0;
        while ( true ) {
            while ( holeNum != 0 && ss >> holeNum ) {
                int holeIndex = holeNum - 1;
                if ( holeIndex > -1 ) {
                    if ( cellsVec[ holeIndex ].status != Cell::PEG ) {
                        ++pegCount;
                    }
                    cellsVec[ holeIndex ].status = Cell::PEG;
                }
            }

            if ( holeNum == 0 ) {
                break;
            }

            if ( getline( cin, line ) ) {
                ss.clear();
                ss.str( line );
            } else {
                break;
            }
        }

        if ( pegCount < 33 ) {
            priority_queue< Jump > jumpsMaxPQ;
            for ( int i = 0; i < cellsVec.size(); i++ ) {
                if ( cellsVec[ i ].status == Cell::PEG ) {
                    // Check adjacent cells to see if there's any adjacent pegs,
                    // and whether there are empty holes on the peg after the adjacent
                    // peg.
                    // If all these requirements are met, add new jump 
                    int row = cellsVec[ i ].row;
                    int col = cellsVec[ i ].col;

                    // Jump above
                    if ( row > 1 ) {
                        if ( board[ row - 1 ][ col ] != -1
                                && board[ row - 2 ][ col ] != -1
                                && cellsVec[ board[ row - 1 ][ col ] ].status == Cell::PEG
                                && cellsVec[ board[ row - 2 ][ col ] ].status == Cell::HOLE ) {
                            Jump newJump( &cellsVec[ i ],
                                    &cellsVec[ board[ row - 2 ][ col ] ],
                                    &cellsVec[ board[ row - 1 ][ col ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump below
                    if ( row < board.size() - 2 ) {
                        if ( board[ row + 1 ][ col ] != -1
                                && board[ row + 2 ][ col ] != -1
                                && cellsVec[ board[ row + 1 ][ col ] ].status == Cell::PEG
                                && cellsVec[ board[ row + 2 ][ col ] ].status == Cell::HOLE ) {
                            Jump newJump( &cellsVec[ i ],
                                    &cellsVec[ board[ row + 2 ][ col ] ],
                                    &cellsVec[ board[ row + 1 ][ col ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump left
                    if ( col > 1 ) {
                        if ( board[ row ][ col - 1 ] != -1
                                && board[ row ][ col - 2 ] != -1
                                && cellsVec[ board[ row ][ col - 1 ] ].status == Cell::PEG
                                && cellsVec[ board[ row ][ col - 2 ] ].status == Cell::HOLE ) {
                            Jump newJump( &cellsVec[ i ],
                                    &cellsVec[ board[ row ][ col - 2 ] ],
                                    &cellsVec[ board[ row ][ col - 1 ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump right
                    if ( col < board[ row ].size() - 2 ) {
                        if ( board[ row ][ col + 1 ] != -1
                                && board[ row ][ col + 2 ] != -1
                                && cellsVec[ board[ row ][ col + 1 ] ].status == Cell::PEG
                                && cellsVec[ board[ row ][ col + 2 ] ].status == Cell::HOLE ) {
                            Jump newJump( &cellsVec[ i ],
                                    &cellsVec[ board[ row ][ col + 2 ] ],
                                    &cellsVec[ board[ row ][ col + 1 ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }
                }
            }

            while ( ! jumpsMaxPQ.empty() ) {
                Jump jump = jumpsMaxPQ.top();
                jumpsMaxPQ.pop();
                // Commit the jump by:
                // - Checking if source & over & target are both valid (first 2 are PEG and the last is HOLE). If they are:
                //   - Exchange source & target
                //   - Remove jump.over (Make it a HOLE)
                //   - Re-calculate Jumps from target.
                //   - Re-calculate Jumps over target.
                //   - Re-calculate Jumps to over
                //   - Re-calculate Jumps to source

                if ( jump.isValid() ) {
                    jump.commit();

                    // Re-calculate jumps from target
                    int row = jump.target->row;
                    int col = jump.target->col;

                    // Jump above
                    if ( row > 1 ) {
                        if ( board[ row - 1 ][ col ] != -1
                                && board[ row - 2 ][ col ] != -1
                                && cellsVec[ board[ row - 1 ][ col ] ].status == Cell::PEG
                                && cellsVec[ board[ row - 2 ][ col ] ].status == Cell::HOLE ) {
                            Jump newJump( jump.target,
                                    &cellsVec[ board[ row - 2 ][ col ] ],
                                    &cellsVec[ board[ row - 1 ][ col ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump below
                    if ( row < board.size() - 2 ) {
                        if ( board[ row + 1 ][ col ] != -1
                                && board[ row + 2 ][ col ] != -1
                                && cellsVec[ board[ row + 1 ][ col ] ].status == Cell::PEG
                                && cellsVec[ board[ row + 2 ][ col ] ].status == Cell::HOLE ) {
                            Jump newJump( jump.target,
                                    &cellsVec[ board[ row + 2 ][ col ] ],
                                    &cellsVec[ board[ row + 1 ][ col ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump left
                    if ( col > 1 ) {
                        if ( board[ row ][ col - 1 ] != -1
                                && board[ row ][ col - 2 ] != -1
                                && cellsVec[ board[ row ][ col - 1 ] ].status == Cell::PEG
                                && cellsVec[ board[ row ][ col - 2 ] ].status == Cell::HOLE ) {
                            Jump newJump( jump.target,
                                    &cellsVec[ board[ row ][ col - 2 ] ],
                                    &cellsVec[ board[ row ][ col - 1 ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump right
                    if ( col < board[ row ].size() - 2 ) {
                        if ( board[ row ][ col + 1 ] != -1
                                && board[ row ][ col + 2 ] != -1
                                && cellsVec[ board[ row ][ col + 1 ] ].status == Cell::PEG
                                && cellsVec[ board[ row ][ col + 2 ] ].status == Cell::HOLE ) {
                            Jump newJump( jump.target,
                                    &cellsVec[ board[ row ][ col + 2 ] ],
                                    &cellsVec[ board[ row ][ col + 1 ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Re-calculate jump over target
                    row = jump.target->row;
                    col = jump.target->col;

                    // Jump from above to below
                    if ( row > 0 && row < board.size() - 1 ) {
                        if ( board[ row - 1 ][ col ] != -1
                                && board[ row + 1 ][ col ] != -1
                                && cellsVec[ board[ row - 1 ][ col ] ].status == Cell::PEG
                                && cellsVec[ board[ row + 1 ][ col ] ].status == Cell::HOLE ) {
                            Jump newJump( &cellsVec[ board[ row - 1 ][ col ] ],
                                    &cellsVec[ board[ row + 1 ][ col ] ],
                                    jump.target );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump from below to above
                    if ( row > 0 && row < board.size() - 1 ) {
                        if ( board[ row + 1 ][ col ] != -1
                                && board[ row - 1 ][ col ] != -1
                                && cellsVec[ board[ row + 1 ][ col ] ].status == Cell::PEG
                                && cellsVec[ board[ row - 1 ][ col ] ].status == Cell::HOLE ) {
                            Jump newJump( &cellsVec[ board[ row + 1 ][ col ] ],
                                    &cellsVec[ board[ row - 1 ][ col ] ],
                                    jump.target );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump from left to right
                    if ( col > 0 && col < board[ row ].size() - 1 ) {
                        if ( board[ row ][ col - 1 ] != -1
                                && board[ row ][ col + 1 ] != -1
                                && cellsVec[ board[ row ][ col - 1 ] ].status == Cell::PEG
                                && cellsVec[ board[ row ][ col + 1 ] ].status == Cell::HOLE ) {
                            Jump newJump( &cellsVec[ board[ row ][ col - 1 ] ],
                                    &cellsVec[ board[ row ][ col + 1 ] ],
                                    jump.target );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump from right to left
                    if ( col > 0 && col < board[ row ].size() - 1 ) {
                        if ( board[ row ][ col + 1 ] != -1
                                && board[ row ][ col - 1 ] != -1
                                && cellsVec[ board[ row ][ col + 1 ] ].status == Cell::PEG
                                && cellsVec[ board[ row ][ col - 1 ] ].status == Cell::HOLE ) {
                            Jump newJump( &cellsVec[ board[ row ][ col + 1 ] ],
                                    &cellsVec[ board[ row ][ col - 1 ] ],
                                    jump.target );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Re-calculate jumps to over
                    row = jump.over->row;
                    col = jump.over->col;

                    // Jump from above
                    if ( row > 1 ) {
                        if ( board[ row - 1 ][ col ] != -1
                                && board[ row - 2 ][ col ] != -1
                                && cellsVec[ board[ row - 1 ][ col ] ].status == Cell::PEG
                                && cellsVec[ board[ row - 2 ][ col ] ].status == Cell::PEG ) {
                            Jump newJump( &cellsVec[ board[ row - 2 ][ col ] ],
                                    &cellsVec[ board[ row ][ col ] ],
                                    &cellsVec[ board[ row - 1 ][ col ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump from below
                    if ( row < board.size() - 2 ) {
                        if ( board[ row + 1 ][ col ] != -1
                                && board[ row + 2 ][ col ] != -1
                                && cellsVec[ board[ row + 1 ][ col ] ].status == Cell::PEG
                                && cellsVec[ board[ row + 2 ][ col ] ].status == Cell::PEG ) {
                            Jump newJump( &cellsVec[ board[ row + 2 ][ col ] ],
                                    &cellsVec[ board[ row ][ col ] ],
                                    &cellsVec[ board[ row + 1 ][ col ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump from left
                    if ( col > 1 ) {
                        if ( board[ row ][ col - 1 ] != -1
                                && board[ row ][ col - 2 ] != -1
                                && cellsVec[ board[ row ][ col - 1 ] ].status == Cell::PEG
                                && cellsVec[ board[ row ][ col - 2 ] ].status == Cell::PEG ) {
                            Jump newJump( &cellsVec[ board[ row ][ col - 2 ] ],
                                    &cellsVec[ board[ row ][ col ] ],
                                    &cellsVec[ board[ row ][ col - 1 ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump from right
                    if ( col < board[ row ].size() - 2 ) {
                        if ( board[ row ][ col + 1 ] != -1
                                && board[ row ][ col + 2 ] != -1
                                && cellsVec[ board[ row ][ col + 1 ] ].status == Cell::PEG
                                && cellsVec[ board[ row ][ col + 2 ] ].status == Cell::PEG ) {
                            Jump newJump( &cellsVec[ board[ row ][ col + 2 ] ],
                                    &cellsVec[ board[ row ][ col ] ],
                                    &cellsVec[ board[ row ][ col + 1 ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Re-calculate jumps to source
                    row = jump.source->row;
                    col = jump.source->col;

                    // Jump from above
                    if ( row > 1 ) {
                        if ( board[ row - 1 ][ col ] != -1
                                && board[ row - 2 ][ col ] != -1
                                && cellsVec[ board[ row - 1 ][ col ] ].status == Cell::PEG
                                && cellsVec[ board[ row - 2 ][ col ] ].status == Cell::PEG ) {
                            Jump newJump( &cellsVec[ board[ row - 2 ][ col ] ],
                                    &cellsVec[ board[ row ][ col ] ],
                                    &cellsVec[ board[ row - 1 ][ col ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump from below
                    if ( row < board.size() - 2 ) {
                        if ( board[ row + 1 ][ col ] != -1
                                && board[ row + 2 ][ col ] != -1
                                && cellsVec[ board[ row + 1 ][ col ] ].status == Cell::PEG
                                && cellsVec[ board[ row + 2 ][ col ] ].status == Cell::PEG ) {
                            Jump newJump( &cellsVec[ board[ row + 2 ][ col ] ],
                                    &cellsVec[ board[ row ][ col ] ],
                                    &cellsVec[ board[ row + 1 ][ col ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump from left
                    if ( col > 1 ) {
                        if ( board[ row ][ col - 1 ] != -1
                                && board[ row ][ col - 2 ] != -1
                                && cellsVec[ board[ row ][ col - 1 ] ].status == Cell::PEG
                                && cellsVec[ board[ row ][ col - 2 ] ].status == Cell::PEG ) {
                            Jump newJump( &cellsVec[ board[ row ][ col - 2 ] ],
                                    &cellsVec[ board[ row ][ col ] ],
                                    &cellsVec[ board[ row ][ col - 1 ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }

                    // Jump from right
                    if ( col < board[ row ].size() - 2 ) {
                        if ( board[ row ][ col + 1 ] != -1
                                && board[ row ][ col + 2 ] != -1
                                && cellsVec[ board[ row ][ col + 1 ] ].status == Cell::PEG
                                && cellsVec[ board[ row ][ col + 2 ] ].status == Cell::PEG ) {
                            Jump newJump( &cellsVec[ board[ row ][ col + 2 ] ],
                                    &cellsVec[ board[ row ][ col ] ],
                                    &cellsVec[ board[ row ][ col + 1 ] ] );
                            jumpsMaxPQ.push( newJump );
                        }
                    }
                }
            }
        }

        int sum = 0;
        for ( int i = 0; i < cellsVec.size(); i++ ) {
            if ( cellsVec[ i ].status == Cell::PEG ) {
                sum += i + 1;
            }
        }
        cout << sum << endl;
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
