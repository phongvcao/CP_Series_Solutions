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

namespace Telecom {
    static const vector< int > MINUTES_OF_DAY = { 0, 480, 1080, 1320, 1440 };

    static const vector< vector< double > > RATE_VEC = {
        { 0.10, 0.06, 0.02 },
        { 0.25, 0.15, 0.05 },
        { 0.53, 0.33, 0.13 },
        { 0.87, 0.47, 0.17 },
        { 1.44, 0.80, 0.30 },
    };

    enum RateType {
        RATE_DAY,
        RATE_EVENING,
        RATE_NIGHT,
        RATE_ENUM_SIZE,
    };

    pair< RateType, int > getRateType( int minute ) {
        if ( minute >= 480 && minute <= 1080 ) {
            return make_pair( RATE_DAY, 2 );
        } else if ( minute >= 1080 && minute <= 1320 ) {
            return make_pair( RATE_EVENING, 3 );
        } else if ( minute >= 1320 && minute <= 1440 ) {
            return make_pair( RATE_NIGHT, 4 );
        } else {
            return make_pair( RATE_NIGHT, 1 );
        }
    }
}

int main( int argc, char ** argv ) {

    // We'll save the chart into a vector< vector< double > >
    //
    // - Top level vector is Charging Step
    // - Lower-level vector ( column ) is DAY, EVENING, NIGHT rate
    //
    // - We'll also have a sorted vector< int > of :
    // { 0, 480, 1080, 1320, 1440 } which we can use to determine which rate should we
    // charge:
    //   - If  480 -> 1080 => { DAY, 2 }
    //   - If 1080 -> 1320 => { EVENING, 3 }
    //   - If 1320 -> 1440 => { NIGHT, 4 }
    //           0 -> 480  => { NIGHT, 1 }
    //
    // - We'll do a binary search with beginTime & endTime, which would return 
    // the fromIdx and toIdx of the sorted vector< int > above.
    //

    string line = "";

    while ( getline( cin, line ) ) {
        if ( line == "#" ) break;

        stringstream ss( line );
        char dist = '\0';
        string numStr = "";
        int startHour = 0;
        int startMinute = 0;
        int endHour = 0;
        int endMinute = 0;

        ss >> dist >> numStr >> startHour >> startMinute >> endHour >> endMinute;

        int startTime = startHour * 60 + startMinute;
        int endTime = endHour * 60 + endMinute;

        double totalRate = 0;
        vector< int > timeSpent( 3, 0 );

        if ( startTime < endTime ) {
            pair< Telecom::RateType, int > startRatePair = Telecom::getRateType( startTime );
            pair< Telecom::RateType, int > endRatePair = Telecom::getRateType( endTime );

            do {
                if ( startRatePair.second == endRatePair.second ) {
                    totalRate += Telecom::RATE_VEC[ dist - 'A' ][ endRatePair.first ] * ( double )( endTime - startTime );
                    timeSpent[ endRatePair.first ] += endTime - startTime;
                    break;
                } else {
                    totalRate += Telecom::RATE_VEC[ dist - 'A' ][ startRatePair.first ] * ( double )( Telecom::MINUTES_OF_DAY[ startRatePair.second ] - startTime );
                    timeSpent[ startRatePair.first ] += Telecom::MINUTES_OF_DAY[ startRatePair.second ] - startTime;
                }

                startTime = Telecom::MINUTES_OF_DAY[ startRatePair.second ];
                startRatePair.first = static_cast< Telecom::RateType >( ( startRatePair.first + 1 ) % Telecom::RATE_ENUM_SIZE );
                startRatePair.second = ( startRatePair.second + 1 ) % Telecom::MINUTES_OF_DAY.size();

            } while ( startRatePair.second <= endRatePair.second );
            printf( "%10s%6d%6d%6d%3c%8.2f\n", numStr.c_str(), timeSpent[ Telecom::RATE_DAY ], timeSpent[ Telecom::RATE_EVENING ], timeSpent[ Telecom::RATE_NIGHT ], dist, totalRate );
        } else {
            double totalOfTotal = Telecom::RATE_VEC[ dist - 'A' ][ Telecom::RATE_DAY ] * 600 + Telecom::RATE_VEC[ dist - 'A' ][ Telecom::RATE_EVENING ] * 240 + Telecom::RATE_VEC[ dist - 'A' ][ Telecom::RATE_NIGHT ] * 600;
            
            swap( startTime, endTime );
            pair< Telecom::RateType, int > startRatePair = Telecom::getRateType( startTime );
            pair< Telecom::RateType, int > endRatePair = Telecom::getRateType( endTime );

            do {
                if ( startRatePair.second == endRatePair.second ) {
                    totalRate += Telecom::RATE_VEC[ dist - 'A' ][ endRatePair.first ] * ( double )( endTime - startTime );
                    timeSpent[ endRatePair.first ] += endTime - startTime;
                    break;
                } else {
                    totalRate += Telecom::RATE_VEC[ dist - 'A' ][ startRatePair.first ] * ( double )( Telecom::MINUTES_OF_DAY[ startRatePair.second ] - startTime );
                    timeSpent[ startRatePair.first ] += Telecom::MINUTES_OF_DAY[ startRatePair.second ] - startTime;
                }

                startTime = Telecom::MINUTES_OF_DAY[ startRatePair.second ];
                startRatePair.first = static_cast< Telecom::RateType >( ( startRatePair.first + 1 ) % Telecom::RATE_ENUM_SIZE );
                startRatePair.second = ( startRatePair.second + 1 ) % Telecom::MINUTES_OF_DAY.size();

            } while ( startRatePair.second <= endRatePair.second );
            printf( "%10s%6d%6d%6d%3c%8.2f\n", numStr.c_str(), 600 - timeSpent[ Telecom::RATE_DAY ], 240 - timeSpent[ Telecom::RATE_EVENING ], 600 - timeSpent[ Telecom::RATE_NIGHT ], dist, totalOfTotal - totalRate );
        }
    }

    return 0;
}
