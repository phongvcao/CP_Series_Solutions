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

namespace Poly {

    static const char CELL_OCCUPIED = '*';
    static const char CELL_EMPTY = '.';

    static vector< vector< char > > trimPolyVec( const vector< vector< char > >& polyVec ) {
        // Only trim the outer parts of the polyVec
        vector< bool > isRowEmptyVec( polyVec.size(), false );
        vector< bool > isColEmptyVec( polyVec.size(), false );

        // Trim empty rows
        int topDownIdx = 0;
        for ( topDownIdx = 0; topDownIdx < polyVec.size(); topDownIdx++ ) {
            bool isEmpty = true;
            for ( int j = 0; j < polyVec[ topDownIdx ].size(); j++ ) {
                if ( polyVec[ topDownIdx ][ j ] == CELL_OCCUPIED ) {
                    isEmpty = false;
                    break;
                }
            }
            if ( ! isEmpty ) break;
            isRowEmptyVec[ topDownIdx ] = true;
        }

        int bottomUpIdx = polyVec.size() - 1;
        for ( bottomUpIdx = polyVec.size() - 1; bottomUpIdx > 0; bottomUpIdx-- ) {
            bool isEmpty = true;
            for ( int j = 0; j < polyVec[ bottomUpIdx ].size(); j++ ) {
                if ( polyVec[ bottomUpIdx ][ j ] == CELL_OCCUPIED ) {
                    isEmpty = false;
                    break;
                }
            }
            if ( ! isEmpty ) break;
            isRowEmptyVec[ bottomUpIdx ] = true;
        }

        for ( int i = topDownIdx; i <= bottomUpIdx; i++ ) {
            isRowEmptyVec[ i ] = false;
        }

        // Trim empty cols
        int leftRightIdx = 0;
        for ( leftRightIdx = 0; leftRightIdx < polyVec.size(); leftRightIdx++ ) {
            bool isEmpty = true;
            for ( int i = 0; i < polyVec.size(); i++ ) {
                if ( polyVec[ i ][ leftRightIdx ] == CELL_OCCUPIED ) {
                    isEmpty = false;
                    break;
                }
            }

            if ( ! isEmpty ) break;
            isColEmptyVec[ leftRightIdx ] = true;
        }

        int rightLeftIdx = 0;
        for ( rightLeftIdx = polyVec.size() - 1; rightLeftIdx > 0; rightLeftIdx-- ) {
            bool isEmpty = true;
            for ( int i = 0; i < polyVec.size(); i++ ) {
                if ( polyVec[ i ][ rightLeftIdx ] == CELL_OCCUPIED ) {
                    isEmpty = false;
                    break;
                }
            }

            if ( ! isEmpty ) break;
            isColEmptyVec[ rightLeftIdx ] = true;
        }

        for ( int i = leftRightIdx; i <= rightLeftIdx; i++ ) {
            isColEmptyVec[ i ] = false;
        }

        vector< vector< char > > rvPolyVec( bottomUpIdx - topDownIdx + 1,
                                            vector< char >( rightLeftIdx - leftRightIdx + 1,
                                                            CELL_EMPTY ) );

        int rvPolyVecRowIdx = 0;
        for ( int i = 0; i < polyVec.size(); i++ ) {
            if ( isRowEmptyVec[ i ] ) continue;
            int rvPolyVecColIdx = 0;
            for ( int j = 0; j < polyVec[ i ].size(); j++ ) {
                if ( isColEmptyVec[ j ] ) continue;
                
                rvPolyVec[ rvPolyVecRowIdx ][ rvPolyVecColIdx ] = polyVec[ i ][ j ];
                ++rvPolyVecColIdx;
            }
            ++rvPolyVecRowIdx;
        }

        return rvPolyVec;
    }

