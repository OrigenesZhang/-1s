import java.math.BigInteger;
import java.util.*;
import java.io.*;
 
public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();
 
        // First 200 prime numbers
        List<BigInteger> primes = new ArrayList<>();
        BigInteger curr = new BigInteger("2");
        BigInteger one = new BigInteger("1");
        while (primes.size() < 200) {
            if (isPrime(curr, primes)) {
//                System.out.println(curr);
                primes.add(curr);
            }
            curr = curr.add(one);
        }
 
        BigInteger[] products = new BigInteger[200];
        for (int i = 1; i <= t; ++i) {
            BigInteger n = in.nextBigInteger();
            int k = findMaxK(n, primes, products);
//            System.out.println("k: " + k);
 
            BigInteger numerator = products[k] == null ? getProduct(primes, k) : products[k];
            BigInteger denominator = getDenominator(primes, k);
            BigInteger gcd = gcd(numerator, denominator);
            gcd = gcd.compareTo(BigInteger.ZERO) == 0 ? BigInteger.ONE : gcd;
            System.out.println(numerator.divide(gcd) + "/" + denominator.divide(gcd));
        }
    }
 
    private static int findMaxK(BigInteger n, List<BigInteger> primes, BigInteger[] products) {
        int left = 0;
        int right = 199;
 
        while (left < right - 1) {
            int mid = (left + right) / 2;
//            System.out.println(left + " " + mid + " " + right);
            BigInteger midRes = products[mid] == null ? getProduct(primes, mid) : products[mid];
//            System.out.println("midRes: " + midRes);
            products[mid] = midRes;
            if (midRes.compareTo(n) == 0) {
                return mid;
            } else if (midRes.compareTo(n) > 0) { // midRes > n
                right = mid - 1;
            } else { // midRes < n
                left = mid;
            }
        }
 
        BigInteger rightRes = products[right] == null ? getProduct(primes, right) : products[right];
        if (rightRes.compareTo(n) <= 0) {
            return right;
        }
 
        return left;
    }
 
    private static BigInteger getProduct(List<BigInteger> primes, int k) {
        BigInteger result = BigInteger.ONE;
        for (int i = 0; i < k; i++) {
            result = result.multiply(primes.get(i));
        }
        return result;
    }
 
    private static BigInteger getDenominator(List<BigInteger> primes, int k) {
        BigInteger result = BigInteger.ONE;
        for (int i = 0; i < k; i++) {
            result = result.multiply(primes.get(i).add(BigInteger.ONE));
        }
        return result;
    }
 
    private static boolean isPrime(BigInteger num, List<BigInteger> primes) {
        for (BigInteger factor : primes) {
            if (num.remainder(factor).compareTo(BigInteger.ZERO) == 0) {
                return false;
            }
        }
        return true;
    }
 
    private static BigInteger gcd(BigInteger one, BigInteger two) {
//        System.out.println(one + " " + two);
        if (two.compareTo(BigInteger.ZERO) == 0) {
            return one;
        }
 
        return gcd(two, one.remainder(two));
    }
}