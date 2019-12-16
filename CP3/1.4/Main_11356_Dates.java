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

import java.util.HashMap;
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

        public void solve( int testNumber, InputReader in, PrintWriter out ) {

            int T = in.nextInt();

            HashMap< String, Integer > MONTHS_NAMES_TO_INDEXES = new HashMap< String, Integer >();
            MONTHS_NAMES_TO_INDEXES.put( "January", 0 );
            MONTHS_NAMES_TO_INDEXES.put( "February", 1 );
            MONTHS_NAMES_TO_INDEXES.put( "March", 2 );
            MONTHS_NAMES_TO_INDEXES.put( "April", 3 );
            MONTHS_NAMES_TO_INDEXES.put( "May", 4 );
            MONTHS_NAMES_TO_INDEXES.put( "June", 5 );
            MONTHS_NAMES_TO_INDEXES.put( "July", 6 );
            MONTHS_NAMES_TO_INDEXES.put( "August", 7 );
            MONTHS_NAMES_TO_INDEXES.put( "September", 8 );
            MONTHS_NAMES_TO_INDEXES.put( "October", 9 );
            MONTHS_NAMES_TO_INDEXES.put( "November", 10 );
            MONTHS_NAMES_TO_INDEXES.put( "December", 11 );

            String[] INDEXES_TO_MONTHS_NAMES = {
                "January",
                "February",
                "March",
                "April",
                "May",
                "June",
                "July",
                "August",
                "September",
                "October",
                "November",
                "December",
            };

            for ( int t = 0; t < T; ++t ) {
                String dateStr = in.next();
                int K = in.nextInt();

                String[] dateStrArr = dateStr.split( "-" );

                GregorianCalendar gc = new GregorianCalendar( Integer.parseInt( dateStrArr[ 0 ] ), MONTHS_NAMES_TO_INDEXES.get( dateStrArr[ 1 ] ), Integer.parseInt( dateStrArr[ 2 ] ), 0, 0 );
                gc.add( Calendar.DAY_OF_YEAR, K );
                out.printf( "Case %d: %04d-%s-%02d\n", t + 1, gc.get( Calendar.YEAR ), INDEXES_TO_MONTHS_NAMES[ gc.get( Calendar.MONTH ) ], gc.get( Calendar.DAY_OF_MONTH ) );
            }
        }
    }
}
