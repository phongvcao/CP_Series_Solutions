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



int main( int argc, char ** argv ) {

    int T = 0;
    cin >> T;

    for ( int t = 0; t < T; t++ ) {
        int N = 0;
        cin >> N;

        vector< vector< int > > matrixVec( N, vector< int >( N, 0 ) );
        for ( int n = 0; n < N; n++ ) {
            string line = "";
            cin >> line;
            for ( int i = 0; i < line.size(); i++ ) {
                matrixVec[ n ][ i ] = line[ i ] - '0';
            }
        }

        int M = 0;
        cin >> M;

        for ( int m = 0; m < M; m++ ) {
            string cmd = "";
            cin >> cmd;

            if ( cmd == "transpose" ) {
                // Swap rows for columns
                vector< vector< int > > orgMatrixVec = matrixVec;

                for ( int i = 0; i < matrixVec.size(); i++ ) {
                    for ( int j = 0; j < matrixVec[ i ].size(); j++ ) {
                        matrixVec[ i ][ j ] = orgMatrixVec[ j ][ i ];
                    }
                }
            } else if ( cmd == "inc" ) {
                // Increase values of all cells by 1
                for ( int i = 0; i < matrixVec.size(); i++ ) {
                    for ( int j = 0; j < matrixVec[ i ].size(); j++ ) {
                        ++matrixVec[ i ][ j ];
                        if ( matrixVec[ i ][ j ] == 10 ) {
                            matrixVec[ i ][ j ] = 0;
                        }
                    }
                }
            } else if ( cmd == "dec" ) {
                // Decrease values of all cells by 1
                for ( int i = 0; i < matrixVec.size(); i++ ) {
                    for ( int j = 0; j < matrixVec[ i ].size(); j++ ) {
                        --matrixVec[ i ][ j ];
                        if ( matrixVec[ i ][ j ] == -1 ) {
                            matrixVec[ i ][ j ] = 9;
                        }
                    }
                }
            } else {
                int a = 0;
                int b = 0;
                cin >> a >> b;
                --a;
                --b;

                if ( cmd == "row" ) {
                    // Exchange row a & row b
                    for ( int i = 0; i < matrixVec[ a ].size(); i++ ) {
                        swap( matrixVec[ a ][ i ], matrixVec[ b ][ i ] );
                    }
                } else if ( cmd == "col" ) {
                    // Exchange col a & col b
                    for ( int i = 0; i < matrixVec.size(); i++ ) {
                        swap( matrixVec[ i ][ a ], matrixVec[ i ][ b ] );
                    }
                }
            }
        }

        cout << "Case #" << t + 1 << endl;
        for ( int i = 0; i < matrixVec.size(); i++ ) {
            for ( int j = 0; j < matrixVec[ i ].size(); j++ ) {
                cout << matrixVec[ i ][ j ];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
