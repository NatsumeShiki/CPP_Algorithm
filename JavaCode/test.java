import java.io.*;
import java.text.FieldPosition;
import java.util.*;

class function {
    public static double get(String s) {
        Scanner sc = new Scanner(s);
        sc.useDelimiter("[^0123456789.]+");
        double sum = 0;
        while (sc.hasNext()) {
            sum += sc.nextDouble();
        }
        return sum;
    }
}

public class test {
    public static void main(String[] args) {
        double res = 0;
        BufferedReader br = null;
        try {
            br = new BufferedReader(new FileReader("in.txt"));
            String str;
            while ((str = br.readLine()) != null) {
                res += function.get(str);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally{
            if(br != null) {
                try {
                    br.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        System.out.println(res / 4);
    }
}