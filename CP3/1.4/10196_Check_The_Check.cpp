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

bool check( vector< string >& boardVec, vector< vector< char > >& checkedVec, int i, int j, bool isBlack = true ) {
    // Stop when the spot is occupied by 'o'
    if ( checkedVec[ i ][ j ] == 'o' ) {
        return false;
    }

    // Stop when the spot is occupied by king of same color
    if ( boardVec[ i ][ j ] == 'k' && isBlack ) {
        return false;
    }
    
    // Stop when the spot is occupied by king of same color
    if ( boardVec[ i ][ j ] == 'K' && ! isBlack ) {
        return false;
    }

    if ( isBlack ) {
        if ( checkedVec[ i ][ j ] == 'C' ) {
            checkedVec[ i ][ j ] = '.';
        } else if ( checkedVec[ i ][ j ] == '\0' ) {
            checkedVec[ i ][ j ] = 'c';
        }
    } else {
        if ( checkedVec[ i ][ j ] == 'c' ) {
            checkedVec[ i ][ j ] = '.';
        } else if ( checkedVec[ i ] [ j ] == '\0' ) {
            checkedVec[ i ][ j ] = 'C';
        }
    }

    return true;
}

int main( int argc, char ** argv ) {

    string line = "";
    int row = 0;
    vector< string > boardVec( 8, "" );
    vector< vector< char > > checkedVec( 8, vector< char >( 8, '\0' ) );
    int gameCount = 0;
    bool allLinesEmpty = true;

    // Mark occupied spots as 'o' so chess pieces won't check over the head
    // of one another
    int kRow = -1;
    int kCol = -1;
    int KRow = -1;
    int KCol = -1;

    while ( getline( cin, line ) ) {
        if ( line.empty() ) {
            allLinesEmpty = true;
            row = 0;
            continue;
        }

        if ( row == 0 ) {
            for ( int i = 0; i < checkedVec.size(); i++ ) {
                for ( int j = 0; j < checkedVec[ i ].size(); j++ ) {
                    checkedVec[ i ][ j ] = '\0';
                }
            }
            kRow = -1;
            kCol = -1;
            KRow = -1;
            KCol = -1;
        }

        boardVec[ row ] = line;
        for ( int i = 0; i < line.size(); i++ ) {
            if ( line[ i ] != '.' ) {
                allLinesEmpty = false;
            }

            if ( line[ i ] != '.' && line[ i ] != 'k' && line[ i ] != 'K' ) {
                checkedVec[ row ][ i ] = 'o';
            }

            if ( line[ i ] == 'k' ) {
                kRow = row;
                kCol = i;
            }

            if ( line[ i ] == 'K' ) {
                KRow = row;
                KCol = i;
            }
        }

        if ( row == 7 ) {
            if ( allLinesEmpty ) break;

            // Checked by blacks : 'c'
            // Checked by whites : 'C'
            // Occpied by pieces other than Kings : 'o'
            // Checked by both blacks and whites : '.'
            // Not checked by anything : '\0'

            for ( int i = 0; i < boardVec.size(); i++ ) {
                for ( int j = 0; j < boardVec[ i ].size(); j++ ) {

                    switch ( boardVec[ i ][ j ] ) {
                        case 'p':
                        {
                            if ( i <= 6 && j <= 6 ) {
                                check( boardVec, checkedVec, i + 1, j + 1, true );
                            }

                            if ( i <= 6 && j >= 1 ) {
                                check( boardVec, checkedVec, i + 1, j - 1, true );
                            }
                            break;
                        }

                        case 'P':
                        {
                            if ( i >= 1 && j >= 1 ) {
                                check( boardVec, checkedVec, i - 1, j - 1, false );
                            }

                            if ( i >= 1 && j <= 6 ) {
                                check( boardVec, checkedVec, i - 1, j + 1, false );
                            }
                            break;
                        }

                        case 'n':
                        {
                            // Checking [ i - 1 ][ j - 2 ]
                            if ( i >= 1 && j >= 2 ) {
                                check( boardVec, checkedVec, i - 1, j - 2, true );
                            }

                            // Checking [ i - 2 ][ j - 1 ]
                            if ( i >= 2 && j >= 1 ) {
                                check( boardVec, checkedVec, i - 2, j - 1, true );
                            }

                            // Checking [ i - 2 ][ j + 1 ]
                            if ( i >= 2 && j <= 6 ) {
                                check( boardVec, checkedVec, i - 2, j + 1, true );
                            }

                            // Checking [ i - 1 ][ j + 2 ]
                            if ( i >= 1 && j <= 5 ) {
                                check( boardVec, checkedVec, i - 1, j + 2, true );
                            }

                            // Checking [ i + 1 ][ j + 2 ]
                            if ( i <= 6 && j <= 5 ) {
                                check( boardVec, checkedVec, i + 1, j + 2, true );
                            }

                            // Checking [ i + 2 ][ j + 1 ]
                            if ( i <= 5 && j <= 6 ) {
                                check( boardVec, checkedVec, i + 2, j + 1, true );
                            }

                            // Checking [ i + 2 ][ j - 1 ]
                            if ( i <= 5 && j >= 1 ) {
                                check( boardVec, checkedVec, i + 2, j - 1, true );
                            }

                            // Checking [ i + 1 ][ j - 2 ]
                            if ( i <= 6 && j >= 2 ) {
                                check( boardVec, checkedVec, i + 1, j - 2, true );
                            }

                            break;
                        }

                        case 'N':
                        {
                            // Checking [ i - 1 ][ j - 2 ]
                            if ( i >= 1 && j >= 2 ) {
                                check( boardVec, checkedVec, i - 1, j - 2, false );
                            }

                            // Checking [ i - 2 ][ j - 1 ]
                            if ( i >= 2 && j >= 1 ) {
                                check( boardVec, checkedVec, i - 2, j - 1, false );
                            }

                            // Checking [ i - 2 ][ j + 1 ]
                            if ( i >= 2 && j <= 6 ) {
                                check( boardVec, checkedVec, i - 2, j + 1, false );
                            }

                            // Checking [ i - 1 ][ j + 2 ]
                            if ( i >= 1 && j <= 5 ) {
                                check( boardVec, checkedVec, i - 1, j + 2, false );
                            }

                            // Checking [ i + 1 ][ j + 2 ]
                            if ( i <= 6 && j <= 5 ) {
                                check( boardVec, checkedVec, i + 1, j + 2, false );
                            }

                            // Checking [ i + 2 ][ j + 1 ]
                            if ( i <= 5 && j <= 6 ) {
                                check( boardVec, checkedVec, i + 2, j + 1, false );
                            }

                            // Checking [ i + 2 ][ j - 1 ]
                            if ( i <= 5 && j >= 1 ) {
                                check( boardVec, checkedVec, i + 2, j - 1, false );
                            }

                            // Checking [ i + 1 ][ j - 2 ]
                            if ( i <= 6 && j >= 2 ) {
                                check( boardVec, checkedVec, i + 1, j - 2, false );
                            }

                            break;
                        }

                        case 'b':
                        {
                            // Check all left-top
                            for ( int k = i - 1, l = j - 1; k >= 0 && l >= 0; --k, --l ) {
                                if ( ! check( boardVec, checkedVec, k, l, true ) ) {
                                    break;
                                }
                            }

                            // Check all right-top
                            for ( int k = i - 1, l = j + 1; k >= 0 && l <= 7; --k, ++l ) {
                                if ( ! check( boardVec, checkedVec, k, l, true ) ) {
                                    break;
                                }
                            }

                            // Check all left-bottom
                            for ( int k = i + 1, l = j - 1; k <= 7 && l >= 0; ++k, --l ) {
                                if ( ! check( boardVec, checkedVec, k, l, true ) ) {
                                    break;
                                }
                            }

                            // Check all right-bottom
                            for ( int k = i + 1, l = j + 1; k <= 7 && l <= 7; ++k, ++l ) {
                                if ( ! check( boardVec, checkedVec, k, l, true ) ) {
                                    break;
                                }
                            }

                            break;
                        }

                        case 'B':
                        {
                            // Check all left-top
                            for ( int k = i - 1, l = j - 1; k >= 0 && l >= 0; --k, --l ) {
                                if ( ! check( boardVec, checkedVec, k, l, false ) ) {
                                    break;
                                }
                            }

                            // Check all right-top
                            for ( int k = i - 1, l = j + 1; k >= 0 && l <= 7; --k, ++l ) {
                                if ( ! check( boardVec, checkedVec, k, l, false ) ) {
                                    break;
                                }
                            }

                            // Check all left-bottom
                            for ( int k = i + 1, l = j - 1; k <= 7 && l >= 0; ++k, --l ) {
                                if ( ! check( boardVec, checkedVec, k, l, false ) ) {
                                    break;
                                }
                            }

                            // Check all right-bottom
                            for ( int k = i + 1, l = j + 1; k <= 7 && l <= 7; ++k, ++l ) {
                                if ( ! check( boardVec, checkedVec, k, l, false ) ) {
                                    break;
                                }
                            }

                            break;
                        }

                        case 'r':
                        {
                            // Check all columns to the right
                            for ( int k = j + 1; k <= 7; k++ ) {
                                if ( ! check( boardVec, checkedVec, i, k, true ) ) {
                                    break;
                                }
                            }

                            // Check all columns to the left
                            for ( int k = j - 1; k >= 0; k-- ) {
                                if ( ! check( boardVec, checkedVec, i, k, true ) ) {
                                    break;
                                }
                            }

                            // Check all rows to the bottom
                            for ( int k = i + 1; k <= 7; k++ ) {
                                if ( ! check( boardVec, checkedVec, k, j, true ) ) {
                                    break;
                                }
                            }

                            // Check all rows to the top
                            for ( int k = i - 1; k >= 0; k-- ) {
                                if ( ! check( boardVec, checkedVec, k, j, true ) ) {
                                    break;
                                }
                            }

                            break;
                        }

                        case 'R':
                        {
                            // Check all columns to the right
                            for ( int k = j + 1; k <= 7; k++ ) {
                                if ( ! check( boardVec, checkedVec, i, k, false ) ) {
                                    break;
                                }
                            }

                            // Check all columns to the left
                            for ( int k = j - 1; k >= 0; k-- ) {
                                if ( ! check( boardVec, checkedVec, i, k, false ) ) {
                                    break;
                                }
                            }

                            // Check all rows to the bottom
                            for ( int k = i + 1; k <= 7; k++ ) {
                                if ( ! check( boardVec, checkedVec, k, j, false ) ) {
                                    break;
                                }
                            }

                            // Check all rows to the top
                            for ( int k = i - 1; k >= 0; k-- ) {
                                if ( ! check( boardVec, checkedVec, k, j, false ) ) {
                                    break;
                                }
                            }

                            break;
                        }

                        case 'q':
                        {
                            // Check all columns to the right
                            for ( int k = j + 1; k <= 7; k++ ) {
                                if ( ! check( boardVec, checkedVec, i, k, true ) ) {
                                    break;
                                }
                            }

                            // Check all columns to the left
                            for ( int k = j - 1; k >= 0; k-- ) {
                                if ( ! check( boardVec, checkedVec, i, k, true ) ) {
                                    break;
                                }
                            }

                            // Check all rows to the bottom
                            for ( int k = i + 1; k <= 7; k++ ) {
                                if ( ! check( boardVec, checkedVec, k, j, true ) ) {
                                    break;
                                }
                            }

                            // Check all rows to the top
                            for ( int k = i - 1; k >= 0; k-- ) {
                                if ( ! check( boardVec, checkedVec, k, j, true ) ) {
                                    break;
                                }
                            }
                            
                            // Check all left-top
                            for ( int k = i - 1, l = j - 1; k >= 0 && l >= 0; --k, --l ) {
                                if ( ! check( boardVec, checkedVec, k, l, true ) ) {
                                    break;
                                }
                            }

                            // Check all right-top
                            for ( int k = i - 1, l = j + 1; k >= 0 && l <= 7; --k, ++l ) {
                                if ( ! check( boardVec, checkedVec, k, l, true ) ) {
                                    break;
                                }
                            }

                            // Check all left-bottom
                            for ( int k = i + 1, l = j - 1; k <= 7 && l >= 0; ++k, --l ) {
                                if ( ! check( boardVec, checkedVec, k, l, true ) ) {
                                    break;
                                }
                            }

                            // Check all right-bottom
                            for ( int k = i + 1, l = j + 1; k <= 7 && l <= 7; ++k, ++l ) {
                                if ( ! check( boardVec, checkedVec, k, l, true ) ) {
                                    break;
                                }
                            }
                            
                            break;
                        }

                        case 'Q':
                        {
                            // Check all columns to the right
                            for ( int k = j + 1; k <= 7; k++ ) {
                                if ( ! check( boardVec, checkedVec, i, k, false ) ) {
                                    break;
                                }
                            }

                            // Check all columns to the left
                            for ( int k = j - 1; k >= 0; k-- ) {
                                if ( ! check( boardVec, checkedVec, i, k, false ) ) {
                                    break;
                                }
                            }

                            // Check all rows to the bottom
                            for ( int k = i + 1; k <= 7; k++ ) {
                                if ( ! check( boardVec, checkedVec, k, j, false ) ) {
                                    break;
                                }
                            }

                            // Check all rows to the top
                            for ( int k = i - 1; k >= 0; k-- ) {
                                if ( ! check( boardVec, checkedVec, k, j, false ) ) {
                                    break;
                                }
                            }
                            
                            // Check all left-top
                            for ( int k = i - 1, l = j - 1; k >= 0 && l >= 0; --k, --l ) {
                                if ( ! check( boardVec, checkedVec, k, l, false ) ) {
                                    break;
                                }
                            }

                            // Check all right-top
                            for ( int k = i - 1, l = j + 1; k >= 0 && l <= 7; --k, ++l ) {
                                if ( ! check( boardVec, checkedVec, k, l, false ) ) {
                                    break;
                                }
                            }

                            // Check all left-bottom
                            for ( int k = i + 1, l = j - 1; k <= 7 && l >= 0; ++k, --l ) {
                                if ( ! check( boardVec, checkedVec, k, l, false ) ) {
                                    break;
                                }
                            }

                            // Check all right-bottom
                            for ( int k = i + 1, l = j + 1; k <= 7 && l <= 7; ++k, ++l ) {
                                if ( ! check( boardVec, checkedVec, k, l, false ) ) {
                                    break;
                                }
                            }

                            break;
                        }

                        case 'k':
                        {
                            // Check 3 x spots in top row
                            if ( i > 0 ) {
                                check( boardVec, checkedVec, i - 1, j, true );

                                if ( j > 0 ) {
                                    check( boardVec, checkedVec, i - 1, j - 1, true );
                                }

                                if ( j < 7 ) {
                                    check( boardVec, checkedVec, i - 1, j + 1, true );
                                }
                            }

                            // Check 1 x spot on the left
                            if ( j > 0 ) {
                                check( boardVec, checkedVec, i, j - 1, true );
                            }

                            // Cheek 1 x spot on the right
                            if ( j < 7 ) {
                                check( boardVec, checkedVec, i, j + 1, true );
                            }

                            // Check 3 x spots in bottom row
                            if ( i < 7 ) {
                                check( boardVec, checkedVec, i + 1, j, true );

                                if ( j > 0 ) {
                                    check( boardVec, checkedVec, i + 1, j - 1, true );
                                }

                                if ( j < 7 ) {
                                    check( boardVec, checkedVec, i + 1, j + 1, true );
                                }
                            }

                            break;
                        }

                        case 'K':
                        {
                            // Check 3 x spots in top row
                            if ( i > 0 ) {
                                check( boardVec, checkedVec, i - 1, j, false );

                                if ( j > 0 ) {
                                    check( boardVec, checkedVec, i - 1, j - 1, false );
                                }

                                if ( j < 7 ) {
                                    check( boardVec, checkedVec, i - 1, j + 1, false );
                                }
                            }

                            // Check 1 x spot on the left
                            if ( j > 0 ) {
                                check( boardVec, checkedVec, i, j - 1, false );
                            }

                            // Cheek 1 x spot on the right
                            if ( j < 7 ) {
                                check( boardVec, checkedVec, i, j + 1, false );
                            }

                            // Check 3 x spots in bottom row
                            if ( i < 7 ) {
                                check( boardVec, checkedVec, i + 1, j, false );

                                if ( j > 0 ) {
                                    check( boardVec, checkedVec, i + 1, j - 1, false );
                                }

                                if ( j < 7 ) {
                                    check( boardVec, checkedVec, i + 1, j + 1, false );
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

            cout << "Game #" << gameCount + 1 << ": ";
            if ( checkedVec[ kRow ][ kCol ] == 'C' || checkedVec[ kRow ][ kCol ] == '.' )  {
                cout << "black king is in check." << endl;
            } else if ( checkedVec[ KRow ][ KCol ] == 'c' || checkedVec[ KRow ][ KCol ] == '.' ) {
                cout << "white king is in check." << endl;
            } else {
                cout << "no king is in check." << endl;
            }

            ++gameCount;
        }

        ++row;
    }

    return 0;
}
