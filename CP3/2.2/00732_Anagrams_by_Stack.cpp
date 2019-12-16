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
using std::partial_sum;         // Calculate partial_sum of range beginIter, endIter and put result to 3rd argument outIter
// using std::gcd;
// using std::lcm;

//------------------------------//

//
// Solution 1:
//
// - First we need to store the anagram of both strings in a vector< int > of
// size 256, or an unordered_map< char, int >.
//
// - We first compare their anagrams. If they're not the same, skip.
//
// - Now we push the first word into the stack. As we push the first word in the
// stack char-by-char:
//     - If charStack.top() == secondStr[ secondStrIdx ]
//         - If anagram[ charStack.top() ] > 1:
//             - We have 2 choices :
//                 - Keep pushing this char to charStack, OR
//                     - charStack.push( firstStr[ firstStrIdx ] )
//                     - seqStr += 'i'
//                 - Pop this char out of charStack
//                     - charStack.pop()
//                     - seqStr += 'o'
//         - ElseIf anagram[ charStack.top() ] == 1:
//             - We have to pop this char out of charStack
//                 - charStack.pop()
//                 - seqStr += 'o'
//     - ElseIf charStack.top() != secondStr[ secondStrIdx ]
//         - We have to push this char into charStack
//
// Time Complexity : O( N ! ) for the number of permutation of push & pop
// Space Complexity : O( N ) for the recursive stack
//
//

class Solution {
public:

    static void printPushPopSequences( const string& word1, const string& word2,
                                       stack< char > word1Stack,
                                       int word1Index, int word2Index,
                                       unordered_map< char, int > word1AnaMap,
                                       string strSoFar, string outputSoFar ) {
        if ( word2Index == word2.size() || word1Index == word1.size() ) {
            while ( ! word1Stack.empty() ) {
                outputSoFar += ( char )word1Stack.top();
                if ( outputSoFar.back() != word2[ outputSoFar.size() - 1 ] ) return;
                word1Stack.pop();
                strSoFar += " o";
            }
            strSoFar = strSoFar.substr( 1 );
            cout << strSoFar << endl;
            return;
        }

        if ( ! word1Stack.empty() ) {
            // We have 2 choices:
            //   - Keep pushing onto word1Stack
            //   - Pop out of word1Stack
            if ( word1Stack.top() == word2[ word2Index ] ) {
                //
                // When top of word1Stack == word2[ word2Index ], we have 2 choices:
                //   - Keep pushing if word1AnaMap[ word1[ word1Index ] ] > 0
                //   - We can pop in all cases

                if ( word1AnaMap[ word1[ word1Index ] ] > 0 ) {
                    stack< char > tmpWord1Stack = word1Stack;
                    tmpWord1Stack.push( word1[ word1Index ] );
                    unordered_map< char, int > tmpWord1AnaMap = word1AnaMap;
                    --tmpWord1AnaMap[ word1[ word1Index ] ];
                    printPushPopSequences( word1, word2, tmpWord1Stack, word1Index + 1, word2Index, tmpWord1AnaMap, strSoFar + " i", outputSoFar );
                }

                char topStack = word1Stack.top();
                word1Stack.pop();
                printPushPopSequences( word1, word2, word1Stack, word1Index, word2Index + 1, word1AnaMap, strSoFar + " o", outputSoFar + ( char )topStack );
            } else {
                word1Stack.push( word1[ word1Index ] );
                // Whenver we push, we subtract from word1AnaMap
                --word1AnaMap[ word1[ word1Index ] ];
                printPushPopSequences( word1, word2, word1Stack, word1Index + 1, word2Index, word1AnaMap, strSoFar + " i", outputSoFar );
            }
        } else {
            word1Stack.push( word1[ word1Index ] );
            --word1AnaMap[ word1[ word1Index ] ];
            printPushPopSequences( word1, word2, word1Stack, word1Index + 1, word2Index, word1AnaMap, strSoFar + " i", outputSoFar );
        }
    }

};

int main( int argc, char ** argv ) {

    while ( true ) {
        string word1 = "";
        unordered_map< char, int > word1AnaMap;
        cin >> word1;
        if ( ! word1.empty() ) {
            for ( int i = 0; i < word1.size(); i++ ) {
                if ( word1AnaMap.find( word1[ i ] ) != word1AnaMap.end() ) {
                    ++word1AnaMap[ word1[ i ] ];
                } else {
                    word1AnaMap.insert( { word1[ i ], 1 } );
                }
            }
        } else {
            break;
        }

        bool isValid = true;
        string word2 = "";
        unordered_map< char, int > tmpWord1AnaMap = word1AnaMap;
        cin >> word2;
        if ( ! word2.empty() ) {
            if ( ( word1.size() != word2.size() ) || ( word1.empty() && word2.empty() ) ) {
                isValid = false;
            } else {
                for ( int i = 0; i < word2.size(); i++ ) {
                    if ( tmpWord1AnaMap.find( word2[ i ] ) == tmpWord1AnaMap.end() ) {
                        isValid = false;
                        break;
                    } else {
                        if ( tmpWord1AnaMap[ word2[ i ] ] == 0 ) {
                            isValid = false;
                            break;
                        }

                        --tmpWord1AnaMap[ word2[ i ] ];
                    }
                }
            }
        } else {
            break;
        }

        if ( ! isValid ) {
            cout << "[" << endl;
            cout << "]" << endl;
        } else {
            cout << "[" << endl;
            stack< char > word1Stack;
            Solution::printPushPopSequences( word1, word2, word1Stack, 0, 0, word1AnaMap, "", "" );
            cout << "]" << endl;
        }
    }

    return 0;
}
