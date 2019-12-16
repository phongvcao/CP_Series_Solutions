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

namespace Postscript {
    vector< vector< string > > CHARS_C5_VEC = {
        {
            ".***..",
            "*...*.",
            "*****.",
            "*...*.",
            "*...*.",
        },

        {
            "****..",
            "*...*.",
            "****..",
            "*...*.",
            "****..",
        },

        {
            ".****.",
            "*...*.",
            "*.....",
            "*.....",
            ".****.",
        },

        {
            "****..",
            "*...*.",
            "*...*.",
            "*...*.",
            "****..",
        },

        {
            "*****.",
            "*.....",
            "***...",
            "*.....",
            "*****.",
        },

        {
            "*****.",
            "*.....",
            "***...",
            "*.....",
            "*.....",
        },

        {
            ".****.",
            "*.....",
            "*..**.",
            "*...*.",
            ".***..",
        },

        {
            "*...*.",
            "*...*.",
            "*****.",
            "*...*.",
            "*...*.",
        },

        {
            "*****.",
            "..*...",
            "..*...",
            "..*...",
            "*****.",
        },

        {
            "..***.",
            "...*..",
            "...*..",
            "*..*..",
            ".**...",
        },

        {
            "*...*.",
            "*..*..",
            "***...",
            "*..*..",
            "*...*.",
        },

        {
            "*.....",
            "*.....",
            "*.....",
            "*.....",
            "*****.",
        },

        {
            "*...*.",
            "**.**.",
            "*.*.*.",
            "*...*.",
            "*...*.",
        },

        {
            "*...*.",
            "**..*.",
            "*.*.*.",
            "*..**.",
            "*...*.",
        },

        {
            ".***..",
            "*...*.",
            "*...*.",
            "*...*.",
            ".***..",
        },

        {
            "****..",
            "*...*.",
            "****..",
            "*.....",
            "*.....",
        },

        {
            ".***..",
            "*...*.",
            "*...*.",
            "*..**.",
            ".****.",
        },

        {
            "****..",
            "*...*.",
            "****..",
            "*..*..",
            "*...*.",
        },

        {
            ".****.",
            "*.....",
            ".***..",
            "....*.",
            "****..",
        },
        
        {
            "*****.",
            "*.*.*.",
            "..*...",
            "..*...",
            ".***..",
        },
        
        {
            "*...*.",
            "*...*.",
            "*...*.",
            "*...*.",
            ".***..",
        },
        
        {
            "*...*.",
            "*...*.",
            ".*.*..",
            ".*.*..",
            "..*...",
        },
        
        {
            "*...*.",
            "*...*.",
            "*.*.*.",
            "**.**.",
            "*...*.",
        },
        
        {
            "*...*.",
            ".*.*..",
            "..*...",
            ".*.*..",
            "*...*.",
        },
        
        {
            "*...*.",
            ".*.*..",
            "..*...",
            "..*...",
            "..*...",
        },
        
        {
            "*****.",
            "...*..",
            "..*...",
            ".*....",
            "*****.",
        },
        
        {
            "......",
            "......",
            "......",
            "......",
            "......",
        },

    };

    static int C1_CHAR_HEIGHT = 1;
    static int C1_CHAR_WIDTH = 1;

    static int C5_CHAR_HEIGHT = 5;
    static int C5_CHAR_WIDTH = 6;

    static int GRID_WIDTH = 60;
    static int GRID_HEIGHT = 60;

};

