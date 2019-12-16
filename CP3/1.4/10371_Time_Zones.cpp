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

namespace TimeZones {
    static unordered_map< string, double > TIME_ZONES_TO_OFFSET = {
        { "UTC",   0 },
        { "GMT",   0 },
        { "BST",   1 },
        { "IST",   1 },
        { "WET",   0 },
        { "WEST",  1 },
        { "CET",   1 },
        { "CEST",  2 },
        { "EET",   2 },
        { "EEST",  3 },
        { "MSK",   3 },
        { "MSD",   4 },
        { "AST",  -4 },
        { "ADT",  -3 },
        { "NST",  -3.5 },
        { "NDT",  -2.5 },
        { "EST",  -5 },
        { "EDT",  -4 },
        { "CST",  -6 },
        { "CDT",  -5 },
        { "MST",  -7 },
        { "MDT",  -6 },
        { "PST",  -8 },
        { "PDT",  -7 },
        { "HST",  -10 },
        { "AKST", -9 },
        { "AKDT", -8 },
        { "AEST",  10 },
        { "AEDT",  11 },
        { "ACST",  9.5 },
        { "ACDT",  10.5 },
        { "AWST",  8 },
    };

    static vector< double > PM_HOURS_TO_TRUE_HOURS = {
        0, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 12,
    };

    static const string SUFFIX_AM = "a.m.";
    static const string SUFFIX_PM = "p.m.";

    static const double MINUTES_PER_DAY = 24.0 * 60.0;
    static const double MINUTES_PER_HALF_DAY = 12.0 * 60.0;

    static const vector< double > HALF_DAY_INTERVALS = {
        -48.0, -36.0, -24.0, -12.0, 0.0, 12.0, 24.0, 36.0, 48.0
    };
    
    static const vector< string > HALF_DAY_SUFFIXES = {
        "a.m.", "p.m.", "a.m.", "p.m.", "a.m.", "p.m.", "a.m.", "p.m.", "a.m.",
    };

    int binarySearch( const vector< double > arr, double timeInMinutes ) {
        int low = 0;
        int high = arr.size() - 1;

        while ( low <= high ) {
            int mid = low + ( high - low ) / 2;
            if ( timeInMinutes < arr[ mid ] * 60.0 ) {
                high = mid - 1;
            } else if ( timeInMinutes > arr[ mid ] * 60.0 ) {
                low = mid + 1;
            } else {
                return mid - 1;
            }
        }
        return low - 1;
    }

    double timeStrToMinutes( const string& timeStr, const string& suffix ) {
        if ( timeStr == "noon" ) {
            return 12.0 * 60.0;
        } else if ( timeStr == "midnight" ) {
            return 0.0;
        } else {
            int colonIdx = timeStr.find_first_of( ":" );
            double hour = 0;
            double minute = 0;
            if ( colonIdx != string::npos ) {
                hour = ( double )atoi( timeStr.substr( 0, colonIdx ).c_str() );
                minute = ( double )atoi( timeStr.substr( colonIdx + 1 ).c_str() );
            }

            if ( suffix == SUFFIX_PM ) {
                hour = PM_HOURS_TO_TRUE_HOURS[ ( int )hour ];
            } else if ( suffix == SUFFIX_AM && hour == 12 ) {
                hour = 0;
            }

            double totalMinutes = hour * 60.0 + minute;
            return totalMinutes;
        }
    }
}

int main( int argc, char ** argv ) {

    string line = "";
    int N = 0;
    
    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> N;
    }

    for ( int n = 0; n < N; n++ ) {
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            string timeStr = "";
            string suffix = "";
            string fromTimeZone = "";
            string toTimeZone = "";

            ss >> timeStr;

            if ( timeStr != "noon" && timeStr != "midnight" ) {
                ss >> suffix >> fromTimeZone >> toTimeZone;
            } else {
                ss >> fromTimeZone >> toTimeZone;
                if ( timeStr == "noon" ) {
                    suffix = TimeZones::SUFFIX_PM;
                } else {
                    suffix = TimeZones::SUFFIX_AM;
                }
            }

            double minute = TimeZones::timeStrToMinutes( timeStr, suffix );
            double minuteDist = ( TimeZones::TIME_ZONES_TO_OFFSET[ toTimeZone ] - TimeZones::TIME_ZONES_TO_OFFSET[ fromTimeZone ] ) * 60.0;
            minute += minuteDist;

            int newMinuteHalfDayCount = TimeZones::binarySearch( TimeZones::HALF_DAY_INTERVALS, minute );
            suffix = TimeZones::HALF_DAY_SUFFIXES[ newMinuteHalfDayCount ];

            if ( minute < 0 ) {
                minute += ( double )TimeZones::MINUTES_PER_DAY;
            } else if ( minute >= TimeZones::MINUTES_PER_DAY ) {
                minute -= ( double )TimeZones::MINUTES_PER_DAY;
            }

            minuteDist = abs( minuteDist );

            if ( minute == 0 ) {
                printf( "midnight\n" );
            } else if ( minute == TimeZones::MINUTES_PER_HALF_DAY ) {
                printf( "noon\n" );
            } else {
                int hourInt = ( int )minute / 60;
                if ( hourInt > 12 ) {
                    hourInt -= 12;
                } else if ( hourInt == 0 ) {
                    hourInt = 12;
                }

                printf( "%d:%02d %s\n", hourInt, ( int )minute % 60, suffix.c_str() );
            }
        }
    }

    return 0;
}
