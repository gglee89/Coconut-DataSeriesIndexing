/**
 * @title: Convert String to Unsigned Integer
 * @author: Giwoo G Lee
 * @project: COP5725 - @FSU Fall '19
 * @since 2019-11-24
 */
uint_fast32_t string_to_unsigned_int(string str) {
  uint_fast32_t result(0);
  for (int i = str.size() - 1; i >= 0; i--) {
    uint_fast32_t temp(0), k = str.size() - i - 1;
    if (isdigit(str[i])) {
      temp = str[i] - '0';
      while (k--) temp *= 10;
      result += temp;
    } else {
      break;
    }
  }
  return result;
}

/**
 * @title: Split and Vectorize string
 *  e.g.:
 *    intput - 0 20 2 4 19 20
 *    output - ["0", "20", "2", "4", "19", "20"]
 * @author: Giwoo G Lee
 * @project: COP5725 - @FSU Fall '19
 * @since 2019-11-24
 */
vector<string> split(string str, string pattern) {
  string::size_type pos;
  vector<string> result;
  str += pattern;
  int size = str.size();
  for (int i = 0; i < size; i++) {
    pos = str.find(pattern, i);
    if (pos < size) {
      string s = str.substr(i, pos - i);
      result.push_back(s);
      i = pos + pattern.size() - 1;
    }
  }
  return result;
}