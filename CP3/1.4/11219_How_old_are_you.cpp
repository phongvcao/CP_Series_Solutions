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

namespace Age {

    static int compareDayMonth( int day1, int month1, int day2, int month2 ) {
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

    static string compareDates( int curDay, int curMonth, int curYear,
                                int birthDay, int birthMonth, int birthYear ) {
        string rv = "";

        if ( curYear < birthYear ) {
            rv = "Invalid birth date";
        } else if ( curYear > birthYear ) {
            if ( curYear - birthYear > 130 ) {
                int curBirthYearDiff = curYear - birthYear;
                if ( curBirthYearDiff == 131 && compareDayMonth( curDay, curMonth, birthDay, birthMonth ) < 0 ) {
                    rv = to_string( 130 );
                } else {
                    rv = "Check birth date";
                }
            } else {
                //
                // If curYear is larger than birthYear but not larger than 
                // 130, the age is at least curYear - birthYear.
                //
                // Now we compare curDay, curMonth to birthDay, birthMonth
                // 
                // If curDay, curMonth is after or on the same date as 
                // birthDay, birthMonth, then += age
                //
                // If curDay, curMonth is before in terms of values compared
                // to birthDay, birthMonth, then curYear - birthYear is the
                // final age.
                int curBirthYearDiff = curYear - birthYear;
                if ( compareDayMonth( curDay, curMonth, birthDay, birthMonth ) >= 0 ) {
                    rv = to_string( curBirthYearDiff );
                } else {
                    rv = to_string( curBirthYearDiff - 1 );
                }
            }
        } else {
            // If curYear and birthYear are the same, the age is 0 if curDay, curMonth
            // is after birthDay, birthMonth. Otherwise, the age is invalid
            if ( compareDayMonth( curDay, curMonth, birthDay, birthMonth ) >= 0 ) {
                rv = "0";
            } else {
                rv = "Invalid birth date";
            }
        }

        return rv;
    }
}

int main( int argc, char ** argv ) {

    int T = 0;
    string line = "";

    while ( getline( cin, line ) ) {
        if ( line.empty() ) continue;
        stringstream ss( line );
        ss >> T;
        break;
    }

    for ( int t = 0; t < T; t++ ) {
        getline( cin, line );


        int curDay = 0;
        int curMonth = 0;
        int curYear = 0;

        if ( getline( cin, line ) ) {
            curDay = atoi( line.substr( 0, 2 ).c_str() );
            curMonth = atoi( line.substr( 3, 2 ).c_str() );
            curYear = atoi( line.substr( 6 ).c_str() );
        }

        int birthDay = 0;
        int birthMonth = 0;
        int birthYear = 0;

        if ( getline( cin, line ) ) {
            birthDay = atoi( line.substr( 0, 2 ).c_str() );
            birthMonth = atoi( line.substr( 3, 2 ).c_str() );
            birthYear = atoi( line.substr( 6 ).c_str() );
        }

        cout << "Case #" << t + 1 << ": ";
        cout << Age::compareDates( curDay, curMonth, curYear,
                                   birthDay, birthMonth, birthYear ) << endl;
    }

    return 0;
}
