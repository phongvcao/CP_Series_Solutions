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

class Appointment {
public:

    int begin = -1;
    int end = -1;
    string beginStr = "";
    string endStr = "";

    Appointment() {
        // not implemented
    }

    Appointment( int begin, int end, const string& beginStr, const string& endStr )
        : begin( begin ),
          end( end ),
          beginStr( beginStr ),
          endStr( endStr )
    {
        // not implemented
    }

    Appointment( const Appointment& other )
        : begin( other.begin ),
          end( other.end ),
          beginStr( other.beginStr ),
          endStr( other.endStr )
    {
        // not implemented
    }

    virtual ~Appointment() {
        // not implemented
    }

    friend bool operator <( const Appointment& a1, const Appointment& a2 ) {
        return a1.begin < a2.begin;
    }

    friend bool operator >( const Appointment& a1, const Appointment& a2 ) {
        return a1.begin > a2.begin;
    }

    friend ostream& operator <<( ostream& out, const Appointment& appt ) {
        out << " | " << appt.beginStr << " : " << appt.endStr << " | ";
        return out;
    }

};

class Nap {

public:

    int begin = -1;
    int end = -1;
    string beginTimeStr = "";

    Nap( int beginTime, int endTime, string beginTimeStr )
        : begin( beginTime ),
          end( endTime ),
          beginTimeStr( beginTimeStr )
    {
        // not implemented
    }

    Nap() {
        // not implemented
    }

    Nap( const Nap& other )
        : begin( other.begin ),
          end( other.end ),
          beginTimeStr( other.beginTimeStr )
    {
        // not implemented
    }

    virtual ~Nap() {
        // not implemented
    }

    int getDuration() const {
        return end - begin;
    }

    static int stringToSeconds( const string& s ) {
        int hour = atoi( s.substr( 0, 2 ).c_str() );
        int minute = atoi( s.substr( 3, 2 ).c_str() );
        return hour * 3600 + minute * 60;
    }

    friend bool operator <( const Nap& n1, const Nap& n2 ) {
        return n1.getDuration() < n2.getDuration();
    }

    friend bool operator >( const Nap& n1, const Nap& n2 ) {
        return n1.getDuration() > n2.getDuration();
    }

    friend bool operator >=( const Nap& n1, const Nap& n2 ) {
        return n1.getDuration() >= n2.getDuration();
    }

    friend ostream& operator <<( ostream& out, const Nap& nap ) {
        out << "nap starts at " << nap.beginTimeStr << " and will last for ";
        int sec = nap.end - nap.begin;
        int hour = sec / 3600;
        int minute = ( sec - hour * 3600 ) / 60;

        if ( hour > 0 ) {
            out << hour << " hours and ";
        }
        out << minute << " minutes.";
        return out;
    }

};

int main( int argc, char ** argv ) {

    string line = "";
    bool gameFinished = false;
    int dayCount = 0;

    while ( true ) {
        if ( gameFinished ) break;

        if ( getline( cin, line ) ) {
            stringstream ss( line );
            int N = 0;
            ss >> N;

            Nap maxNap;
            set< Appointment > apptsSet;
            string lastApptEnd = "";
            string firstApptBegin = "";

            for ( int n = 0; n < N; n++ ) {
                if ( getline( cin, line ) ) {
                    ss.clear();
                    ss.str( line );

                    string apptBegin = "";
                    string apptEnd = "";
                    ss >> apptBegin >> apptEnd;

                    Appointment appt( Nap::stringToSeconds( apptBegin ),
                                      Nap::stringToSeconds( apptEnd ),
                                      apptBegin, apptEnd );
                    apptsSet.insert( appt );
                }
            }

            set< Appointment >::iterator beforeApptsIter = apptsSet.end();
            for ( set< Appointment >::iterator apptsIter = apptsSet.begin();
                    apptsIter != apptsSet.end(); apptsIter++ ) {
                if ( firstApptBegin.empty() ) {
                    firstApptBegin = apptsIter->beginStr;
                }

                if ( beforeApptsIter == apptsSet.end() ) {
                    beforeApptsIter = apptsIter;
                    lastApptEnd = apptsIter->endStr;
                    continue;
                } else {
                    if ( apptsIter->begin > beforeApptsIter->end ) {
                        Nap nap( beforeApptsIter->end, apptsIter->begin, beforeApptsIter->endStr );
                        if ( nap > maxNap ) {
                            maxNap = nap;
                        }
                    }
                }
                lastApptEnd = apptsIter->endStr;
                beforeApptsIter = apptsIter;
            }

            if ( firstApptBegin.empty() && lastApptEnd.empty() ) {
                Nap nap( Nap::stringToSeconds( "10:00" ), Nap::stringToSeconds( "18:00" ), "10:00" );
                if ( nap > maxNap ) {
                    maxNap = nap;
                }
            } else {

                if ( firstApptBegin != "10:00" ) {
                    Nap nap( Nap::stringToSeconds( "10:00" ), apptsSet.begin()->begin, "10:00" );
                    if ( nap >= maxNap ) {
                        maxNap = nap;
                    }
                }

                if ( lastApptEnd != "18:00" ) {
                    Nap nap( prev( apptsSet.end(), 1 )->end, Nap::stringToSeconds( "18:00" ), lastApptEnd );
                    if ( nap > maxNap ) {
                        maxNap = nap;
                    }
                }

            }

            cout << "Day #" << dayCount + 1 << ": the longest " << maxNap << endl;
            ++dayCount;

        } else {
            gameFinished = true;
            continue;
        }
    }

    return 0;
}
