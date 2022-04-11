// Question link :- https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution {
  public boolean isValidSerialization(String preorder) {
    String[] nodes = preorder.split(",");
    int vacancy = 1;
    for (String s : nodes)
    {
      vacancy--;
      if (vacancy < 0)
        return false;
      if (!s.equals("#"))
        vacancy += 2;
    }
    return (vacancy == 0);
  }
}