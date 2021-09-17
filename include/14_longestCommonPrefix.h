#include "common_header.h"

class Solution14 {
public:
  std::string commonPrefix(std::string s1, std::string s2)
  {
    if (s1.empty() || s2.empty())
      return "";
    size_t l1 = s1.size();
    size_t l2 = s2.size();
    std::string common_prefix;
    for (size_t i = 0; i < l1 && i < l2; i++)
    {
      if (s1[i] != s2[i])
        break;
      common_prefix.push_back(s1[i]);
    }
    return common_prefix;
  }
  std::string helper(std::vector<std::string>& strs)
  {
    if (strs.empty())
      return "";

    if (strs.size() == 1)
      return strs[0];

    size_t mid = strs.size() / 2;
    std::vector<std::string> v1{strs.begin(), strs.begin() + mid};
    std::vector<std::string> v2{strs.begin() + mid, strs.end()};

    return commonPrefix(helper(v1), helper(v2));
  }

  std::string longestCommonPrefix(std::vector<std::string>& strs)
  {
    return helper(strs);
  }

  // std::string longestCommonPrefix(std::vector<std::string>& strs)
  // {
  //   if (strs.empty())
  //     return "";

  //   if (strs.size() == 1)
  //     return strs[0];

  //   size_t mid = strs.size() / 2;
  //   std::vector<std::string>* v1 = new std::vector<std::string>(strs.begin(), strs.begin() + mid);
  //   std::vector<std::string>* v2 = new std::vector<std::string>(strs.begin() + mid, strs.end());
  //   return commonPrefix(longestCommonPrefix(*v1), longestCommonPrefix(*v2));
  // }
};