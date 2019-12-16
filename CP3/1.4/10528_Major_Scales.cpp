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



int main( int argc, char ** argv ) {

    vector< string > notesVec = { "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };
    unordered_map< string, int > notesIdxMap = {
        { "C",   0 },
        { "C#",  1 },
        { "D",   2 },
        { "D#",  3 },
        { "E",   4 },
        { "F",   5 },
        { "F#",  6 },
        { "G",   7 },
        { "G#",  8 },
        { "A",   9 },
        { "A#", 10 },
        { "B",  11 },
    };
    vector< int > notesSteps = { 2, 2, 1, 2, 2, 2, 1 };

    // Key is note
    // Values are all scales that the note is in
    unordered_map< string, set< string > > scalesMap;

    for ( int i = 0; i < notesVec.size(); i++ ) {
        if ( scalesMap.find( notesVec[ i ] ) == scalesMap.end() ) {
            scalesMap.insert( { notesVec[ i ], set< string >() } );
            int notesVecIdx = i;

            for ( int j = 0; j < notesSteps.size(); j++ ) {
                scalesMap[ notesVec[ i ] ].insert( notesVec[ notesVecIdx % notesVec.size() ] );
                notesVecIdx += notesSteps[ j ];
            }
        }
    }
    // Key is note
    // Values are all scales that the note is in
    unordered_map< string, set< string > > notesToScalesMap;
    for ( unordered_map< string, set< string > >::iterator iter = scalesMap.begin();
            iter != scalesMap.end(); iter++ ) {
        for ( const string& s : iter->second ) {
            if ( notesToScalesMap.find( s ) == notesToScalesMap.end() ) {
                notesToScalesMap.insert( { s, set< string >() } );
            }

            notesToScalesMap[ s ].insert( iter->first );
        }
    }

    string line = "";
    while ( getline( cin, line ) ) {
        if ( line == "END" ) break;

        stringstream ss( line );
        set< string > intersectSet;

        string note = "";
        int readIdx = 0;
        while ( ss >> note ) {
            if ( readIdx == 0 ) {
                intersectSet = notesToScalesMap[ note ];
            } else {
                set< string > resultSet;
                set< string > notesSet = notesToScalesMap[ note ];

                set_intersection( intersectSet.begin(), intersectSet.end(),
                                  notesSet.begin(), notesSet.end(),
                                  inserter( resultSet, resultSet.begin() ) );
                intersectSet = resultSet;

                if ( intersectSet.empty() ) {
                    break;
                }
            }
            ++readIdx;
        }

        if ( intersectSet.empty() ) {
            cout << endl;
        } else {
            vector< bool > scalesUsedVec( notesVec.size(), false );
            int usedCount = 0;
            for ( const string& s : intersectSet ) {
                scalesUsedVec[ notesIdxMap[ s ] ] = true;
                ++usedCount;
            }

            int usedCountIdx = 0;
            for ( int i = 0; i < notesVec.size(); i++ ) {
                if ( scalesUsedVec[ i ] ) {
                    cout << notesVec[ i ];
                    if ( usedCountIdx < usedCount - 1 ) {
                        cout << " ";
                    }
                    ++usedCountIdx;
                }
            }
            cout << endl;
        }
    }

    return 0;
}
