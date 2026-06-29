
import java.util.Arrays;
public class twosum_sortedarray_lc167 {
    public static int[] twoSum(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            } else {
                // Return 1-based indices
                return new int[]{left + 1, right + 1};
            }
        }

        return new int[]{-1, -1};
    }

    public static void main(String[] args) {

        int[] nums = {2, 3, 4, 7, 11, 15};
        int target = 9;

        int[] result = twoSum(nums, target);

        System.out.println("Array : " + Arrays.toString(nums));
        System.out.println("Target: " + target);
        System.out.println("Result: " + Arrays.toString(result));
    }
}


    

