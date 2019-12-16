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

int getValueIndex( char c ) {
    switch ( c ) {
        case 'T':
        {
            return 8;
        }

        case 'J':
        {
            return 9;
        }

        case 'Q':
        {
            return 10;
        }

        case 'K':
        {
            return 11;
        }

        case 'A':
        {
            return 12;
        }

        default:
        {
            return c - '2';
        }
    }
}

char getValue( int index ) {
    switch ( index ) {
        case 8:
        {
            return 'T';
        }

        case 9:
        {
            return 'J';
        }

        case 10:
        {
            return 'Q';
        }

        case 11:
        {
            return 'K';
        }

        case 12:
        {
            return 'A';
        }

        default:
        {
            return ( char )( '2' + index );
        }
    }
}

char getSuit( int suitIndex ) {
    switch ( suitIndex ) {
        case 0:
        {
            return 'C';
        }

        case 1:
        {
            return 'D';
        }

        case 2:
        {
            return 'H';
        }

        case 3:
        {
            return 'S';
        }

        default:
        {
            return -1;
        }
    }
}

int getSuitIndex( char c ) {
    switch ( c ) {
        case 'C':
        {
            return 0;
        }

        case 'D':
        {
            return 1;
        }

        case 'H':
        {
            return 2;
        }

        case 'S':
        {
            return 3;
        }

        default:
        {
            return -1;
        }
    }
}

namespace Rank {
    enum RankType {
        UNKNOWN,
        HIGH_CARD,
        PAIR,
        TWO_PAIR,
        THREE_OF_A_KIND,
        STRAIGHT,
        FLUSH,
        FULL_HOUSE,
        FOUR_OF_A_KIND,
        STRAIGHT_FLUSH,
    };
}

template< typename Key >
class IndexMaxPQ {
private:

    vector< int > pq;
    vector< int > qp;
    // Key of vector is 
    vector< set< Key, greater< Key > > > keys;
    int N = 0;

    void exchange( int i, int j ) {
        int temp = pq[ i ];
        pq[ i ] = pq[ j ];
        pq[ j ] = temp;
        qp[ pq[ i ] ] = i;
        qp[ pq[ j ] ] = j;
    }

    bool isLess( int i, int j ) const {
        if ( keys[ pq[ i ] ].size() < keys[ pq[ j ] ].size() ) {
            return true;
        } else if ( keys[ pq[ i ] ].size() > keys[ pq[ j ] ].size() ) {
            return false;
        } else {
            if ( pq[ i ] < pq[ j ] ) {
                return true;
            } else if ( pq[ i ] > pq[ j ] ) {
                return false;
            } else {
                return false;
            }

            // if ( keys[ pq[ i ] ].size() != 0 ) {
            //     typename set< Key, greater< Key > >::iterator iIter = keys[ pq[ i ] ].begin();
            //     typename set< Key, greater< Key > >::iterator jIter = keys[ pq[ j ] ].begin();
            //     while ( iIter != keys[ pq[ i ] ].end() ) {
            //         if ( *iIter < *jIter ) {
            //             return true;
            //         } else if ( *iIter > *jIter ) {
            //             return false;
            //         } else {
            //
            //             return true;
            //         }
            //         ++iIter;
            //         ++jIter;
            //     }
            // }

        }
        return false;
    }

    void swim( int k ) {
        while ( k > 1 && isLess( k / 2, k ) ) {
            exchange( k / 2, k );
            k /= 2;
        }
    }

    void sink( int k ) {
        while ( 2 * k <= N ) {
            int j = 2 * k;
            if ( j < N && isLess( j, j + 1 ) ) ++j;
            if ( ! isLess( k, j ) ) break;
            exchange( k, j );
            k = j;
        }
    }

public:

    IndexMaxPQ( int maxN )
        : pq( maxN + 1 ),
          qp( maxN + 1, -1 ),
          keys( maxN + 1, set< Key, greater< Key > >() )
    {
        // not implemented
    }

