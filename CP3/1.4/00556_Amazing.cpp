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

namespace Amazing {
    static const vector< vector< int > > DIRECTION_STEPS = {
        {  0,  1 },
        { -1,  0 },
        {  0, -1 },
        {  1,  0 },
    };

    enum DirectionType {
        DIRECTION_RIGHT = 0,
        DIRECTION_UP = 1,
        DIRECTION_LEFT = 2,
        DIRECTION_DOWN = 3,
    };

    static const vector< DirectionType > RIGHT_DIRECTION_OF = {
        DIRECTION_DOWN, DIRECTION_RIGHT, DIRECTION_UP, DIRECTION_LEFT,
    };

    static const vector< DirectionType > LEFT_DIRECTION_OF = {
        DIRECTION_UP, DIRECTION_LEFT, DIRECTION_DOWN, DIRECTION_RIGHT,
    };

    static const char CHAR_WALL = '1';
    static const char CHAR_EMPTY = '0';

    static const int CELL_WALL = -1;

    static bool hasRightWall( const vector< vector< int > >& mazeVec, int rowIdx, int colIdx, DirectionType direction ) {
        switch ( direction ) {
            case DIRECTION_RIGHT:
            {
                if ( rowIdx == mazeVec.size() - 1 || mazeVec[ rowIdx + 1 ][ colIdx ] == CELL_WALL ) {
                    return true;
                }
                break;
            }

            case DIRECTION_UP:
            {
                if ( colIdx == mazeVec[ rowIdx ].size() - 1 || mazeVec[ rowIdx ][ colIdx + 1 ] == CELL_WALL ) {
                    return true;
                }
                break;
            }

            case DIRECTION_LEFT:
            {
                if ( rowIdx == 0 || mazeVec[ rowIdx - 1 ][ colIdx ] == CELL_WALL ) {
                    return true;
                }
                break;
            }

            case DIRECTION_DOWN:
            {
                if ( colIdx == 0 || mazeVec[ rowIdx ][ colIdx - 1 ] == CELL_WALL ) {
                    return true;
                }
                break;
            }

            default:
            {
                break;
            }
        }
        return false;
    }

    static bool isFrontBlocked( const vector< vector< int > >& mazeVec, int rowIdx, int colIdx, DirectionType direction ) {
        switch ( direction ) {
            case DIRECTION_RIGHT:
            {
                if ( colIdx == mazeVec[ rowIdx ].size() - 1 || mazeVec[ rowIdx ][ colIdx + 1 ] == CELL_WALL ) {
                    return true;
                }
                break;
            }

            case DIRECTION_UP:
            {
                if ( rowIdx == 0 || mazeVec[ rowIdx - 1 ][ colIdx ] == CELL_WALL ) {
                    return true;
                }
                break;
            }

            case DIRECTION_LEFT:
            {
                if ( colIdx == 0 || mazeVec[ rowIdx ][ colIdx - 1 ] == CELL_WALL ) {
                    return true;
                }
                break;
            }

            case DIRECTION_DOWN:
            {
                if ( rowIdx == mazeVec.size() - 1 || mazeVec[ rowIdx + 1 ][ colIdx ] == CELL_WALL ) {
                    return true;
                }
                break;
            }

            default:
            {
                break;
            }
        }
        return false;
    }
}

int main( int argc, char ** argv ) {

    string line = "";
    while ( getline( cin, line ) ) {
        int rowCount = 0;
        int colCount = 0;
        stringstream ss( line );
        ss >> rowCount >> colCount;

        if ( rowCount == 0 && colCount == 0 ) break;

        vector< vector< int > > mazeVec( rowCount, vector< int >( colCount, -1 ) );
        int emptyCellCount = 0;
        for ( int i = 0; i < rowCount; i++ ) {
            if ( getline( cin, line ) ) {
                for ( int j = 0; j < line.size(); j++ ) {
                    if ( line[ j ] == '1' ) {
                        mazeVec[ i ][ j ] = -1;
                    } else {
                        mazeVec[ i ][ j ] = 0;
                        ++emptyCellCount;
                    }
                }
            }
        }

        int startRowIdx = rowCount - 1;
        int startColIdx = 0;
        Amazing::DirectionType startDirection = Amazing::DIRECTION_RIGHT;

        vector< int > visitedTimesVec = { emptyCellCount, 0, 0, 0, 0 };
        int curRowIdx = startRowIdx;
        int curColIdx = startColIdx;
        Amazing::DirectionType curDirection = startDirection;

        do {
            // Keep moving while still having a wall on the right
            // But once there's no wall on the right, turn right to keep the wall
            // in-tact.
            // ElseIf there's a wall on the right and it's going to hit a wall
            // in the front, rotate left until finding a way with wall on the right
            // and no wall in front.
            if ( Amazing::hasRightWall( mazeVec, curRowIdx, curColIdx, curDirection )
                    && ! Amazing::isFrontBlocked( mazeVec, curRowIdx, curColIdx, curDirection ) ) {
                // Mark the current cell
                --visitedTimesVec[ mazeVec[ curRowIdx ][ curColIdx ] ];
                ++mazeVec[ curRowIdx ][ curColIdx ];
                ++visitedTimesVec[ mazeVec[ curRowIdx ][ curColIdx ] ];

                curRowIdx += Amazing::DIRECTION_STEPS[ curDirection ][ 0 ];
                curColIdx += Amazing::DIRECTION_STEPS[ curDirection ][ 1 ];
            } else if ( ! Amazing::hasRightWall( mazeVec, curRowIdx, curColIdx, curDirection ) ) {
                // Mark the current cell
                --visitedTimesVec[ mazeVec[ curRowIdx ][ curColIdx ] ];
                ++mazeVec[ curRowIdx ][ curColIdx ];
                ++visitedTimesVec[ mazeVec[ curRowIdx ][ curColIdx ] ];
                
                curDirection = Amazing::RIGHT_DIRECTION_OF[ curDirection ];
                curRowIdx += Amazing::DIRECTION_STEPS[ curDirection ][ 0 ];
                curColIdx += Amazing::DIRECTION_STEPS[ curDirection ][ 1 ];
            } else if ( Amazing::hasRightWall( mazeVec, curRowIdx, curColIdx, curDirection )
                    && Amazing::isFrontBlocked( mazeVec, curRowIdx, curColIdx, curDirection ) ) {
                curDirection = Amazing::LEFT_DIRECTION_OF[ curDirection ];
            }
        } while ( curRowIdx != startRowIdx || curColIdx != startColIdx );


        for ( int i = 0; i < visitedTimesVec.size(); i++ ) {
            printf( "%3d", visitedTimesVec[ i ] );
        }
        cout << endl;
    }

    return 0;
}
