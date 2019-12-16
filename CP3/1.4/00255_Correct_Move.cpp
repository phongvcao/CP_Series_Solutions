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

    while ( getline( cin, line ) ) {
        stringstream ss( line );

        int kPos = 0;
        int qPos = 0;
        int qNewPos = 0;

        ss >> kPos >> qPos >> qNewPos;

        //
        // Illegal state : King same place as Queen
        //
        if ( kPos == qPos ) {
            cout << "Illegal state" << endl;

        } else {
            int qCurRow = qPos / 8;
            int qCurCol = qPos % 8;
            int kCurRow = kPos / 8;
            int kCurCol = kPos % 8;
            int qNewRow = qNewPos / 8;
            int qNewCol = qNewPos % 8;
                    
            if ( kPos == qNewPos || qPos == qNewPos ) {
                //
                // Illegal move : 
                // - Queen's new position is same as King's position
                //
                cout << "Illegal move" << endl;

            } else if ( qCurRow != qNewRow && qCurCol != qNewCol ) {
                //
                // Illegal move : 
                // - Queen doesn't move horizonally or vertically
                //
                cout << "Illegal move" << endl;

            } else if ( (
                        kCurRow == qCurRow
                        && qCurRow == qNewRow
                        && abs( qNewCol - kCurCol ) + abs( kCurCol - qCurCol ) == abs( qNewCol - qCurCol ) )
                     || (
                        kCurCol == qCurCol
                        && qCurCol == qNewCol
                        && abs( qNewRow - kCurRow ) + abs( kCurRow - qCurRow ) == abs( qNewRow - qCurRow ) ) ) {
                //
                // Illegal move :
                // - Queen moves over King's head
                //   - If queen and king are both on a straight line, either
                //   horizonally or vertically
                //   - AND the place queen is moving to is same on that line
                //   - AND all the places that have King in between queen current
                //   position and new position
                //
                cout << "Illegal move" << endl;

            } else if ( ( qNewRow == kCurRow - 1 && qNewCol == kCurCol )
                    || ( qNewRow == kCurRow + 1 && qNewCol == kCurCol )
                    || ( qNewCol == kCurCol - 1 && qNewRow == kCurRow )
                    || ( qNewCol == kCurCol + 1 && qNewRow == kCurRow ) ) {
                //
                // Move not allowed
                // - Queen moves to shared place between King and Queen
                // ( excluding the ones that are over King's head )
                //
                cout << "Move not allowed" << endl;

            } else {
                vector< int > kMoves;
                if ( kCurRow - 1 >= 0 ) {
                    kMoves.push_back( ( kCurRow - 1 ) * 8 + kCurCol );
                }

                if ( kCurRow + 1 <= 7 ) {
                    kMoves.push_back( ( kCurRow + 1 ) * 8 + kCurCol );
                }

                if ( kCurCol - 1 >= 0 ) {
                    kMoves.push_back( kCurRow * 8 + kCurCol - 1 );
                }

                if ( kCurCol + 1 <= 7 ) {
                    kMoves.push_back( kCurRow * 8 + kCurCol + 1 );
                }

                bool isStopped = true;
                for ( int i = 0; i < kMoves.size(); i++ ) {
                    if ( kMoves[ i ] / 8 != qNewRow && kMoves[ i ] % 8 != qNewCol ) {
                        isStopped = false;
                        break;
                    }
                }

                if ( isStopped ) {
                    //
                    // King is stopped
                    // - All of King's possible moves are either blocked by negatives
                    // OR are on same row or same column with Queen's possible moves 
                    // in the new position
                    //
                    cout << "Stop" << endl;
                } else {
                    //
                    // King is continue
                    // - All of King's possible moves are not blocked by negatives
                    // AND are not on same row or same column with Queen's possible moves 
                    // in the new position
                    //
                    cout << "Continue" << endl;
                }
            }
        }
    }

    return 0;
}
