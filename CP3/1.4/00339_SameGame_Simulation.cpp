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

list< int > * getList( list< list< int > >& cellsList, int j ) {
    if ( next( cellsList.begin(), j ) != cellsList.end() ) {
        return &( *( next( cellsList.begin(), j ) ) );
    }
    return NULL;
}

string getCellInList( list< list< int > >& cellsList, int i, int j ) {
    if ( j >= 0 && j <= cellsList.size() - 1 ) {
        if ( ! getList( cellsList, j ) ) return " ";
        if ( i >= 0 && i <= getList( cellsList, j )->size() - 1 ) {
            stringstream ss;
            ss << *( next( getList( cellsList, j )->begin(), i ) );
            return ss.str();
        }
    }
    return " ";
}

pair< int, int > deleteCellInList( list< list< int > >& cellsList, int i, int j ) {
    if ( j > cellsList.size() - 1 ) return { 0, 0 };
    if ( i >= getList( cellsList, j )->size() ) return { 0, 0 };
    if ( *( next( getList( cellsList, j )->begin(), i ) ) == -1 ) return { 0, 0 };

    pair< int, int > cellsRemovedInfo = { 0, 0 };
    cellsRemovedInfo.first = 1;
    int oldCellVal = *( next( getList( cellsList, j )->begin(), i ) );
    *( next( getList( cellsList, j )->begin(), i ) ) = -1;
    pair< int, int > cellsJustRemovedInfo;

    if ( i > 0 ) {
        if ( *( next( getList( cellsList, j )->begin(), i - 1 ) ) == oldCellVal ) {
            cellsJustRemovedInfo = deleteCellInList( cellsList, i - 1, j );
            cellsRemovedInfo.first = cellsRemovedInfo.first + cellsJustRemovedInfo.first;
        }
    }

    if ( i < getList( cellsList, j )->size() - 1 ) {
        if ( *( next( getList( cellsList, j )->begin(), i + 1 ) ) == oldCellVal ) {
            cellsJustRemovedInfo = deleteCellInList( cellsList, i + 1, j );
            cellsRemovedInfo.first = cellsRemovedInfo.first + cellsJustRemovedInfo.first;
        }
    }

    if ( j > 0 ) {
        if ( getList( cellsList, j - 1 ) && *( next( getList( cellsList, j - 1 )->begin(), i ) ) == oldCellVal ) {
            cellsJustRemovedInfo = deleteCellInList( cellsList, i, j - 1 );
            cellsRemovedInfo.first = cellsRemovedInfo.first + cellsJustRemovedInfo.first;
        }
    }

    if ( j < cellsList.size() - 1 ) {
        if ( getList( cellsList, j + 1 ) && *( next( getList( cellsList, j + 1 )->begin(), i ) ) == oldCellVal ) {
            cellsJustRemovedInfo = deleteCellInList( cellsList, i, j + 1 );
            cellsRemovedInfo.first = cellsRemovedInfo.first + cellsJustRemovedInfo.first;
        }
    }
    cellsRemovedInfo.second = oldCellVal;
    return cellsRemovedInfo;
}

void cleanCellInList( list< list< int > >& cellsList ) {
    for ( int j = 0; j < cellsList.size(); j++ ) {
        if ( ! getList( cellsList, j ) ) continue;
        for ( int i = 0; i < getList( cellsList, j )->size(); i++ ) {
            while ( *( next( getList( cellsList, j )->begin(), i ) ) == -1 ) {
                getList( cellsList, j )->erase( next( getList( cellsList, j )->begin(), i ) );
            }
        }
    }
        
    for ( int j = 0; j < cellsList.size(); j++ ) {
        while ( getList( cellsList, j ) &&  getList( cellsList, j )->empty() ) {
            cellsList.erase( next( cellsList.begin(), j ) );
        }
    }
}

void reApplyCellInList( list< list< int > >& cellsList, int val ) {
    for ( int j = 0; j < cellsList.size(); j++ ) {
        for ( int i = 0; i < getList( cellsList, j )->size(); i++ ) {
            if ( *( next( getList( cellsList, j )->begin(), i ) ) == -1 ) {
                // cout << "DEBUG : ERASING : i : " << i << " ; j : " << j << endl;
                *( next( getList( cellsList, j )->begin(), i ) ) = val;
            }
        }
    }
}

int main( int argc, char ** argv ) {

    string line = "";
    int gridCount = 0;

    while ( getline( cin, line ) ) {
        if ( line.empty() ) continue;

        stringstream ss( line );

        int m = 0;
        int n = 0;
        ss >> m >> n;

        if ( m == 0 && n == 0 ) break;

        list< list< int > > cellsList( n, list< int >() );

        for ( int i = 0; i < m; i++ ) {
            int row = i;
            if ( getline( cin, line ) ) {
                ss.clear();
                ss.str( line );

                for ( int j = 0; j < n; j++ ) {
                    int val = 0;
                    int col = j;
                    ss >> val;
                    getList( cellsList, j )->push_back( val );
                }
            }
        }

        int totalCellsCount = m * n;
        while ( getline( cin, line ) ) {
            ss.clear();
            ss.str( line );

            int row = 0;
            int col = 0;
            bool testCaseEnded = false;

            while ( ss >> row >> col ) {
                if ( row == 0 && col == 0 ) {
                    testCaseEnded = true;
                    break;
                }
                pair< int, int > cellsRemovedInfo = deleteCellInList( cellsList, row - 1, col - 1 );
                if ( cellsRemovedInfo.first > 1 ) {
                    totalCellsCount -= cellsRemovedInfo.first;
                    cleanCellInList( cellsList );
                } else {
                    reApplyCellInList( cellsList, cellsRemovedInfo.second );
                }
            }

            if ( testCaseEnded ) break;
        }
        
        if ( gridCount > 0 ) {
            cout << endl;
        }

        cout << "Grid " << gridCount + 1 << "." << endl;
        if ( totalCellsCount == 0 ) {
            cout << "    Game Won" << endl;
        } else {
            vector< vector< string > > printVec( m, vector< string >( n, " " ) );
            for ( int i = 0; i < cellsList.size(); i++ ) {
                for ( int j = 0; j < getList( cellsList, i )->size(); j++ ) {
                    printVec[ m - j - 1 ][ i ] = getCellInList( cellsList, j, i );
                }
            }

            for ( int i = 0; i < printVec.size(); i++ ) {
                cout << "    ";
                for ( int j = 0; j < printVec[ i ].size(); j++ ) {
                    cout << printVec[ i ][ j ];

                    if ( j < printVec[ i ].size() - 1 ) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
        ++gridCount;
    }

    return 0;
}
