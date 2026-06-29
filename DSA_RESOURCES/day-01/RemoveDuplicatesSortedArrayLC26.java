




public class RemoveDuplicatesSortedArrayLC26 {

    public static int removeDuplicates(int[] nums) {

        int slow = 0;

        for (int fast = 1; fast < nums.length; fast++) {

            if (nums[slow] != nums[fast]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }

        return slow + 1;
    }

    public static void main(String[] args) {

        int[] nums = {1, 1, 2, 2, 3, 4, 4, 5};

        int k = removeDuplicates(nums);

        System.out.println("Number of Unique Elements: " + k);

        System.out.print("Updated Array: ");
        for (int i = 0; i < k; i++) {
            System.out.print(nums[i] + " ");
        }
    }
}

