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

    while ( true ) {
        long long size = 0;
        long long pos = 0;

        cin >> size >> pos;

        if ( size == 0 && pos == 0 ) break;

        double posSize = sqrt( pos );
        long long posSizeInt = ( long long )floor( posSize );

        long long lowerBound = -1;
        long long upperBound = -1;
        long long quadIdx = -1;
        long long quadArrIdx = -1;
        long long lowerBoundSize = -1;
        long long upperBoundSize = -1;

        if ( posSizeInt % 2 == 0 ) {
            lowerBoundSize = posSizeInt - 1;
            upperBoundSize = posSizeInt + 1;
            lowerBound = lowerBoundSize * lowerBoundSize + 1;
            upperBound = upperBoundSize * upperBoundSize;

            // Calculate the quadrant that pos is in
            quadIdx = ( pos - lowerBound ) / ( upperBoundSize - 1 );
            quadArrIdx = ( pos - lowerBound ) % ( upperBoundSize - 1 );
        } else {
            if ( posSize > floor( posSize ) ) {
                lowerBoundSize = posSizeInt;
                upperBoundSize = posSizeInt + 2;
                lowerBound = lowerBoundSize * lowerBoundSize + 1;
                upperBound = upperBoundSize * upperBoundSize;

                // Calculate the quadrant that pos is in
                quadIdx = ( pos - lowerBound ) / ( upperBoundSize - 1 );
                quadArrIdx = ( pos - lowerBound ) % ( upperBoundSize - 1 );
            } else {
                lowerBoundSize = posSizeInt - 2;
                upperBoundSize = posSizeInt;
                // If posSize == floor( posSize )
                // The quadIdx & quadArrIdx is known
                quadIdx = 3;
                quadArrIdx = upperBoundSize - 2;
            }
        }

        //
        // Quad Index 0:
        //   - From row = size - 1 ; col = size - 2
        //   - To   row = size - 1 ; col = 0
        //
        // Quad Index 1:
        //   - From row = size - 2 ; col = 0
        //   - To   row = 0        ; col = 0
        //
        // Quad Index 2:
        //   - From row = 0        ; col = 1
        //   - To   row = 0        ; col = size - 1
        //
        // Quad Index 3:
        //   - From row = 1        ; col = size - 1
        //   - To   row = size - 1 ; col = size - 1
        //
        if ( pos == 1 ) {
            if ( size == 1 ) {
                cout << "Line = " << size << ", column = " << size << "." << endl;
            } else {
                cout << "Line = " << ( size + 1 ) / 2 << ", column = " << ( size + 1 ) / 2 << "." << endl;
            }
        } else {
            switch ( quadIdx ) {
                case 0:
                {
                    if ( size == floor( posSize ) ) {
                        cout << "Line = " << size << ", column = " << size - 1 - quadArrIdx << "." << endl;
                    } else {
                        cout << "Line = " << upperBoundSize + ( size - upperBoundSize ) / 2 << ", column = " << ( upperBoundSize - 1 - quadArrIdx ) + ( size - upperBoundSize ) / 2 << "." << endl;
                    }
                    break;
                }

                case 1:
                {
                    if ( size == floor( posSize ) ) {
                        cout << "Line = " << size - 2 - quadArrIdx << ", column = " << 1 << "." << endl;
                    } else {
                        cout << "Line = " << upperBoundSize - 1 - quadArrIdx + ( size - upperBoundSize ) / 2 << ", column = " << 1 + ( size - upperBoundSize ) / 2 << "." << endl;
                    }
                    break;
                }

                case 2:
                {
                    if ( size == floor( posSize ) ) {
                        cout << "Line = " << 1 << ", column = " << 2 + quadArrIdx << "." << endl;
                    } else {
                        cout << "Line = " << 1 + ( size - upperBoundSize ) / 2 << ", column = " << 2 + quadArrIdx + ( size - upperBoundSize ) / 2 << "." << endl;
                    }
                    break;
                }

                case 3:
                {
                    // Since quadIdx & quadArrIdx is calculated according to lowerBound
                    // If size == lowerBound then we output this way
                    // Otherwise, we output line + 1 and column + 1
                    if ( size == floor( posSize ) ) {
                        cout << "Line = " << size << ", column = " << size << "." << endl;
                    } else {
                        cout << "Line = " << 2 + quadArrIdx + ( size - upperBoundSize ) / 2 << ", column = " << upperBoundSize + ( size - upperBoundSize ) / 2 << "." << endl;
                    }
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
