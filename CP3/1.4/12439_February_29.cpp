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
using std::set_difference;      // Only works on std::set and not std::unordered_set
using std::set_union;
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

namespace February {
    static vector< int > LEAP_YEARS;
    static unordered_map< string, int > MONTH_NAMES_TO_INDEXES = {
        { "January", 0 },
        { "February", 1 },
        { "March", 2 },
        { "April", 3 },
        { "May", 4 },
        { "June", 5 },
        { "July", 6 },
        { "August", 7 },
        { "September", 8 },
        { "October", 9 },
        { "November", 10 },
        { "December", 11 },
    };

    static bool isLeap( int year ) {
        return ( ( year % 400 == 0 ) || ( year % 4 == 0 && year % 100 != 0 ) );
    }

    static int countLeapYearsBefore( int year ) {
        --year;
        return ( year / 4 ) - ( year / 100 ) + ( year / 400 );
    }

    static int countLeapYearsBothEndsInclusive( int startYear, int endYear ) {
        return countLeapYearsBefore( endYear + 1 ) - countLeapYearsBefore( startYear );
    }

    template< typename Value >
    static int binarySearch( const vector< Value >& arr, Value val ) {
        int low = 0;
        int high = arr.size() - 1;

        while ( low <= high ) {
            int mid = low + ( high - low ) / 2;
            if ( val < arr[ mid ] ) {
                high = mid - 1;
            } else if ( val > arr[ mid ] ) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
        return low - 1;
    }

    static int compareDates( int month1, int day1, int month2, int day2 ) {
        if ( month1 < month2 ) {
            return -1;
        } else if ( month1 > month2 ) {
            return 1;
        } else {
            if ( day1 < day2 ) {
                return -1;
            } else if ( day1 > day2 ) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

int main( int argc, char ** argv ) {

    int T = 0;
    cin >> T;

    for ( int t = 0; t < T; t++ ) {
        string startMonthStr = "";
        string startDayStr = "";
        int startYear = 0;
        int startDay = 0;
        int startMonth = 0;
        
        string endMonthStr = "";
        string endDayStr = "";
        int endYear = 0;
        int endDay = 0;
        int endMonth = 0;
            
        cin >> startMonthStr >> startDayStr >> startYear;
        cin >> endMonthStr >> endDayStr >> endYear;

        int startDayCommaIdx = startDayStr.find_first_of( "," );
        startDay = atoi( startDayStr.substr( 0, startDayCommaIdx ).c_str() );

        int endDayCommaIdx = endDayStr.find_first_of( "," );
        endDay = atoi( endDayStr.substr( 0, endDayCommaIdx ).c_str() );

        startMonth = February::MONTH_NAMES_TO_INDEXES[ startMonthStr ] + 1;
        endMonth = February::MONTH_NAMES_TO_INDEXES[ endMonthStr ] + 1;

        // Get leap years count including both startYear & endYear
        int leapCount = February::countLeapYearsBothEndsInclusive( startYear, endYear );
        
        if ( February::isLeap( startYear ) ) {
            // If startMonth & startDay is after feb 29, decrement
            if ( February::compareDates( startMonth, startDay, 2, 29 ) > 0 ) {
                --leapCount;
            }

        }

        if ( February::isLeap( endYear ) ) {
            // If endMonth & endDay is before feb 29, decrement
            if ( February::compareDates( endMonth, endDay, 2, 29 ) < 0 ) {
                --leapCount;
            }

        }

        cout << "Case " << t + 1 << ": " << leapCount << endl;
    }

    return 0;
}
