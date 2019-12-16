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

bool isNumeric( char c ) {
    return ( c >= '0' && c <= '9' );
}

bool isEmpty( const vector< vector< char > >& boardVec, int i, int j ) {
    return boardVec[ i ][ j ] == '.';
}

bool isChecked( const vector< vector< char > >& boardVec, int i, int j ) {
    return boardVec[ i ][ j ] == 'c';
}

bool check( vector< vector< char > >& boardVec, int i, int j ) {
    if ( ! isEmpty( boardVec, i, j ) ) return false;

    boardVec[ i ][ j ] = 'c';
    return true;
}

int main( int argc, char ** argv ) {

    string line = "";
    while ( getline( cin, line ) ) {
        int squaresCount = 64;

        // Checked will be marked with character 'c'
        vector< vector< char > > boardVec( 8, vector< char >( 8, '.' ) );

        int row = 0;
        int col = 0;
        for ( int i = 0; i < line.size(); i++ ) {
            if ( isNumeric( line[ i ] ) ) {
                col += line[ i ] - '0';
            } else if ( line[ i ] == '/' ) {
                ++row;
                col = 0;
            } else {
                boardVec[ row ][ col++ ] = line[ i ];
                --squaresCount;
            }
        }

        for ( int i = 0; i < boardVec.size(); i++ ) {
            for ( int j = 0; j < boardVec[ i ].size(); j++ ) {
                switch ( boardVec[ i ][ j ] ) {
                    case 'p':
                    {
                        if ( i <= 6 && j <= 6
                                && ! isChecked( boardVec, i + 1, j + 1 )
                                && check( boardVec, i + 1, j + 1 ) ) {
                            --squaresCount;
                        }

                        if ( i <= 6 && j >= 1
                                && ! isChecked( boardVec, i + 1, j - 1 )
                                && check( boardVec, i + 1, j - 1 ) ) {
                            --squaresCount;
                        }

                        break;
                    }

                    case 'P':
                    {
                        if ( i >= 1 && j >= 1
                                && ! isChecked( boardVec, i - 1, j - 1 )
                                && check( boardVec, i - 1, j - 1 ) ) {
                            --squaresCount;
                        }

                        if ( i >= 1 && j <= 6
                                && ! isChecked( boardVec, i - 1, j + 1 )
                                && check( boardVec, i - 1, j + 1 ) ) {
                            --squaresCount;
                        }
                        
                        break;
                    }

                    case 'n':
                    case 'N':
                    {
                        // Checking [ i - 1 ][ j - 2 ]
                        if ( i >= 1 && j >= 2
                                && ! isChecked( boardVec, i - 1, j - 2 )
                                && check( boardVec, i - 1, j - 2 ) ) {
                            --squaresCount;
                        }

                        // Checking [ i - 2 ][ j - 1 ]
                        if ( i >= 2 && j >= 1
                                && ! isChecked( boardVec, i - 2, j - 1 )
                                && check( boardVec, i - 2, j - 1 ) ) {
                            --squaresCount;
                        }

                        // Checking [ i - 2 ][ j + 1 ]
                        if ( i >= 2 && j <= 6
                                && ! isChecked( boardVec, i - 2, j + 1 )
                                && check( boardVec, i - 2, j + 1 ) ) {
                            --squaresCount;
                        }

                        // Checking [ i - 1 ][ j + 2 ]
                        if ( i >= 1 && j <= 5
                                && ! isChecked( boardVec, i - 1, j + 2 )
                                && check( boardVec, i - 1, j + 2 ) ) {
                            --squaresCount;
                        }

                        // Checking [ i + 1 ][ j + 2 ]
                        if ( i <= 6 && j <= 5
                                && ! isChecked( boardVec, i + 1, j + 2 )
                                && check( boardVec, i + 1, j + 2 ) ) {
                            --squaresCount;
                        }

                        // Checking [ i + 2 ][ j + 1 ]
                        if ( i <= 5 && j <= 6
                                && ! isChecked( boardVec, i + 2, j + 1 )
                                && check( boardVec, i + 2, j + 1 ) ) {
                            --squaresCount;
                        }

                        // Checking [ i + 2 ][ j - 1 ]
                        if ( i <= 5 && j >= 1
                                && ! isChecked( boardVec, i + 2, j - 1 )
                                && check( boardVec, i + 2, j - 1 ) ) {
                            --squaresCount;
                        }

                        // Checking [ i + 1 ][ j - 2 ]
                        if ( i <= 6 && j >= 2
                                && ! isChecked( boardVec, i + 1, j - 2 )
                                && check( boardVec, i + 1, j - 2 ) ) {
                            --squaresCount;
                        }

                        break;
                    }

                    case 'b':
                    case 'B':
                    {
                        // Check all left-top
                        for ( int k = i - 1, l = j - 1; k >= 0 && l >= 0; --k, --l ) {
                            if ( isChecked( boardVec, k, l ) ) continue;
                            if ( ! check( boardVec, k, l ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        // Check all right-top
                        for ( int k = i - 1, l = j + 1; k >= 0 && l <= 7; --k, ++l ) {
                            if ( isChecked( boardVec, k, l ) ) continue;
                            if ( ! check( boardVec, k, l ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        // Check all left-bottom
                        for ( int k = i + 1, l = j - 1; k <= 7 && l >= 0; ++k, --l ) {
                            if ( isChecked( boardVec, k, l ) ) continue;
                            if ( ! check( boardVec, k, l ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        // Check all right-bottom
                        for ( int k = i + 1, l = j + 1; k <= 7 && l <= 7; ++k, ++l ) {
                            if ( isChecked( boardVec, k, l ) ) continue;
                            if ( ! check( boardVec, k, l ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        break;
                    }

                    case 'r':
                    case 'R':
                    {
                        // Check all columns to the right
                        for ( int k = j + 1; k <= 7; k++ ) {
                            if ( isChecked( boardVec, i, k ) ) continue;
                            if ( ! check( boardVec, i, k ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        // Check all columns to the left
                        for ( int k = j - 1; k >= 0; k-- ) {
                            if ( isChecked( boardVec, i, k ) ) continue;
                            if ( ! check( boardVec, i, k ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        // Check all rows to the bottom
                        for ( int k = i + 1; k <= 7; k++ ) {
                            if ( isChecked( boardVec, k, j ) ) continue;
                            if ( ! check( boardVec, k, j ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        // Check all rows to the top
                        for ( int k = i - 1; k >= 0; k-- ) {
                            if ( isChecked( boardVec, k, j ) ) continue;
                            if ( ! check( boardVec, k, j ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        break;
                    }

                    case 'q':
                    case 'Q':
                    {
                        // Check all left-top
                        for ( int k = i - 1, l = j - 1; k >= 0 && l >= 0; --k, --l ) {
                            if ( isChecked( boardVec, k, l ) ) continue;
                            if ( ! check( boardVec, k, l ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        // Check all right-top
                        for ( int k = i - 1, l = j + 1; k >= 0 && l <= 7; --k, ++l ) {
                            if ( isChecked( boardVec, k, l ) ) continue;
                            if ( ! check( boardVec, k, l ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        // Check all left-bottom
                        for ( int k = i + 1, l = j - 1; k <= 7 && l >= 0; ++k, --l ) {
                            if ( isChecked( boardVec, k, l ) ) continue;
                            if ( ! check( boardVec, k, l ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        // Check all right-bottom
                        for ( int k = i + 1, l = j + 1; k <= 7 && l <= 7; ++k, ++l ) {
                            if ( isChecked( boardVec, k, l ) ) continue;
                            if ( ! check( boardVec, k, l ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }
                        
                        // Check all columns to the right
                        for ( int k = j + 1; k <= 7; k++ ) {
                            if ( isChecked( boardVec, i, k ) ) continue;
                            if ( ! check( boardVec, i, k ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        // Check all columns to the left
                        for ( int k = j - 1; k >= 0; k-- ) {
                            if ( isChecked( boardVec, i, k ) ) continue;
                            if ( ! check( boardVec, i, k ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        // Check all rows to the bottom
                        for ( int k = i + 1; k <= 7; k++ ) {
                            if ( isChecked( boardVec, k, j ) ) continue;
                            if ( ! check( boardVec, k, j ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        // Check all rows to the top
                        for ( int k = i - 1; k >= 0; k-- ) {
                            if ( isChecked( boardVec, k, j ) ) continue;
                            if ( ! check( boardVec, k, j ) ) {
                                break;
                            } else {
                                --squaresCount;
                            }
                        }

                        break;
                    }

                    case 'k':
                    case 'K':
                    {
                        // Check 3 x spots in top row
                        if ( i > 0 ) {
                            if ( ! isChecked( boardVec, i - 1, j )
                                    && check( boardVec, i - 1, j ) ) {
                                --squaresCount;
                            }

                            if ( j > 0 ) {
                                if ( ! isChecked( boardVec, i - 1, j - 1 )
                                        && check( boardVec, i - 1, j - 1 ) ) {
                                    --squaresCount;
                                }
                            }

                            if ( j < 7 ) {
                                if ( ! isChecked( boardVec, i - 1, j + 1 )
                                        && check( boardVec, i - 1, j + 1 ) ) {
                                    --squaresCount;
                                }
                            }
                        }

                        // Check 1 x spot on the left
                        if ( j > 0 ) {
                            if ( ! isChecked( boardVec, i, j - 1 )
                                    && check( boardVec, i, j - 1 ) ) {
                                --squaresCount;
                            }
                        }

                        // Cheek 1 x spot on the right
                        if ( j < 7 ) {
                            if ( ! isChecked( boardVec, i, j + 1 )
                                    && check( boardVec, i, j + 1 ) ) {
                                --squaresCount;
                            }
                        }

                        // Check 3 x spots in bottom row
                        if ( i < 7 ) {
                            if ( ! isChecked( boardVec, i + 1, j )
                                    && check( boardVec, i + 1, j ) ) {
                                --squaresCount;
                            }

                            if ( j > 0 ) {
                                if ( ! isChecked( boardVec, i + 1, j - 1 )
                                        && check( boardVec, i + 1, j - 1 ) ) {
                                    --squaresCount;
                                }
                            }

                            if ( j < 7 ) {
                                if ( ! isChecked( boardVec, i + 1, j + 1 )
                                        && check( boardVec, i + 1, j + 1 ) ) {
                                    --squaresCount;
                                }
                            }
                        }

                        break;
                    }

                    default:
                    {
                        break;
                    }

                }
            }
        }

        cout << squaresCount << endl;

    }

    return 0;
}