int main( int argc, char ** argv ) {

    string line = "";
    vector< vector< char > > outputVec( Postscript::GRID_HEIGHT, vector< char >( Postscript::GRID_WIDTH, '.' ) );

    while ( getline( cin, line ) ) {
        if ( line == ".EOP" ) {
            // Print out outputVec
            for ( int i = 0; i < outputVec.size(); i++ ) {
                for ( int j = 0; j < outputVec[ i ].size(); j++ ) {
                    cout << outputVec[ i ][ j ];
                }
                cout << endl;
            }
            cout << endl;
            for ( int i = 0; i < outputVec.size(); i++ ) {
                cout << "-";
            }
            cout << endl;
            cout << endl;

            // Reset all data structures
            outputVec.clear();
            outputVec.resize( Postscript::GRID_HEIGHT, vector< char >( Postscript::GRID_WIDTH, '.' ) );
            continue;
        }

        string command = "";
        string font = "";
        int row = 0;
        int col = -1;
        string value = "";
        stringstream ss( line );
        ss >> command >> font >> row;

        if ( command == ".P" ) {
            ss >> col;
            --col;
        }

        int firstVertBarIdx = line.find_first_of( "|" );
        int lastVertBarIdx = line.find_last_of( "|" );
        if ( firstVertBarIdx != -1 && lastVertBarIdx != -1 ) {
            value = line.substr( firstVertBarIdx + 1, lastVertBarIdx - firstVertBarIdx - 1 );
        }

        // We know both row & col for .P
        //
        // But we know only row for .L, .R, .C
        //
        // Now let's determine col for .L, .R, .C
        if ( command == ".L" ) {
            col = 0;
        } else if ( command == ".R" ) {
            if ( font == "C1" ) {
                col = Postscript::GRID_WIDTH - Postscript::C1_CHAR_WIDTH * value.size();
            } else {
                col = Postscript::GRID_WIDTH - Postscript::C5_CHAR_WIDTH * value.size();
            }
        } else if ( command == ".C" ) {
            if ( font == "C1" && value.size() & 1 ) {
                // If the width of output text is odd, we'll centerly align it
                // on colIdx 30.
                col = 30 - value.size() / 2;
            } else {
                // For the even cases, we just centerly align the text
                if ( font == "C1" ) {
                    col = 30 - value.size() / 2;
                } else {
                    col = 30 - value.size() * Postscript::C5_CHAR_WIDTH / 2;
                }
            }
        }

        // Now we just print the text to outputVec
        // Remember that C1 overrides C5 and C5 can only overrides '.'
        if ( font == "C1" ) {
            int valueIdx = 0;
            int rowIdx = row - 1;
            int colIdx = col;

            while ( valueIdx < value.size() && colIdx < Postscript::GRID_WIDTH ) {
                // We only write wheen colIdx is within range [ 0, 60 ].
                // Otherwise, keep incrementing valueIdx
                if ( valueIdx >= 0 && colIdx >= 0 ) {
                    if ( ! isspace( value[ valueIdx ] ) ) {
                        outputVec[ rowIdx ][ colIdx ] = value[ valueIdx ];
                    }
                }

                ++valueIdx;
                ++colIdx;
            }
        } else if ( font == "C5" ) {
            int valueRowIdx = 0;
            int rowIdx = row - 1;

            while ( valueRowIdx < Postscript::C5_CHAR_HEIGHT
                    && rowIdx < Postscript::GRID_HEIGHT ) {

                if ( valueRowIdx >= 0 && rowIdx >= 0 ) {

                    int valueColIdx = 0;
                    int colIdx = col;

                    while ( valueColIdx < Postscript::C5_CHAR_WIDTH * value.size()
                            && colIdx < Postscript::GRID_WIDTH ) {

                        int charsC5VecIdx = 0;
                        if ( isspace( value[ valueColIdx / Postscript::C5_CHAR_WIDTH ] ) ) {
                            charsC5VecIdx = Postscript::CHARS_C5_VEC.size() - 1;
                        } else {
                            charsC5VecIdx = value[ valueColIdx / Postscript::C5_CHAR_WIDTH ] - 'A';
                        }

                        if ( valueColIdx >= 0 && colIdx >= 0 ) {
                            // Output the character in C5 font to outputVec
                            if ( Postscript::CHARS_C5_VEC[ charsC5VecIdx ][ valueRowIdx ][ valueColIdx % Postscript::C5_CHAR_WIDTH ] != '.' ) {
                                outputVec[ rowIdx ][ colIdx ] = Postscript::CHARS_C5_VEC[ charsC5VecIdx ][ valueRowIdx ][ valueColIdx % Postscript::C5_CHAR_WIDTH ];
                            }
                        }

                        ++valueColIdx;
                        ++colIdx;
                    }

                }

                ++valueRowIdx;
                ++rowIdx;

            }
        }
    }

    return 0;
}
