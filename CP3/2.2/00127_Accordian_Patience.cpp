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

//
// Solution 1:
//
// - We would use a deque< stack< string > > to represent the cards as they're dealt
// - We keep reading new cards & push a new stack< string > onto the deque
// - After pushing stack< string > into the deque, we loop the deque< stack< string > >
// from right to left
//     - With each stack< string > 3 places to the left or 1 place to the left of
//     the curIndex, we see if there's any chance curIndex can move to the 
//     stack< string > on the left.
//         - If the top can be moved, move it furthest to the left most.
//             - After moving card to the left most, loop from that left-most place
//             to curIndex ( inclusively )
//                 - As we're looping, check again to see if all cards on current
//                 stack< string > can be popped & move to the furthest left.
//
// Time Complexity : O( N ) since the number of cards are fixed
//                   N is the amount of deck dealed.
// Space Complexity : O( N )
//
//

class Solution {
public:
    static bool isMatched( const string& c1, const string& c2 ) {
        return ( c1[ 0 ] == c2[ 0 ] ) || ( c1[ 1 ] == c2[ 1 ] );
    }

    static pair< int, bool > moveCardLeftMost( deque< stack< string > >& deq, int fromIdx ) {
        int curIndex = fromIdx;
        if ( curIndex >= 3
                && Solution::isMatched( deq[ curIndex - 3 ].top(),
                                        deq[ fromIdx ].top() ) ) {
            curIndex -= 3;
        } else if ( curIndex >= 1
                && Solution::isMatched( deq[ curIndex - 1 ].top(),
                                        deq[ fromIdx ].top() ) ) {
            curIndex -= 1;
        }

        if ( curIndex == fromIdx ) return { 0, false };
        int cardsMoved = 0;
        bool stackRemoved = false;
        if ( Solution::isMatched( deq[ curIndex ].top(), deq[ fromIdx ].top() ) ) {
            deq[ curIndex ].push( deq[ fromIdx ].top() );
            deq[ fromIdx ].pop();
            ++cardsMoved;
            if ( deq[ fromIdx ].empty() ) {
                deq.erase( deq.begin() + fromIdx );
                stackRemoved = true;
            }
        }
        return { cardsMoved, stackRemoved };
    }
};

int main( int argc, char ** argv ) {

    while ( true ) {
        deque< stack< string > > cardsDeque;
        bool gameFinished = false;

        for ( int i = 0; i < 52; i++ ) {
            string card;
            cin >> card;

            // end of input
            if ( card == "#" ) {
                gameFinished = true;
                break;
            }

            stack< string > cardsStack;
            cardsStack.push( card );
            cardsDeque.push_back( cardsStack );
            
            pair< int, bool > cardsStackPair = { 0, false };
            do {
                cardsStackPair = { 0, false }; 
                for ( int j = 1; j < cardsDeque.size(); j++ ) {
                    pair< int, bool > curCardsStackPair = Solution::moveCardLeftMost( cardsDeque, j );
                    if ( curCardsStackPair.first > 0 ) {
                        cardsStackPair = curCardsStackPair;
                    }
                    if ( curCardsStackPair.second ) --j;
                    if ( cardsStackPair.first > 0 ) break;
                }
            } while ( cardsStackPair.first > 0 );
        }

        if ( gameFinished ) break;

        cout << cardsDeque.size() << " pile" << ( cardsDeque.size() > 1 ? "s" : "" ) << " remaining:";
        for ( int i = 0; i < cardsDeque.size(); i++ ) {
            cout << " " << cardsDeque[ i ].size();
        }
        cout << endl;
    }

    return 0;
}
