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

namespace Squarelotron {
    enum FlipType {
        FLIP_UPSIDE_DOWN = 1,
        FLIP_LEFT_RIGHT = 2,
        FLIP_MAIN_DIAGONAL = 3,
        FLIP_MAIN_INVERSE_DIAGONAL = 4,
    };

    void flipRing( vector< vector< string > >& matrixVec, int ringIdx, FlipType flipType ) {
        switch ( flipType ) {
            case FLIP_UPSIDE_DOWN:
            {
                // From ring num & matrixVec, calculate the bottom row index,
                // top row index, left col index, right col index
                int topRowIndex = ringIdx;
                int bottomRowIndex = matrixVec.size() - 1 - topRowIndex;
                int firstColIndex = ringIdx;
                int lastColIndex = matrixVec.size() - 1 - firstColIndex;

                // Exchange top & bottom rows
                for ( int i = firstColIndex; i <= lastColIndex; i++ ) {
                    swap( matrixVec[ topRowIndex ][ i ], matrixVec[ bottomRowIndex ][ i ] );
                }

                // Exchange members in first & last cols except:
                // - The first & last members of the first col
                // - The first & last members of the last col
                for ( int i = topRowIndex + 1; i < matrixVec.size() / 2; i++ ) {
                    swap( matrixVec[ i ][ firstColIndex ], matrixVec[ matrixVec.size() - 1 - i ][ firstColIndex ] );
                    swap( matrixVec[ i ][ lastColIndex ], matrixVec[ matrixVec.size() - 1 - i ][ lastColIndex ] );
                }
                break;
            }

            case FLIP_LEFT_RIGHT:
            {
                // From ring num & matrixVec, calculate the bottom row index,
                // top row index, left col index, right col index
                int topRowIndex = ringIdx;
                int bottomRowIndex = matrixVec.size() - 1 - topRowIndex;
                int firstColIndex = ringIdx;
                int lastColIndex = matrixVec.size() - 1 - firstColIndex;
                
                // Exchange left & right cols
                for ( int i = topRowIndex; i <= bottomRowIndex; i++ ) {
                    swap( matrixVec[ i ][ firstColIndex ], matrixVec[ i ][ lastColIndex ] );
                }

                // Exchange members in first & last rows except:
                // - The first & last members of the first row
                // - The first & last members of the last row
                for ( int i = firstColIndex + 1; i < matrixVec.size() / 2; i++ ) {
                    swap( matrixVec[ topRowIndex ][ i ], matrixVec[ topRowIndex ][ matrixVec.size() - 1 - i ] );
                    swap( matrixVec[ bottomRowIndex ][ i ], matrixVec[ bottomRowIndex ][ matrixVec.size() - 1 - i ] );
                }

                break;
            }

            case FLIP_MAIN_DIAGONAL:
            {
                // From ring num & matrixVec, calculate the bottom row index,
                // top row index, left col index, right col index
                int topRowIndex = ringIdx;
                int bottomRowIndex = matrixVec.size() - 1 - topRowIndex;
                int firstColIndex = ringIdx;
                int lastColIndex = matrixVec.size() - 1 - firstColIndex;

                // Exchange elements in topRowIndex with elements in firstColIndex
                for ( int i = firstColIndex + 1; i <= lastColIndex; i++ ) {
                    swap( matrixVec[ i ][ firstColIndex ], matrixVec[ topRowIndex ][ i ] );
                }

                // Exchange elements from 1..N-1 in bottomRowIndex with lastColIndex
                for ( int i = firstColIndex + 1; i < lastColIndex; i++ ) {
                    swap( matrixVec[ i ][ lastColIndex ], matrixVec[ bottomRowIndex ][ i ] );
                }

                break;
            }

            case FLIP_MAIN_INVERSE_DIAGONAL:
            {
                // From ring num & matrixVec, calculate the bottom row index,
                // top row index, left col index, right col index
                int topRowIndex = ringIdx;
                int bottomRowIndex = matrixVec.size() - 1 - topRowIndex;
                int firstColIndex = ringIdx;
                int lastColIndex = matrixVec.size() - 1 - firstColIndex;

                // Exchange elements in topRowIndex with elements in lastColIndex
                for ( int i = firstColIndex; i < lastColIndex; i++ ) {
                    swap( matrixVec[ topRowIndex ][ i ], matrixVec[ matrixVec.size() - 1 - i ][ lastColIndex ] );
                }

                // Exchange elements in firstColIndex with elements in bottomRowIndex
                for ( int i = topRowIndex + 1; i < bottomRowIndex; i++ ) {
                    swap( matrixVec[ i ][ firstColIndex ], matrixVec[ bottomRowIndex ][ matrixVec.size() - 1 - i ] );
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

int main( int argc, char ** argv ) {

    int M = 0;
    cin >> M;

    for ( int m = 0; m < M; m++ ) {
        int N = 0;
        cin >> N;

        vector< vector< string > > matrixVec( N, vector< string >( N, "" ) );
        for ( int i = 0; i < N; i++ ) {
            for ( int j = 0; j < N; j++ ) {
                cin >> matrixVec[ i ][ j ];
            }
        }

        int ringsCount = ( int )ceil( ( double )N / 2.0 );
        for ( int i = 0; i < ringsCount; i++ ) {
            int movesCount = 0;
            cin >> movesCount;
            for ( int j = 0; j < movesCount; j++ ) {
                int flipType = 0;
                cin >> flipType;

                Squarelotron::flipRing( matrixVec, i, static_cast< Squarelotron::FlipType >( flipType ) );
            }
        }

        for ( int i = 0; i < matrixVec.size(); i++ ) {
            for ( int j = 0; j < matrixVec[ i ].size(); j++ ) {
                if ( j > 0 ) {
                    cout << " ";
                }
                cout << matrixVec[ i ][ j ];
            }
            cout << endl;
        }
    }

    return 0;
}
