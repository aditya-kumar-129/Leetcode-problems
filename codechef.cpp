// THE UNCHANGING OR
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// void method()
// {
//   int n;
//   cin >> n;
//   int val1, val2;
//   for (int i = 0;i <= 31;i++)
//   {
//     if ((1 << i) & n)
//     {
//       val1 = i;
//       val2 = (1 << i);
//     }
//   }
//   int ans = 0;
//   int var = 1;
//   for (int i = 0;i < val1;i++)
//   {
//     ans += (var - 1);
//     var *= 2;
//   }
//   ans += (n - val2);
//   cout << ans << endl;
// }
// int main()
// {
//   int t;
//   cin >> t;
//   while (t--)
//     method();
//   return 0;
// }