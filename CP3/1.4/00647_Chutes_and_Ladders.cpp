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

class Square {
public:

    static const int SQUARE_NORMAL;
    static const int SQUARE_LADDER_CHUTE;
    static const int SQUARE_LOSE_TURN;
    static const int SQUARE_EXTRA_TURN;
    static const int SQUARE_UNKNOWN;

    int index = -1;
    int type = SQUARE_NORMAL;

    // Only for ladder/chute
    int endIndex = -1;

    Square() {
        // not implemented
    }

    Square( int index )
        : index( index )
    {
        // not implemented
    }

    Square( const Square& other )
        : index( other.index ),
          type( other.type ),
          endIndex( other.endIndex )
    {
        // not implemented
    }

    virtual ~Square() {
        // not implemented
    }

};

const int Square::SQUARE_NORMAL = 0;
const int Square::SQUARE_LADDER_CHUTE = 1;
const int Square::SQUARE_LOSE_TURN = 2;
const int Square::SQUARE_EXTRA_TURN = 3;
const int Square::SQUARE_UNKNOWN = 4;

class Player {
public:

    int index = -1;
    int throwsIndex = 0;
    int squareIndex = 0;
    bool skip = false;
    bool extra = false;
    bool isWinner = false;
    vector< int > throwsVec;

    Player() {
        // not implemented
    }

    Player( int index, int squareIndex )
        : index( index ),
          squareIndex( index )
    {
        // not implemented
    }

    Player( const Player& player )
        : index( player.index ),
          squareIndex( player.squareIndex )
    {
        // not implemented
    }

    virtual ~Player() {
        // not implemented
    }

};

int main( int argc, char ** argv ) {

    string line = "";
    stringstream ss( line );
    vector< int > throwsVec;

    while ( true ) {
        int dieNum = -1;

        if ( throwsVec.empty() ) {
            if ( getline( cin, line ) ) {
                ss.clear();
                ss.str( line );
            }
        }

        while ( dieNum != 0 && ss >> dieNum ) {
            throwsVec.push_back( dieNum );
        }

        if ( dieNum != 0 ) {
            if ( getline( cin, line ) ) {
                ss.clear();
                ss.str( line );
            }
        } else {
            break;
        }
    }

    while ( getline( cin, line ) ) {
        ss.clear();
        ss.str( line );

        int numPlayers = 0;
        ss >> numPlayers;

        if ( numPlayers == 0 ) break;

        vector< Player > playersVec( numPlayers );
        vector< Square > squaresVec( 101 );
        for ( int i = 0; i < squaresVec.size(); i++ ) {
            squaresVec[ i ].index = i;
        }

        // Get ladders / chutes
        while ( getline( cin, line ) ) {
            if ( line == "0 0" ) {
                break;
            }

            ss.clear();
            ss.str( line );

            int beginIndex = -1;
            int endIndex = -1;
            ss >> beginIndex >> endIndex;

            squaresVec[ beginIndex ].type = Square::SQUARE_LADDER_CHUTE;
            squaresVec[ beginIndex ].endIndex = endIndex;
        }

        for ( int i = 0; i < throwsVec.size(); i++ ) {
            playersVec[ i % playersVec.size() ].throwsVec.push_back( throwsVec[ i ] );
        }

        // Get lose turn / extra turn
        while ( getline( cin, line ) ) {
            if ( line == "0" ) {
                break;
            }

            ss.clear();
            ss.str( line );

            int index = -1;
            ss >> index;
            
            if ( index < 0 ) {
                squaresVec[ abs( index ) ].type = Square::SQUARE_LOSE_TURN;
            } else {
                squaresVec[ index ].type = Square::SQUARE_EXTRA_TURN;
            }
        }

        // Game start
        int winnerCount = 0;
        for ( int i = 0; i < playersVec.size(); i++ ) {
            for ( int j = 0; j < playersVec[ i ].throwsVec.size(); j++ ) {
                if ( playersVec[ i ].isWinner ) break;

                if ( playersVec[ i ].squareIndex + playersVec[ i ].throwsVec[ j ] > squaresVec.size() - 1 ) {
                    continue;
                }

                if ( playersVec[ i ].squareIndex == squaresVec.size() - 1 ) {
                    playersVec[ i ].isWinner = true;
                    ++winnerCount;
                    break;
                }

                playersVec[ i ].squareIndex += playersVec[ i ].throwsVec[ j ];

                switch ( squaresVec[ playersVec[ i ].squareIndex ].type ) {
                    case Square::SQUARE_NORMAL:
                    {
                        // This is not the winning step since winners are already
                        // declared above
                        break;
                    }

                    case Square::SQUARE_LADDER_CHUTE:
                    {
                        // We probably won't have ladders/chutes at the last square
                        // If we're here, follow the ladder/chute
                        playersVec[ i ].squareIndex = squaresVec[ playersVec[ i ].squareIndex ].endIndex;
                        break;
                    }

                    case Square::SQUARE_LOSE_TURN:
                    {
                        // Here player loses turn
                        playersVec[ i ].skip = true;
                        break;
                    }

                    case Square::SQUARE_EXTRA_TURN:
                    {
                        // Here player gets an extra turn
                        playersVec[ i ].extra = true;
                        break;
                    }

                    default:
                    {
                        break;
                    }
                }

                if ( playersVec[ i ].squareIndex == squaresVec.size() - 1 ) {
                    playersVec[ i ].isWinner = true;
                    ++winnerCount;
                    break;
                }
                
            }
            
        }

        cout << winnerCount << endl;
    }


    return 0;
}
