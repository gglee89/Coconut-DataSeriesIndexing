/**
 * @title: Display program main menu
 * @author: Giwoo G Lee
 * @project: COP5725 - @FSU Fall '19
 * @since 2019-11-24
 */
int program_main_menu() {
  system("clear");
  cout << "\n==================================" << endl;
  cout << "========== Coconut Menu ==========" << endl;
  cout << "==================================" << endl;
  cout << "== [0]: Indexing =================" << endl;
  cout << "== [1]: Query ====================" << endl;
  cout << "== [2]: Exit =====================" << endl;
  cout << "==================================" << endl;
  cout << "Enter choice: ";

  int input;
  cin >> input;
  return input;
}

char program_query_menu() {
  system("clear");
  cout << "\n=================================" << endl;
  cout << "========= Coconut Query =========" << endl;
  cout << "=================================" << endl;
  cout << "[e or E]: Exact Search" << endl;
  cout << "[s or S]: Simiilarity Search" << endl;
  cout << "[r or R]: Return to Main Menu" << endl;
  cout << "Enter choice : ";

  char input;
  cin >> input;
  return input;
}