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

class Mta {
public:

    static const string MATCH_ALL;

    int index = -1;
    string name = "";
    string country = "";
    string transport = "";
    string domain = "";
    string organization = "";

    Mta() {
        // not implemented
    }

    Mta( const Mta& other )
        : index( other.index ),
          name( other.name ),
          country( other.country ),
          transport( other.transport ),
          domain( other.domain ),
          organization( other.organization )
    {
        // not implemented
    }

    virtual ~Mta() {
        // not implemented
    }

    friend bool operator ==( const Mta& m1, const Mta& m2 ) {
        // bool nameMatched = false;
        bool countryMatched = false;
        bool transportMatched = false;
        bool domainMatched = false;
        bool orgMatched = false;

        // if ( m1.name == MATCH_ALL || m2.name == MATCH_ALL ) {
        //     nameMatched = true;
        // } else {
        //     nameMatched = ( m1.name == m2.name );
        // }
        
        if ( m2.country == MATCH_ALL ) {
            countryMatched = true;
        } else {
            countryMatched = ( m1.country == m2.country );
        }
        
        if ( m2.transport == MATCH_ALL ) {
            transportMatched = true;
        } else {
            transportMatched = ( m1.transport == m2.transport );
        }
        
        if ( m2.domain == MATCH_ALL ) {
            domainMatched = true;
        } else {
            domainMatched = ( m1.domain == m2.domain );
        }
        
        if ( m2.organization == MATCH_ALL ) {
            orgMatched = true;
        } else {
            orgMatched = ( m1.organization == m2.organization );
        }

        return ( countryMatched && transportMatched && domainMatched && orgMatched );
    }

    friend bool operator !=( const Mta& m1, const Mta& m2 ) {
        return ! ( m1 == m2 );
    }

};

const string Mta::MATCH_ALL = "*";

int main( int argc, char ** argv ) {

    string line = "";
    int scenarioCount = 0;

    while ( getline( cin, line ) ) {
        if ( line.empty() ) continue;
        stringstream ss( line );
        int M = 0;
        ss >> M;

        unordered_map< string, vector< Mta > > mtaMap;
        unordered_map< string, bool > markedMap;

        for ( int m = 0; m < M; m++ ) {
            if ( getline( cin, line ) ) {
                string fromStr = "";
                int mtaCount = 0;
                ss.clear();
                ss.str( line );
                ss >> fromStr >> mtaCount;

                if ( mtaMap.find( fromStr ) == mtaMap.end() ) {
                    mtaMap.insert( { fromStr, vector< Mta >() } );
                    markedMap.insert( { fromStr, false } );
                }

                for ( int i = 0; i < mtaCount; i++ ) {
                    if ( getline( cin, line ) ) {
                        ss.clear();
                        ss.str( line );
                        Mta mta;
                        mta.index = mtaMap[ fromStr ].size();
                        ss >> mta.name >> mta.country >> mta.transport >> mta.domain >> mta.organization;
                        mtaMap[ fromStr ].push_back( mta );
                    }
                }
            }
        }

        int N = 0;
        if ( getline( cin, line ) ) {
            ss.clear();
            ss.str( line );
            ss >> N;
        }

        cout << "Scenario # " << scenarioCount + 1 << endl;
        for ( int n = 0; n < N; n++ ) {
            cout << n + 1 << " -- ";
            if ( getline( cin, line ) ) {
                ss.clear();
                ss.str( line );

                Mta mta;
                ss >> mta.name >> mta.country >> mta.transport >> mta.domain >> mta.organization;
                string orgMtaName = mta.name;

                for ( unordered_map< string, bool >::iterator iter = markedMap.begin();
                        iter != markedMap.end(); iter++ ) {
                    iter->second = false;
                }

                bool unableToRoute = false;
                while ( true ) {
                    bool mtaFound = false;
                    string rootMtaName = mta.name;

                    for ( int i = 0; i < mtaMap[ mta.name ].size(); i++ ) {
                        if ( mta == mtaMap[ mta.name ][ i ] ) {
                            mta.name = mtaMap[ mta.name ][ i ].name;
                            mtaFound = true;
                            break;
                        }
                    }

                    if ( ! mtaFound ) {
                        // We cannot find MTA in this list. Which means we're unable
                        // to route and should break out of while ( true ) loop
                        cout << "unable to route at " << mta.name << endl;
                        unableToRoute = true;
                        break;
                    } else {
                        // We can find MTA in this list. If it's same as rootMtaName,
                        // it means we have found final delivery point.
                        // Thus, we have to break out of the while ( true ) loop.
                        if ( markedMap[ rootMtaName ] ) {
                            cout << "circular routing detected by " << rootMtaName << endl;
                            unableToRoute = true;
                            break;
                        } else if ( rootMtaName == mta.name ) {
                            break;
                        }
                    }
                    markedMap[ rootMtaName ] = true;
                }

                if ( ! unableToRoute ) {
                    cout << "delivered to " << mta.name << endl;
                }
            }
        }
        cout << endl;
        ++scenarioCount;
    }

    return 0;
}
