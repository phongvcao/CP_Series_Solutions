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

namespace Terminal {
    static const char CHAR_CIRCUMFLEX = '^';

    static const char CURSOR_LINE_BEGIN = 'b';
    static const char CURSOR_UP = 'u';
    static const char CURSOR_DOWN = 'd';
    static const char CURSOR_LEFT = 'l';
    static const char CURSOR_RIGHT = 'r';
    static const char CURSOR_LEFT_TOP = 'h';

    static const char ERASE_RIGHT_CHAR = 'e';

    static const char CLEAR_SCREEN = 'c';

    static const char MODE_INSERT = 'i';
    static const char MODE_OVERWRITE = 'o';

    static const char CHAR_BLANK = ' ';

    static const int INITIAL_TERM_SIZE = 10;
}

int main( int argc, char ** argv ) {

    int caseCount = 0;
    string line = "";

    while ( true ) {
        int N = 0;
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> N;
        }

        if ( N == 0 ) break;

        vector< string > termVec( Terminal::INITIAL_TERM_SIZE, "          " );
        int cursorRow = 0;
        int cursorCol = 0;
        char curMode = Terminal::MODE_OVERWRITE;
        string buffer = "";

        for ( int n = 0; n < N; n++ ) {
            string line = "";
            if ( getline( cin, line ) ) {

                int lineIdx = 0;
                while ( lineIdx < line.size() ) {
                    if ( line[ lineIdx ] == Terminal::CHAR_CIRCUMFLEX ) {
                        if ( ! buffer.empty() ) {
                            switch ( curMode ) {
                                case Terminal::MODE_INSERT:
                                {
                                    // Insert buffer char to termVec
                                    string firstSubStr = termVec[ cursorRow ].substr( 0, cursorCol );
                                    string secondSubStr = termVec[ cursorRow ].substr( cursorCol );
                                    string finalStr = firstSubStr + buffer + secondSubStr;
                                    termVec[ cursorRow ] = finalStr.substr( 0, Terminal::INITIAL_TERM_SIZE );
                                    cursorCol += buffer.size();
                                    if ( cursorCol >= Terminal::INITIAL_TERM_SIZE ) {
                                        cursorCol = Terminal::INITIAL_TERM_SIZE - 1;
                                    }
                                    firstSubStr += buffer;
                                    if ( firstSubStr.size() > Terminal::INITIAL_TERM_SIZE ) {
                                        termVec[ cursorRow ][ cursorCol ] = buffer.back();
                                    }
                                    break;
                                }

                                case Terminal::MODE_OVERWRITE:
                                {
                                    // Loop through buffer & replace chars in termVec
                                    int limit = min( termVec[ cursorRow ].size() - cursorCol, buffer.size() );
                                    int oldCursorCol = cursorCol;
                                    for ( int i = 0; i < limit; i++ ) {
                                        termVec[ cursorRow ][ cursorCol ] = buffer[ i ];
                                        if ( cursorCol < Terminal::INITIAL_TERM_SIZE - 1 ) {
                                            ++cursorCol;
                                        }
                                    }

                                    if ( buffer.size() > termVec[ cursorRow ].size() - oldCursorCol ) {
                                        termVec[ cursorRow ][ cursorCol ] = buffer.back();
                                    }
                                    
                                    break;
                                }

                                default:
                                {
                                    break;
                                }
                            }
                            buffer = "";
                        }

                        if ( isdigit( line[ lineIdx + 1 ] ) ) {
                            cursorRow = line[ lineIdx + 1 ] - '0';
                            cursorCol = line[ lineIdx + 2 ] - '0';
                            lineIdx += 2;
                        } else {
                            switch ( line[ lineIdx + 1 ] ) {
                                case Terminal::CURSOR_LINE_BEGIN:
                                {
                                    cursorCol = 0;
                                    break;
                                }

                                case Terminal::CURSOR_UP:
                                {
                                    if ( cursorRow > 0 ) {
                                        cursorRow -= 1;
                                    }
                                    break;
                                }

                                case Terminal::CURSOR_DOWN:
                                {
                                    if ( cursorRow < 9 ) {
                                        cursorRow += 1;
                                    }
                                    break;
                                }

                                case Terminal::CURSOR_LEFT:
                                {
                                    if ( cursorCol > 0 ) {
                                        cursorCol -= 1;
                                    }
                                    break;
                                }

                                case Terminal::CURSOR_RIGHT:
                                {
                                    if ( cursorCol < 9 ) {
                                        cursorCol += 1;
                                    }
                                    break;
                                }

                                case Terminal::CURSOR_LEFT_TOP:
                                {
                                    cursorRow = 0;
                                    cursorCol = 0;
                                    break;
                                }

                                case Terminal::ERASE_RIGHT_CHAR:
                                {
                                    for ( int i = cursorCol; i < termVec[ cursorRow ].size(); i++ ) {
                                        termVec[ cursorRow ][ i ] = Terminal::CHAR_BLANK;
                                    }
                                    break;
                                }

                                case Terminal::CLEAR_SCREEN:
                                {
                                    for ( int i = 0; i < termVec.size(); i++ ) {
                                        for ( int j = 0; j < termVec[ i ].size(); j++ ) {
                                            termVec[ i ][ j ] = Terminal::CHAR_BLANK;
                                        }
                                    }
                                    break;
                                }

                                case Terminal::MODE_INSERT:
                                {
                                    curMode = Terminal::MODE_INSERT;
                                    break;
                                }

                                case Terminal::MODE_OVERWRITE:
                                {
                                    curMode = Terminal::MODE_OVERWRITE;
                                    break;
                                }

                                default:
                                {
                                    buffer += line[ lineIdx + 1 ];
                                    // Treat it as normal char
                                    // This is likely ^^ which writes circumflex
                                    // to current cursor position.
                                    break;
                                }
                            }
                            ++lineIdx;
                        }
                    } else {
                        switch ( curMode ) {
                            case Terminal::MODE_INSERT:
                            {
                                buffer += line[ lineIdx ];
                                break;
                            }

                            case Terminal::MODE_OVERWRITE:
                            {
                                buffer += line[ lineIdx ];
                                break;
                            }

                            default:
                            {
                                break;
                            }
                        }
                    }
                    ++lineIdx;
                }

                if ( ! buffer.empty() ) {
                    switch ( curMode ) {
                        case Terminal::MODE_INSERT:
                        {
                            // Insert buffer char to termVec
                            string firstSubStr = termVec[ cursorRow ].substr( 0, cursorCol );
                            string secondSubStr = termVec[ cursorRow ].substr( cursorCol );
                            string finalStr = firstSubStr + buffer + secondSubStr;
                            termVec[ cursorRow ] = finalStr.substr( 0, Terminal::INITIAL_TERM_SIZE );
                            cursorCol += buffer.size();
                            if ( cursorCol >= Terminal::INITIAL_TERM_SIZE ) {
                                cursorCol = Terminal::INITIAL_TERM_SIZE - 1;
                            }
                            firstSubStr += buffer;
                            if ( firstSubStr.size() > Terminal::INITIAL_TERM_SIZE ) {
                                termVec[ cursorRow ][ cursorCol ] = buffer.back();
                            }
                            break;
                        }

                        case Terminal::MODE_OVERWRITE:
                        {
                            // Loop through buffer & replace chars in termVec
                            int oldCursorCol = cursorCol;
                            int limit = min( termVec[ cursorRow ].size() - cursorCol, buffer.size() );
                            for ( int i = 0; i < limit; i++ ) {
                                termVec[ cursorRow ][ cursorCol ] = buffer[ i ];
                                if ( cursorCol < Terminal::INITIAL_TERM_SIZE - 1 ) {
                                    ++cursorCol;
                                }
                            }
                            if ( buffer.size() > termVec[ cursorRow ].size() - oldCursorCol ) {
                                termVec[ cursorRow ][ cursorCol ] = buffer.back();
                            }
                            break;
                        }

                        default:
                        {
                            break;
                        }
                    }
                    buffer = "";
                }
            }
        }

        cout << "Case " << caseCount + 1 << endl;
        cout << "+----------+" << endl;
        for ( int i = 0; i < termVec.size(); i++ ) {
            cout << "|" << termVec[ i ] << "|" << endl;
        }
        cout << "+----------+" << endl;
        ++caseCount;
    }

    return 0;
}
