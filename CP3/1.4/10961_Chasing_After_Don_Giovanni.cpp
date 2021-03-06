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
    int N = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> N;
    }

    for ( int n = 0; n < N; n++ ) {
        // Blank line
        vector< pair< int, int > > gioVec;

        if ( ! getline( cin, line ) ) {
            break;
        }

        if ( getline( cin, line ) ) {
            stringstream ss( line );
            gioVec.push_back( make_pair( -1, -1 ) );
            ss >> gioVec.back().first >> gioVec.back().second;
        }
        
        vector< pair< int, int > > lepoVec;
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            lepoVec.push_back( make_pair( -1, -1 ) );
            ss >> lepoVec.back().first >> lepoVec.back().second;
        }

        // Read Lepo's steps
        int lepoStepsCount = 0;
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> lepoStepsCount;
        }

        int lepoCurRow = lepoVec.back().first;
        int lepoCurCol = lepoVec.back().second;

        for ( int i = 0; i < lepoStepsCount; i++ ) {
            if ( getline( cin, line ) ) {
                stringstream ss( line );
                int lepoNextRow = -1;
                int lepoNextCol = -1;
                ss >> lepoNextRow >> lepoNextCol;

                if ( lepoCurRow == lepoNextRow ) {
                    int step = 1;
                    if ( lepoCurCol < lepoNextCol ) {
                        step = 1;
                    } else if ( lepoCurCol > lepoNextCol ) {
                        step = -1;
                    } else {
                        lepoVec.push_back( make_pair( lepoCurRow, lepoCurCol ) );
                        continue;
                    }
                    lepoVec.pop_back();

                    for ( int j = lepoCurCol; j != lepoNextCol; j += step ) {
                        lepoVec.push_back( make_pair( lepoCurRow, j ) );
                    }
                    lepoVec.push_back( make_pair( lepoNextRow, lepoNextCol ) );
                } else if ( lepoCurCol == lepoNextCol ) {
                    int step = 1;
                    if ( lepoCurRow < lepoNextRow ) {
                        step = 1;
                    } else if ( lepoCurRow > lepoNextRow ) {
                        step = -1;
                    } else {
                        lepoVec.push_back( make_pair( lepoCurRow, lepoCurCol ) );
                        continue;
                    }
                    lepoVec.pop_back();
                    for ( int j = lepoCurRow; j != lepoNextRow; j += step ) {
                        lepoVec.push_back( make_pair( j, lepoCurCol ) );
                    }
                    lepoVec.push_back( make_pair( lepoNextRow, lepoNextCol ) );
                }
                lepoCurRow = lepoNextRow;
                lepoCurCol = lepoNextCol;
            }
        }

        // Read Gio's steps
        int gioStepsCount = 0;
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> gioStepsCount;
        }

        int gioCurRow = gioVec.back().first;
        int gioCurCol = gioVec.back().second;

        for ( int i = 0; i < gioStepsCount; i++ ) {
            if ( getline( cin, line ) ) {
                stringstream ss( line );
                int gioNextRow = -1;
                int gioNextCol = -1;
                ss >> gioNextRow >> gioNextCol;
                
                if ( gioCurRow == gioNextRow ) {
                    int step = 1;
                    if ( gioCurCol < gioNextCol ) {
                        step = 1;
                    } else if ( gioCurCol > gioNextCol ) {
                        step = -1;
                    } else {
                        gioVec.push_back( make_pair( gioCurRow, gioCurCol ) );
                        continue;
                    }
                    gioVec.pop_back();
                    for ( int j = gioCurCol; j != gioNextCol; j += step ) {
                        gioVec.push_back( make_pair( gioCurRow, j ) );
                    }
                    gioVec.push_back( make_pair( gioNextRow, gioNextCol ) );
                } else if ( gioCurCol == gioNextCol ) {
                    int step = 1;
                    if ( gioCurRow < gioNextRow ) {
                        step = 1;
                    } else if ( gioCurRow > gioNextRow ) {
                        step = -1;
                    } else {
                        gioVec.push_back( make_pair( gioCurRow, gioCurCol ) );
                        continue;
                    }
                    gioVec.pop_back();
                    for ( int j = gioCurRow; j != gioNextRow; j += step ) {
                        gioVec.push_back( make_pair( j, gioCurCol ) );
                    }
                    gioVec.push_back( make_pair( gioNextRow, gioNextCol ) );
                }
                gioCurRow = gioNextRow;
                gioCurCol = gioNextCol;
            }
        }

        // Evaluate the case
        bool answerFound = false;
        int index = 0;
        while ( index < lepoVec.size() && index < gioVec.size() ) {
            if ( lepoVec[ index ].first == gioVec[ index ].first
                    && lepoVec[ index ].second == gioVec[ index ].second
                    && index < lepoVec.size() - 1 ) {
                cout << "No" << endl;
                answerFound = true;
                break;
            }
            ++index;
        }

        if ( ! answerFound ) {
            cout << "Yes" << endl;
        }

        if ( n < N - 1 ) {
            cout << endl;
        }
    }

    return 0;
}
