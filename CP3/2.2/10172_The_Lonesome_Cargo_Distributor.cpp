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
#include <bitset>
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
using std::stoll;

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
using std::atoi;
using std::atol;
using std::atoll;

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

//----< bitset >----------------//
using std::bitset;

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
using std::sort;                // Intro-Sort (QuickSort => HeapSort when recursion depth exceeds certain level), NOT IN-PLACE & NOT STABLE
using std::partial_sort;        // HeapSort elements in range ( iterFirst, iterLast ) ( exclusively ). IN-PLACE & NOT STABLE
using std::stable_sort;         // Merge-Sort elements. NOT IN-PLACE & STABLE
using std::sort_heap;           // HeapSort elements. IN-PLACE & NOT STABLE
using std::remove;
using std::swap;
using std::binary_search;
using std::next_permutation;
using std::prev_permutation;
using std::set_intersection;    // Only works on std::set and not std::unordered_set
using std::set_difference;      // Only works on std::set and not std::unordered_set
using std::set_union;
using std::lower_bound;         // Returns iter pointing to first element >= value
using std::upper_bound;         // Returns iter pointing to first element > value
using std::transform;           // Apply the given function to a range and store result in another range
// using std::nth_element;

//----< memory >----------------//
using std::make_unique;
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
using std::partial_sum;         // Calculate partial_sum of range beginIter, endIter and put result to 3rd argument outIter
// using std::gcd;
// using std::lcm;

//------------------------------//

//
// Solution 1:
//
// - We will use a vector< queue< int > > for the stations & cargos in each
// station
//
// - vector< queue< int > > will be initialized to size N, and filled with the
// appropriate values
//
// - We will also have a stack< int > carrierStack which represents the carrier
// stack
//
// - We need to define constant MIN_BETWEEN_STATION and MIN_UNLOAD_PER_CARGO
// and MIN_LOAD_CARGO
//
// - We will just simulate the process of loading/unloading starting from
// station 1 around the ring until all cargos distributed to destination
// ( we would keep track of this by having a vector< bool > that says which
// station has had the correct cargo loaded, we ++correctCargoLoaded when 
// unloading to the correct station until correctCargoLoaded == N )
//
// - Unloading cargo to correct station simply means we don't push the value
// into vector< queue< int > > above and ++correctCargoLoaded
//
// Time Complexity : O( N )
// Space Complexity : O( N )
//
//

class Solution {
public:

    static const int MIN_BETWEEN_STATION;
    static const int MIN_UNLOAD_PER_CARGO;
    static const int MIN_LOAD_PER_CARGO;

};

const int Solution::MIN_BETWEEN_STATION = 2;
const int Solution::MIN_UNLOAD_PER_CARGO = 1;
const int Solution::MIN_LOAD_PER_CARGO = 1;


int main( int argc, char ** argv ) {

    int T = 0;
    cin >> T;

    for ( int t = 0; t < T; t++ ) {
        int numStations = 0;
        int carrierCap = 0;
        int maxCargoes = 0;
        cin >> numStations >> carrierCap >> maxCargoes;

        vector< queue< int > > stationsVec( numStations, queue< int >() );

        for ( int i = 0; i < numStations; i++ ) {
            int numCargoes = 0;
            cin >> numCargoes;
            for ( int j = 0; j < numCargoes; j++ ) {
                int cargoId = 0;
                cin >> cargoId;
                stationsVec[ i ].push( cargoId );
            }
        }

        stack< int > carrierStack;
        int curStationIndex = 0;
        int totalTime = 0;
        while ( true ) {
            // UNLOADING
            while ( ! carrierStack.empty()
                    && ( carrierStack.top() == curStationIndex + 1 || stationsVec[ curStationIndex ].size() < maxCargoes ) ) {
                if ( carrierStack.top() != curStationIndex + 1 ) {
                    stationsVec[ curStationIndex ].push( carrierStack.top() );
                }
                totalTime += Solution::MIN_UNLOAD_PER_CARGO;
                carrierStack.pop();
            }

            // LOADING
            while ( carrierStack.size() < carrierCap
                    && ! stationsVec[ curStationIndex ].empty() ) {
                carrierStack.push( stationsVec[ curStationIndex ].front() );
                stationsVec[ curStationIndex ].pop();
                totalTime += Solution::MIN_LOAD_PER_CARGO;
            }

            bool finished = carrierStack.empty();
            for ( int i = 0; i < numStations; i++ ) {
                finished &= stationsVec[ i ].empty();
            }

            if ( finished ) break;

            curStationIndex = ( curStationIndex + 1 ) % stationsVec.size();
            totalTime += Solution::MIN_BETWEEN_STATION;
        }

        cout << totalTime << endl;
    }

    return 0;
}
