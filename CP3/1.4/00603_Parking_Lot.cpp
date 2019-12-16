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

class Car {
public:
    
    static const int TOTAL_SPACES;

    int orgIndex = -1;
    int index = -1;
    int parkedIndex = -1;
    int outputIndex = -1;

    Car() {
        // not implemented
    }

    Car( const Car& other )
        : orgIndex( other.orgIndex ),
          index( other.index ),
          parkedIndex( other.parkedIndex ),
          outputIndex( other.outputIndex )
    {
        // not implemented
    }

    virtual ~Car() {
        // not implemented
    }

    bool advance( const vector< Car >& parkingVec, int stepsCount ) {
        index = ( index + stepsCount ) % TOTAL_SPACES;
        if ( parkingVec[ index ].parkedIndex == -1 ) {
            return false;
        } else {
            return true;
        }
    }

    friend bool operator <( const Car& c1, const Car& c2 ) {
        return c1.outputIndex < c2.outputIndex;
    }

    friend bool operator >( const Car& c1, const Car& c2 ) {
        return c1.outputIndex > c2.outputIndex;
    }

    friend ostream& operator <<( ostream& out, const Car& car ) {
        out << " | orgIndex : " << car.orgIndex
            << " ; index : " << car.index
            << " ; parkedIndex : " << car.parkedIndex << " | ";
        return out;
    }
};

const int Car::TOTAL_SPACES = 20;

int main( int argc, char ** argv ) {

    int N = 0;
    string line = "";

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> N;
    }

    // Empty line
    getline( cin, line );

    for ( int n = 0; n < N; n++ ) {

        vector< Car > parkingVec( Car::TOTAL_SPACES );
        for ( int i = 0; i < parkingVec.size(); i++ ) {
            parkingVec[ i ].parkedIndex = i;
        }

        unordered_map< int, Car > waitingMap;
        set< Car > waitingSet;
        
        Car car;
        int orgIndex = 0;
        int outputIndex = 0;

        while ( true ) {
            if ( getline( cin, line ) ) {
                stringstream ss( line );
                ss >> orgIndex;

                if ( orgIndex == 99 ) break;

                --orgIndex;

                car.orgIndex = orgIndex;
                car.index = car.orgIndex;
                car.outputIndex = outputIndex++;
                waitingMap.insert( { car.index, car } );
                waitingSet.insert( car );
            }
        }

        int vacantIndex = 0;
        set< Car > parkedSet;
        while ( getline( cin, line ) ) {
            if ( line.empty() ) {
                break;
            }

            stringstream ss( line );
            ss >> vacantIndex;
            --vacantIndex;

            parkingVec[ vacantIndex ].parkedIndex = -1;

            //
            // Logic starts here
            //
            // First we need to find the closest waiting car before vacantIndex.
            // We do this by keep decrementing vacantIndex ( if vacantIndex < 0,
            // we can deduce the final index by vacantIndex + 20 )
            //
            // The distance that we went through to find this car is the increment
            // amount we will use to advance() all the cars.
            //
            // The advance() function automatically checks whether the current
            // slot the car in is vacant. If not, it returns false. If it is
            // vacant, it returns true
            //
            int tmpVacantIndex = vacantIndex;
            int dist = 0;

            do {
                if ( waitingMap.find( tmpVacantIndex ) != waitingMap.end() ) {
                    // There's a waitng car in the position
                    // Mark this parkingVec slot as occupied then loop through
                    // all cars & increment the indexes of the cars a distance
                    // of dist
                    // Push the car into parkedSet
                    // Then break out of this do while loop.
                    parkingVec[ vacantIndex ] = waitingMap[ tmpVacantIndex ];
                    parkingVec[ vacantIndex ].parkedIndex = vacantIndex;
                    unordered_map< int, Car > tmpWaitingMap = waitingMap;
                    waitingMap.clear();

                    for ( unordered_map< int, Car >::iterator iter = tmpWaitingMap.begin();
                            iter != tmpWaitingMap.end(); iter++) {
                        iter->second.index = ( iter->second.index + dist ) % Car::TOTAL_SPACES;

                        if ( iter->first != tmpVacantIndex ) {
                            waitingMap.insert( { iter->second.index, iter->second } );
                        }
                    }

                    parkedSet.insert( parkingVec[ vacantIndex ] );
                    break;
                }

                --tmpVacantIndex;
                ++dist;
                if ( tmpVacantIndex < 0 ) {
                    tmpVacantIndex += Car::TOTAL_SPACES;
                }

            } while ( tmpVacantIndex != vacantIndex );
        }

        for ( const Car& car : waitingSet ) {
            set< Car >::iterator foundIter = parkedSet.find( car );
            if ( foundIter != parkedSet.end() ) {
                cout << "Original position " << foundIter->orgIndex + 1 << " parked in " << foundIter->parkedIndex + 1 << endl;
            } else {
                cout << "Original position " << car.orgIndex + 1 << " did not park" << endl;
            }
        }

        if ( n < N - 1 ) {
            cout << endl;
        }

    }

    return 0;
}