    static bool isEqual( const vector< vector< char > >& polyVec1, const vector< vector< char > >& polyVec2 ) {
        if ( polyVec1.empty() && polyVec2.empty() ) return true;
        if ( ( polyVec1.empty() && ! polyVec2.empty() )
                || ( ! polyVec1.empty() && polyVec2.empty() )
                || polyVec1.size() != polyVec2.size()
                || polyVec1.begin()->size() != polyVec2.begin()->size() ) return false;

        for ( int i = 0; i < polyVec1.size(); i++ ) {
            for ( int j = 0; j < polyVec1[ i ].size(); j++ ) {
                if ( polyVec1[ i ][ j ] != polyVec2[ i ][ j ] ) return false;
            }
        }
        return true;
    }
}

int main( int argc, char ** argv ) {

    while ( true ) {
        int N = 0;
        int M = 0;
        cin >> N >> M;

        if ( N == 0 && M == 0 ) break;

        vector< vector< char > > largePolyVec( N, vector< char >( N, Poly::CELL_EMPTY ) );
        for ( int i = 0; i < N; i++ ) {
            string line = "";
            cin >> line;
            for ( int j = 0; j < line.size(); j++ ) {
                largePolyVec[ i ][ j ] = line[ j ];
            }
        }
        
        vector< vector< char > > smallPolyVec( M, vector< char >( M, Poly::CELL_EMPTY ) );
        for ( int i = 0; i < M; i++ ) {
            string line = "";
            cin >> line;
            for ( int j = 0; j < line.size(); j++ ) {
                smallPolyVec[ i ][ j ] = line[ j ];
            }
        }

        // Trim down small polyVec
        smallPolyVec = Poly::trimPolyVec( smallPolyVec );

        // Find all smallPolyVec instances in largePolyVec, counting from the
        // left most corner of smallPolyVec.
        //
        // With each smallPolyVec instance in largePolyVec, zero-out the matched
        // part, then trim down the largePolyVec, and compare the final,
        // transformed largePolyVec with the smallPolyVec to see if they match.
        //
        // If they don't, keep going to find the next index for smallPolyVec
        // inside the original largePolyVec.
        //
        // Otherwise, break out and print 1.

        bool isTotallyMatched = false;
        for ( int i = 0; i < largePolyVec.size() - smallPolyVec.size() + 1; i++ ) {
            for ( int j = 0; j < largePolyVec[ i ].size() - smallPolyVec.begin()->size() + 1; j++ ) {
                bool isMatched = true;

                for ( int k = 0; k < smallPolyVec.size(); k++ ) {
                    for ( int l = 0; l < smallPolyVec[ k ].size(); l++ ) {
                        // We declare notMatched when:
                        // - smallPolyVec cell is CELL_OCCUPIED but largePolyVec
                        // cell is CELL_EMPTY
                        if ( smallPolyVec[ k ][ l ] == Poly::CELL_OCCUPIED && largePolyVec[ i + k ][ j + l ] == Poly::CELL_EMPTY ) {
                            isMatched = false;
                            break;
                        }
                    }

                    if ( ! isMatched ) break;
                }

                if ( isMatched ) {
                    vector< vector< char > > tmpLargePolyVec = largePolyVec;

                    for ( int k = 0; k < smallPolyVec.size(); k++ ) {
                        for ( int l = 0; l < smallPolyVec[ k ].size(); l++ ) {
                            if ( smallPolyVec[ k ][ l ] == Poly::CELL_OCCUPIED ) {
                                tmpLargePolyVec[ i + k ][ j + l ] = Poly::CELL_EMPTY;
                            }
                        }
                    }

                    tmpLargePolyVec = Poly::trimPolyVec( tmpLargePolyVec );
                    if ( Poly::isEqual( smallPolyVec, tmpLargePolyVec ) ) {
                        isTotallyMatched = true;
                        break;
                    }
                }
            }

            if ( isTotallyMatched ) {
                break;
            }
        }

        if ( ! isTotallyMatched ) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }

    return 0;
}
