

public class ValidPalindromeLC125 {

    public static boolean isPalindrome(String s) {

        s = s.replaceAll("[^A-Za-z0-9]", "").toLowerCase();

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    public static void main(String[] args) {

        String str = "A man, a plan, a canal: Panama";

        System.out.println("Input : " + str);
        System.out.println("Output: " + isPalindrome(str));
    }
}

