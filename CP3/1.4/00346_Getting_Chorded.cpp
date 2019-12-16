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

namespace Chord {
    unordered_map< string, string > COMMON_NAMES_TO_NAMES = {
        { "BB", "A#" },
        { "DB", "C#" },
        { "EB", "D#" },
        { "GB", "F#" },
        { "AB", "G#" },
        { "CB", "B" },
        { "FB", "E" },
        { "B#", "C" },
        { "E#", "F" },
    };

    static int CHORD_COUNT = 12;

    unordered_map< string, int > NAMES_TO_INDEXES = {
        { "A",  0 },
        { "A#", 1 },
        { "B",  2 },
        { "C",  3 },
        { "C#", 4 },
        { "D",  5 },
        { "D#", 6 },
        { "E",  7 },
        { "F",  8 },
        { "F#", 9 },
        { "G",  10 },
        { "G#", 11 },

        { "BB", 1 },  // A#
        { "CB", 2 },  // B
        { "B#", 3 },  // C
        { "DB", 4 },  // C#
        { "EB", 6 },  // D#
        { "FB", 7 },  // E
        { "E#", 8 },  // F
        { "GB", 9 },  // F#
        { "AB", 11 }, // G#
    };

    static string toUpperCase( const string& s ) {
        string rvStr = s;
        for ( int i = 0; i < rvStr.size(); i++ ) {
            if ( isalpha( rvStr[ i ] ) ) {
                rvStr[ i ] = toupper( rvStr[ i ] );
            }
        }
        return rvStr;
    }

    enum ChordType {
        CHORD_MAJOR,
        CHORD_MINOR,
        CHORD_UNKNOWN,
    };
};

int main( int argc, char ** argv ) {

    //
    // We'll have an unordered_map< string, string > of common names of notes
    // to real names of notes ( all uppercase )
    //
    // We'll have an unordered_map< string, int > of indexes of each note
    //
    // We'll have an auxiliary function to return toUpperCase() names of notes
    //

    string line = "";

    while ( getline( cin, line ) ) {
        stringstream ss( line );

        vector< string > notesVec( 3 );
        ss >> notesVec[ 0 ] >> notesVec[ 1 ] >> notesVec[ 2 ];

        map< int, string > notesMap;
        for ( int i = 0; i < notesVec.size(); i++ ) {
            if ( Chord::COMMON_NAMES_TO_NAMES.find( Chord::toUpperCase( notesVec[ i ] ) ) != Chord::COMMON_NAMES_TO_NAMES.end() ) {
                notesMap.insert( { Chord::NAMES_TO_INDEXES[ Chord::toUpperCase( notesVec[ i ] ) ], Chord::COMMON_NAMES_TO_NAMES[ Chord::toUpperCase( notesVec[ i ] ) ] } );
            } else {
                notesMap.insert( { Chord::NAMES_TO_INDEXES[ Chord::toUpperCase( notesVec[ i ] ) ], Chord::toUpperCase( notesVec[ i ] ) } );
            }
        }

        map< int, string >::iterator firstIter = notesMap.begin();
        map< int, string >::iterator secondIter = next( firstIter, 1 );
        map< int, string >::iterator thirdIter = next( firstIter, 2 );

        int distFirstSecond = secondIter->first - firstIter->first;
        int distSecondThird = thirdIter->first - secondIter->first;
        int distThirdFirst = Chord::CHORD_COUNT - ( thirdIter->first - firstIter->first );

        Chord::ChordType chordType = Chord::CHORD_UNKNOWN;
        string chordName = "";

        if ( distFirstSecond == 4 && distSecondThird == 3 ) {
            chordType = Chord::CHORD_MAJOR;
            chordName = firstIter->second;
        } else if ( distSecondThird == 4 && distThirdFirst == 3 ) {
            chordType = Chord::CHORD_MAJOR;
            chordName = secondIter->second;
        } else if ( distThirdFirst == 4 && distFirstSecond == 3 ) {
            chordType = Chord::CHORD_MAJOR;
            chordName = thirdIter->second;
        } else if ( distFirstSecond == 3 && distSecondThird == 4 ) {
            chordType = Chord::CHORD_MINOR;
            chordName = firstIter->second;
        } else if ( distSecondThird == 3 && distThirdFirst == 4 ) {
            chordType = Chord::CHORD_MINOR;
            chordName = secondIter->second;
        } else if ( distThirdFirst == 3 && distFirstSecond == 4 ) {
            chordType = Chord::CHORD_MINOR;
            chordName = thirdIter->second;
        }

        chordName = Chord::toUpperCase( chordName );
        if ( Chord::COMMON_NAMES_TO_NAMES.find( chordName ) != Chord::COMMON_NAMES_TO_NAMES.end() ) {
            chordName = Chord::COMMON_NAMES_TO_NAMES[ chordName ];
        }

        switch ( chordType ) {
            case Chord::CHORD_MAJOR:
            {
                cout << notesVec[ 0 ] << " " << notesVec[ 1 ] << " " << notesVec[ 2 ] << " is a " << chordName << " Major chord." << endl;
                break;
            }

            case Chord::CHORD_MINOR:
            {
                cout << notesVec[ 0 ] << " " << notesVec[ 1 ] << " " << notesVec[ 2 ] << " is a " << chordName << " Minor chord." << endl;
                break;
            }

            case Chord::CHORD_UNKNOWN:
            {
                cout << notesVec[ 0 ] << " " << notesVec[ 1 ] << " " << notesVec[ 2 ] << " is unrecognized." << endl;
                break;
            }
        }
    }

    return 0;
}
