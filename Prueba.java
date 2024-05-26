public class Prueba {

    public static void main(String[] args) {
        boolean a = isValid(new char[]  {'n','n','n','s','n','s','n','s','n','s'});
        if (a) {
            System.out.println("es");
        } else {
            System.out.println("no es");
        }
    }

    public static boolean isValid(char[] walk) {
        // Insert brilliant code here
        int min = 0;
        for (int i = 0; i < walk.length; i++) {
            if (i == 0) {
                min++;
            } else if (i >= 1) {
                if (walk[i] != walk[i - 1]) {
                    min++;
                }
            }
        }
        System.out.println(min);
        return min == 10;
    }
}