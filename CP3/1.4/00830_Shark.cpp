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
using std::fabs;
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
using std::inserter;            // Insert element into first arg starting from position in second arg

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
using std::sort;                // Intro-Sort elements, but NOT preserve original order of equal elements
using std::partial_sort;        // Sort elements in range ( iterFirst, iterLast ) ( exclusively )
using std::stable_sort;         // Merge-Sort elements & preserve original order of equal elements
using std::remove;
using std::swap;
using std::binary_search;
using std::next_permutation;
using std::set_intersection;    // Only works on std::set and not std::unordered_set
using std::set_difference;      // Only works on std::set and not std::unordered_set
using std::set_union;
// using std::nth_element;

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

    static const char CELL_EMPTY;

    int row = -1;
    int col = -1;
    int fishIndex = -1;
    int index = -1;
    char value = CELL_EMPTY;

    Cell() {
        // not implemented
    }

    Cell( const Cell& other )
        : row( other.row ),
          col( other.col ),
          value( other.value ),
          fishIndex( other.fishIndex ),
          index( other.index )
    {
        // not implemented
    }

    virtual ~Cell() {
        // not implemented
    }

};

struct cmpCellsByPosition {
    bool operator ()( const Cell* c1, const Cell* c2 ) const {
        if ( c1->row < c2->row ) {
            return true;
        } else if ( c1->row > c2->row ) {
            return false;
        } else {
            if ( c1->col < c2->col ) {
                return true;
            } else {
                return c1->index < c2->index;
            }
        }
    }
};

const char Cell::CELL_EMPTY = '.';

class Fish {
public:

    static const int FISH_UNKNOWN = -1;

    static const int FISH_SARDINE = 0;
    static const int FISH_MACKEREL = 1;
    static const int FISH_SALMON = 2;
    static const int FISH_GROUPER = 3;
    static const int FISH_TURTLE = 4;
    static const int FISH_DOLPHIN = 5;
    static const int FISH_WHALE = 6;
    static const int FISH_SHARK = 7;
    
    int index = -1;
    set< Cell*, cmpCellsByPosition > cellsPtrSet;

    Fish() {
        // not implemented
    }

    Fish( const Fish& other )
        : index( other.index ),
          cellsPtrSet( other.cellsPtrSet )
    {
        // not implemented
    }

    virtual ~Fish() {
        // not implemented
    }

    int getFishType() const {
        if ( cellsPtrSet.size() == 1 ) {
            // Single-square are SARDINE
            return FISH_SARDINE;
        } else if ( cellsPtrSet.size() == 2 ) {
            // Double-square are MACKEREL
            return FISH_MACKEREL;
        } else {
            int minRow = numeric_limits< int >::max();
            int minCol = numeric_limits< int >::max();
            int maxRow = numeric_limits< int >::min();
            int maxCol = numeric_limits< int >::min();
            for ( const Cell * cellPtr : cellsPtrSet ) {
                if ( cellPtr->row < minRow ) {
                    minRow = cellPtr->row;
                }

                if ( cellPtr->col < minCol ) {
                    minCol = cellPtr->col;
                }

                if ( cellPtr->row > maxRow ) {
                    maxRow = cellPtr->row;
                }

                if ( cellPtr->col > maxCol ) {
                    maxCol = cellPtr->col;
                }
            }

            // Single-square Width are SALMON
            if ( maxRow - minRow == 0 || maxCol - minCol == 0 ) {
                return FISH_SALMON;
            }

            // Rectangular with width 4 and length greater than 4 are WHALE
            if ( ( maxRow - minRow == 3 && maxCol - minCol > 3 )
                    || ( maxCol - minCol == 3 && maxRow - minRow > 3 ) ) {
                return FISH_WHALE;
            }

            // TURTLE, DOLPHIN, GROUPER, SHARK can be messed up
            if ( ( maxRow - minRow + 1 ) * ( maxCol - minCol + 1 ) != cellsPtrSet.size() ) {
                // SHARK has odd tail
                return FISH_SHARK;
            }

            if ( maxRow - minRow == maxCol - minCol ) {
                // TURTLE: Square animals larger than sardines
                return FISH_TURTLE;
            }

            if ( ( maxRow - minRow == 1 ) || ( maxCol - minCol == 1 ) ) {
                // GROUPER: Rectangular with width 2 and length greater than 2
                return FISH_GROUPER;
            }

            if ( ( maxRow - minRow == 2 ) || ( maxCol - minCol == 2 ) ) {
                // DOLPHIN: Rectangular with width 3 and length greater than 3
                return FISH_DOLPHIN;
            }
        }
        return FISH_UNKNOWN;
    }