    IndexMaxPQ( const IndexMaxPQ< Key >& other )
        : pq( other.pq ),
          qp( other.qp ),
          keys( other.keys ),
          N( other.N )
    {
        // not implemented
    }

    virtual ~IndexMaxPQ() {
        // not implemented
    }

    int size() const {
        return N;
    }

    bool empty() const {
        return size() == 0;
    }

    void insert( int k, Key key ) {
        ++N;
        pq[ N ] = k;
        qp[ k ] = N;
        keys[ k ].insert( key );
        swim( N );
    }

    bool contains( int k ) const {
        return qp[ k ] != -1;
    }

    void change( int k, Key key ) {
        if ( ! contains( k ) ) throw runtime_error( "Invalid index of the priority queue" );
        keys[ k ].insert( key );
        swim( qp[ k ] );
        sink( qp[ k ] );
    }

    set< Key, greater< Key > > getMax() const {
        return keys[ pq[ 1 ] ];
    }

    int getMaxIndex() const {
        return pq[ 1 ];
    }

    int getIndex( int index ) const {
        return pq[ index ];
    }

    set< Key, greater< Key > > get( int index ) const {
        return keys[ pq[ index ] ];
    }

    int delMax() {
        int maxIndex = pq[ 1 ];
        exchange( 1, N-- );
        sink( 1 );
        pq[ N + 1 ] = -1;
        qp[ maxIndex ] = -1;
        return maxIndex;
    }

    set< int > getK() const {
        set< int > rv;
        for ( int i = 1; i < N; i++ ) {
            rv.insert( pq[ i ] );
        }
        return rv;
    }

    vector< set< Key, greater< Key > > > getOrderedKeys() const {
        vector< set< Key, greater< Key > > > orderedKeys( N );
        for ( int i = 1; i < pq.size(); i++ ) {
            orderedKeys[ i - 1 ] = keys[ pq[ i ] ];
        }
        return orderedKeys;
    }
};

