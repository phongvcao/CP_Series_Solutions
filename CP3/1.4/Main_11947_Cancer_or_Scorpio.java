import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

import java.util.GregorianCalendar;
import java.util.Calendar;

class Main {

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader( InputStream stream ) {
            reader = new BufferedReader( new InputStreamReader( stream ), 32768 );
            tokenizer = null;
        }

        public String next() {
            while ( tokenizer == null || !tokenizer.hasMoreTokens() ) {
                try {
                    tokenizer = new StringTokenizer( reader.readLine() );
                } catch ( IOException e ) {
                    throw new RuntimeException( e );
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt( next() );
        }

        public long nextLong() {
            return Long.parseLong( next() );
        }
    }

    public static void main( String[] args ) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader( inputStream );
        PrintWriter out = new PrintWriter( outputStream );
        Task solver = new Task();
        solver.solve( 1, in, out );
        out.close();
    }

    static class Task {

        private class MonthDayPair {
            public int day = 0;
            public int month = 0;

            public MonthDayPair() {
                // not implemented
            }

            public MonthDayPair( int month, int day ) {
                this.month = month;
                this.day = day;
            }

            public int compareTo( GregorianCalendar gc ) {
                if ( month < gc.get( Calendar.MONTH ) ) {
                    return -1;
                } else if ( month > gc.get( Calendar.MONTH ) ) {
                    return 1;
                } else {
                    if ( day < gc.get( Calendar.DAY_OF_MONTH ) ) {
                        return -1;
                    } else if ( day > gc.get( Calendar.DAY_OF_MONTH ) ) {
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }

        private MonthDayPair[] MONTH_DAY_TO_SIGN_INDEXES = {
            new MonthDayPair( 0, 0 ),
            new MonthDayPair( 0, 21 ),
            new MonthDayPair( 1, 20 ),
            new MonthDayPair( 2, 21 ),
            new MonthDayPair( 3, 21 ),
            new MonthDayPair( 4, 22 ),
            new MonthDayPair( 5, 22 ),
            new MonthDayPair( 6, 23 ),
            new MonthDayPair( 7, 22 ),
            new MonthDayPair( 8, 24 ),
            new MonthDayPair( 9, 24 ),
            new MonthDayPair( 10, 23 ),
            new MonthDayPair( 11, 23 ),
            new MonthDayPair( 11, 32 ),
        };

        private String[] SIGN_NAMES = {
            "capricorn",
            "aquarius",
            "pisces",
            "aries",
            "taurus",
            "gemini",
            "cancer",
            "leo",
            "virgo",
            "libra",
            "scorpio",
            "sagittarius",
            "capricorn",
        };

        private int binarySearchMonthDayToSignIndexes( GregorianCalendar gc ) {
            int low = 0;
            int high = MONTH_DAY_TO_SIGN_INDEXES.length - 1;

            while ( low <= high ) {
                int mid = low + ( high - low ) / 2;
                int cmp = MONTH_DAY_TO_SIGN_INDEXES[ mid ].compareTo( gc );
                if ( cmp < 0 ) {
                    low = mid + 1;
                } else if ( cmp > 0 ) {
                    high = mid - 1;
                } else {
                    return mid;
                }
            }
            return low - 1;
        }

        public void solve( int testNumber, InputReader in, PrintWriter out ) {
            int N = in.nextInt();

            for ( int n = 0; n < N; ++n ) {
                String dateMenstrual = in.next();
                int monthMenstrual = Integer.parseInt( dateMenstrual.substring( 0, 2 ) ) - 1;
                int dayMenstrual = Integer.parseInt( dateMenstrual.substring( 2, 4 ) );
                int yearMenstrual = Integer.parseInt( dateMenstrual.substring( 4 ) );

                GregorianCalendar gc = new GregorianCalendar( yearMenstrual, monthMenstrual, dayMenstrual, 0, 0 );

                gc.add( Calendar.WEEK_OF_YEAR, 40 );

                out.printf( "%d %02d/%02d/%04d %s\n", n + 1, gc.get( Calendar.MONTH ) + 1, gc.get( Calendar.DAY_OF_MONTH ), gc.get( Calendar.YEAR ), SIGN_NAMES[ binarySearchMonthDayToSignIndexes( gc ) ] );
            }
        }
    }
}
