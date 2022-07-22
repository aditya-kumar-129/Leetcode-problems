// Question link :- https://leetcode.com/problems/add-binary/
// Explained solution :- https://leetcode.com/problems/reverse-bits/discuss/54738/Sharing-my-2ms-Java-Solution-with-Explanation

int reverseBits(int n) {
  if (n == 0)
    return 0;
  int result = 0;
  for (int i = 0; i < 32; i++) {
    result <<= 1;
    if ((n & 1) == 1)
      result++;
    n >>= 1;
  }
  return result;
}