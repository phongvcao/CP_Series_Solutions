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



int main( int argc, char ** argv ) {

    int N = 0;
    cin >> N;

    // blocksVec contains the main simulation of the program
    vector< vector< int > > blocksVec( N, vector< int >() );

    // blockAddressesVec contains the address of the blocks
    // - .first value contains index of the stack
    // - .second value contains exact index of the block on the stack
    vector< pair< int, int > > blockAddressesVec;
    for ( int n = 0; n < N; n++ ) {
        blocksVec[ n ].push_back( n );
        blockAddressesVec.push_back( make_pair( n, 0 ) );
    }

    while ( true ) {
        string cmdPart1 = "";
        cin >> cmdPart1;

        if ( cmdPart1 == "quit" ) {
            // Print out the result
            for ( int i = 0; i < blocksVec.size(); i++ ) {
                cout << i << ":";
                for ( int j = 0; j < blocksVec[ i ].size(); j++ ) {
                    cout << " " << blocksVec[ i ][ j ];
                }
                cout << endl;
            }
            break;
        }

        int fromIdx = 0;
        string cmdPart2 = "";
        int toIdx = 0;
        cin >> fromIdx >> cmdPart2 >> toIdx;

        if ( cmdPart1 == "move" ) {
            if ( cmdPart2 == "onto" ) {
                // where a and b are block numbers,
                // puts block a onto block b after returning any blocks that are
                // stacked on top of blocks a and b to their initial positions.
                //
                // Block a is fromIdx
                // Block b is toIdx
                //

                int fromBlockIdx = blockAddressesVec[ fromIdx ].first;
                int fromStackIdx = blockAddressesVec[ fromIdx ].second;
                int toBlockIdx = blockAddressesVec[ toIdx ].first;
                int toStackIdx = blockAddressesVec[ toIdx ].second;

                if ( fromBlockIdx != toBlockIdx ) {

                    while ( ! blocksVec[ fromBlockIdx ].empty() && blocksVec[ fromBlockIdx ].back() != fromIdx ) {
                        int backBlockIdx = blocksVec[ fromBlockIdx ].back();
                        blocksVec[ fromBlockIdx ].pop_back();

                        blocksVec[ backBlockIdx ].push_back( backBlockIdx );

                        blockAddressesVec[ backBlockIdx ].first = backBlockIdx;
                        blockAddressesVec[ backBlockIdx ].second = 0;
                    }

                    while ( ! blocksVec[ toBlockIdx ].empty() && blocksVec[ toBlockIdx ].back() != toIdx ) {
                        int backBlockIdx = blocksVec[ toBlockIdx ].back();
                        blocksVec[ toBlockIdx ].pop_back();

                        blocksVec[ backBlockIdx ].push_back( backBlockIdx );

                        blockAddressesVec[ backBlockIdx ].first = backBlockIdx;
                        blockAddressesVec[ backBlockIdx ].second = 0;
                    }

                    blocksVec[ toBlockIdx ].push_back( blocksVec[ fromBlockIdx ][ fromStackIdx ] );
                    blockAddressesVec[ toIdx ].first = toBlockIdx;
                    blockAddressesVec[ toIdx ].second = toStackIdx;
                    blockAddressesVec[ fromIdx ].first = toBlockIdx;
                    blockAddressesVec[ fromIdx ].second = toStackIdx + 1;
                    blocksVec[ fromBlockIdx ].pop_back();

                }

            } else if ( cmdPart2 == "over" ) {
                // where a and b are block numbers,
                // puts block a onto the top of the stack containing block b,
                // after returning any blocks that are stacked on top of block
                // a to their initial positions.
                //
                // Block a is fromIdx
                // Block b is toIdx
                //

                int fromBlockIdx = blockAddressesVec[ fromIdx ].first;
                int fromStackIdx = blockAddressesVec[ fromIdx ].second;
                int toBlockIdx = blockAddressesVec[ toIdx ].first;

                if ( fromBlockIdx != toBlockIdx ) {
                    while ( ! blocksVec[ fromBlockIdx ].empty() && blocksVec[ fromBlockIdx ].back() != fromIdx ) {
                        int backBlockIdx = blocksVec[ fromBlockIdx ].back();
                        blocksVec[ fromBlockIdx ].pop_back();

                        blocksVec[ backBlockIdx ].push_back( backBlockIdx );

                        blockAddressesVec[ backBlockIdx ].first = backBlockIdx;
                        blockAddressesVec[ backBlockIdx ].second = 0;
                    }

                    blocksVec[ toBlockIdx ].push_back( blocksVec[ fromBlockIdx ][ fromStackIdx ] );
                    blockAddressesVec[ toIdx ].first = toBlockIdx;
                    blockAddressesVec[ fromIdx ].first = toBlockIdx;
                    blockAddressesVec[ fromIdx ].second = blocksVec[ toBlockIdx ].size() - 1;
                    blocksVec[ fromBlockIdx ].pop_back();

                }
            }
        } else if ( cmdPart1 == "pile" ) {
            if ( cmdPart2 == "onto" ) {
                // where a and b are block numbers, moves the pile of blocks
                // consisting of block a, and any blocks that are stacked above
                // block a, onto block b. All blocks on top of block b are
                // moved to their initial positions prior to the pile taking
                // place. The blocks stacked above block a retain their order
                // when moved.
                //
                // Block a is fromIdx
                // Block b is toIdx
                //

                // All blocks on top of block b are moved to their initial
                // positions
                int toBlockIdx = blockAddressesVec[ toIdx ].first;
                int toStackIdx = blockAddressesVec[ toIdx ].second;
                int fromBlockIdx = blockAddressesVec[ fromIdx ].first;
                int fromStackIdx = blockAddressesVec[ fromIdx ].second;

                if ( fromBlockIdx != toBlockIdx ) {

                    while ( ! blocksVec[ toBlockIdx ].empty() && blocksVec[ toBlockIdx ].back() != toIdx ) {
                        int backBlockIdx = blocksVec[ toBlockIdx ].back();
                        blocksVec[ toBlockIdx ].pop_back();

                        blocksVec[ backBlockIdx ].push_back( backBlockIdx );

                        blockAddressesVec[ backBlockIdx ].first = backBlockIdx;
                        blockAddressesVec[ backBlockIdx ].second = 0;
                    }

                    // The blocks stacked above block a retain their order when
                    // moved
                    
                    for ( int i = fromStackIdx; i < blocksVec[ fromBlockIdx ].size(); i++ ) {
                        blockAddressesVec[ blocksVec[ fromBlockIdx ][ i ] ].first = toBlockIdx;
                        blockAddressesVec[ blocksVec[ fromBlockIdx ][ i ] ].second = blocksVec[ toBlockIdx ].size();

                        blocksVec[ toBlockIdx ].push_back( blocksVec[ fromBlockIdx ][ i ] );
                    }

                    int fromBlockSize = blocksVec[ fromBlockIdx ].size();
                    for ( int i = fromStackIdx; i < fromBlockSize; i++ ) {
                        blocksVec[ fromBlockIdx ].pop_back();
                    }

                }

            } else if ( cmdPart2 == "over" ) {
                // where a and b are block numbers, puts the pile of blocks
                // consisting of block a, and any blocks that are stacked
                // above block a, onto the top of the stack containing block b.
                // The blocks stacked above block a retain their original
                // order when moved.
                //
                // Block a is fromIdx
                // Block b is toIdx
                //
                int toBlockIdx = blockAddressesVec[ toIdx ].first;
                int toStackIdx = blockAddressesVec[ toIdx ].second;
                int fromBlockIdx = blockAddressesVec[ fromIdx ].first;
                int fromStackIdx = blockAddressesVec[ fromIdx ].second;

                if ( fromBlockIdx != toBlockIdx ) {
                    for ( int i = fromStackIdx; i < blocksVec[ fromBlockIdx ].size(); i++ ) {
                        blockAddressesVec[ blocksVec[ fromBlockIdx ][ i ] ].first = toBlockIdx;
                        blockAddressesVec[ blocksVec[ fromBlockIdx ][ i ] ].second = blocksVec[ toBlockIdx ].size();

                        blocksVec[ toBlockIdx ].push_back( blocksVec[ fromBlockIdx ][ i ] );
                    }

                    int fromBlockSize = blocksVec[ fromBlockIdx ].size();
                    for ( int i = fromStackIdx; i < fromBlockSize; i++ ) {
                        blocksVec[ fromBlockIdx ].pop_back();
                    }
                }
            }
        }
    }

    return 0;
}
