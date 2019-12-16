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

namespace Puzzle {
    static const char BOARD_CELL_EMPTY = '*';
    static const char BOARD_CELL_OCCUPIED = '.';

    static const char PIECE_CELL_NON_EMPTY = '*';
    static const char PIECE_CELL_EMPTY = '.';

    static int search( const deque< char >& txt, const deque< char >& pat,
                       int txtOffset ) {
        int M = pat.size();
        int N = txt.size();
        int i = txtOffset;
        int j = 0;

        for ( i = txtOffset, j = 0; i < N && j < M; i++ ) {
            if ( txt[ i ] == pat[ j ] ) {
                ++j;
            } else {
                if ( txt[ i ] == '*' ) {
                    ++j;
                } else {
                    i -= j;
                    j = 0;
                }
            }
        }

        if ( j == M ) return i - M;
        else return N;
    }

    static bool match( const deque< deque< char > >& boardVec,
                       const deque< deque< char > >& pieceVec ) {

        // Brute force:
        //
        // Just loop through boardVec row-by-row ( with index i )
        // from 0 to boardVec.size() - pieceVec.size()
        //
        // Then loop through each boardVec col-by-col ( with index j )
        // from 0 to boardVec[ i ].size() - pieceVec[ j ].size()
        //
        // If there is a total match of boardVec[ i ] and pieceVec[ k ],
        // we ++i and ++k. Otherwise, 
        //
        
        // cout << "DEBUG : match() INVOKED!!!" << endl;

        if ( boardVec.size() < pieceVec.size() || boardVec[ 0 ].size() < pieceVec[ 0 ].size() ) return false;
        
        // cout << "DEBUG : match() INVOKED ( 1 )!!!" << endl;

        // For each boardVec's row
        for ( int i = 0; i < boardVec.size() - pieceVec.size() + 1; i++ ) {

            // cout << "DEBUG : FIRST LOOP " << endl;

            for ( int j = 0; j < boardVec[ i ].size() - pieceVec[ 0 ].size() + 1; j++ ) {
                // cout << "DEBUG : SECOND LOOP " << endl;

                int finalColIdx = -1;
                bool isMatched = true;

                for ( int l = 0; l < pieceVec.size(); l++ ) {
                    // cout << "DEBUG : THIRD LOOP " << endl;
                    // cout << "DEBUG : COMPARING : boardVec[ i + l ] : " << i + l
                    //      << " with pieceVec[ l ] : " << l
                    //      << " at OFFSET : " << j;
                    // cout << endl;
                    // cout << "DEBUG : boardVec[ i + l ] : ";
                    // for ( char c : boardVec[ i + l ] ) {
                    //     cout << c;
                    // }
                    // cout << endl;
                    // cout << "DEBUG : pieceVec[ l ] : ";
                    // for ( char c : pieceVec[ l ] ) {
                    //     cout << c;
                    // }
                    // cout << endl;
                    int index = search( boardVec[ i + l ], pieceVec[ l ], j );

                    if ( index == boardVec[ i + l ].size() ) {
                        isMatched = false;
                        break;
                    }

                    if ( finalColIdx == -1 ) {
                        finalColIdx = index;
                    } else {
                        if ( index != finalColIdx ) {
                            isMatched = false;
                            break;
                        }
                    }
                }

                // If all lines of piece match, return true
                if ( isMatched ) {
                    return true;
                }
            }
        }

        return false;
    }
}

int main( int argc, char ** argv ) {

    string line = "";
    int T = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> T;
    }

    for ( int t = 0; t < T; t++ ) {
        int rowCount = 0;
        int colCount = 0;
        int piecesCount = 0;

        while ( getline( cin, line ) ) {
            if ( line.empty() ) continue;
            stringstream ss( line );
            ss >> rowCount >> colCount >> piecesCount;
            break;
        }
        
        deque< deque< char > > boardVec( rowCount, deque< char >( colCount, Puzzle::BOARD_CELL_EMPTY ) );
        for ( int i = 0; i < rowCount; i++ ) {
            while ( getline( cin, line ) ) {
                if ( line.empty() ) continue;
                for ( int j = 0; j < line.size(); j++ ) {
                    boardVec[ i ][ j ] = line[ j ];
                }
                break;
            }
        }

        for ( int i = 0; i < piecesCount; i++ ) {
            int pieceRowCount = 0;
            int pieceColCount = 0;
            while ( getline( cin, line ) ) {
                if ( line.empty() ) continue;
                stringstream ss( line );
                ss >> pieceRowCount >> pieceColCount;
                break;
            }

            deque< deque< char > > pieceVec( pieceRowCount, deque< char >( pieceColCount, Puzzle::PIECE_CELL_EMPTY ) );
            deque< bool > isRowEmptyVec( pieceRowCount, true );
            deque< bool > isColEmptyVec( pieceColCount, true );
            for ( int j = 0; j < pieceRowCount; j++ ) {
                while ( getline( cin, line ) ) {
                    if ( line.empty() ) continue;
                    for ( int k = 0; k < line.size(); k++ ) {
                        pieceVec[ j ][ k ] = line[ k ];
                        if ( pieceVec[ j ][ k ] == Puzzle::PIECE_CELL_NON_EMPTY ) {
                            isRowEmptyVec[ j ] = false;
                            isColEmptyVec[ k ] = false;
                        }
                    }
                    break;
                }
            }

            // We need to trim first & last rows of pieceVec
            // and first and last cols of pieceVec
            int isRowEmptyVecIdx = 0;
            while ( isRowEmptyVecIdx >= 0
                    && isRowEmptyVecIdx <= isRowEmptyVec.size() - 1
                    && isRowEmptyVec[ isRowEmptyVecIdx++ ]
                    && ! pieceVec.empty() ) {
                pieceVec.pop_front();
            }

            isRowEmptyVecIdx = isRowEmptyVec.size() - 1;
            while ( isRowEmptyVecIdx >= 0
                    && isRowEmptyVecIdx <= isRowEmptyVec.size() - 1
                    && isRowEmptyVec[ isRowEmptyVecIdx-- ]
                    && ! pieceVec.empty() ) {
                pieceVec.pop_back();
            }

            int isColEmptyVecIdx = 0;
            while ( isColEmptyVecIdx >= 0
                    && isColEmptyVecIdx <= isColEmptyVec.size() - 1
                    && isColEmptyVec[ isColEmptyVecIdx++ ] ) {
                for ( int i = 0; i < pieceVec.size(); i++ ) {
                    pieceVec[ i ].pop_front();
                }
            }

            isColEmptyVecIdx = isColEmptyVec.size() - 1;
            while ( isColEmptyVecIdx >= 0
                    && isColEmptyVecIdx <= isColEmptyVec.size() - 1
                    && isColEmptyVec[ isColEmptyVecIdx-- ] ) {
                for ( int i = 0; i < pieceVec.size(); i++ ) {
                    pieceVec[ i ].pop_back();
                }
            }

            if ( pieceVec.empty() || Puzzle::match( boardVec, pieceVec ) ) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
