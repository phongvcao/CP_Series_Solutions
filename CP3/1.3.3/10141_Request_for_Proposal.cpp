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
#include <iterator>
#include <utility>
#include <algorithm>
#include <memory>
#include <cctype>
#include <stdexcept>
#include <limits>
#include <numeric>

//----< iostream >----------//
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

//----< cstdio >------------//
using std::printf;
using std::fprintf;
using std::sprintf;
using std::snprintf;

//----< iomanip >-----------//
using std::setprecision;
using std::setw;

//----< ios >---------------//
using std::hex;
using std::dec;
using std::oct;
using std::fixed;

//----< sstream >-----------//
using std::stringstream;
using std::ostringstream;
using std::istringstream;

//----< fstream >-----------//
using std::ofstream;
using std::ifstream;

//----< string >------------//
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stol;

//----< cmath >-------------//
using std::sqrt;
using std::pow;
using std::log;             // log( <arg> )
using std::exp;             // e ^ <arg>
using std::abs;
using std::floor;           // Round down to nearest integer double
using std::ceil;            // Round up to nearest integer double
using std::trunc;           // Truncate the fractional part to get the integer part
using std::round;           // Round to nearest integer double

//----< cstdlib >-----------//
using std::rand;
using std::srand;

//----< ctime >-------------//
using std::time;

//----< functional >--------//
using std::hash;
using std::greater;         // lhs > rhs. Used for MinPQ
using std::less;            // lhs < rhs. Used for MaxPQ. Default for priority_queue<>
using std::less_equal;
using std::greater_equal;

//----< array >-------------//
using std::array;           // Fixed & Unordered Array

//----< vector >------------//
using std::vector;          // Resizable & Unordered Array

//----< map >---------------//
using std::map;             // Ordered Map (Red-Black Tree)

//----< unordered_map >-----//
using std::unordered_map;   // HashMap (SeparateChainingHashST)

//----< set >---------------//
using std::set;             // Ordered Set (Red-Black Tree)

//----< unordered_set >-----//
using std::unordered_set;   // HashSet (SeparateChainingHashST)

//----< list >--------------//
using std::list;            // Doubly-Linked List with size() ( O( 1 ) )

//----< forward_list >------//
using std::forward_list;    // Singly-Linked List without size() function ( so O( N ) if we need to get size() )

//----< deque >-------------//
using std::deque;           // Vector of fixed-size Vectors: 1 fixed-size vector for each end of the deque

//----< queue >-------------//
using std::queue;           // Non-Iterable & Use std::deque as underlying data structure
using std::priority_queue;  // MaxPQ (MaxHeap) & Non-Iterable.
//                          // => Pass std::greater<> as template params to create MinPQ (MinHeap)

//----< stack >-------------//
using std::stack;           // Non-Iterable & Use std::deque as underlying data structure

//----< iterator >----------//
using std::next;            // Return an advanced iter without changing original iter
using std::prev;            // Return an decremented iter without changing original iter
using std::distance;        // Calculate distance between 2 iterators

//----< utility >-----------//
using std::pair;
using std::make_pair;
using std::move;            // Move resources between objects - typically used with std::unique_ptr<T>

//----< algorithm >---------//
using std::fill;
using std::max;
using std::min;
using std::find;
using std::reverse;
using std::sort;
using std::remove;
using std::swap;

//----< memory >------------//
// using std::make_unique;
using std::unique_ptr;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

//----< cctype >------------//
using std::isalnum;
using std::isalpha;
using std::islower;
using std::isupper;
using std::isdigit;
using std::isspace;         // Check whether char is whitespace character (space, newline, tab, etc. )
using std::isblank;         // Check whether char is blank character ( space or tab )
using std::tolower;
using std::toupper;

//----< stdexcept >---------//
using std::runtime_error;
using std::invalid_argument;
using std::out_of_range;

//----< limits >------------//
using std::numeric_limits;

//----< numeric >-----------//
using std::iota;
// using std::gcd;
// using std::lcm;

//--------------------------//

class Proposal {
public:

    int met = 0;
    int numReq = 0;
    double price = 0;
    int index = 0;
    double compliance = 0;
    string name = "";

    Proposal( const Proposal& p )
        : met( p.met ),
          numReq( p.numReq ),
          price( p.price ),
          index( p.index ),
          compliance( p.compliance ),
          name( p.name )
    {
        // not implemented
    }

    Proposal( int met, int numReq, double price, int index, string name )
        : met( met ),
          numReq( numReq ),
          price( price ),
          index( index ),
          compliance( ( double ) met / ( double ) numReq ),
          name( name )
    {
        // not implemented
    }

    virtual ~Proposal() {
        // not implemented
    }

    friend bool operator <( const Proposal& p1, const Proposal& p2 ) {
        if ( p1.compliance < p2.compliance ) {
            return true;
        } else if ( p1.compliance > p2.compliance ) {
            return false;
        } else {
            if ( p1.price > p2.price ) {
                return true;
            } else if ( p1.price < p2.price ) {
                return false;
            } else {
                if ( p1.index > p2.index ) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }

    friend bool operator >( const Proposal& p1, const Proposal& p2 ) {
        if ( p1.compliance > p2.compliance ) {
            return true;
        } else if ( p1.compliance < p2.compliance ) {
            return false;
        } else {
            if ( p1.price < p2.price ) {
                return true;
            } else if ( p1.price > p2.price ) {
                return false;
            } else {
                if ( p1.index < p2.index ) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
};

int main( int argc, char ** argv ) {

    string line = "";
    int idx = 0;

    while ( getline( cin, line ) ) {
        int n = 0;
        int p = 0;
        stringstream ss( line );
        ss >> n >> p;

        if ( n == 0 && p == 0 ) break;

        for ( int i = 0; i < n; i++ ) {
            if ( getline( cin, line ) ) {
                ss.clear();
                ss.str( line );
            }
        }
        
        set< Proposal, greater< Proposal > > propoSet;

        for ( int i = 0; i < p; i++ ) {
            string name = "";
            getline( cin, name );

            double price = 0;
            int met = 0;
            if ( getline( cin, line ) ) {
                ss.clear();
                ss.str( line );
                ss >> price >> met;
            }

            for ( int j = 0; j < met; j++ ) {
                string metName = "";
                getline( cin, metName );
            }

            Proposal p( met, n, price, i, name );
            propoSet.insert( p );
        }

        if ( idx > 0 ) {
            cout << endl;
        }
        cout << "RFP #" << idx + 1 << endl;
        cout << propoSet.begin()->name << endl;
        ++idx;
    }

    return 0;
}