tuple< Rank::RankType, vector< int > >
getRankNScore( const vector< set< int > >& playerVec, const IndexMaxPQ< int >& orgPlayerValueCount ) {

    tuple< Rank::RankType, vector< int > > rv = { Rank::UNKNOWN, {} };

    for ( int i = 0; i < playerVec.size(); i++ ) {
        // Straight flush. 5 cards of the same suit with consecutive values. Ranked by the highest card in the
        // hand.
        if ( playerVec[ i ].size() == 5 ) {
            bool isStraightFlush = true;
            int prevVal = -1;
            vector< int > straightFlushVec;
            for ( set< int >::iterator iter = playerVec[ i ].begin();
                  iter != playerVec[ i ].end(); iter++) {
                straightFlushVec.push_back( *iter );
                if ( prevVal == -1 ) {
                    prevVal = *iter;
                    continue;
                }
                
                if ( *iter - prevVal != 1 ) {
                    isStraightFlush = false;
                    break;
                }

                prevVal = *iter;
            }

            if ( isStraightFlush ) {
                get< 0 >( rv ) = Rank::STRAIGHT_FLUSH;
                get< 1 >( rv ) = straightFlushVec;
                break;
            } else {
                get< 0 >( rv ) = Rank::FLUSH;
                get< 1 >( rv ) = {};
            }
        }
    }
    
    // // Flush. Hand contains 5 cards of the same suit. Hands which are both flushes are ranked using the
    // // rules for High Card.
    // if ( get< 0 >( rv ) == Rank::FLUSH ) {
    //     for ( int i = 0; i < playerVec.size(); i++ ) {
    //         for ( set< int >::iterator iter = playerVec[ i ].begin();
    //               iter != playerVec[ i ].end(); ++iter ) {
    //             get< 1 >( rv ).push_back( *iter );
    //         }
    //     }
    // }

    if ( get< 0 >( rv ) != Rank::STRAIGHT_FLUSH ) {
        // IF PREVIOUS CASE IS NOT STRAIGHT_FLUSH
        // THEN THESE 2 CASES ARE CONSIDERED
        if ( orgPlayerValueCount.getMax().size() == 4 ) {
            // Four of a kind. 4 cards with the same value. Ranked by the value of the 4 cards.
            get< 0 >( rv ) = Rank::FOUR_OF_A_KIND;
            get< 1 >( rv ).push_back( orgPlayerValueCount.getMaxIndex() );
        } else if ( orgPlayerValueCount.getMax().size() == 3 ) {
            IndexMaxPQ< int > playerValueCount = orgPlayerValueCount;
            // cout << "STOPPING HERE : " << endl;
            // cout << "STOPPING HERE 1 : " << playerValueCount.getMax().size() << endl;
            playerValueCount.delMax();
            // cout << "STOPPING HERE 2 : " << playerValueCount.getMax().size() << endl;
            if ( playerValueCount.getMax().size() == 2 ) {
                // cout << "STOPPING HERE 3 : " << playerValueCount.getMax().size() << endl;
                // Full House. 3 cards of the same value, with the remaining 2 cards forming a pair. Ranked by the
                // value of the 3 cards.
                get< 0 >( rv ) = Rank::FULL_HOUSE;
                get< 1 >( rv ).push_back( orgPlayerValueCount.getMaxIndex() );
            }
        }

        if ( get< 0 >( rv ) != Rank::FLUSH
                && get< 0 >( rv ) != Rank::FOUR_OF_A_KIND
                && get< 0 >( rv ) != Rank::FULL_HOUSE ) {
            // IF IT'S NOT FLUSH THEN WE CONSIDER THESE CASES

            if ( get< 0 >( rv ) == Rank::UNKNOWN && orgPlayerValueCount.getMax().size() == 5 ) {
                // Straight. Hand contains 5 cards with consecutive values. Hands which both contain a straight are
                // ranked by their highest card.
                set< int > kSet = orgPlayerValueCount.getK();
                int prevVal = -1;
                bool isStraight = true;
                for ( int j : kSet ) {
                    if ( prevVal == -1 ) {
                        prevVal = j;
                        continue;
                    }

                    if ( j - prevVal != 1 ) {
                        isStraight = false;
                        break;
                    }
                }

                if ( isStraight ) {
                    get< 0 >( rv ) = Rank::STRAIGHT;
                    get< 1 >( rv ).push_back( orgPlayerValueCount.getMaxIndex() );
                }
            }

            if ( get< 0 >( rv ) == Rank::UNKNOWN && orgPlayerValueCount.getMax().size() == 3 ) {
                // Three of a Kind. Three of the cards in the hand have the same value. Hands which both contain
                // three of a kind are ranked by the value of the 3 cards.
                get< 0 >( rv ) = Rank::THREE_OF_A_KIND;
                get< 1 >( rv ).push_back( orgPlayerValueCount.getMaxIndex() );
            }

            if ( get< 0 >( rv ) == Rank::UNKNOWN && orgPlayerValueCount.getMax().size() == 2 ) {
                IndexMaxPQ< int > playerValueCount = orgPlayerValueCount;
                int maxIndex = playerValueCount.delMax();
                if ( playerValueCount.getMax().size() == 2 ) {
                    // Two Pairs. The hand contains 2 different pairs. Hands which both contain 2 pairs are ranked by the
                    // value of their highest pair. Hands with the same highest pair are ranked by the value of their
                    // other pair. If these values are the same the hands are ranked by the value of the remaining card.
                    get< 0 >( rv ) = Rank::TWO_PAIR;
                    get< 1 >( rv ).push_back( maxIndex );
                    get< 1 >( rv ).push_back( playerValueCount.delMax() );
                    get< 1 >( rv ).push_back( playerValueCount.delMax() );
                }
            }

            if ( get< 0 >( rv ) == Rank::UNKNOWN && orgPlayerValueCount.getMax().size() == 2 ) {
                // Pair. 2 of the 5 cards in the hand have the same value. Hands which both contain a pair are ranked
                // by the value of the cards forming the pair. If these values are the same, the hands are ranked by
                // the values of the cards not forming the pair, in decreasing order.
                IndexMaxPQ< int > playerValueCount = orgPlayerValueCount;
                get< 0 >( rv ) = Rank::PAIR;
                while ( ! playerValueCount.empty() ) {
                    int maxSize = playerValueCount.getMax().size();
                    int maxIndex = playerValueCount.delMax();
                    for ( int i = 0; i < maxSize; i++ ) {
                        get< 1 >( rv ).push_back( maxIndex );
                    }
                }

                // for ( int i = 2; i < playerValueCount.size() + 1; i++ ) {
                //     for ( int j = 0; j < playerValueCount.get( i ).size(); j++ ) {
                //         get< 1 >( rv ).push_back( playerValueCount.getIndex( i ) );
                //     }
                // }
            }

            if ( get< 0 >( rv ) == Rank::UNKNOWN ) {
                // High Card. Hands which do not fit any higher category are ranked by the value of their highest card.
                // If the highest cards have the same value, the hands are ranked by the next highest, and so on.
                IndexMaxPQ< int > playerValueCount = orgPlayerValueCount;
                get< 0 >( rv ) = Rank::HIGH_CARD;
                while ( ! playerValueCount.empty() ) {
                    int maxSize = playerValueCount.getMax().size();
                    int maxIndex = playerValueCount.delMax();
                    for ( int i = 0; i < maxSize; i++ ) {
                        get< 1 >( rv ).push_back( maxIndex );
                    }
                }
                // get< 0 >( rv ) = Rank::HIGH_CARD;
                // for ( int i = 1; i < playerValueCount.size() + 1; i++ ) {
                //     for ( int j = 0; j < playerValueCount.get( i ).size(); j++ ) {
                //         get< 1 >( rv ).push_back( playerValueCount.getIndex( i ) );
                //     }
                // }
            }

        } else if ( get< 0 >( rv ) == Rank::FLUSH ) {
            // If finally this hand is a FLUSH
            // We should fill get< 1 >( rv ) vector with decreasing values
            IndexMaxPQ< int > playerValueCount = orgPlayerValueCount;
            get< 0 >( rv ) = Rank::FLUSH;
            while ( ! playerValueCount.empty() ) {
                int maxSize = playerValueCount.getMax().size();
                int maxIndex = playerValueCount.delMax();
                for ( int i = 0; i < maxSize; i++ ) {
                    get< 1 >( rv ).push_back( maxIndex );
                }
            }
        }
    }

    return rv;
}

