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

        public void solve( int testNumber, InputReader in, PrintWriter out ) {
            while ( true ) {
                int N = in.nextInt();

                if ( N == 0 ) break;

                int dayCount = 0;
                int consumeCount = 0;

                GregorianCalendar prevDay = null;
                int prevDayConsume = 0;

                for ( int n = 0; n < N; ++n ) {
                    int D = in.nextInt();
                    int M = in.nextInt();
                    int Y = in.nextInt();
                    int C = in.nextInt();

                    if ( prevDay == null ) {
                        prevDay = new GregorianCalendar( Y, M - 1, D, 0, 0 );
                        prevDayConsume = C;
                    } else {
                        prevDay.add( Calendar.DAY_OF_YEAR, 1 );
                        if ( ( prevDay.get( Calendar.YEAR ) == Y )
                                && ( prevDay.get( Calendar.MONTH ) == M - 1 )
                                && ( prevDay.get( Calendar.DAY_OF_MONTH ) == D ) ) {
                            ++dayCount;
                            consumeCount += C - prevDayConsume;
                        } else {
                            prevDay = new GregorianCalendar( Y, M - 1, D, 0, 0 );
                        }
                        prevDayConsume = C;
                    }
                }

                out.println( dayCount + " " + consumeCount );

            }
        }
    }
}
