// Java program to find four
// elements with the given sum
import java.util.*;

class fourElementWithSum {

	// Function to find 4 elements that add up to
	// given sum
	public static void fourElementWithSu(int[] arr,int arr_size,int target)
	{
		ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
    Arrays.sort(arr);
    for (int i = 0; i < arr_size - 3; i++) 
    {
        for (int j = i + 1; j < arr_size -  2; j++) 
        {
            int left = j + 1, right = arr_size - 1;
            // To handle overflow condition we have to
            // subtract the two traversed element from the
            // target and get the new target (target_2)
            int target_2 = target - arr[i] - arr[j];
            while (left < right) 
            {
                if (arr[left] + arr[right] == target_2) 
                {
                    ArrayList<Integer> quad = new ArrayList<>();
                        quad.add(arr[i]);
                        quad.add(arr[j]);
                        quad.add(arr[left]);
                        quad.add(arr[right]);
                        ans.add(quad);
                    // Skip the element that are same in the
                    // left pointer and the left + 1 pointer
                    // in order to get the unique pairs only
                    // by executing the below line of code
                    while (left < right && arr[left] == arr[left+1])
                        left++;
                    // Skip the element that are same in the
                    // right pointer and the right - 1
                    // pointer in order to get the unique
                    // pairs only by executing the below
                    // line of code
                    while (left < right && arr[right] == arr[right-1])
                        right--;
                }
                else if (arr[left] + arr[right] > target_2)
                    right--;
                else
                    left++;
            }
            // Skip the element that are same in the "j"
            // pointer and the "j" + 1 pointer in order to
            // get the unique pairs only by executing the
            // below line of code
            while (j + 1 < arr_size && arr[j] == arr[j + 1])
                j++;
        }
        // Skip the element that are same in the "i" pointer
        // and the "i" + 1 pointer in order to get the
        // unique pairs only by executing the below line of
        // code
        while (i + 1 < arr_size && arr[i] == arr[i + 1])
            i++;
    }
    for (ArrayList<Integer> v : ans) 
    {
      for (int u : v) 
        System.out.print(u + " ");
      System.out.print("$");
    }
    if (ans.isEmpty()) 
        System.out.print(-1);
    System.out.println();
	}
  

	public static void main(String args[])
	{
		int[] arr = { 10, 20, 30, 40, 1, 2 };
		int n = arr.length;
		int X = 91;
		fourElementWithSu(arr,n, X);
	}
}

// This code is contributed by Aditya Kumar (adityakumar129)