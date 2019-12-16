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

bool isMagic( const string& orgStr ) {
    vector< vector< char > > squareVec(
            ( int ) sqrt( orgStr.size() ),
            vector< char >( ( int ) sqrt( orgStr.size() ), '\0' ) );

    int orgStrIdx = 0;
    for ( int i = 0; i < squareVec.size(); i++ ) {
        for ( int j = 0; j < squareVec[ i ].size(); j++ ) {
            squareVec[ i ][ j ] = orgStr[ orgStrIdx++ ];
        }
    }

    orgStrIdx = 0;
    for ( int j = 0; j < squareVec[ 0 ].size(); j++ ) {
        for ( int i = 0; i < squareVec.size(); i++ ) {
            if ( squareVec[ i ][ j ] != orgStr[ orgStrIdx++ ] ) {
                return false;
            }
        }
    }

    orgStrIdx = 0;
    for ( int i = squareVec.size() - 1; i >= 0; i-- ) {
        for ( int j = squareVec[ i ].size() - 1; j >= 0; j-- ) {
            if ( squareVec[ i ][ j ] != orgStr[ orgStrIdx++ ] ) {
                return false;
            }
        }
    }

    orgStrIdx = 0;
    for ( int j = squareVec[ 0 ].size() - 1; j >= 0; j-- ) {
        for ( int i = squareVec.size() - 1; i >= 0; i-- ) {
            if ( squareVec[ i ][ j ] != orgStr[ orgStrIdx++ ] ) {
                return false;
            }
        }
    }

    return true;
}

int main( int argc, char ** argv ) {

    string line = "";
    int T = 0;
    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> T;
    }

    for ( int t = 0; t < T; t++ ) {
        cout << "Case #" << t + 1 << ":" << endl;

        if ( getline( cin, line ) ) {
            string alphaStr = "";
            for ( int i = 0; i < line.size(); i++ ) {
                if ( isalpha( line[ i ] ) ) {
                    alphaStr += line[ i ];
                }
            }

            if ( alphaStr.empty() ) {
                cout << alphaStr.size() << endl;
                continue;
            }

            double squareVecSize = sqrt( alphaStr.size() );
            if ( squareVecSize != ( int ) squareVecSize ) {
                cout << "No magic :(" << endl;
                continue;
            }

            if ( isMagic( alphaStr ) ) {
                cout << ( int ) squareVecSize << endl;
            } else {
                cout << "No magic :(" << endl;
            }

        }
    }

    return 0;
}
