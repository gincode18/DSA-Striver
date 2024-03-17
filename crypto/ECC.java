import java.math.BigInteger;
import java.security.SecureRandom;

public class ECC {

    private static final BigInteger P = new BigInteger("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F", 16);
    private static final BigInteger A = BigInteger.ZERO;
    private static final BigInteger B = BigInteger.valueOf(7);
    private static final BigInteger N = new BigInteger("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141", 16);
    private static final BigInteger Gx = new BigInteger("79BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798", 16);
    private static final BigInteger Gy = new BigInteger("483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8", 16);

    public static void main(String[] args) {
        BigInteger private_key = generatePrivateKey();
        ECCPoint public_key = generatePublicKey(private_key);
        System.out.println("Private Key (d): " + private_key.toString(16));
        System.out.println("Public Key (x, y): " + public_key.x.toString(16) + ", " + public_key.y.toString(16));

        if (isOnCurve(public_key)) {
            System.out.println("Public Key is on the curve.");
        } else {
            System.out.println("Public Key is NOT on the curve.");
        }
    }

    public static BigInteger generatePrivateKey() {
        return new BigInteger(N.bitLength() - 1, new SecureRandom());
    }

    public static ECCPoint generatePublicKey(BigInteger private_key) {
        ECCPoint point = pointMultiply(private_key, new ECCPoint(Gx, Gy));
        return point;
    }

    public static boolean isOnCurve(ECCPoint point) {
        BigInteger left = point.y.pow(2).mod(P);
        BigInteger right = point.x.pow(3).add(A.multiply(point.x)).add(B).mod(P);
        return left.equals(right);
    }

    public static ECCPoint pointAdd(ECCPoint p1, ECCPoint p2) {
        if (p1 == null) return p2;
        if (p2 == null) return p1;

        if (p1.x.equals(p2.x) && !p1.y.equals(p2.y)) return null;

        BigInteger m;
        if (p1.x.equals(p2.x)) {
            m = p1.x.pow(2).multiply(BigInteger.valueOf(3)).add(A).multiply(p1.y.modInverse(P)).mod(P);
        } else {
            m = p1.y.subtract(p2.y).multiply(p1.x.subtract(p2.x).modInverse(P)).mod(P);
        }

        BigInteger x3 = m.pow(2).subtract(p1.x).subtract(p2.x).mod(P);
        BigInteger y3 = m.multiply(p1.x.subtract(x3)).subtract(p1.y).mod(P);

        return new ECCPoint(x3, y3);
    }

    public static ECCPoint pointMultiply(BigInteger k, ECCPoint point) {
        ECCPoint result = null;
        ECCPoint addend = point;
        while (k.compareTo(BigInteger.ZERO) > 0) {
            if (k.and(BigInteger.ONE).equals(BigInteger.ONE)) {
                result = pointAdd(result, addend);
            }
            addend = pointAdd(addend, addend);
            k = k.shiftRight(1);
        }
        return result;
    }

    public static class ECCPoint {
        public BigInteger x;
        public BigInteger y;

        public ECCPoint(BigInteger x, BigInteger y) {
            this.x = x;
            this.y = y;
        }
    }
}