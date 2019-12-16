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
#include <iterator>
#include <utility>
#include <algorithm>
#include <memory>
#include <cctype>
#include <stdexcept>
#include <limits>
#include <numeric>

//----< iostream >----------//
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

//----< cstdio >------------//
using std::printf;
using std::fprintf;
using std::sprintf;
using std::snprintf;

//----< iomanip >-----------//
using std::setprecision;
using std::setw;

//----< ios >---------------//
using std::hex;
using std::dec;
using std::oct;
using std::fixed;

//----< sstream >-----------//
using std::stringstream;
using std::ostringstream;
using std::istringstream;

//----< fstream >-----------//
using std::ofstream;
using std::ifstream;

//----< string >------------//
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;

//----< cmath >-------------//
using std::sqrt;
using std::pow;
using std::log;             // log( <arg> )
using std::exp;             // e ^ <arg>
using std::abs;
using std::floor;           // Round down to nearest integer double
using std::ceil;            // Round up to nearest integer double
using std::trunc;           // Truncate the fractional part to get the integer part
using std::round;           // Round to nearest integer double

//----< cstdlib >-----------//
using std::rand;
using std::srand;

//----< ctime >-------------//
using std::time;

//----< functional >--------//
using std::hash;
using std::greater;         // lhs > rhs. Used for MinPQ
using std::less;            // lhs < rhs. Used for MaxPQ. Default for priority_queue<>
using std::less_equal;
using std::greater_equal;

//----< array >-------------//
using std::array;           // Fixed & Unordered Array

//----< vector >------------//
using std::vector;          // Resizable & Unordered Array

//----< map >---------------//
using std::map;             // Ordered Map (Red-Black Tree)

//----< unordered_map >-----//
using std::unordered_map;   // HashMap (SeparateChainingHashST)

//----< set >---------------//
using std::set;             // Ordered Set (Red-Black Tree)

//----< unordered_set >-----//
using std::unordered_set;   // HashSet (SeparateChainingHashST)

//----< list >--------------//
using std::list;            // Doubly-Linked List with size() ( O( 1 ) )

//----< forward_list >------//
using std::forward_list;    // Singly-Linked List without size() function ( so O( N ) if we need to get size() )

//----< deque >-------------//
using std::deque;           // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque

//----< queue >-------------//
using std::queue;           // Non-Iterable & Use std::deque as underlying data structure
using std::priority_queue;  // MaxPQ (MaxHeap) & Non-Iterable.
//                          // => Pass std::greater<> as template params to create MinPQ (MinHeap)

//----< stack >-------------//
using std::stack;           // Non-Iterable & Use std::deque as underlying data structure

//----< iterator >----------//
using std::next;            // Return an advanced iter without changing original iter
using std::prev;            // Return an decremented iter without changing original iter
using std::distance;        // Calculate distance between 2 iterators

//----< utility >-----------//
using std::pair;
using std::make_pair;
using std::move;            // Move resources between objects - typically used with std::unique_ptr<T>

//----< algorithm >---------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;
using std::remove;
using std::swap;

//----< memory >------------//
// using std::make_unique;
using std::unique_ptr;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

//----< cctype >------------//
using std::isalnum;
using std::isalpha;
using std::islower;
using std::isupper;
using std::isdigit;
using std::isspace;         // Check whether char is whitespace character (space, newline, tab, etc. )
using std::isblank;         // Check whether char is blank character ( space or tab )
using std::tolower;
using std::toupper;

//----< stdexcept >---------//
using std::runtime_error;
using std::invalid_argument;
using std::out_of_range;

//----< limits >------------//
using std::numeric_limits;

//----< numeric >-----------//
using std::iota;
// using std::gcd;
// using std::lcm;

//--------------------------//

char getSuit( const string& card ) {
    return card[ 1 ];
}

char getRank( const string& card ) {
    return card[ 0 ];
}

int getSuitIndex( char c ) {
    switch ( c ) {
        case 'S':
        {
            return 0;
        }

        case 'H':
        {
            return 1;
        }

        case 'D':
        {
            return 2;
        }

        case 'C':
        {
            return 3;
        }

        default:
        {
            return -1;
        }
    }
}

char getSuitName( int index ) {
    switch ( index ) {
        case 0:
        {
            return 'S';
        }

        case 1:
        {
            return 'H';
        }

        case 2:
        {
            return 'D';
        }

        case 3:
        {
            return 'C';
        }

        default:
        {
            return '\0';
        }
    }
}

