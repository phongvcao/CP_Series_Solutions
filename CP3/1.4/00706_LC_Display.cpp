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

namespace Display {

    // Stroke Map
    //     0
    //    ---
    //   |   |
    // 3 |   | 5
    //   | 1 |
    //    ---
    //   |   |
    // 4 |   | 6
    //   |   |
    //    ---
    //     2
    //
    // There are 7 strokes maximum
    //
    // vector< vector< pair< Point, Point > > > is the map of maximum strokes
    // constructed based on s
    //
    // Stroke 0, 1, 2 is horizontal
    // Stroke 3, 4, 5, 6 is vertical
    //
    // We'll have a vector< vector< int > > toBeDeleted that specifies which number ( index
    // of outer vector<> has which strokes removed ( inner vector< int > ) )
    // 

    static const char STROKE_VERTICAL = '|';
    static const char STROKE_HORIZONTAL = '-';
    static const char STROKE_EMPTY = ' ';

    vector< vector< bool > > STROKES_VEC = {
    //  {     0,     1,     2,     3,     4,     5,     6 }
        {  true, false,  true,  true,  true,  true,  true },    // 0
        { false, false, false, false, false,  true,  true },    // 1
        {  true,  true,  true, false,  true,  true, false },    // 2
        {  true,  true,  true, false, false,  true,  true },    // 3
        { false,  true, false,  true, false,  true,  true },    // 4
        {  true,  true,  true,  true, false, false,  true },    // 5
        {  true,  true,  true,  true,  true, false,  true },    // 6
        {  true, false, false, false, false,  true,  true },    // 7
        {  true,  true,  true,  true,  true,  true,  true },    // 8
        {  true,  true,  true,  true, false,  true,  true },    // 9
    };

    void setStrokes( vector< vector< char > >& outputVec, int num, int s, int rowOffset, int colOffset ) {
        // Stroke 0
        if ( STROKES_VEC[ num ][ 0 ] ) {
            // Stroke 0 runs horizontally, from ( 0, 1 ) to ( 0, s + 1 )
            for ( int i = 1; i < s + 1; i++ ) {
                outputVec[ 0 + rowOffset ][ i + colOffset ] = STROKE_HORIZONTAL;
            }
        }
        
        // Stroke 1
        if ( STROKES_VEC[ num ][ 1 ] ) {
            // Stroke 1 runs horizontally, from ( s + 1, 1 ) to ( s + 1, s + 1 )
            for ( int i = 1; i < s + 1; i++ ) {
                outputVec[ s + 1 + rowOffset ][ i + colOffset ] = STROKE_HORIZONTAL;
            }
        }

        // Stroke 2
        if ( STROKES_VEC[ num ][ 2 ] ) {
            // Stroke 2 runs horizontally, from ( 2 * s + 2, 1 ) to ( 2 * s + 2, s + 1 )
            for ( int i = 1; i < s + 1; i++ ) {
                outputVec[ 2 * s + 2 + rowOffset ][ i + colOffset ] = STROKE_HORIZONTAL;
            }
        }

        // Stroke 3
        if ( STROKES_VEC[ num ][ 3 ] ) {
            // Stroke 3 runs vertically, from ( 1, 0 ) to ( s, 0 )
            for ( int i = 1; i < s + 1; i++ ) {
                outputVec[ i + rowOffset ][ 0 + colOffset ] = STROKE_VERTICAL;
            }
        }

        // Stroke 4
        if ( STROKES_VEC[ num ][ 4 ] ) {
            // Stroke 4 runs vertically, from ( s + 2, 0 ) to ( 2 * s + 1, 0 )
            for ( int i = s + 2; i < 2 * s + 2; i++ ) {
                outputVec[ i + rowOffset ][ 0 + colOffset ] = STROKE_VERTICAL;
            }
        }

        // Stroke 5
        if ( STROKES_VEC[ num ][ 5 ] ) {
            // Stroke 5 runs vertically, from ( 1, s + 1 ) to ( s, s + 1 )
            for ( int i = 1; i < s + 1; i++ ) {
                outputVec[ i + rowOffset ][ s + 1 + colOffset ] = STROKE_VERTICAL;
            }
        }

        // Stroke 6
        if ( STROKES_VEC[ num ][ 6 ] ) {
            // Stroke 6 runs vertically, from ( s + 2, s + 1 ) to ( 2 * s + 1, s + 1 )
            for ( int i = s + 2; i < 2 * s + 2; i++ ) {
                outputVec[ i + rowOffset ][ s + 1 + colOffset ] = STROKE_VERTICAL;
            }
        }
    }
}

int main( int argc, char ** argv ) {

    string line = "";
    while ( getline( cin, line ) ) {
        stringstream ss( line );
        int s = 0;
        string numStr = "";

        ss >> s >> numStr;

        if ( s == 0 ) break;

        vector< vector< char > > outputVec( 2 * s + 3, vector< char >( ( s + 2 ) * numStr.size() + numStr.size() - 1, Display::STROKE_EMPTY ) );
        for ( int i = 0; i < numStr.size(); i++ ) {
            if ( i == 0 ) {
                Display::setStrokes( outputVec, numStr[ i ] - '0', s, 0, ( s + 2 ) * i );
            } else {
                Display::setStrokes( outputVec, numStr[ i ] - '0', s, 0, ( s + 2 ) * i + i );
            }
        }

        for ( int i = 0; i < outputVec.size(); i++ ) {
            for ( int j = 0; j < outputVec[ i ].size(); j++ ) {
                cout << outputVec[ i ][ j ];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
