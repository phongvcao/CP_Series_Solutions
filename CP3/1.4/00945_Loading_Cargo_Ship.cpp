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

class Container {
public:

    int index = -1;
    int totalCap = 0;
    int usedCap = 0;
    vector< int > packagesVec;

    Container() {
        // not implemented
    }

    Container( const Container& other )
        : index( other.index ),
          totalCap( other.totalCap ),
          usedCap( other.usedCap ),
          packagesVec( other.packagesVec )
    {
        // not implemented
    }

    virtual ~Container() {
        // not implemented
    }

    int getAvailableCap() const {
        return totalCap - usedCap;
    }

    int getNumPackages() const {
        return packagesVec.size();
    }

    bool addPackage( int package ) {
        if ( package <= getAvailableCap() ) {
            usedCap += package;
            packagesVec.push_back( package );
            return true;
        }
        return false;
    }

    friend ostream& operator <<( ostream& out, const Container& container ) {
        out << " | index : " << container.index
            << " ; totalCap : " << container.totalCap
            << " ; usedCap : " << container.usedCap
            << " ; packagesVec : ";
        for ( int i = 0; i < container.packagesVec.size(); i++ ) {
            out << container.packagesVec[ i ] << ", ";
        }
        out << " | ";
        return out;
    }

};

struct cmpContainers {
    bool operator ()( const Container& c1, const Container& c2 ) const {
        if ( c1.getNumPackages() < c2.getNumPackages() ) {
            return true;
        } else if ( c1.getNumPackages() > c2.getNumPackages() ) {
            return false;
        } else {
            if ( c1.getAvailableCap() > c2.getAvailableCap() ) {
                return true;
            } else if ( c1.getAvailableCap() < c2.getAvailableCap() ) {
                return false;
            } else {
                return c1.index < c2.index;
            }
        }
    }
};

int main( int argc, char ** argv ) {

    int caseCount = 0;

    while ( true ) {
        // We will compare the containers by:
        // - First by lowest number of packages
        // - Second by greatest available left-over weight capacity
        // - Third by the lowest number ( index )
        // Finally if the 
        string line = "";
        int C = 0;

        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> C;
        } else {
            break;
        }

        set< Container, cmpContainers > containersSet;
        int totalShipCap = 0;
        for ( int c = 0; c < C; c++ ) {
            if ( getline( cin, line ) ) {
                Container container;
                container.index = c;

                stringstream ss( line );
                ss >> container.totalCap;
                totalShipCap += container.totalCap;
                containersSet.insert( container );
            }
        }

        // Blank line
        getline( cin, line );

        int P = 0;
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> P;
        }

        int totalPackagesWeight = 0;
        int totalLoadedWeight = 0;
        bool caseFinished = false;

        for ( int p = 0; p < P; p++ ) {
            if ( getline( cin, line ) ) {
                stringstream ss( line );
                int package = 0;
                ss >> package;
                totalPackagesWeight += package;

                if ( ! caseFinished ) {
                    Container container = *( containersSet.begin() );
                    containersSet.erase( container );

                    if ( container.addPackage( package ) ) {
                        totalLoadedWeight += package;
                    } else {
                        caseFinished = true;
                    }
                    containersSet.insert( container );
                }
            }
        }

        // Print out the result
        vector< vector< char > > outputVec( containersSet.rbegin()->getNumPackages(), vector< char >( containersSet.size(), ':' ) );

        for ( const Container& container : containersSet ) {
            for ( int i = 0; i < container.packagesVec.size(); i++ ) {
                outputVec[ outputVec.size() - 1 - i ][ container.index ] = '0' + container.packagesVec[ i ];
            }
        }
    
        if ( caseCount > 0 ) {
            cout << endl;
        }

        for ( int i = 0; i < outputVec.size(); i++ ) {
            for ( int j = 0; j < outputVec[ i ].size(); j++ ) {
                cout << outputVec[ i ][ j ];
                if ( j < outputVec[ i ].size() - 1 ) {
                    cout << " ";
                }
            }
            cout << endl;
        }

        string sepStr = "";
        string cargoNumStr = "";
        for ( int i = 0; i < containersSet.size(); i++ ) {
            cargoNumStr += to_string( i + 1 );
            if ( i < containersSet.size() - 1 ) {
                sepStr += "=";
                cargoNumStr += " ";
            }
            sepStr += "=";
        }
        cout << sepStr << endl;
        cout << cargoNumStr << endl;
        cout << endl;

        cout << "cargo weight: " << totalLoadedWeight << endl;
        cout << "unused weight: " << totalShipCap - totalLoadedWeight << endl;
        cout << "unloaded weight: " << totalPackagesWeight - totalLoadedWeight << endl;

        // Blank line
        if ( ! getline( cin, line ) ) {
            break;
        }

        ++caseCount;
    }

    return 0;
}
