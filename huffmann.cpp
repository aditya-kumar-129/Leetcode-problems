#include<bits/stdc++.h>
using namespace std;

class HuffTree
{
public:
  int val;
  char letter;
  HuffTree* left, * right;
  HuffTree(int val, char letter)
  {
    this->val = val;
    this->letter = letter;
    this->left = nullptr;
    this->right = nullptr;
  }
};

vector<pair<int, char>> FrequencyCount(string s)
{
  map<char, int> mp;
  for (int i = 0;i < s.size();i++)
    mp[s[i]]++;
  vector<pair<int, char>> v;
  for (auto it : mp)
    v.push_back(make_pair(it.second, it.first));
  return v;
}

class Compare
{
public:
  bool operator() (HuffTree* a, HuffTree* b)
  {
    return (a->val > b->val);
  }
};

vector<pair<char, string >> huffmannCodes;
void printCodes(HuffTree* root, string str)
{
  if (!root)
    return;
  if (root->letter != '#')
    huffmannCodes.push_back(make_pair(root->letter, str));
  printCodes(root->left, str + "0");
  printCodes(root->right, str + "1");
}

HuffTree* makeTree(vector<pair<int, char>>& frq)
{
  priority_queue<HuffTree*, vector<HuffTree*>, Compare> pq;
  for (auto it : frq)
    pq.push(new HuffTree(it.first, it.second));
  while (pq.size() > 1)
  {
    HuffTree* left = pq.top();
    pq.pop();
    HuffTree* right = pq.top();
    pq.pop();
    HuffTree* newNode = new HuffTree(left->val + right->val, '#');
    newNode->left = left;
    newNode->right = right;
    pq.push(newNode);
  }
  printCodes(pq.top(), "");
  return pq.top();
}

string decode(HuffTree* root, string s)
{
  string ans = "";
  HuffTree* curr = root;
  for (int i = 0;i < s.size();i++)
  {
    if (s[i] == '0')
      curr = curr->left;
    else
      curr = curr->right;
    // reached leaf node
    if (!curr->left && !curr->right )
    {
      ans += curr->letter;
      curr = root;
    }
  }
  return ans + '\0';
}

int main()
{
  string s;
  cin >> s;
  vector<pair<int, char>> freqcount = FrequencyCount(s);
  sort(freqcount.begin(), freqcount.end());
  HuffTree* root = makeTree(freqcount);

  for (auto it : huffmannCodes)
    cout << it.first << "-->" << it.second << endl;

  map<char, string> mp;
  for (auto it : huffmannCodes)
    mp[it.first] = it.second;

  string encoded_string = "";
  for (auto it : s)
    encoded_string += mp[it];
  cout << encoded_string << endl;

  string decoded_string = "";
  decoded_string = decode(root, encoded_string);
  cout << decoded_string << endl;
}