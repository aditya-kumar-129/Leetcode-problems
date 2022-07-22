#include<iostream>
using namespace std;

int fun0(string s, int first, int last, int i)
{
  i++;
  int mid = (first + last) / 2;
  if (i == 4)
    return mid;
  if (s[i] == '0')
    return fun0(s, first, mid, i);
  else
    return fun0(s, mid + 1, last, i);
}
int fun(string s)
{
  int first = 97, last = 112, i = 0;
  int mid = (first + last) / 2;
  if (s[i] == '0')
    return fun0(s, first, mid, i);
  else
    return fun0(s, mid + 1, last, i);
}

int main()
{
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1 = "";
    for (int i = 0;i < n;i += 4) {
      int b = fun(s.substr(i, 4));
      s1 = s1 + char(b);
    }
    cout << s1;
  }
}