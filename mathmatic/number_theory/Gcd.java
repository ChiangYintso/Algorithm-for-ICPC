public class Gcd {
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) {
        System.out.println(gcd(24, 16));
        System.out.println(gcd(17, 11));
    }
}