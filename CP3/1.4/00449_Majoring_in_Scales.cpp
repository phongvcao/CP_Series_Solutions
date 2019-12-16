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

namespace Scale {
    static vector< pair< string, string > > NOTES_ALTERNATE_VEC = {
        { "C" , "B#" },
        { "C#", "Db" },
        { "D" , ""   },
        { "D#", "Eb" },
        { "E" , "Fb" },
        { "F" , "E#" },
        { "F#", "Gb" },
        { "G" , ""   },
        { "G#", "Ab" },
        { "A",  ""   },
        { "A#", "Bb" },
        { "B",  "Cb" },
    };
    
    static unordered_map< string, int > NOTES_TO_INDEXES = {
        { "C",  0 },
        { "Db", 1 },
        { "D",  2 },
        { "Eb", 3 },
        { "E",  4 },
        { "F",  5 },
        { "Gb", 6 },
        { "G",  7 },
        { "Ab", 8 },
        { "A",  9 },
        { "Bb", 10 },
        { "B",  11 },
    };

    static unordered_map< string, int > DIRECTION_TO_INT = {
        { "UP",    1 },
        { "DOWN", -1 },
    };
    
    static unordered_map< string, int > INTERVAL_TO_DIST = {
        { "SECOND",  1 },
        { "THIRD",   2 },
        { "FOURTH",  3 },
        { "FIFTH",   4 },
        { "SIXTH",   5 },
        { "SEVENTH", 6 },
        { "OCTAVE",  7 },
    };

    static const vector< int > MAJOR_SCALE_DIST = {
        2, 2, 1, 2, 2, 2, 1
    };
    
    static const vector< string > MAJOR_NOTES_VEC = {
        "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B",
    };
    
    static unordered_map< string, int > MAJOR_TO_INDEXES = {
        { "C",  0 },
        { "Db", 1 },
        { "D",  2 },
        { "Eb", 3 },
        { "E",  4 },
        { "F",  5 },
        { "Gb", 6 },
        { "G",  7 },
        { "Ab", 8 },
        { "A",  9 },
        { "Bb", 10 },
        { "B",  11 },
    };

    static const char KEY_SHARP = '#';
    static const char KEY_FLAT = 'b';
    static const char KEY_NON = '\0';
}