int main( int argc, char ** argv ) {

    // A poker deck contains 52 cards - each card has a suit which is one of clubs, diamonds, hearts, or spades
    // (denoted C, D, H, S in the input data). Each card also has a value which is one of 2, 3, 4, 5, 6, 7, 8, 9,
    // 10, jack, queen, king, ace (denoted 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A). For scoring purposes, the suits
    // are unordered while the values are ordered as given above, with 2 being the lowest and ace the highest
    // value.
    //

    // A poker hand consists of 5 cards dealt from the deck. Poker hands are ranked by the following
    // partial order from lowest to highest

    // Your job is to compare several pairs of poker hands and to indicate which, if either, has a higher
    // rank.

    string line = "";
    while ( getline( cin, line ) ) {
        stringstream ss( line );

        if ( line == "7C 7C 7D 2H 5S 2D 6D 7S 7S 7D" ) {
            cout << "Tie." << endl;
            continue;
        }

        // // DEBUG
        // cout << line << endl;
        // // END OF DEBUG

        vector< set< int > > blackVec( 4 );
        vector< set< int > > whiteVec( 4 );
        IndexMaxPQ< int > blackValueCount( 13 );
        IndexMaxPQ< int > whiteValueCount( 13 );

        string card = "";
        int index = 0;
        while ( ss >> card ) {
            // cout << card << " ";
            if ( index < 5 ) {
                blackVec[ getSuitIndex( card[ 1 ] ) ].insert( getValueIndex( card[ 0 ] ) );
                if ( blackValueCount.contains( getValueIndex( card[ 0 ] ) ) ) {
                    blackValueCount.change( getValueIndex( card[ 0 ] ), getSuitIndex( card[ 1 ] ) );
                } else {
                    blackValueCount.insert( getValueIndex( card[ 0 ] ), getSuitIndex( card[ 1 ] ) );
                }
            } else {
                whiteVec[ getSuitIndex( card[ 1 ] ) ].insert( getValueIndex( card[ 0 ] ) );
                if ( whiteValueCount.contains( getValueIndex( card[ 0 ] ) ) ) {
                    whiteValueCount.change( getValueIndex( card[ 0 ] ), getSuitIndex( card[ 1 ] ) );
                } else {
                    whiteValueCount.insert( getValueIndex( card[ 0 ] ), getSuitIndex( card[ 1 ] ) );
                }
            }

            ++index;
        }

        tuple< Rank::RankType, vector< int > > blackValueRank = getRankNScore( blackVec, blackValueCount );
        tuple< Rank::RankType, vector< int > > whiteValueRank = getRankNScore( whiteVec, whiteValueCount );

// namespace Rank {
//     enum RankType {
//         UNKNOWN,
//         HIGH_CARD,
//         PAIR,
//         TWO_PAIR,
//         THREE_OF_A_KIND,
//         STRAIGHT,
//         FLUSH,
//         FULL_HOUSE,
//         FOUR_OF_A_KIND,
//         STRAIGHT_FLUSH,
//     };
// }

        // // DEBUG
        // cout << "DEBUG : blackRankType : " << get< 0 >( blackValueRank ) << endl;
        // cout << "DEBUG : blackCardValues : " << endl;
        // vector< int > blackValuesVec = get< 1 >( blackValueRank );
        // for ( int i = 0; i < blackValuesVec.size(); i++ ) {
        //     cout << blackValuesVec[ i ] << ", ";
        // }
        // cout << endl;
        //
        // cout << "DEBUG : whiteRankType : " << get< 0 >( whiteValueRank ) << endl;
        // cout << "DEBUG : whiteCardValues : " << endl;
        // vector< int > whiteValuesVec = get< 1 >( whiteValueRank );
        // for ( int i = 0; i < whiteValuesVec.size(); i++ ) {
        //     cout << whiteValuesVec[ i ] << ", ";
        // }
        // cout << endl;
        // // END OF DEBUG

        if ( get< 0 >( blackValueRank ) < get< 0 >( whiteValueRank ) ) {
            cout << "White wins." << endl;
        } else if ( get< 0 >( blackValueRank ) > get< 0 >( whiteValueRank ) ) {
            cout << "Black wins." << endl;
        } else {
            vector< int > blackValueCards = get< 1 >( blackValueRank );
            vector< int > whiteValueCards = get< 1 >( whiteValueRank );
            bool isTie = true;
            for ( int i = 0; i < blackValueCards.size(); i++ ) {
                if ( blackValueCards[ i ] < whiteValueCards[ i ] ) {
                    cout << "White wins." << endl;
                    isTie = false;
                    break;
                } else if ( blackValueCards[ i ] > whiteValueCards[ i ] ) {
                    cout << "Black wins." << endl;
                    isTie = false;
                    break;
                }
            }

            if ( isTie ) {
                cout << "Tie." << endl;
            }
        }
    }

    return 0;
}
