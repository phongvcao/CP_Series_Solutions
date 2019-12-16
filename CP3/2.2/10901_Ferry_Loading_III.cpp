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
// - We will use 2 queue< int > : leftQueue & rightQueue
//
// - We will need curFerrySide string which represents which side (left or right)
// the ferry is on and also curTime which represents the current time.
//
// - As we're reading through the lines:
//     - If the time of arrival of the car is larger than curTime
//         - If it arrives on current side
//             - If the ferry still has available slots
//                 - Load until the ferry is full ( queue.pop() ), then
//                 
//             - ElseIf the ferry doesn't have any available slots left
//         - ElseIf it arrives on the other side
//     - ElseIf the time of arrival of the car is == curTime
//         - If it arrives on current side
//         - ElseIf it arrives on the other wide
//
// Time Complexity : O( N ) where N is number of cars
// Space Complexity : O( N ) where N is number of cars
//
//

class Solution {
public:

    static unordered_map< string, int > BANK_NAMES_TO_INDICES;
};

unordered_map< string, int > Solution::BANK_NAMES_TO_INDICES = {
    { "left", 0 },
    { "right", 1 },
};

int main( int argc, char ** argv ) {

    int C = 0;
    cin >> C;

    for ( int c = 0; c < C; c++ ) {
        int ferryCap = 0;
        int crossRiverTime = 0;
        int numCars = 0;

        cin >> ferryCap >> crossRiverTime >> numCars;

        vector< queue< pair< int, int > > > banksQueueVec( 2, queue< pair< int, int > >() );
        for ( int i = 0; i < numCars; i++ ) {
            int timeStamp = 0;
            string bankName = "";
            cin >> timeStamp >> bankName;

            banksQueueVec[ Solution::BANK_NAMES_TO_INDICES[ bankName ] ].push( { timeStamp, i } );
        }

        int curTime = 0;
        int curBankIndex = 0;
        vector< int > carsOutputVec( numCars, 0 );
        queue< pair< int, int > > carsOnFerryQueue;

        while ( true ) {
            if ( banksQueueVec[ 0 ].empty() && banksQueueVec[ 1 ].empty() ) break;

            int emptyBankIndex = -1;
            if ( banksQueueVec[ 0 ].empty() ) {
                emptyBankIndex = 0;
            } else if ( banksQueueVec[ 1 ].empty() ) {
                emptyBankIndex = 1;
            }

            // If either of the bank is empty, the ferry should just carry
            // the cars of the non-empty banks to destination
            if ( emptyBankIndex != -1 ) {
                // When there's an empty bank, the ferry must be on the non-empty
                // bank since it just finished transitting the last element
                // of the empty bank.
                //
                // Exception : When bank 0 starts out empty
                bool isCurBankEmpty = curBankIndex == emptyBankIndex;
                curBankIndex = emptyBankIndex ^ 1;
                int loopCount = 0;
                while ( ! banksQueueVec[ curBankIndex ].empty() ) {
                    int oldCurTime = curTime;
                    while ( ! banksQueueVec[ curBankIndex ].empty()
                            && carsOnFerryQueue.size() < ferryCap ) {
                        carsOnFerryQueue.push( banksQueueVec[ curBankIndex ].front() );
                        if ( loopCount == 0 && ! isCurBankEmpty ) {
                            curTime = max( oldCurTime, banksQueueVec[ curBankIndex ].front().first );
                        } else {
                            curTime = max( oldCurTime, banksQueueVec[ curBankIndex ].front().first + crossRiverTime );
                        }
                        banksQueueVec[ curBankIndex ].pop();

                        while ( carsOnFerryQueue.size() < ferryCap
                                && ! banksQueueVec[ curBankIndex ].empty()
                                && curTime >= banksQueueVec[ curBankIndex ].front().first ) {
                            carsOnFerryQueue.push( banksQueueVec[ curBankIndex ].front() );
                            curTime = max( curTime, banksQueueVec[ curBankIndex ].front().first );
                            banksQueueVec[ curBankIndex ].pop();
                        }

                        if ( banksQueueVec[ curBankIndex ].front().first > oldCurTime ) {
                            break;
                        }
                    }

                    // Cross the river
                    curTime += crossRiverTime;

                    while ( ! carsOnFerryQueue.empty() ) {
                        carsOutputVec[ carsOnFerryQueue.front().second ] = curTime;
                        carsOnFerryQueue.pop();
                    }
                    curTime += crossRiverTime;
                    ++loopCount;
                }
                break;
            }

            // Always compare 2 banks:
            //   - If either bank is empty(), the ferry should just carry
            //     the cars of the non-empty banks to destination
            //   - If current bank has top element equal to curTime
            //       - Load as many of these equal elements on ferry as possible
            //   - If current bank has top element smaller than or equal the other bank's
            //     OR the other bank is empty()
            //       - while the banksQueueVec[ curBankIndex ].top() still smaller
            //       than the other bank, we pop elements out until it meets
            //       quota. At this time, curTime = arrival time of latest element popped
            //       - We then unload the elements on the other side, then 
            //       end the loop
            //   - Else current bank has top element larger than other bank
            //     OR the current bank is empty()
            //       - We have to add travelTime into curTime first, then switch
            //       curBankIndex to the other bank
            //       - After switching, we have a while loop like in the first case

            bool riverCrossed = false;
            if ( ! banksQueueVec[ curBankIndex ].empty()
                    && banksQueueVec[ curBankIndex ].front().first <= curTime ) {
                while ( ! banksQueueVec[ curBankIndex ].empty()
                        && banksQueueVec[ curBankIndex ].front().first <= curTime
                        && carsOnFerryQueue.size() < ferryCap ) {
                    carsOnFerryQueue.push( banksQueueVec[ curBankIndex ].front() );
                    banksQueueVec[ curBankIndex ].pop();
                }
            } else if ( banksQueueVec[ curBankIndex ].empty()
                    || banksQueueVec[ curBankIndex ].front().first > banksQueueVec[ curBankIndex ^ 1 ].front().first ) {
                curTime = max( curTime, banksQueueVec[ curBankIndex ^ 1 ].front().first ) + crossRiverTime;
                riverCrossed = true;
                curBankIndex ^= 1;
                carsOnFerryQueue.push( banksQueueVec[ curBankIndex ].front() );
                banksQueueVec[ curBankIndex ].pop();
            } else {
                curTime = max( curTime, banksQueueVec[ curBankIndex ].front().first );
                carsOnFerryQueue.push( banksQueueVec[ curBankIndex ].front() );
                banksQueueVec[ curBankIndex ].pop();
            }

            while ( carsOnFerryQueue.size() < ferryCap
                    && ! banksQueueVec[ curBankIndex ].empty()
                    && curTime >= banksQueueVec[ curBankIndex ].front().first ) {
                carsOnFerryQueue.push( banksQueueVec[ curBankIndex ].front() );
                curTime = max( curTime, banksQueueVec[ curBankIndex ].front().first );
                banksQueueVec[ curBankIndex ].pop();
            }
            
            // Cross the river
            curTime += crossRiverTime;
            curBankIndex ^= 1;

            while ( ! carsOnFerryQueue.empty() ) {
                carsOutputVec[ carsOnFerryQueue.front().second ] = curTime;
                carsOnFerryQueue.pop();
            }
            
        }

        for ( int i = 0; i < carsOutputVec.size(); i++ ) {
            cout << carsOutputVec[ i ] << endl;
        }

        if ( c < C - 1 ) {
            cout << endl;
        }
    }

    return 0;
}