int main( int argc, char ** argv ) {

    // We need auxiliary MAJOR_AUX_VEC vector< unordered_map< char, vector< string > > > which contains
    // mapping of INDEX -> '#', '\0' or 'b', vector< string > of possible notes in the major scale
    //
    // We need auxiliary MAJOR_AUX_COUNT_VEC vector< unordered_map< char, pair< bool, vector< int > > > which keeps
    // track of how many chars of each char of '#', '\0', 'b' has been used. If there's one that has been used
    // ( count == 2 ), we mark the .first value as false ( invalid )
    //
    // We need auxiliary MAJOR_AUX_MAP_VEC vector< unordered_map< char, unordered_map< string, int > > which keeps
    // track of NOTE-TO-INDEX information in the vector< string > innermost of MAJOR_AUX_VEC
    //

    vector< unordered_map< char, vector< string > > >
        MAJOR_AUX_VEC(
            Scale::NOTES_TO_INDEXES.size(),
            {
                { Scale::KEY_SHARP , vector< string >() },
                { Scale::KEY_FLAT  , vector< string >() },
                { Scale::KEY_NON   , vector< string >() },
            }
        );

    vector< unordered_map< char, pair< bool, vector< int > > > >
        MAJOR_AUX_COUNT_VEC(
            Scale::NOTES_TO_INDEXES.size(),
            {
                { Scale::KEY_SHARP , { true, vector< int >( 7, 0 ) } },
                { Scale::KEY_FLAT  , { true, vector< int >( 7, 0 ) } },
                { Scale::KEY_NON   , { true, vector< int >( 7, 0 ) } },
            }
        );

    vector< unordered_map< char, unordered_map< string, int > > >
        MAJOR_AUX_MAP_VEC(
            Scale::NOTES_TO_INDEXES.size(),
            {
                { Scale::KEY_SHARP , unordered_map< string, int >() },
                { Scale::KEY_FLAT  , unordered_map< string, int >() },
                { Scale::KEY_NON   , unordered_map< string, int >() },
            }
        );


    for ( int i = 0; i < Scale::MAJOR_NOTES_VEC.size(); i++ ) {
        int notesDist = 0;
        int majorIdx = i;

        for ( int j = 0; j < Scale::MAJOR_SCALE_DIST.size(); j++ ) {
            pair< string, string > notesPair = Scale::NOTES_ALTERNATE_VEC[ ( majorIdx + notesDist ) % Scale::NOTES_TO_INDEXES.size() ];

            if ( notesDist == 0 ) {
                MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_NON ].push_back( Scale::MAJOR_NOTES_VEC[ majorIdx + notesDist ] );
                MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].push_back( Scale::MAJOR_NOTES_VEC[ majorIdx + notesDist ] );
                MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].push_back( Scale::MAJOR_NOTES_VEC[ majorIdx + notesDist ] );

                MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_NON ].insert( { Scale::MAJOR_NOTES_VEC[ majorIdx + notesDist ], MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_NON ].size() - 1 } );
                MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_SHARP ].insert( { Scale::MAJOR_NOTES_VEC[ majorIdx + notesDist ], MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].size() - 1 } );
                MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_FLAT ].insert( { Scale::MAJOR_NOTES_VEC[ majorIdx + notesDist ], MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].size() - 1 } );

                ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_NON ].second[ Scale::MAJOR_NOTES_VEC[ majorIdx + notesDist ][ 0 ] - 'A' ];
                ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ Scale::MAJOR_NOTES_VEC[ majorIdx + notesDist ][ 0 ] - 'A' ];
                ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ Scale::MAJOR_NOTES_VEC[ majorIdx + notesDist ][ 0 ] - 'A' ];
            } else {

                if ( notesPair.first.size() == 1 ) {
                    MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_NON ].push_back( notesPair.first );
                    MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_NON ].insert( { notesPair.first, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_NON ].size() - 1 } );
                    ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_NON ].second[ notesPair.first[ 0 ] - 'A' ];

                    if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_NON ].second[ notesPair.first[ 0 ] - 'A' ] == 2 ) {
                        MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_NON ].first = false;
                    }

                    if ( notesPair.second.size() == 2 && notesPair.second[ 1 ] == Scale::KEY_SHARP ) {
                        if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ notesPair.second[ 0 ] - 'A' ] == 0 ) {
                            MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].push_back( notesPair.second );
                            MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_SHARP ].insert( { notesPair.second, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].size() - 1 } );
                            ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ notesPair.second[ 0 ] - 'A' ];
                        } else {
                            MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].push_back( notesPair.first );
                            MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_SHARP ].insert( { notesPair.first, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].size() - 1 } );
                            ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ notesPair.first[ 0 ] - 'A' ];
                        }

                        MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].push_back( notesPair.first );
                        MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_FLAT ].insert( { notesPair.first, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].size() - 1 } );
                        ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ notesPair.first[ 0 ] - 'A' ];

                        if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ notesPair.second[ 0 ] - 'A' ] == 2 ) {
                            MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].first = false;
                        }

                        if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ notesPair.first[ 0 ] - 'A' ] == 2 ) {
                            MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].first = false;
                        }

                    } else if ( notesPair.second.size() == 2 && notesPair.second[ 1 ] == Scale::KEY_FLAT ) {
                        if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ notesPair.second[ 0 ] - 'A' ] == 0 ) {
                            MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].push_back( notesPair.second );
                            MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_FLAT ].insert( { notesPair.second, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].size() - 1 } );
                            ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ notesPair.second[ 0 ] - 'A' ];
                        } else {
                            MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].push_back( notesPair.first );
                            MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_FLAT ].insert( { notesPair.first, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].size() - 1 } );
                            ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ notesPair.first[ 0 ] - 'A' ];
                        }

                        MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].push_back( notesPair.first );
                        MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_SHARP ].insert( { notesPair.first, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].size() - 1 } );
                        ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ notesPair.first[ 0 ] - 'A' ];

                        if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ notesPair.second[ 0 ] - 'A' ] == 2 ) {
                            MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].first = false;
                        }

                        if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ notesPair.first[ 0 ] - 'A' ] == 2 ) {
                            MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].first = false;
                        }

                    } else {
                        // Second can be empty
                        // This means we insert first to all other vec
                        MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].push_back( notesPair.first );
                        MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].push_back( notesPair.first );
                        
                        MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_SHARP ].insert( { notesPair.first, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].size() - 1 } );
                        MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_FLAT ].insert( { notesPair.first, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].size() - 1 } );

                        ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ notesPair.first[ 0 ] - 'A' ];
                        ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ notesPair.first[ 0 ] - 'A' ];

                        if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ notesPair.first[ 0 ] - 'A' ] == 2 ) {
                            MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].first = false;
                        }

                        if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ notesPair.first[ 0 ] - 'A' ] == 2 ) {
                            MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].first = false;
                        }
                    }
                } else if ( notesPair.second.size() == 1 ) {
                    MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_NON ].push_back( notesPair.second );
                    MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_NON ].insert( { notesPair.second, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_NON ].size() - 1 } );
                    ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_NON ].second[ notesPair.second[ 0 ] - 'A' ];

                    if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_NON ].second[ notesPair.second[ 0 ] - 'A' ] == 2 ) {
                        MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_NON ].first = false;
                    }

                    if ( notesPair.first.size() == 2 && notesPair.first[ 1 ] == Scale::KEY_SHARP ) {
                        MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].push_back( notesPair.first );
                        MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].push_back( notesPair.second );

                        MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_SHARP ].insert( { notesPair.first, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].size() - 1 } );
                        MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_FLAT ].insert( { notesPair.second, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].size() - 1 } );

                        ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ notesPair.first[ 0 ] - 'A' ];
                        ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ notesPair.second[ 0 ] - 'A' ];

                        if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ notesPair.first[ 0 ] - 'A' ] == 2 ) {
                            MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].first = false;
                        }

                        if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ notesPair.second[ 0 ] - 'A' ] == 2 ) {
                            MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].first = false;
                        }

                    } else if ( notesPair.first.size() == 2 && notesPair.first[ 1 ] == Scale::KEY_FLAT ) {
                        MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].push_back( notesPair.first );
                        MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].push_back( notesPair.second );
                        
                        MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_FLAT ].insert( { notesPair.first, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_FLAT ].size() - 1 } );
                        MAJOR_AUX_MAP_VEC[ majorIdx ][ Scale::KEY_SHARP ].insert( { notesPair.second, MAJOR_AUX_VEC[ majorIdx ][ Scale::KEY_SHARP ].size() - 1 } );

                        ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ notesPair.first[ 0 ] - 'A' ];
                        ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ notesPair.second[ 0 ] - 'A' ];

                        if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].second[ notesPair.first[ 0 ] - 'A' ] == 2 ) {
                            MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_FLAT ].first = false;
                        }

                        if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].second[ notesPair.second[ 0 ] - 'A' ] == 2 ) {
                            MAJOR_AUX_COUNT_VEC[ majorIdx ][ Scale::KEY_SHARP ].first = false;
                        }
                    }

                } else {
                    // Both notes are either sharp - flat or flat - sharp
                    MAJOR_AUX_VEC[ majorIdx ][ notesPair.first[ 1 ] ].push_back( notesPair.first );
                    MAJOR_AUX_VEC[ majorIdx ][ notesPair.second[ 1 ] ].push_back( notesPair.second );
                        
                    MAJOR_AUX_MAP_VEC[ majorIdx ][ notesPair.first[ 1 ] ].insert( { notesPair.first, MAJOR_AUX_VEC[ majorIdx ][ notesPair.first[ 1 ] ].size() - 1 } );
                    MAJOR_AUX_MAP_VEC[ majorIdx ][ notesPair.second[ 1 ] ].insert( { notesPair.second, MAJOR_AUX_VEC[ majorIdx ][ notesPair.first[ 1 ] ].size() - 1 } );

                    ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ notesPair.first[ 1 ] ].second[ notesPair.first[ 0 ] - 'A' ];
                    ++MAJOR_AUX_COUNT_VEC[ majorIdx ][ notesPair.second[ 1 ] ].second[ notesPair.second[ 0 ] - 'A' ];

                    if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ notesPair.first[ 1 ] ].second[ notesPair.first[ 0 ] - 'A' ] == 2 ) {
                        MAJOR_AUX_COUNT_VEC[ majorIdx ][ notesPair.first[ 1 ] ].first = false;
                    }

                    if ( MAJOR_AUX_COUNT_VEC[ majorIdx ][ notesPair.second[ 1 ] ].second[ notesPair.second[ 0 ] - 'A' ] == 2 ) {
                        MAJOR_AUX_COUNT_VEC[ majorIdx ][ notesPair.second[ 1 ] ].first = false;
                    }
                }

            }

            notesDist = ( notesDist + Scale::MAJOR_SCALE_DIST[ j ] );
        }
    }

    for ( int i = 0; i < MAJOR_AUX_VEC.size(); i++ ) {
        if ( MAJOR_AUX_VEC[ i ][ Scale::KEY_NON ].size() < 7 ) {
            MAJOR_AUX_COUNT_VEC[ i ][ Scale::KEY_NON ].first = false;
        }

        if ( MAJOR_AUX_VEC[ i ][ Scale::KEY_SHARP ].size() < 7 ) {
            MAJOR_AUX_COUNT_VEC[ i ][ Scale::KEY_SHARP ].first = false;
        }

        if ( MAJOR_AUX_VEC[ i ][ Scale::KEY_FLAT ].size() < 7 ) {
            MAJOR_AUX_COUNT_VEC[ i ][ Scale::KEY_FLAT ].first = false;
        }
    }

    // We now read the input & output appropriately
    string line = "";
    bool progFinished = false;
    int caseCount = 0;
    int majorIdx = -1;

    while ( true ) {
        string majorName = "";

        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> majorName;
            majorIdx = Scale::MAJOR_TO_INDEXES[ majorName ];
        } else {
            break;
        }

        if ( caseCount > 0 ) {
            cout << endl;
        }
        cout << "Key of " << majorName << endl;

        if ( getline( cin, line ) ) {
            int semiColonIdx = -1;
            string curLine = line;

            do {
                semiColonIdx = curLine.find_first_of( ";" );
                string instructStr = "";

                if ( semiColonIdx != -1 ) {
                    instructStr = curLine.substr( 0, semiColonIdx );
                    curLine = curLine.substr( semiColonIdx + 1 );
                } else {
                    // curLine is also the instruction string
                    instructStr  = curLine;
                }

                string noteStr = "";
                string directionStr = "";
                string intervalStr = "";

                stringstream ss( instructStr );
                ss >> noteStr >> directionStr >> intervalStr;

                int direction = Scale::DIRECTION_TO_INT[ directionStr ] * Scale::INTERVAL_TO_DIST[ intervalStr ];

                for ( unordered_map< char, pair< bool, vector< int > > >::iterator
                        iter = MAJOR_AUX_COUNT_VEC[ majorIdx ].begin();
                        iter != MAJOR_AUX_COUNT_VEC[ majorIdx ].end(); iter++ ) {
                    if ( iter->second.first ) {
                        if ( MAJOR_AUX_MAP_VEC[ majorIdx ][ iter->first ].find( noteStr ) == MAJOR_AUX_MAP_VEC[ majorIdx ][ iter->first ].end() ) {
                            cout << noteStr << ": invalid note for this key";
                        } else {
                            cout << noteStr << ": " << directionStr << " " << intervalStr << " > ";

                            int direction = Scale::DIRECTION_TO_INT[ directionStr ] * Scale::INTERVAL_TO_DIST[ intervalStr ];
                            string resultNote = "";

                            if ( direction >= 0 ) {
                                resultNote = MAJOR_AUX_VEC[ majorIdx ][ iter->first ][ ( MAJOR_AUX_MAP_VEC[ majorIdx ][ iter->first ][ noteStr ] + Scale::DIRECTION_TO_INT[ directionStr ] * Scale::INTERVAL_TO_DIST[ intervalStr ] ) % MAJOR_AUX_VEC[ majorIdx ][ iter->first ].size() ];
                            } else {
                                resultNote = MAJOR_AUX_VEC[ majorIdx ][ iter->first ][ ( MAJOR_AUX_MAP_VEC[ majorIdx ][ iter->first ][ noteStr ] + Scale::DIRECTION_TO_INT[ directionStr ] * Scale::INTERVAL_TO_DIST[ intervalStr ] + MAJOR_AUX_VEC[ majorIdx ][ iter->first ].size() ) % MAJOR_AUX_VEC[ majorIdx ][ iter->first ].size() ];
                            }
                            cout << resultNote;
                        }
                        cout << endl;
                        break;
                    }
                }


            } while ( semiColonIdx != -1 );
            ++caseCount;

        } else {
            break;
        }
    }

    cout << endl;

    return 0;
}
