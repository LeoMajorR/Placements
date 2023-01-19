public class ReverseString {
    String reverse(String s) {
        String r = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            r += s.charAt(i);
        }
        return r;
    }

    public static void main(String[] args) {
        ReverseString rs = new ReverseString();
        System.out.println(rs.reverse("Hello, world!"));
    }
}
