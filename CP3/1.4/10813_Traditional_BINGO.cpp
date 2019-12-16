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

namespace Bingo {
    static const int SPACE_FREE = 0;
    static const int SPACE_UNKNOWN = -1;

    class Space {
    public:

        int row = -1;
        int col = -1;
        vector< int > bingoPathsIndexVec;
        int val = SPACE_FREE;

        Space() {
            // not implemented
        }

        Space( const Space& other )
            : row( other.row ),
              col( other.col ),
              bingoPathsIndexVec( other.bingoPathsIndexVec )
        {
            // not implemented
        }

        Space( int row, int col )
            : row( row ),
              col( col )
        {
            // not implemented
        }

        virtual ~Space() {
            // not implemented
        }

        operator bool() const {
            return ( row != -1 && col != -1 );
        }
    };
}

int main( int argc, char ** argv ) {

    string line = "";
    int N = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> N;
    }

    for ( int n = 0; n < N; n++ ) {
        // First 5 elements are row bingo
        // Next 5 elements are col bingo
        // Last 2 elements are ( top-left -> bot-right ) diagonal and
        //                     ( top-right -> bot-left ) diagonal
        vector< int > bingoPathsVec( 12, 0 );

        vector< vector< Bingo::Space > > boardVec( 5, vector< Bingo::Space >( 5 ) );
        vector< Bingo::Space * > numVec( 76, NULL );

        int skip = 1;
        for ( int i = 0; i < boardVec.size(); i += skip ) {
            if ( getline( cin, line ) ) {
                if ( line.empty() ) {
                    skip = 0;
                    continue;
                } else {
                    skip = 1;
                }

                stringstream ss( line );
                for ( int j = 0; j < boardVec[ i ].size(); j++ ) {
                    boardVec[ i ][ j ].row = i;
                    boardVec[ i ][ j ].col = j;

                    if ( i == 2 && j == 2 ) {
                        continue;
                    }

                    ss >> boardVec[ i ][ j ].val;

                    ++bingoPathsVec[ i ];
                    ++bingoPathsVec[ 5 + j ];

                    boardVec[ i ][ j ].bingoPathsIndexVec.push_back( i );
                    boardVec[ i ][ j ].bingoPathsIndexVec.push_back( 5 + j );

                    numVec[ boardVec[ i ][ j ].val ] = &boardVec[ i ][ j ];
                }
            }
        }

        // ( top-left -> bot-right ) diagonal
        bingoPathsVec[ 10 ] = 4;
        boardVec[ 0 ][ 0 ].bingoPathsIndexVec.push_back( 10 );
        boardVec[ 1 ][ 1 ].bingoPathsIndexVec.push_back( 10 );
        boardVec[ 3 ][ 3 ].bingoPathsIndexVec.push_back( 10 );
        boardVec[ 4 ][ 4 ].bingoPathsIndexVec.push_back( 10 );

        // ( top-right -> bot-left ) diagonal
        bingoPathsVec[ 11 ] = 4;
        boardVec[ 0 ][ 4 ].bingoPathsIndexVec.push_back( 11 );
        boardVec[ 1 ][ 3 ].bingoPathsIndexVec.push_back( 11 );
        boardVec[ 3 ][ 1 ].bingoPathsIndexVec.push_back( 11 );
        boardVec[ 4 ][ 0 ].bingoPathsIndexVec.push_back( 11 );
        
        bool gameFinished = false;
        int numCount = 0;

        // Now read in the bingo number calls.
        while ( ! gameFinished || numCount < 75 ) {
            if ( getline( cin, line ) ) {
                stringstream ss( line );
                int num = 0;

                while ( ss >> num ) {
                    ++numCount;
                    // Play game
                    if ( ! gameFinished && numVec[ num ] ) {
                        for ( int i = 0; i < numVec[ num ]->bingoPathsIndexVec.size(); i++ ) {
                            --bingoPathsVec[ numVec[ num ]->bingoPathsIndexVec[ i ] ];

                            if ( bingoPathsVec[ numVec[ num ]->bingoPathsIndexVec[ i ] ] == 0 ) {
                                cout << "BINGO after " << numCount << " numbers announced" << endl;
                                gameFinished = true;
                                break;
                            }
                        }
                    }
                }

                if ( numCount == 75 ) break;
            }
        }
    }

    return 0;
}
