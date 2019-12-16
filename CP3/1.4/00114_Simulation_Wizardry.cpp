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

namespace Pinball {
    enum DirectionType {
        DIRECTION_RIGHT,    // 0
        DIRECTION_UP,       // 1
        DIRECTION_LEFT,     // 2
        DIRECTION_DOWN,     // 3
        // DIRECTION_UNKNOWN MUST BE LAST
        DIRECTION_UNKNOWN,  // 4
    };

    class Wall {
    public:
        int x = numeric_limits< int >::max();
        int y = numeric_limits< int >::max();
        int cost = 0;

        Wall( int cost )
            : cost( cost )
        {
            // not implemented
        }

        virtual ~Wall() {
            // not implemented
        }
    };

    class Bumper {
    public:
        int x = 0;
        int y = 0;
        int value = 0;
        int cost = 0;

        Bumper() {
            // not implemented
        }

        Bumper( int x, int y, int value, int cost )
            : x( x ),
              y( y ),
              value( value ),
              cost( cost )
        {
            // not implemented
        }

        virtual ~Bumper() {
            // not implemented
        }
    };

    class Ball {
    private:

        void changeDirection() {
            switch ( direction ) {
                case DIRECTION_UP:
                {
                    direction = DIRECTION_RIGHT;
                    break;
                }

                case DIRECTION_DOWN:
                {
                    direction = DIRECTION_LEFT;
                    break;
                }

                case DIRECTION_LEFT:
                {
                    direction = DIRECTION_UP;
                    break;
                }

                case DIRECTION_RIGHT:
                {
                    direction = DIRECTION_DOWN;
                    break;
                }

                default:
                {
                    break;
                }
            }
        }

    public:
        int x = 0;
        int y = 0;
        DirectionType direction = DIRECTION_UNKNOWN;
        int life = 0;
        int point = 0;

        Ball() {
            // not implemented
        }

        Ball( int x, int y, DirectionType direction, int life )
            : x( x ),
              y( y ),
              direction( direction ),
              life( life )
        {
            // not implemented
        }

        virtual ~Ball() {
            // not implemented
        }

        void move() {
            switch ( direction ) {
                case DIRECTION_UP:
                {
                    ++y;
                    break;
                }

                case DIRECTION_DOWN:
                {
                    --y;
                    break;
                }

                case DIRECTION_LEFT:
                {
                    --x;
                    break;
                }

                case DIRECTION_RIGHT:
                {
                    ++x;
                    break;
                }

                default:
                {
                    break;
                }
            }
            --life;
        }

        Pinball::Bumper * isHitAny( unordered_map< int, unordered_map< int, unique_ptr< Pinball::Bumper > > >& bumpersMap ) const {
            switch ( direction ) {
                case DIRECTION_UP:
                {
                    if ( bumpersMap.find( x ) != bumpersMap.end() && bumpersMap[ x ].find( y + 1 ) != bumpersMap[ x ].end() ) {
                        return bumpersMap[ x ][ y + 1 ].get();
                    }
                    break;
                }

                case DIRECTION_DOWN:
                {
                    if ( bumpersMap.find( x ) != bumpersMap.end() && bumpersMap[ x ].find( y - 1 ) != bumpersMap[ x ].end() ) {
                        return bumpersMap[ x ][ y - 1 ].get();
                    }
                    break;
                }

                case DIRECTION_LEFT:
                {
                    if ( bumpersMap.find( x - 1 ) != bumpersMap.end() && bumpersMap[ x - 1 ].find( y ) != bumpersMap[ x - 1 ].end() ) {
                        return bumpersMap[ x - 1 ][ y ].get();
                    }
                    break;
                }

                case DIRECTION_RIGHT:
                {
                    if ( bumpersMap.find( x + 1 ) != bumpersMap.end() && bumpersMap[ x + 1 ].find( y ) != bumpersMap[ x + 1 ].end() ) {
                        return bumpersMap[ x + 1 ][ y ].get();
                    }
                    break;
                }

                default:
                {
                    break;
                }
            }
            return NULL;
        }

        bool isHit( const Bumper& bumper ) const {
            switch ( direction ) {
                case DIRECTION_UP:
                {
                    if ( x == bumper.x && y + 1 == bumper.y ) {
                        return true;
                    }
                    break;
                }

                case DIRECTION_DOWN:
                {
                    if ( x == bumper.x && y - 1 == bumper.y ) {
                        return true;
                    }
                    break;
                }

                case DIRECTION_LEFT:
                {
                    if ( y == bumper.y && x - 1 == bumper.x ) {
                        return true;
                    }
                    break;
                }

                case DIRECTION_RIGHT:
                {
                    if ( y == bumper.y && x + 1 == bumper.x ) {
                        return true;
                    }
                }

                default:
                {
                    break;
                }
            }
            return false;
        }

