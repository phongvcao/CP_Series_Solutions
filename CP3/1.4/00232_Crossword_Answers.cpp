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

namespace Crossword {
    class Square {
    public:
        static const char BLACK;

        int index = -1;
        char value = BLACK;
        // bool isBlack = false;

        Square() {
            // not implemented
        }

        Square( const Square& other )
            : index( other.index ),
              value( other.value )
        {
            // not implemented
        }

        virtual ~Square() {
            // not implemented
        }

        bool isBlack() const {
            return value == '*';
        }

        friend ostream& operator <<( ostream& out, const Square& sq ) {
            out << " | " << sq.value << " : " << sq.index << " : " << sq.isBlack() << " | ";
            return out;
        }
    };
}

const char Crossword::Square::BLACK = '*';

int main( int argc, char ** argv ) {

    string line = "";
    int gameCount = 0;

    while ( getline( cin, line ) ) {
        stringstream ss( line );

        if ( line == "0" ) break;

        int rowCount = 0;
        int colCount = 0;
        
        ss >> rowCount >> colCount;

        map< int, string > acrossMap;
        map< int, string > downMap;
        vector< vector< Crossword::Square > > puzzleVec( rowCount, vector< Crossword::Square >( colCount ) );
        int num = 1;
        for ( int i = 0; i < rowCount; i++ ) {
            if ( getline( cin, line ) ) {
                for ( int j = 0; j < line.size(); j++ ) {
                    puzzleVec[ i ][ j ].index = num;
                    puzzleVec[ i ][ j ].value = line[ j ];
                    if ( ( i == 0 || j == 0 || ( j > 0 && line[ j - 1 ] == Crossword::Square::BLACK ) || ( i > 0 && puzzleVec[ i - 1 ][ j ].isBlack() ) ) && line[ j ] != Crossword::Square::BLACK ) ++num;
                }
            }
        }

        for ( int i = 0; i < puzzleVec.size(); i++ ) {
            string acrossWord = "";
            int curNum = -1;
            for ( int j = 0; j < puzzleVec[ i ].size(); j++ ) {
                if ( ! puzzleVec[ i ][ j ].isBlack() ) {
                    if ( acrossWord.empty() ) {
                        curNum = puzzleVec[ i ][ j ].index;
                    }

                    acrossWord += puzzleVec[ i ][ j ].value;

                    if ( j == puzzleVec[ i ].size() - 1 ) {
                        acrossMap.insert( { curNum, acrossWord } );
                        curNum = -1;
                        acrossWord = "";
                    }
                } else {
                    if ( ! acrossWord.empty() ) {
                        acrossMap.insert( { curNum, acrossWord } );
                        curNum = -1;
                        acrossWord = "";

                    }
                }

            }
        }

        for ( int j = 0; j < puzzleVec[ 0 ].size(); j++ ) {
            string downWord = "";
            int curNum = -1;
            for ( int i = 0; i < puzzleVec.size(); i++ ) {
                if ( ! puzzleVec[ i ][ j ].isBlack() ) {
                    if ( downWord.empty() ) {
                        curNum = puzzleVec[ i ][ j ].index;
                    }

                    downWord += puzzleVec[ i ][ j ].value;

                    if ( i == puzzleVec.size() - 1 ) {
                        downMap.insert( { curNum, downWord } );
                        curNum = -1;
                        downWord = "";
                    }
                } else {
                    if ( ! downWord.empty() ) {
                        downMap.insert( { curNum, downWord } );
                        curNum = -1;
                        downWord = "";
                    }
                }
            }
        }

        if ( gameCount > 0 ) cout << endl;
        cout << "puzzle #" << gameCount + 1 << ":" << endl;
        cout << "Across" << endl;
        for ( map< int, string >::iterator iter = acrossMap.begin();
                iter != acrossMap.end(); iter++ ) {
            printf( "%3d.%s\n", iter->first, iter->second.c_str() );
        }
        cout << "Down" << endl;
        for ( map< int, string >::iterator iter = downMap.begin();
                iter != downMap.end(); iter++ ) {
            printf( "%3d.%s\n", iter->first, iter->second.c_str() );
        }
        ++gameCount;
    }

    return 0;
}
