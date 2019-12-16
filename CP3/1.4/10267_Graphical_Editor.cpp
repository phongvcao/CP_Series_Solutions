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

    string line = "";
    vector< vector< char > > tableVec;
    while ( getline( cin, line ) ) {
        if ( line[ 0 ] == 'X' ) break;

        stringstream ss( line );

        char cmd = '\0';
        ss >> cmd;

        switch ( cmd ) {
            case 'I':
            {
                // Create a new table M X N
                int rowCount = 0;
                int colCount = 0;
                ss >> colCount >> rowCount;
                tableVec.clear();
                tableVec.resize( rowCount, vector< char >( colCount, 'O' ) );
                break;
            }

            case 'C':
            {
                // Clear the table
                for ( int i = 0; i < tableVec.size(); i++ ) {
                    for ( int j = 0; j < tableVec[ i ].size(); j++ ) {
                        tableVec[ i ][ j ] = 'O';
                    }
                }
                break;
            }

            case 'L':
            {
                // Color pixel with coordinate row, col
                int row = 0;
                int col = 0;
                char color = 'O';
                ss >> col >> row >> color;
                --row;
                --col;
                if ( row >= 0 && row <= tableVec.size() - 1
                        && col >= 0 && col <= tableVec[ row ].size() - 1 ) {
                    tableVec[ row ][ col ] = color;
                }
                break;
            }

            case 'V':
            {
                // Draw vertical segment
                int col = 0;
                int fromRow = 0;
                int toRow = 0;
                char color = 'O';
                ss >> col >> fromRow >> toRow >> color;
                --col;
                --fromRow;
                --toRow;
                if ( fromRow >= 0 && fromRow <= tableVec.size() - 1
                        && toRow >= 0 && toRow <= tableVec.size() - 1
                        && col >= 0 && col <= tableVec[ fromRow ].size() - 1 ) {
                    for ( int i = min( fromRow, toRow ); i <= max( fromRow, toRow ); i++ ) {
                        tableVec[ i ][ col ] = color;
                    }
                }
                break;
            }

            case 'H':
            {
                // Draw horizontal segment
                int fromCol = 0;
                int toCol = 0;
                int row = 0;
                char color = 'O';
                ss >> fromCol >> toCol >> row >> color;
                --fromCol;
                --toCol;
                --row;
                if ( row >= 0 && row <= tableVec.size() - 1
                        && fromCol >= 0 && fromCol <= tableVec[ row ].size() - 1
                        && toCol >= 0 && toCol <= tableVec[ row ].size() - 1 ) {
                    for ( int i = min( fromCol, toCol ); i <= max( fromCol, toCol ); i++ ) {
                        tableVec[ row ][ i ] = color;
                    }
                }
                break;
            }

            case 'K':
            {
                // Draw filled rectangle
                int fromRow = 0;
                int fromCol = 0;
                int toRow = 0;
                int toCol = 0;
                char color = 'O';
                ss >> fromCol >> fromRow >> toCol >> toRow >> color;
                --fromRow;
                --fromCol;
                --toRow;
                --toCol;
                if ( fromRow >= 0 && fromRow <= tableVec.size() - 1
                        && fromCol >= 0 && fromCol <= tableVec[ fromRow ].size() - 1
                        && toRow >= 0 && toRow <= tableVec.size() - 1
                        && toCol >= 0 && toCol <= tableVec[ toRow ].size() - 1 ) {
                    for ( int i = min( fromRow, toRow ); i <= max( fromRow, toRow ); i++ ) {
                        for ( int j = min( fromCol, toCol ); j <= max( fromCol, toCol ); j++ ) {
                            tableVec[ i ][ j ] = color;
                        }
                    }
                }
                break;
            }

            case 'F':
            {
                //
                // Fill the region
                // We will have a queue of pair< int, int > which stores the 
                // adjacent pixels with same colors as the current pixel.
                //
                // First we push the current pixel into this queue< pair< int, int > >,
                // and as we pop each pair< int, int > out of the queue, we check
                // its adjacent pixels to see if they have same color as it is and 
                // push those with same colors on the queue< pair< int, int > >
                //
                // As with the pixel ( pair< int, int > ) that was popped out, we 
                // color it to the new color. We keep looping like this until
                // queue< pair< int, int > > is empty.
                //
                int row = 0;
                int col = 0;
                char color = 'O';
                ss >> col >> row >> color;
                --row;
                --col;

                if ( row >= 0 && row <= tableVec.size() - 1
                        && col >= 0 && col <= tableVec[ row ].size() - 1 ) {
                    vector< vector< bool > > tableMarkedVec( tableVec.size(), vector< bool >( tableVec[ row ].size(), false ) );
                    queue< pair< int, int > > pixelsQueue;
                    char oldColor = tableVec[ row ][ col ];
                    pixelsQueue.push( make_pair( row, col ) );

                    while ( ! pixelsQueue.empty() ) {
                        pair< int, int > pixelPair = pixelsQueue.front();
                        pixelsQueue.pop();

                        if ( tableVec[ pixelPair.first ][ pixelPair.second ] == oldColor
                                && ! tableMarkedVec[ pixelPair.first ][ pixelPair.second ] ) {
                            tableVec[ pixelPair.first ][ pixelPair.second ] = color;
                            tableMarkedVec[ pixelPair.first ][ pixelPair.second ] = true;

                            if ( pixelPair.first > 0
                                    && tableVec[ pixelPair.first - 1 ][ pixelPair.second ] == oldColor ) {
                                pixelsQueue.push( make_pair( pixelPair.first - 1, pixelPair.second ) );
                            }

                            if ( pixelPair.first < tableVec.size() - 1
                                    && tableVec[ pixelPair.first + 1 ][ pixelPair.second ] == oldColor ) {
                                pixelsQueue.push( make_pair( pixelPair.first + 1, pixelPair.second ) );
                            }

                            if ( pixelPair.second > 0
                                    && tableVec[ pixelPair.first ][ pixelPair.second - 1 ] == oldColor ) {
                                pixelsQueue.push( make_pair( pixelPair.first, pixelPair.second - 1 ) );
                            }

                            if ( pixelPair.second < tableVec[ row ].size() - 1
                                    && tableVec[ pixelPair.first ][ pixelPair.second + 1 ] == oldColor ) {
                                pixelsQueue.push( make_pair( pixelPair.first, pixelPair.second + 1 ) );
                            }

                        }
                    }
                }
                break;
            }

            case 'S':
            {
                // Output the picture
                string name = "";
                ss >> name;
                cout << name << endl;
                for ( int i = 0; i < tableVec.size(); i++ ) {
                    for ( int j = 0; j < tableVec[ i ].size(); j++ ) {
                        cout << tableVec[ i ][ j ];
                    }
                    cout << endl;
                }
                break;
            }

            default:
            {
                break;
            }
        }
    }

    return 0;
}
