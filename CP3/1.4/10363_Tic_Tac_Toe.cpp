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

pair< unordered_map< char, int >, int > getWonCount( const vector< vector< char > >& boardVec ) {
    pair< unordered_map< char, int >, int > rvPair = { { { '.', '0' }, { 'X', 0 }, { 'O', 0 } }, 0 };

    // Top-bottom
    for ( int i = 0; i < boardVec.size(); i++ ) {
        bool rowEqual = true;
        char firstVal = boardVec[ i ][ 0 ];

        if ( firstVal == '.' ) continue;

        for ( int j = 1; j < boardVec[ i ].size(); j++ ) {
            if ( boardVec[ i ][ j ] != firstVal ) {
                rowEqual = false;
                break;
            }

            if ( boardVec[ i ][ j ] != boardVec[ i ][ j - 1 ] ) {
                rowEqual = false;
                break;
            }
        }

        if ( rowEqual ) {
            ++rvPair.first[ firstVal ];
            ++rvPair.second;
        }
    }

    
    // Left-right
    for ( int j = 0; j < boardVec[ 0 ].size(); j++ ) {
        bool colEqual = true;
        char firstVal = boardVec[ 0 ][ j ];

        if ( firstVal == '.' ) continue;

        for ( int i = 1; i < boardVec.size(); i++ ) {
            if ( boardVec[ i ][ j ] != firstVal ) {
                colEqual = false;
                break;
            }

            if ( boardVec[ i ][ j ] != boardVec[ i - 1 ][ j ] ) {
                colEqual = false;
                break;
            }
        }

        if ( colEqual ) {
            ++rvPair.first[ firstVal ];
            ++rvPair.second;
        }
    }

    // Top-left - Bot-right diagonal
    if ( boardVec[ 0 ][ 0 ] != '.'
            && boardVec[ 0 ][ 0 ] == boardVec[ 1 ][ 1 ]
            && boardVec[ 1 ][ 1 ] == boardVec[ 2 ][ 2 ] ) {
        ++rvPair.first[ boardVec[ 0 ][ 0 ] ];
        ++rvPair.second;
    }
    
    // Top-right - Bot-left diagonal
    if ( boardVec[ 0 ][ 2 ] != '.'
            && boardVec[ 0 ][ 2 ] == boardVec[ 1 ][ 1 ]
            && boardVec[ 1 ][ 1 ] == boardVec[ 2 ][ 0 ] ) {
        ++rvPair.first[ boardVec[ 0 ][ 2 ] ];
        ++rvPair.second;
    }

    return rvPair;
}

int main( int argc, char ** argv ) {

    string line = "";
    int N = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> N;
    }

    for ( int t = 0; t < N; t++ ) {
        int xCount = 0;
        int oCount = 0;
        int dotCount = 0;
        vector< vector< char > > boardVec( 3, vector< char >( 3, '.' ) );

        for ( int i = 0; i < 3; i++ ) {
            if ( getline( cin, line ) ) {
                for ( int j = 0; j < line.size(); j++ ) {
                    if ( line[ j ] == '.' ) {
                        ++dotCount;
                    } else if ( line[ j ] == 'X' ) {
                        ++xCount;
                    } else if ( line[ j ] == 'O' ) {
                        ++oCount;
                    }
                    boardVec[ i ][ j ] = line[ j ];
                }
            }
        }

        if ( xCount < oCount || abs( xCount - oCount ) > 1 ) {
            cout << "no";
        } else {
            pair< unordered_map< char, int >, int > rvPair = getWonCount( boardVec );
            if ( rvPair.second > 1 ) {
                if ( rvPair.first[ 'X' ] > 1 && xCount > oCount ) {
                    cout << "yes";
                } else {
                    cout << "no";
                }
            } else {
                if ( ( rvPair.first[ 'O' ] == 1 && xCount > oCount )
                        || ( rvPair.first[ 'X' ] == 1 && xCount <= oCount ) ) {
                    cout << "no";
                } else {
                    cout << "yes";
                }
            }
        }
        cout << endl;

        getline( cin, line );
    }

    return 0;
}
