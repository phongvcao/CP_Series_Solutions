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

namespace Bowling {
    class Frame {
    public:

        static const char FRAME_SPARE = '/';
        static const char FRAME_STRIKE = 'X';
        static const char FRAME_NORMAL = 'N';

        static const char ROLL_UNKNOWN = '\0';

        char firstRoll = ROLL_UNKNOWN;
        char secondRoll = ROLL_UNKNOWN;
        char frameType = FRAME_NORMAL;
        int index = -1;
        vector< Frame > * framesVec;

        Frame() {
            // not implemented
        }

        Frame( int index, vector< Frame > * framesVec )
            : index( index ),
              framesVec( framesVec )
        {
            // not implemented
        }

        Frame( const Frame& other )
            : firstRoll( other.firstRoll ),
              secondRoll( other.secondRoll )
        {
            // not implemented
        }

        virtual ~Frame() {
            // not implemented
        }

        void roll( char c ) {
            if ( c == '/' ) {
                frameType = FRAME_SPARE;
            } else if ( c == 'X' ) {
                frameType = FRAME_STRIKE;
            }

            if ( firstRoll == ROLL_UNKNOWN ) {
                firstRoll = c;
            } else if ( secondRoll == ROLL_UNKNOWN ) {
                secondRoll = c;
            }
        }

        int getScore() const {
            if ( frameType == FRAME_SPARE ) {
                //
                // If we have a SPARE here, the score of this frame would be
                // 10 + <_score_of_next_1_roll_>
                //   - If the next frame is a STRIKE, we +10 into 10
                //   - If the next frame is NOT a STRIKE, we +score of first roll
                //   of the next frame into 10
                //
                // Of course this means the spare has to be earned before the last
                // framesIndex
                //
                int finalScore = 10;
                if ( index < framesVec->size() - 1 ) {
                    if ( framesVec->at( index + 1 ).frameType == FRAME_STRIKE ) {
                        return finalScore + 10;
                    } else {
                        return finalScore + framesVec->at( index + 1 ).firstRoll - '0';
                    }
                }
                return finalScore;
            } else if ( frameType == FRAME_STRIKE ) {
                //
                // If we have a STRIKE here, the score of this frame would be
                // 10 + <_score_of_next_2_rolls_>
                //   - If next frame is STRIKE, we have to add score of roll after,
                //   if any.
                //     - If there is no frame after, that's it
                //     - If there is frame after
                //       - If it's STRIKE or SPARE, we add 10
                //       - If it's neither STRIKE nor SPARE, we add its score
                //   - If next frame is SPARE, we add 10
                //   - If next frame is NEITHER of the above, we just add score of
                //   next roll
                //
                int finalScore = 10;
                if ( index < framesVec->size() - 1 ) {
                    if ( framesVec->at( index + 1 ).frameType == FRAME_STRIKE ) {
                        finalScore += 10;
                        if ( index < framesVec->size() - 2 ) {
                            if ( framesVec->at( index + 2 ).frameType == FRAME_STRIKE ) {
                                finalScore += 10;
                            } else if ( framesVec->at( index + 2 ).frameType == FRAME_SPARE ) {
                                finalScore += framesVec->at( index + 2 ).firstRoll - '0';
                            } else {
                                finalScore += framesVec->at( index + 2 ).firstRoll - '0';
                            }
                        }
                    } else if ( framesVec->at( index + 1 ).frameType == FRAME_SPARE ) {
                        finalScore += 10;
                    } else {
                        finalScore += framesVec->at( index + 1 ).getScore();
                    }
                }
                return finalScore;
            } else {
                return ( firstRoll - '0' ) + ( secondRoll - '0' );
            }
        }

        friend ostream& operator <<( ostream& out, const Frame& fr ) {
            out << " | first : " << fr.firstRoll << " ; second : " << fr.secondRoll
                << " ; type : " << fr.frameType << " ; index : " << fr.index
                << " ; score : " << fr.getScore() << " | ";
            return out;
        }
    };
}

int main( int argc, char ** argv ) {

    string line = "";
    while ( getline( cin, line ) ) {
        if ( line == "Game Over" ) {
            break;
        }

        stringstream ss( line );
        vector< Bowling::Frame > framesVec( 12 );
        int framesIndex = 0;
        char roll = '\0';

        while ( ss >> roll ) {
            framesVec[ framesIndex ].roll( roll );
            framesVec[ framesIndex ].index = framesIndex;
            framesVec[ framesIndex ].framesVec = &framesVec;

            if ( roll == 'X'
                    || roll == '/'
                    || framesVec[ framesIndex ].secondRoll != Bowling::Frame::ROLL_UNKNOWN ) {
                ++framesIndex;
            }
        }

        int finalScore = 0;
        for ( int i = 0; i < 10; i++ ) {
            finalScore += framesVec[ i ].getScore();
        }
        cout << finalScore << endl;
    }

    return 0;
}
