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

    string expressionStr = "";
    int expressionCount = 0;

    while ( cin >> expressionStr ) {
        //
        // Whenever we hit an operator, we have to evaluate the expression
        //
        // We will have the following data structures:
        // - deque< string > operandsDeque
        //
        // - deque< string > storageDeque
        //
        // - deque< string > outputDeque
        //   - This contains our output. When outputting, what we do is we keep
        //   pop_front() and cout. With each "ST" instruction, we ++curStorageIndex.
        //   With each non-"ST" instruction that contains $, we --curStorageIndex.
        //
        // - We loop through expressionStr
        //   - If we hit an alphabet char, we push_back() it to operandsDeque.
        //   - If we hit a non-alphabet char:
        //     - If the prevChar is an alphabet one, we evaluate the current
        //     expression and push_back() the output onto the outputDeque.
        //       If the prevPrevChar is also an alphabet one, we push_back() 
        //    storage sign "$" onto the operandsDeque. If prevPrevChar is NOT
        //    an alphabet one, we don't push back.
        //       We also push_back() the storage sign "$" onto the operandsDeque.
        //
        //     - If the prevChar is a non-alphabet one, we keep stacking up
        //     evaluation of the expression as follow ( we have 2 cases ):
        //       - Case 1: The top-level register in operandsDeque
        //       ( operandsDeque.back() ) is storage sign "$":
        //         - Here we just outputDeque.push_back( "A $" )
        //
        //       - Case 2: The top-level register in operandsDeque
        //       ( operandsDeque.back() ) is a normal alphabet register:
        //         - Here we do outputQueue.push_front( "ST $" ),
        //         then outputDeque.push_front( "L " + topReg ),
        //         then outputDeque.push_back( "A $" )
        //
        // - At the end if operandsDeque has any element left, we just
        // outputDeque.push_front( operandsDeque.pop_back() );
        //
        // Final step is to loop through outputDeque and print the statements.
        // We have curStorageIndex = 0 initially and:
        // - With each ST statement, we ++curStorageIndex
        // - With each other statement, we --curStorageIndex if
        // curStorageIndex > 0
        //

        deque< string > operandsDeque;
        deque< string > outputDeque;
        for ( int i = 0; i < expressionStr.size(); i++ ) {
            if ( isalpha( expressionStr[ i ] ) ) {
                string operandStr( 1, expressionStr[ i ] );
                operandsDeque.push_back( operandStr );
            } else {
                switch ( expressionStr[ i ] ) {
                    case '+':
                    {
                        string topReg = "";
                        string secondTopReg = "";

                        if ( isalpha( expressionStr[ i - 1 ] ) ) {
                            topReg = operandsDeque.back();
                            operandsDeque.pop_back();

                            if ( ! operandsDeque.empty() ) {
                                secondTopReg = operandsDeque.back();
                                operandsDeque.pop_back();
                            }

                            bool isInitiallyEmpty = outputDeque.empty();

                            if ( ! isInitiallyEmpty && ! secondTopReg.empty() ) {
                                outputDeque.push_back( "ST $" );
                            }

                            if ( ! secondTopReg.empty() ) {
                                outputDeque.push_back( "L " + secondTopReg );
                            }
                            outputDeque.push_back( "A " + topReg );
                            
                            if ( ! isInitiallyEmpty ) {
                                // We should be considerate when pushing this in
                                // Perhap only push in when the i + 2 char of expressionStr
                                // is alpha
                                if ( i + 2 < expressionStr.size() && isalpha( expressionStr[ i + 2 ] ) ) {
                                    operandsDeque.push_back( "$" );
                                } else if ( i + 2 >= expressionStr.size() ) {
                                    operandsDeque.push_back( "$" );
                                } else {
                                    operandsDeque.push_back( "" );
                                }
                            }
                        } else {
                            //     - If the prevChar is a non-alphabet one, we keep stacking up
                            //     evaluation of the expression as follow ( we have 2 cases ):
                            //       - Case 1: The top-level register in operandsDeque
                            //       ( operandsDeque.back() ) is storage sign "$":
                            //         - Here we just outputDeque.push_back( "A $" )
                            //
                            //       - Case 2: The top-level register in operandsDeque
                            //       ( operandsDeque.back() ) is a normal alphabet register:
                            //         - Here we do outputDeque.push_front( "ST $" ),
                            //         then outputDeque.push_front( "L " + topReg ),
                            //         then outputDeque.push_back( "A $" )
                            topReg = operandsDeque.back();
                            operandsDeque.pop_back();
                            if ( topReg[ 0 ] == '$' ) {
                                outputDeque.push_back( "A $" );
                            } else {
                                if ( ! topReg.empty() ) {
                                    outputDeque.push_front( "ST $" );
                                    outputDeque.push_front( "L " + topReg );
                                }
                                outputDeque.push_back( "A $" );
                            }
                        }

                        break;
                    }
                    
                    case '*':
                    {
                        string topReg = "";
                        string secondTopReg = "";

                        if ( isalpha( expressionStr[ i - 1 ] ) ) {
                            topReg = operandsDeque.back();
                            operandsDeque.pop_back();
                            
                            if ( ! operandsDeque.empty() ) {
                                secondTopReg = operandsDeque.back();
                                operandsDeque.pop_back();
                            }

                            bool isInitiallyEmpty = outputDeque.empty();

                            if ( ! isInitiallyEmpty && ! secondTopReg.empty() ) {
                                outputDeque.push_back( "ST $" );
                            }

                            if ( ! secondTopReg.empty() ) {
                                outputDeque.push_back( "L " + secondTopReg );
                            }
                            outputDeque.push_back( "M " + topReg );

                            if ( ! isInitiallyEmpty ) {
                                // We should be considerate when pushing this in
                                // Perhap only push in when the i + 2 char of expressionStr
                                // is alpha
                                if ( i + 2 < expressionStr.size() && isalpha( expressionStr[ i + 2 ] ) ) {
                                    operandsDeque.push_back( "$" );
                                } else if ( i + 2 >= expressionStr.size() ) {
                                    operandsDeque.push_back( "$" );
                                } else {
                                    operandsDeque.push_back( "" );
                                }
                            }
                        } else {
                            //     - If the prevChar is a non-alphabet one, we keep stacking up
                            //     evaluation of the expression as follow ( we have 2 cases ):
                            //       - Case 1: The top-level register in operandsDeque
                            //       ( operandsDeque.back() ) is storage sign "$":
                            //         - Here we just outputDeque.push_back( "M $" )
                            //
                            //       - Case 2: The top-level register in operandsDeque
                            //       ( operandsDeque.back() ) is a normal alphabet register:
                            //         - Here we do outputDeque.push_front( "ST $" ),
                            //         then outputDeque.push_front( "L " + topReg ),
                            //         then outputDeque.push_back( "M $" )
                            topReg = operandsDeque.back();
                            operandsDeque.pop_back();
                            if ( topReg[ 0 ] == '$' ) {
                                outputDeque.push_back( "M $" );
                            } else {
                                if ( ! topReg.empty() ) {
                                    outputDeque.push_front( "ST $" );
                                    outputDeque.push_front( "L " + topReg );
                                }
                                outputDeque.push_back( "M $" );
                            }
                        }

                        break;
                    }
                    
                    case '-':
                    {
                        // Here we can use either negate or subtract
                        // - Subtract when prevChar is an alphabet one
                        // - Negate when prevChar is non-alphabet one
                        string topReg = "";
                        string secondTopReg = "";

                        if ( isalpha( expressionStr[ i - 1 ] ) ) {
                            topReg = operandsDeque.back();
                            operandsDeque.pop_back();
                            
                            if ( ! operandsDeque.empty() ) {
                                secondTopReg = operandsDeque.back();
                                operandsDeque.pop_back();
                            }

                            bool isInitiallyEmpty = outputDeque.empty();

                            if ( ! isInitiallyEmpty && ! secondTopReg.empty() ) {
                                outputDeque.push_back( "ST $" );
                            }

                            if ( ! secondTopReg.empty() ) {
                                outputDeque.push_back( "L " + secondTopReg );
                            }
                            outputDeque.push_back( "S " + topReg );

                            if ( ! isInitiallyEmpty ) {
                                // We should be considerate when pushing this in
                                // Perhap only push in when the i + 2 char of expressionStr
                                // is alpha
                                if ( i + 2 < expressionStr.size() && isalpha( expressionStr[ i + 2 ] ) ) {
                                    operandsDeque.push_back( "$" );
                                } else if ( i + 2 >= expressionStr.size() ) {
                                    operandsDeque.push_back( "$" );
                                } else {
                                    operandsDeque.push_back( "" );
                                }
                            }
                        } else {
                            //     - If the prevChar is a non-alphabet one, we keep stacking up
                            //     evaluation of the expression as follow ( we have 2 cases ):
                            //       - Case 1: The top-level register in operandsDeque
                            //       ( operandsDeque.back() ) is storage sign "$":
                            //         - Here we just outputDeque.push_back( "A $" )
                            //
                            //       - Case 2: The top-level register in operandsDeque
                            //       ( operandsDeque.back() ) is a normal alphabet register:
                            //         - Here we do outputDeque.push_front( "ST $" ),
                            //         then outputDeque.push_front( "L " + topReg ),
                            //         then outputDeque.push_back( "A $" )
                            topReg = operandsDeque.back();
                            operandsDeque.pop_back();
                            if ( topReg[ 0 ] == '$' ) {
                                outputDeque.push_back( "N" );
                                outputDeque.push_back( "A $" );
                            } else {
                                if ( ! topReg.empty() ) {
                                    outputDeque.push_front( "ST $" );
                                    outputDeque.push_front( "L " + topReg );
                                }
                                outputDeque.push_back( "N" );
                                outputDeque.push_back( "A $" );
                            }
                        }

                        break;
                    }

                    case '/':
                    {
                        string topReg = "";
                        string secondTopReg = "";

                        if ( isalpha( expressionStr[ i - 1 ] ) ) {
                            topReg = operandsDeque.back();
                            operandsDeque.pop_back();
                            
                            if ( ! operandsDeque.empty() ) {
                                secondTopReg = operandsDeque.back();
                                operandsDeque.pop_back();
                            }

                            bool isInitiallyEmpty = outputDeque.empty();
                            if ( ! isInitiallyEmpty && ! secondTopReg.empty() ) {
                                outputDeque.push_back( "ST $" );
                            }

                            if ( ! secondTopReg.empty() ) {
                                outputDeque.push_back( "L " + secondTopReg );
                            }
                            outputDeque.push_back( "D " + topReg );

                            if ( ! isInitiallyEmpty ) {
                                // We should be considerate when pushing this in
                                // Perhap only push in when the i + 2 char of expressionStr
                                // is alpha
                                if ( i + 2 < expressionStr.size() && isalpha( expressionStr[ i + 2 ] ) ) {
                                    operandsDeque.push_back( "$" );
                                } else if ( i + 2 >= expressionStr.size() ) {
                                    operandsDeque.push_back( "$" );
                                } else {
                                    operandsDeque.push_back( "" );
                                }
                            }
                        } else {
                            //     - If the prevChar is a non-alphabet one, we keep stacking up
                            //     evaluation of the expression as follow ( we have 2 cases ):
                            //       - Case 1: The top-level register in operandsDeque
                            //       ( operandsDeque.back() ) is storage sign "$":
                            //         - Here we just outputDeque.push_back( "M $" )
                            //
                            //       - Case 2: The top-level register in operandsDeque
                            //       ( operandsDeque.back() ) is a normal alphabet register:
                            //         - Here we do outputDeque.push_front( "ST $" ),
                            //         then outputDeque.push_front( "L " + topReg ),
                            //         then outputDeque.push_back( "M $" )
                            topReg = operandsDeque.back();
                            operandsDeque.pop_back();
                            if ( topReg[ 0 ] == '$' ) {
                                outputDeque.push_back( "ST $" );
                                outputDeque.push_back( "L $" );
                                outputDeque.push_back( "D $" );
                            } else {
                                if ( ! topReg.empty() ) {
                                    outputDeque.push_front( "ST $" );
                                    outputDeque.push_front( "L " + topReg );
                                }
                                outputDeque.push_back( "ST $" );
                                outputDeque.push_back( "L $" );
                                outputDeque.push_back( "D $" );
                            }
                        }

                        break;
                    }
                
                    case '@':
                    {
                        // This is a single-register operation
                        // We check prevChar to see if it's alphabet'
                        //
                        // If prevChar is an alphabet, we just output N
                        //
                        string topReg = "";

                        if ( isalpha( expressionStr[ i - 1 ] ) ) {
                            topReg = operandsDeque.back();
                            operandsDeque.pop_back();

                            bool isInitiallyEmpty = outputDeque.empty();

                            if ( ! isInitiallyEmpty ) {
                                outputDeque.push_back( "ST $" );
                            }

                            outputDeque.push_back( "L " + topReg );
                            outputDeque.push_back( "N" );

                            if ( ! isInitiallyEmpty ) {
                                // We should be considerate when pushing this in
                                // Perhap only push in when the i + 2 char of expressionStr
                                // is alpha
                                if ( i + 2 < expressionStr.size() && isalpha( expressionStr[ i + 2 ] ) ) {
                                    operandsDeque.push_back( "$" );
                                } else if ( i + 2 >= expressionStr.size() ) {
                                    operandsDeque.push_back( "$" );
                                } else {
                                    operandsDeque.push_back( "" );
                                }
                            }
                        } else {
                            //     - If the prevChar is a non-alphabet one, we keep stacking up
                            //     evaluation of the expression as follow ( we have 2 cases ):
                            //       - Case 1: The top-level register in operandsDeque
                            //       ( operandsDeque.back() ) is storage sign "$":
                            //         - Here we just outputDeque.push_back( "A $" )
                            //
                            //       - Case 2: The top-level register in operandsDeque
                            //       ( operandsDeque.back() ) is a normal alphabet register:
                            //         - Here we do outputDeque.push_front( "ST $" ),
                            //         then outputDeque.push_front( "L " + topReg ),
                            //         then outputDeque.push_back( "A $" )
                            outputDeque.push_back( "N" );
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

        // - At the end if operandsDeque has any element left, we just
        // outputDeque.push_front( operandsDeque.pop_back() );
        //
        // Final step is to loop through outputDeque and print the statements.
        // We have curStorageIndex = 0 initially and:
        // - With each ST statement, we ++curStorageIndex
        // - With each other statement, we --curStorageIndex if
        // curStorageIndex > 0
        //
        while ( ! operandsDeque.empty() ) {
            if ( ! operandsDeque.back().empty() && operandsDeque.back() != "$" ) {
                outputDeque.push_front( "L " + operandsDeque.back() );
            }
            operandsDeque.pop_back();
        }

        if ( expressionCount > 0 ) {
            cout << endl;
        }

        int curStorageIndex = -1;
        int minStorageIndex = 0;
        for ( int i = 0; i < outputDeque.size(); i++ ) {
            cout << outputDeque[ i ];
            if ( outputDeque[ i ].back() == '$' ) {
                if ( outputDeque[ i ].substr( 0, outputDeque[ i ].size() - 2 ) == "ST" ) {
                    if ( curStorageIndex < 9 ) {
                        cout << ++curStorageIndex;
                    } else {
                        cout << curStorageIndex;
                    }
                } else {
                    if ( i < outputDeque.size() - 1
                            && outputDeque[ i ].substr( 0, outputDeque[ i ].size() - 2 ) == "L"
                            && outputDeque[ i + 1 ].substr( 0, outputDeque[ i + 1 ].size() - 2 ) == "D" ) {
                        if ( curStorageIndex > 0 ) {
                            cout << --curStorageIndex;
                        } else {
                            cout << curStorageIndex;
                        }
                        if ( curStorageIndex < 9 ) {
                            outputDeque[ i + 1 ] += to_string( curStorageIndex + 1 );
                        } else {
                            outputDeque[ i + 1 ] += "0";
                        }
                        if ( curStorageIndex > 0 ) {
                            --curStorageIndex;
                        }

                    } else {
                        cout << curStorageIndex;
                        if ( curStorageIndex > 0 ) {
                            --curStorageIndex;
                        }
                    }
                }
            }
            cout << endl;
        }
        ++expressionCount;
    }

    return 0;
}
