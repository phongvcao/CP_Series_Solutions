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
using std::sort;
using std::remove;
using std::swap;

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

    string line = "";
    int T = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> T;
    }

    int fieldCount = 0;
    while ( getline( cin, line ) ) {
        if ( line.empty() ) continue;

        int n = 0;
        stringstream ss( line );
        ss >> n;

        vector< vector< char > > fieldVec( n, vector< char >( n, '\0' ) );
        for ( int i = 0; i < n; i++ ) {
            if ( getline( cin, line ) ) {
                for ( int j = 0; j < line.size(); j++ ) {
                    fieldVec[ i ][ j ] = line[ j ];
                }
            }
        }

        bool showAllMines = false;
        vector< vector< char > > solvedVec( n, vector< char >( n, '.' ) );
        for ( int i = 0; i < n; i++ ) {
            if ( getline( cin, line ) ) {
                for ( int j = 0; j < line.size(); j++ ) {
                    if ( line[ j ] == 'x' ) {
                        if ( fieldVec[ i ][ j ] == '*' ) {
                            showAllMines = true;
                        } else {
                            int mineCount = 0;
                            if ( i > 0 ) {
                                if ( fieldVec[ i - 1 ][ j ] == '*' ) {
                                    ++mineCount;
                                }

                                if ( j > 0 ) {
                                    if ( fieldVec[ i - 1 ][ j - 1 ] == '*' ) {
                                        ++mineCount;
                                    }
                                }

                                if ( j < n - 1 ) {
                                    if ( fieldVec[ i - 1 ][ j + 1 ] == '*' ) {
                                        ++mineCount;
                                    }
                                }
                            }

                            if ( i < n - 1 ) {
                                if ( fieldVec[ i + 1 ][ j ] == '*' ) {
                                    ++mineCount;
                                }

                                if ( j > 0 ) {
                                    if ( fieldVec[ i + 1 ][ j - 1 ] == '*' ) {
                                        ++mineCount;
                                    }
                                }

                                if ( j < n - 1 ) {
                                    if ( fieldVec[ i + 1 ][ j + 1 ] == '*' ) {
                                        ++mineCount;
                                    }
                                }
                            }

                            if ( j > 0 ) {
                                if ( fieldVec[ i ][ j - 1 ] == '*' ) {
                                    ++mineCount;
                                }
                            }

                            if ( j < n - 1 ) {
                                if ( fieldVec[ i ][ j + 1 ] == '*' ) {
                                    ++mineCount;
                                }
                            }
                            solvedVec[ i ][ j ] = ( char )( '0' + mineCount );
                        }
                    }
                }
            }
        }

        if ( fieldCount > 0 ) {
            cout << endl;
        }

        for ( int i = 0; i < solvedVec.size(); i++ ) {
            for ( int j = 0; j < solvedVec[ i ].size(); j++ ) {
                if ( showAllMines ) {
                    if ( fieldVec[ i ][ j ] == '*' ) {
                        cout << fieldVec[ i ][ j ];
                    } else {
                        cout << solvedVec[ i ][ j ];
                    }
                } else {
                    cout << solvedVec[ i ][ j ];
                }
            }
            cout << endl;
        }
        
        ++fieldCount;
    }

    return 0;
}