int main( int argc, char ** argv ) {

    string line = "";
    while ( getline( cin, line ) ) {
        stringstream ss( line );

        vector< string > cardsVec( 13 );

        vector< char > suitNames = { 'S', 'H', 'D', 'C' };
        vector< int > suitCount( 4, 0 );

        vector< int > aceSuitCount( 4, 0 );
        vector< int > kingSuitCount( 4, 0 );
        vector< int > queenSuitCount( 4, 0 );
        vector< int > jackSuitCount( 4, 0 );
        vector< bool > suitStopped( 4, false );
        int point = 0;

        for ( int i = 0; i < cardsVec.size(); i++ ) {
            ss >> cardsVec[ i ];
            
            int suitIndex = getSuitIndex( getSuit( cardsVec[ i ] ) );
            ++suitCount[ suitIndex ];

            // 1. Each ace counts 4 points. Each king counts 3 points. Each queen counts 2 points. Each jack
            // counts one point.
            switch ( getRank( cardsVec[ i ] ) ) {
                case 'A':
                {
                    point += 4;
                    ++aceSuitCount[ suitIndex ];
                    suitStopped[ suitIndex ] = true;
                    break;
                }

                case 'K':
                {
                    point += 3;
                    ++kingSuitCount[ suitIndex ];
                    break;
                }

                case 'Q':
                {
                    point += 2;
                    ++queenSuitCount[ suitIndex ];
                    break;
                }

                case 'J':
                {
                    point += 1;
                    ++jackSuitCount[ suitIndex ];
                    break;
                }

                default:
                {
                    break;
                }
            }

        }
        
        // 2. Subtract a point for any king of a suit in which the hand holds no other cards.
        for ( int i = 0; i < kingSuitCount.size(); i++ ) {
            if ( kingSuitCount[ i ] > 0 ) {
                if ( suitCount[ i ] == 1 ) {
                    --point;
                } else if ( suitCount[ i ] >= 2 ) {
                    suitStopped[ i ] = true;
                }
            }
        }

        // 3. Subtract a point for any queen in a suit in which the hand holds only zero or one other cards.
        for ( int i = 0; i < kingSuitCount.size(); i++ ) {
            if ( queenSuitCount[ i ] > 0 ) {
                if ( suitCount[ i ] <= 2 ) {
                    --point;
                } else if ( suitCount[ i ] >= 3 ) {
                    suitStopped[ i ] = true;
                }
            }
        }

        // 4. Subtract a point for any jack in a suit in which the hand holds only zero, one, or two other cards.
        for ( int i = 0; i < jackSuitCount.size(); i++ ) {
            if ( jackSuitCount[ i ] > 0 ) {
                if ( suitCount[ i ] <= 3 ) {
                    --point;
                }
            }
        }

        int noTrumpPoint = point;
        int maxSuitIndex = 0;

        for ( int i = 0; i < suitCount.size(); i++ ) {
            switch ( suitCount[ i ] ) {
                case 0:
                {
                    // 7. Add two points for each suit in which the hand contains no cards.
                    point += 2;
                    break;
                }
                
                case 1:
                {
                    // 6. Add two points for each suit in which the hand contains exactly one card.
                    point += 2;
                    break;
                }
                
                case 2:
                {
                    // 5. Add a point for each suit in which the hand contains exactly two cards.
                    ++point;
                    break;
                }

                default:
                {
                    break;
                }
            }

            if ( suitCount[ i ] > suitCount[ maxSuitIndex ] )  {
                maxSuitIndex = i;
            }
        }

        bool isAllStopped = suitStopped[ 0 ] && suitStopped[ 1 ] && suitStopped[ 2 ] && suitStopped[ 3 ];

        if ( point < 14 ) {
            cout << "PASS" << endl;
        } else {
            if ( noTrumpPoint >= 16 && isAllStopped ) {
                cout << "BID NO-TRUMP" << endl;
            } else {
                cout << "BID " << getSuitName( maxSuitIndex ) << endl;
            }
        }


        // A suit is stopped if it contains an ace, or if it contains a king and at least one other card, or if it
        // contains a queen and at least two other cards.

        // During the opening assessment, the three most common possibilities are:
        //
        // • If the hand evaluates to fewer than 14 points, then the player must pass.
        //
        // • One may open bidding in a suit if the hand evaluates to 14 or more points. Bidding is always
        // opened in one of the suits with the most cards.
        //
        // • One may open bidding in “no trump” if the hand evaluates to 16 or more points ignoring rules
        //
        // 5, 6, and 7 and if all four suits are stopped. A no trump bid is always preferred over a suit bid
        // when both are possible.
        //
    }

    return 0;
}
