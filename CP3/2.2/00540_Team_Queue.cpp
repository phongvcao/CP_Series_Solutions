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
// - We probably need to keep unordered_map< int, int > of which element belongs
// to which team
//
// - We also would have another unordered_map< int, int > of dequeIndexToTeam
//
// - Teams are indexed from 0 to t
//
// - We would have a deque< pair< int, deque< int > > > of elements. 
//     - The index of qDeque is the team numbers. qDeque starts out empty
//         - The first int of the pair< int, deque< int > > is the ID of the team
//         - The deque< int > inside the deque< pair< int, deque< int > > >
//         is the list of element of the particular team
//     - Whenever we ENQUEUE, we check for teamId of the element with unordered_map< int, int >
//     above, 
//
//
// Solution 2:
//
// - We would have a queue< queue< int > > of elements & teams
// - We would also have unordered_map< int, int > to check if the elements have
// the same team membership
// - We would have a vector< queue< int > * > connecting vectorIndex teamId
// with the queue< int > inside queue< queue< int > >. Initially vector< queue< int > * >
// only contain NULL pointers.
//
// - As we're enqueue-ing, we check whether qVec[ teamId_of_element ] is NULL
// If it's, we enqueue a new queue into queue< queue< int > >. Otherwise, we
// follow the pointers to queue< int > * to insert the new element.
//
// - When we dequeue, we dequeue elements according to the order of queue< int >
// inside queue< queue< int > >
//
// Time Complexity : O( 1 ) for enqueue() & dequeue()
// Space Complexity : O( N ) for the queue & vectors & maps, where N is the
//                    number of elements.
//
//



int main( int argc, char ** argv ) {

    int caseCount = 0;
    while ( true ) {
        string line = "";
        int T = 0;
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> T;
        }

        if ( T == 0 ) break;

        unordered_map< int, int > elesToTeamsMap;
        for ( int t = 0; t < T; t++ ) {
            if ( getline( cin, line ) ) {
                stringstream ss( line );
                int numEles = 0;
                ss >> numEles;

                for ( int i = 0; i < numEles; i++ ) {
                    int eleId = 0;
                    ss >> eleId;
                    elesToTeamsMap.insert( { eleId, t } );
                }
            }
        }

        queue< pair< int, queue< int > > > teamsQueue;
        vector< queue< int > * > queueVec( T, NULL );

        cout << "Scenario #" << caseCount + 1 << endl;
        while ( getline( cin, line ) ) {
            if ( line == "STOP" ) {
                break;
            }

            stringstream ss( line );
            string cmd = "";
            ss >> cmd;

            if ( cmd == "ENQUEUE" ) {
                // ENQUEUE operation
                int eleId = 0;
                ss >> eleId;

                if ( queueVec[ elesToTeamsMap[ eleId ] ] ) {
                    queueVec[ elesToTeamsMap[ eleId ] ]->push( eleId );
                } else {
                    queue< int > newQueue;
                    newQueue.push( eleId );
                    teamsQueue.push( { elesToTeamsMap[ eleId ], newQueue } );
                    queueVec[ elesToTeamsMap[ eleId ] ] = &( teamsQueue.back().second );
                }
            } else if ( cmd == "DEQUEUE" ) {
                // DEQUEUE operation
                if ( ! teamsQueue.empty() ) {
                    if ( ! teamsQueue.front().second.empty() ) {
                        cout << teamsQueue.front().second.front() << endl;
                        int teamId = teamsQueue.front().first;
                        teamsQueue.front().second.pop();
                        if ( teamsQueue.front().second.empty() ) {
                            teamsQueue.pop();
                            queueVec[ teamId ] = NULL;
                        }
                    }
                }
            }
        }

        cout << endl;
        ++caseCount;
    }

    return 0;
}
