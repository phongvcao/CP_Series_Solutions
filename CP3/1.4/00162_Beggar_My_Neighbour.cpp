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

bool isFace( const string& card ) {
    return ( ( card[ 1 ] == 'A' ) || ( card[ 1 ] == 'K' ) || ( card[ 1 ] == 'Q' ) || ( card[ 1 ] == 'J' ) );
}

int main( int argc, char ** argv ) {

    bool quit = false;
    while ( true ) {

        string line = "";
        vector< deque< string > > playersDeque( 2 );
        int cardCount = 1;

        for ( int i = 0; i < 4; i++ ) {
            if ( getline( cin, line ) ) {
                if ( line == "#" ) {
                    quit = true;
                    break;
                }

                stringstream ss( line );
                for ( int j = 0; j < 13; j++ ) {
                    string card = "";
                    ss >> card;
                    playersDeque[ cardCount % 2 ].push_back( card );
                    ++cardCount;
                }
            }
        }

        if ( quit ) break;

        string curCard = "";
        int turn = 1;
        deque< string > table;
        int cardPlay = 1;
        int faceCardCount = 0;
        int faceCardTurn = -1;
        int faceCardNum = 16;
        int covering = -1;
        while ( cardPlay > 0 ) {
            --cardPlay;

            if ( playersDeque[ turn % 2 ].empty() ) {
                int winnerIdx = ( turn + 1 ) % 2;
                int size = playersDeque[ winnerIdx ].size();
                printf( "%d %2d\n", winnerIdx + 1, size );
                break;
            }

            //
            // The non-dealer starts the game by playing the top card of her
            // deck (the second last card dealt) face up on the table.
            // The dealer then covers it by playing her top card face up.
            //
            curCard = playersDeque[ turn % 2 ].back();
            table.push_back( curCard );
            playersDeque[ turn % 2 ].pop_back();

            //
            // Play continues in this fashion until a “face” card (Ace, King, Queen or Jack) is played.
            //
            // The next player must then “cover” that card, by playing one card for a Jack, two for a
            // Queen, three for a King and four for an Ace.
            //
            // If a face card is played at any stage during this sequence,
            // play switches and the other player must cover that card. 
            //

            if ( curCard[ 1 ] == 'J' ) {
                cardPlay = 1;
                covering = ( turn + 1 ) % 2;
                ++faceCardCount;
                faceCardTurn = turn;
            } else if ( curCard[ 1 ] == 'Q' ) {
                cardPlay = 2;
                covering = ( turn + 1 ) % 2;
                ++faceCardCount;
                faceCardTurn = turn;
            } else if ( curCard[ 1 ] == 'K' ) {
                cardPlay = 3;
                covering = ( turn + 1 ) % 2;
                ++faceCardCount;
                faceCardTurn = turn;
            } else if ( curCard[ 1 ] == 'A' ) {
                cardPlay = 4;
                covering = ( turn + 1 ) % 2;
                ++faceCardCount;
                faceCardTurn = turn;
            } else {
                //
                // When this sequence has ended, the player who exposed the last face card takes the entire heap,
                // placing it face down under her existing deck.
                //
                // She then starts the next round by playing one card face up as before, 
                // and play continues until one player cannot play when called upon to do so,
                // because they have no more cards
                //
                if ( covering != turn % 2 ) {
                    cardPlay = 1;
                } else {
                    if ( cardPlay == 0 ) {
                        // covering sequence ended
                        while ( ! table.empty() ) {
                            playersDeque[ faceCardTurn % 2 ].push_front( table.front() );
                            table.pop_front();
                        }

                        faceCardTurn = -1;
                        covering = -1;
                        cardPlay = 1;
                    }
                }
            }

            if ( covering != turn % 2 ) {
                ++turn;
            }
        }
    }

    return 0;
}