        bool isHit( const Wall& wall ) const {
            switch ( direction ) {
                case DIRECTION_UP:
                {
                    if ( y + 1 == wall.y ) {
                        return true;
                    }
                    break;
                }

                case DIRECTION_DOWN:
                {
                    if ( y - 1 == wall.y ) {
                        return true;
                    }
                    break;
                }

                case DIRECTION_LEFT:
                {
                    if ( x - 1 == wall.x ) {
                        return true;
                    }
                    break;
                }

                case DIRECTION_RIGHT:
                {
                    if ( x + 1 == wall.x ) {
                        return true;
                    }
                    break;
                }

                default:
                {
                    break;
                }
            }
            return false;
        }

        bool isDead() const {
            return life <= 0;
        }

        void maybeHit( const Bumper& bumper ) {
            if ( isHit( bumper ) ) {
                --life;
                if ( life > 0 ) {
                    point += bumper.value;
                    life -= bumper.cost;
                    changeDirection();
                }
            }
        }

        void maybeHit( const Wall& wall ) {
            if ( isHit( wall ) ) {
                --life;
                if ( life > 0 ) {
                    life -= wall.cost;
                    changeDirection();
                }
            }
        }
    };
};

int main( int argc, char ** argv ) {

    string line = "";
    int m = 0;
    int n = 0;

    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> m >> n;
    }

    int wallHitCost = 0;
    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> wallHitCost;
    }

    // Construct the walls
    vector< unique_ptr< Pinball::Wall > > wallsVec;
    // Positive y axis
    wallsVec.push_back( unique_ptr< Pinball::Wall >( new Pinball::Wall( wallHitCost ) ) );
    wallsVec.back()->x = 1;
    // Positive x axis
    wallsVec.push_back( unique_ptr< Pinball::Wall >( new Pinball::Wall( wallHitCost ) ) );
    wallsVec.back()->y = 1;
    // Parallel to y axis
    wallsVec.push_back( unique_ptr< Pinball::Wall >( new Pinball::Wall( wallHitCost ) ) );
    wallsVec.back()->x = m;
    // Parallel to x axis
    wallsVec.push_back( unique_ptr< Pinball::Wall >( new Pinball::Wall( wallHitCost ) ) );
    wallsVec.back()->y = n;

    int bumpersCount = 0;
    if ( getline( cin, line ) ) {
        stringstream ss( line );
        ss >> bumpersCount;
    }
    
    // Construct a map for bumpers to speed up bumpers look-up
    unordered_map< int, unordered_map< int, unique_ptr< Pinball::Bumper > > > bumpersMap;
    for ( int i = 0; i < bumpersCount; i++ ) {
        if ( getline( cin, line ) ) {
            stringstream ss( line );
            int x = 0;
            int y = 0;
            int value = 0;
            int cost = 0;
            ss >> x >> y >> value >> cost;
            if ( bumpersMap.find( x ) == bumpersMap.end() ) {
                bumpersMap.insert( { x, unordered_map< int, unique_ptr< Pinball::Bumper > >() } );
            }

            bumpersMap[ x ].insert( { y, unique_ptr< Pinball::Bumper >( new Pinball::Bumper() ) } );
            bumpersMap[ x ][ y ]->x = x;
            bumpersMap[ x ][ y ]->y = y;
            bumpersMap[ x ][ y ]->value = value;
            bumpersMap[ x ][ y ]->cost = cost;
        }
    }

    int totalPoint = 0;
    while ( getline( cin, line ) ) {
        stringstream ss( line );
        Pinball::Ball ball;
        int direction = 0;
        ss >> ball.x >> ball.y >> direction >> ball.life;
        ball.direction = static_cast< Pinball::DirectionType >( direction );
        while ( ! ball.isDead() ) {
            bool isDead = false;
            bool isHit = false;
            for ( int i = 0; i < wallsVec.size(); i++ ) {
                if ( ball.isHit( *( wallsVec[ i ] ) ) ) {
                    isHit = true;
                }

                ball.maybeHit( *( wallsVec[ i ] ) );
                if ( ball.isDead() ) {
                    isDead = true;
                    break;
                }
            }

            if ( isDead ) {
                break;
            }

            Pinball::Bumper * hitBumper = ball.isHitAny( bumpersMap );
            if ( hitBumper ) {
                isHit = true;
                ball.maybeHit( * hitBumper );
                if ( ball.isDead() ) {
                    isDead = true;
                }
            }
            
            if ( isDead ) {
                break;
            }
            
            if ( ! isDead && ! isHit ) {
                ball.move();
            }
        }
        cout << ball.point << endl;
        totalPoint += ball.point;
    }

    cout << totalPoint << endl;

    return 0;
}