    friend ostream& operator <<( ostream& out, const Fish& fish ) {
        out << " | fishType : " << fish.getFishType() << " ; ";
        for ( const Cell* cellPtr : fish.cellsPtrSet ) {
            out << cellPtr->value << ", ";
        }
        out << " | ";
        return out;
    }
};

int main( int argc, char ** argv ) {

    string line = "";
    int N = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> N;
    }

    for ( int n = 0; n < N; n++ ) {
        int rowCount = 0;
        int colCount = 0;
        while ( getline( cin, line ) ) {
            if ( line.empty() ) continue;
            stringstream ss( line );
            ss >> rowCount >> colCount;
            break;
        }

        vector< vector< Cell > > gridVec( rowCount, vector< Cell >( colCount ) );

        for ( int i = 0; i < rowCount; i++ ) {
            if ( getline( cin, line ) ) {
                if ( line.empty() ) {
                    --i;
                    continue;
                }
                if ( line.size() != colCount ) gridVec[ i ].resize( line.size() );
                for ( int j = 0; j < line.size(); j++ ) {
                    gridVec[ i ][ j ].row = i;
                    gridVec[ i ][ j ].col = j;
                    gridVec[ i ][ j ].value = line[ j ];
                    gridVec[ i ][ j ].index = i * line.size() + j;
                }
            }
        }

        // Evaluate the case
        // First find out the list of fishes
        vector< Fish > fishesVec;
        for ( int i = 0; i < rowCount; i++ ) {
            for ( int j = 0; j < colCount; j++ ) {
                if ( gridVec[ i ][ j ].value == Cell::CELL_EMPTY ) continue;
                //
                // Check adjacent cells
                // - If the adjacent cell have same letters
                //   - Push pointer to adjacent cells to a vector
                //     ( During this time, find fishIndex )
                // - Push the pointer to current cell to a vector
                //   ( During this step, find fishIndex )
                // - If fishIndex == -1
                //   - Add new fish
                //   - Set fishIndex to this new index
                // - Now loop through the vector of all adjacent cells and
                // current cell and add them all to cellsPtrSet of the respective
                // fishIndex.
                //
                vector< Cell * > cellsPtrVec;
                Cell * curCellPtr = &gridVec[ i ][ j ];
                cellsPtrVec.push_back( curCellPtr );
                if ( i > 0 && curCellPtr->value == gridVec[ i - 1 ][ j ].value ) {
                    // gridVec[ i - 1 ][ j ]
                    cellsPtrVec.push_back( &gridVec[ i - 1 ][ j ] );
                }

                if ( j > 0 && curCellPtr->value == gridVec[ i ][ j - 1 ].value ) {
                    // gridVec[ i ][ j - 1 ]
                    cellsPtrVec.push_back( &gridVec[ i ][ j - 1 ] );
                }

                if ( i < rowCount - 1 && curCellPtr->value == gridVec[ i + 1 ][ j ].value ) {
                    // gridVec[ i + 1 ][ j ]
                    cellsPtrVec.push_back( &gridVec[ i + 1 ][ j ] );
                }

                if ( j < colCount - 1 && curCellPtr->value == gridVec[ i ][ j + 1 ].value ) {
                    // gridVec[ i ][ j + 1 ]
                    cellsPtrVec.push_back( &gridVec[ i ][ j + 1 ] );
                }

                int fishIndex = -1;
                for ( int k = 0; k < cellsPtrVec.size(); k++ ) {
                    if ( cellsPtrVec[ k ]->fishIndex != -1 ) {
                        fishIndex = cellsPtrVec[ k ]->fishIndex;
                    }
                }

                if ( fishIndex == -1 ) {
                    Fish newFish;
                    newFish.index = fishesVec.size();
                    fishesVec.push_back( newFish );
                    fishIndex = newFish.index;
                }

                for ( int k = 0; k < cellsPtrVec.size(); k++ ) {
                    cellsPtrVec[ k ]->fishIndex = fishIndex;
                    fishesVec[ fishIndex ].cellsPtrSet.insert( cellsPtrVec[ k ] );
                }
            }
        }

        vector< int > fishesCountVec( 8, 0 );
        // Now loop through list of fishes & determine the type
        // of fish it is
        for ( int i = 0; i < fishesVec.size(); i++ ) {
            ++fishesCountVec[ fishesVec[ i ].getFishType() ];
        }

        for ( int i = 0; i < fishesCountVec.size(); i++ ) {
            if ( i > 0 ) {
                cout << " ";
            }
            cout << fishesCountVec[ i ];
        }
        cout << endl;

        if ( n < N - 1 ) {
            cout << endl;
        }
    }

    return 0;
}
