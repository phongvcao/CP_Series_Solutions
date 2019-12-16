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
using std::sort;                // Intro-Sort elements, but NOT preserve original order of equal elements
using std::partial_sort;        // Sort elements in range ( iterFirst, iterLast ) ( exclusively )
using std::stable_sort;         // Merge-Sort elements & preserve original order of equal elements
using std::remove;
using std::swap;
using std::binary_search;
using std::next_permutation;

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

class Event {
public:

    static const int NOTE_ON = 1;
    static const int NOTE_OFF = 0;
    static const int TICK_STEP = 60;

    int index = -1;
    int code = NOTE_ON;
    int note = 0;
    int m = 0;
    int b = 0;
    int t = 0;

    bool isValid = true;
    
    Event() {
        // not implemented
    }

    Event( const Event& other )
        : index( other.index ),
          code( other.code ),
          note( other.note ),
          m( other.m ),
          b( other.b ),
          t( other.t ),
          isValid( other.isValid )
    {
        // not implemented
    }

    virtual ~Event() {
        // not implemented
    }

    int getBeforeRoundT() const {
        return ( int )( round( ( double )t / ( double )TICK_STEP ) * ( double )TICK_STEP );
    }

    int getRoundT() const {
        int newT = getBeforeRoundT();
        if ( newT == 480 ) {
            return 0;
        }
        return newT;
    }

    int getRoundB() const {
        int newT = getBeforeRoundT();
        if ( newT == 480 ) {
            if ( b == 4 ) {
                return 1;
            } else {
                return b + 1;
            }
        } else {
            return b;
        }
    }

    int getRoundM() const {
        int newT = getBeforeRoundT();

        if ( newT == 480 ) {
            if ( b == 4 ) {
                return m + 1;
            } else {
                return m;
            }
        } else {
            return m;
        }
    }

    friend bool operator <( const Event& e1, const Event& e2 ) {
        return e1.index < e2.index;
    }

    friend bool operator >( const Event& e1, const Event& e2 ) {
        return e1.index > e2.index;
    }

    friend bool operator ==( const Event& e1, const Event& e2 ) {
        return ( e1.getRoundT() == e2.getRoundT()
                 && e1.getRoundB() == e2.getRoundB()
                 && e1.getRoundM() == e2.getRoundM() );
    }

    friend bool operator !=( const Event& e1, const Event& e2 ) {
        return ! ( e1 == e2 );
    }

    operator bool() const {
        return isValid;
    }

    friend ostream& operator <<( ostream& out, const Event& event ) {
        out << event.code << " " << event.note << " " << event.getRoundM()
            << " " << event.getRoundB() << " " << event.getRoundT();
        return out;
    }

};

int main( int argc, char ** argv ) {

    string line = "";

    while ( getline( cin, line ) ) {
        if ( line == "-1" ) break;

        stringstream ss( line );
        int N = 0;

        ss >> N;

        // Key is event.code
        // Key of unordered_map is event.note
        vector< unordered_map< int, Event * > > notesMapVec( 2, unordered_map< int, Event * >() );

        // Key is index
        vector< Event > eventsVec;

        int eventCount = 0;
        for ( int n = 0; n < N; n++ ) {
            if ( getline( cin, line ) ) {
                ss.clear();
                ss.str( line );

                ++eventCount;
                Event event;
                event.index = n;
                ss >> event.code >> event.note >> event.m >> event.b >> event.t;

                // If this is a NoteOff event, we look for NoteOn event before it
                // and set isValid of both to "false" if these 2 events are "equal"
                if ( event.code == Event::NOTE_OFF ) {
                    if ( *notesMapVec[ Event::NOTE_ON ][ event.note ] == event ) {
                        eventsVec[ notesMapVec[ Event::NOTE_ON ][ event.note ]->index ].isValid = false;
                        event.isValid = false;
                        eventCount -= 2;
                    }
                }

                eventsVec.push_back( event );

                if ( notesMapVec[ event.code ].find( event.note ) != notesMapVec[ event.code ].end() ) {
                    notesMapVec[ event.code ][ event.note ] = &eventsVec.back();
                } else {
                    notesMapVec[ event.code ].insert( { event.note, &eventsVec.back() } );
                }
            }
        }

        cout << eventCount << endl;
        for ( int i = 0; i < eventsVec.size(); i++ ) {
            if ( eventsVec[ i ] ) {
                cout << eventsVec[ i ] << endl;
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
