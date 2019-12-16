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
                int dayCount = in.nextInt();
                int startDay = in.nextInt();
                int startMonth = in.nextInt();
                int startYear = in.nextInt();

                if ( dayCount == 0 && startDay == 0 && startMonth == 0 && startYear == 0 ) return;

                GregorianCalendar gc = new GregorianCalendar( startYear, startMonth - 1, startDay, 0, 0, 0 );

                gc.add( Calendar.DAY_OF_YEAR, dayCount );

                out.println( gc.get( Calendar.DAY_OF_MONTH ) + " " + ( gc.get( Calendar.MONTH ) + 1 ) + " " + gc.get( Calendar.YEAR ) );
            }
        }
    }
}
