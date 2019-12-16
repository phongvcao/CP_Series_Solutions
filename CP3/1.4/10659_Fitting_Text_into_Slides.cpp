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

namespace Slide {

    // Return whether the text with this font size can fit slide with
    // height == height and width == width
    bool isFit( const vector< string >& txtVec, int fontSize, int height, int width ) {
        int curBottomMostSize = fontSize;
        int curRightMostSize = 0;

        for ( int i = 0; i < txtVec.size(); i++ ) {
            if ( txtVec[ i ].size() * fontSize <= width ) {
                curBottomMostSize += fontSize;
                curRightMostSize = 0;
                continue;
            }

            //
            // We look into each paragraph
            //
            // If we're at this step, it means the paragraph has width larger
            // than width. Thus, we need a while loop
            //
            // We see if the word at ( width - 1 ) / fontSize is a space
            // - If it is a space, then the next char must not be a space.
            //   Here we break line. We keep curParaRightMostIdx.

            int lastCharFitsWidthIdx = ( width - 1 ) / fontSize;
            string curParaStr = txtVec[ i ];

            while ( true ) {
                if ( curParaStr.size() * fontSize <= width ) {
                    curBottomMostSize += fontSize;
                    curRightMostSize = 0;
                    break;
                } else {

                    if ( isspace( curParaStr[ lastCharFitsWidthIdx ] ) ) {
                        // break line
                        curBottomMostSize += fontSize;
                        curRightMostSize = 0;
                        curParaStr = curParaStr.substr( lastCharFitsWidthIdx + 1 );
                    } else {
                        // here the char at width - 1 is not a space.
                        // which means if the char after it is a space, we can 
                        // break line.
                        if ( isspace( curParaStr[ lastCharFitsWidthIdx + 1 ] ) ) {
                            // break line
                            curBottomMostSize += fontSize;
                            curRightMostSize = 0;
                            curParaStr = curParaStr.substr( lastCharFitsWidthIdx + 2 );
                        } else {
                            // Now if both the char at width - 1 and the char after
                            // that char is not a space, then we're in the middle 
                            // of a word. We need to backtrack & look forward until
                            // finding the firstIdx and lastIdx of the word.
                            // With this info, we can decide whether to break line
                            // in this case
                            int wordBeginIdx = lastCharFitsWidthIdx;
                            int wordEndIdx = lastCharFitsWidthIdx;

                            while ( wordBeginIdx >= 0 && ! isspace( curParaStr[ wordBeginIdx ] ) ) {
                                --wordBeginIdx;
                            }
                            
                            while ( wordEndIdx < curParaStr.size() && ! isspace( curParaStr[ wordEndIdx ] ) ) {
                                ++wordEndIdx;
                            }

                            ++wordBeginIdx;
                            --wordEndIdx;

                            // curParaStr.substr( wordBeginIdx, wordEndIdx - wordBeginIdx + 1 ) should return
                            // the current word
                            if ( ( wordEndIdx - wordBeginIdx + 1 ) * fontSize > width ) {
                                return false;
                            } else if ( wordEndIdx - wordBeginIdx + 1 == curParaStr.size() ) {
                                // Here the condition satisfies - no need to break line
                                break;
                            } else {
                                // break line
                                curBottomMostSize += fontSize;
                                curRightMostSize = 0;
                                curParaStr = curParaStr.substr( wordBeginIdx );
                            }
                        }
                    }

                }

                if ( curBottomMostSize > height ) {
                    return false;
                }

            }
        }

        return true;
    }
}

int main( int argc, char ** argv ) {

    // We will read the text
    //
    // Then we will have a function bool isFit( const string& txt, int fontSize, int height, int width )
    // to check whether the text fits with heigt & width.
    //
    // We check the fit in function isFit() by having
    // ( curBottomMostIdx, curRightMostIdx ) which indicates the current
    // position of the lower-right corner of the text with the current font.
    // 
    // The stepping of ( curBottomMostIdx, curRightMostIdx ) will be P.
    //
    // If we're at a char and curRightMostIdx += P > width, we can backtrack to 
    // the beginning of the word and wrap the rest of the word
    // to the next line. Here we do
    // ( curBottomMostIdx += P, curRightMostIdx = P * chars since beginning of word )
    //
    // We will have to keep track of the previously nearest word boundary using
    // ( curWordBeginBottomMostIdx, curWordBeginRightMostIdx ).
    //

    string line = "";
    int N = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> N;
    }

    for ( int n = 0; n < N; n++ ) {
        int M = 0;
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> M;
        }

        vector< string > txtVec( M, "" );
        for ( int m = 0; m < M; m++ ) {
            getline( cin, txtVec[ m ] );
        }

        int width = 0;
        int height = 0;
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            ss >> width >> height;
        }

        bool foundFontSize = false;
        for ( int i = 28; i >= 8; i-- ) {
            if ( Slide::isFit( txtVec, i, height, width ) ) {
                cout << i << endl;
                foundFontSize = true;
                break;
            }
        }

        if ( ! foundFontSize ) {
            cout << "No solution" << endl;
        }
    }

    return 0;
}
